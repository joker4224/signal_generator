#include <reg52.h>
#include "lcd1602.h"
#include "interrupt.h"
#include "timer.h"
uchar f;
uchar k;
uint phase_counter=0;
int main()
{
	f=100;
	k=f;
	LCD_Init();
	LCD_Clear();
	show_freq(f);
	interrupt_init();
	timer_init();
	
	while(1)
	{

	}
}
