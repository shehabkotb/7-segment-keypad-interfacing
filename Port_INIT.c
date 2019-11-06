#include "tm4c123gh6pm.h"
#include "Port_INIT.h"

void PORTB_init (){
	
	// 7seg PB0-7
	unsigned int delay;
	SYSCTL_RCGC2_R |= (1U << 1);
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTB_LOCK_R = 0x4c4f434b;
	GPIO_PORTB_CR_R = 0xff;
	GPIO_PORTB_DIR_R |= 0xff;
	GPIO_PORTB_DEN_R |= 0xff;
	
}

void PORTA_init (){

	// rows inputs PUR
	// 0-4 colums pa2-pa5
	unsigned int delay;
	SYSCTL_RCGC2_R |= (1U << 0);
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTA_LOCK_R = 0x4c4f434b;
	GPIO_PORTA_CR_R = 0x1f;
	GPIO_PORTA_PUR_R |= 0x3c;
	GPIO_PORTA_DIR_R &= ~0x3c;
	GPIO_PORTA_DEN_R |= 0x3c;
	
}


void PORTE_init (){
	
	//rows output ODR
	//rows pd0-pd3	
	unsigned int delay;
	SYSCTL_RCGC2_R |= (1U << 4);
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTE_LOCK_R = 0x4c4f434b;
	GPIO_PORTE_CR_R = 0x1f;
	GPIO_PORTE_PCTL_R &= ~0x000000FF;
	GPIO_PORTE_DIR_R |= 0x0f;
	GPIO_PORTE_ODR_R |= 0x0f;  //Open drain pins 0 to 3
	GPIO_PORTE_DEN_R |= 0x0f;
	
}


