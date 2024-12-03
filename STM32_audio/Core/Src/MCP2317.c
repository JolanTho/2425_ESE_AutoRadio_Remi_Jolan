#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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
uint8_t led_state = 0xFF;
volatile int spi_tx_complete = 0;


void MCP17023_write_register(uint8_t addr, uint8_t value){

		Spitxbuffer[0] = MCP23S17_WRITE_OPCODE;
		Spitxbuffer[1] = addr;
		Spitxbuffer[2] = value;

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

		HAL_SPI_Transmit(&hspi3, Spitxbuffer, 3, HAL_MAX_DELAY);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);

}

void MCP17023_init(void){

	MCP17023_write_register(GPIOA_REG, 0xFF);
	MCP17023_write_register(GPIOB_REG, 0xFF);
	MCP17023_write_register(IODIRA_REG, 0x00);
	MCP17023_write_register(IODIRB_REG, 0x00);

}

void MCP17023_set_led (uint8_t addrled){

	MCP17023_write_register(GPIOA_REG, addrled);
	MCP17023_write_register(GPIOB_REG, addrled);

}

void MCP17023_chenillard(char **argv){

	uint8_t actual_led = 0xFF;

	for(;;){

		if (actual_led == 0x00){
			actual_led = 0XFF;
		}

		actual_led <<= 1;
		MCP17023_set_led(actual_led);

		HAL_Delay(500);
	}
}

void MCP17023_led(char **argv){

	int nbrLed = atoi(argv[1]);
	int setReset = atoi(argv[2]);

	printf("Numero de led %d, set %d \r\n", nbrLed, setReset);

	if(nbrLed < 0 || nbrLed >= 8){
		printf("Le nombre de led est pas valide \r\n");
		return;
	}

	if(setReset < 0 || setReset > 1){
		printf("Veuillez saisir un deuxième argument correct \r\n");
		return;
	}

    if (setReset == 1) {
        // Action: SET (éteindre la LED correspondante en mettant le bit à 1)
        led_state &= ~(1 << nbrLed);
    } else {
        // Action: RESET (allumer la LED correspondante en mettant le bit à 0)
        led_state |= (1 << nbrLed);
    }


    MCP17023_set_led(led_state);

    return;

}
