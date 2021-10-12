#include<reg52.h>
#include "lcd1602.h"
uchar f = 123;
int main()
{
	LCD_Init();
	LCD_Clear();
	while(1)
	{
		delay(5);
		LCD_Write_Com(0x80+4);
		delay(5);
		LCD_Write_Data( f / 100 + 0x30 );
		delay(5);
		LCD_Write_Data( f / 10 % 10 + 0x30 );
		delay(5);
		LCD_Write_Data( f % 10 + 0x30 );
		delay(5);
		LCD_Write_Data('H');
		delay(5);
		LCD_Write_Data('z');
		delay(5);
	}
}
