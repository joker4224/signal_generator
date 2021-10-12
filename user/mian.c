#include<reg52.h>
#include "lcd1602.h"

int main()
{
	LCD_Init();
	LCD_Clear();
	while(1)
	{
		LCD_Write_Com(0x80);
		delay(5);
		LCD_Write_Data(0x41);
		delay(5);
	}
}
