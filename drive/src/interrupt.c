#include<reg52.h>
#include "lcd1602.h"

extern unsigned char f;
extern unsigned char k;
void interrupt_init()
{
	IT0=1;
	EX0=1;
	EA=1;
	PX0=1;
}

void interrupt1() interrupt 0
{
	f=f+1;
	k=f;
	show_freq(f);
}