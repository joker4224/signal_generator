#include<reg52.h>
#include "lcd1602.h"

extern unsigned char f;
void interrupt_init()
{
	IT0=1;
	EX0=1;
	EA=1;
	PX0=0;
}

void interrupt1() interrupt 0
{
	f=f+1;
	show_freq(f);
}