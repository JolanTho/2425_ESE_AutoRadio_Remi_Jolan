#include <stdint.h>
#include <stdio.h>
#include "MCP2317.h"
#include "stm32l4xx_hal.h"

#define MCP23S17_WRITE_OPCODE 0x40
#define MCP23S17_READ_OPCODE 0x41
#define IODIRA_REG 0x00
#define IODIRB_REG 0x01
#define GPIOA_REG 0x12
#define GPIOB_REG 0x13

extern SPI_HandleTypeDef hspi3;
uint8_t Spitxbuffer[3];
volatile int spi_tx_complete = 0;


void MCP17023_init(void){

	MCP17023_write_register(IODIRA_REG, 0x00);
	MCP17023_write_register(IODIRB_REG, 0x00);

}

void MCP17023_write_register(uint8_t addr, uint8_t value){
	while(spi_tx_complete != 1){
		spi_tx_complete = 1;

		Spitxbuffer[0] = MCP23S17_WRITE_OPCODE;
		Spitxbuffer[1] = addr;
		Spitxbuffer[2] = value;

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

		HAL_SPI_Transmit_IT(&hspi3, Spitxbuffer, 3);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);

	}
}

void MCP17023_set_led (uint8_t addrled){

	MCP17023_write_register(GPIOA_REG, addrled);
	MCP17023_write_register(GPIOB_REG, addrled);

}

void MCP17023_chenillard(char **argv){
	uint8_t actual_led = 0x01;
	for(;;){
		MCP17023_set_led(actual_led);
		actual_led <<=1;
		if (actual_led == 0x00){
			actual_led = 0X01;
		}
		HAL_Delay(1000);
	}
}
