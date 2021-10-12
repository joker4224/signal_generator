#include <reg52.h>
#include "lcd1602.h"
#include "interrupt.h"
uchar f = 9;
int main()
{
	interrupt_init();
	LCD_Init();
	LCD_Clear();
	show_freq(f);
	while(1)
	{
	}
}
