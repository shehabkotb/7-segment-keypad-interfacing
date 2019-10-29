#include "tm4c123gh6pm.h"
#include "Port_INIT.h"
#include "Fsm.h"
#include "Systick_Timer.h"

StateType Fsm[16] = { 

  {0x3f,  {0, 15, 1,   0} }, //{output, {sw1&sw2 pressed, sw1, sw2, non pressed} }
  {0x06,  {0, 0,  2,   1} },   
  {0x5b,  {0, 1,  3,   2} },  
  {0x4f,  {0, 2,  4,   3} },  
  {0x66,  {0, 3,  5,   4} },  
  {0x6d,  {0, 4,  6,   5} },  
  {0x7d,  {0, 5,  7,   6} },  
  {0x07,  {0, 6,  8,   7} },  
  {0x7f,  {0, 7,  9,   8} },  
  {0x67,  {0, 8,  10,  9} },
  {0x77,  {0, 9,  11,  10} },
  {0x7c,  {0, 10, 12,  11} },
  {0x39,  {0, 11, 13,  12} }, 
  {0x5e,  {0, 12, 14,  13} },
  {0x79,  {0, 13, 15,  14} },
  {0x71,  {0, 14, 0,   15} }

};

const unsigned char keymap[4][4] = {

{ 0x06, 0x5b, 0x4f, 0x77},

{ 0x66, 0x6d, 0x7d, 0x7c},

{ 0x07, 0x7f, 0x67, 0x39},

{ 0x79, 0x3f, 0x71, 0x5e},

};


void execute(unsigned int keys);



int main() {
	PORTB_init(); // seven segment PB0-7
	PORTF_init();
	PORTA_init(); // columns input PA2-5
	PORTE_init(); // rows output PE0-3
	Configure_SysTick();
	
	unsigned long input;
	unsigned int cState = 0;
	GPIO_PORTB_DATA_R |= ~0x3f;
		
	while(1) {
		
		GPIO_PORTE_DATA_R &= ~(0x0f); //ground all rows
		unsigned int keys = (GPIO_PORTA_DATA_R & 0x3c); // PA2-5 -> 0x3c	
		execute(keys);

		
			
	}
}

void execute(unsigned int keys){
	
	if( !(keys == 0x3c) ){
		for(int i=0;i < 4; i++) {
			GPIO_PORTE_DATA_R |= 0x0f; 						// pull rows high
			GPIO_PORTE_DATA_R &= ~(1U << i); 				//ground a single row
			keys = (GPIO_PORTA_DATA_R & 0x3c);
			if( !(keys == 0x3c) ){						   // if button is in this row			
				for(int j = 0;j < 4;j++) {				   // loop on columns
					keys = GPIO_PORTA_DATA_R & (1U << (2 + j)); //(2 + j) cause we start from PA2
					if(!keys) {
						GPIO_PORTB_DATA_R = ~keymap[i][j];
						return;
					}
				}
			}		
		}
	}
}


	


