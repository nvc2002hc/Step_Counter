
#include "button.h"

void init_button() {
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA->CRH &= ~(GPIO_CRH_MODE12);
	GPIOA->CRH &= ~(GPIO_CRH_MODE12);
	GPIOA->CRH |= 2<<18;
	GPIOA->ODR |= GPIO_ODR_ODR12;

	GPIOA->CRH &= ~(GPIO_CRH_MODE13);
	GPIOA->CRH &= ~(GPIO_CRH_CNF13);
	GPIOA->CRH |= 2<<22;
	GPIOA->ODR |= GPIO_ODR_ODR13;
}

uint16_t check(uint16_t GPIO_Pin) {
	uint8_t status = 0x00;
	if ((GPIOA->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET) {
		status = (uint16_t) GPIO_PIN_SET;
	} else  {
		status = (uint16_t) GPIO_PIN_RESET;
	}
	return status;
}
