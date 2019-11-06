#include "tm4c123gh6pm.h"
#include "Port_INIT.h"
#include "Systick_Timer.h"
#include "KeyPad.h"

int main() {
	PORTB_init(); // seven segment PB0-7
	PORTA_init(); // columns input PA2-5
	PORTE_init(); // rows output PE0-3
	
	GPIO_PORTB_DATA_R |= ~0x3f; // display zero at the beggning
		
	while(1) {
		
		GPIO_PORTE_DATA_R &= ~(0x0f); //ground all rows
		unsigned int keys = (GPIO_PORTA_DATA_R & 0x3c); // PA2-5 -> 0x3c	
		if(AnyPressed(keys)){
			detectRow(keys);
		}	
	}
}

	


	


