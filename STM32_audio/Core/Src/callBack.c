/*
 * callBack.c
 *
 *  Created on: Nov 19, 2024
 *      Author: romingo
 */

#include "callBack.h"
#include "stm32l4xx_hal.h"

extern int spi_tx_complete;

SemaphoreHandle_t sem_uart_read = NULL;


//extern uint8_t fifo_status = 0;

/*
 * We must declared here a function CUSTOM_ because main.c already use this callback
 */

/*********** PREEMPTION PRIORITY  ***********/

/*********** PREEMPTION PRIORITY 5 ***********/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	/** SHELL INTERRUPTIONS **/
	if (huart->Instance == USART2) {
		BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
		xSemaphoreGiveFromISR(sem_uart_read, &pxHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(pxHigherPriorityTaskWoken);
	}
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi){
	if(hspi->Instance == SPI3){
		spi_tx_complete = 0;
		//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	}
}
