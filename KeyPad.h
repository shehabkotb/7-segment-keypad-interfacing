#ifndef __KEYPAD__
#define __KEYPAD__

#include <stdbool.h>

extern const unsigned char keymap[4][4];

bool AnyPressed(unsigned int keys);
void detectRow(unsigned int keys);
void detectColumn(unsigned int keys,int row);
unsigned int charTo7Seg(unsigned char character);

#endif