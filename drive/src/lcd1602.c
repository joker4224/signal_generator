#include <REGX52.H>
#include<intrins.h>
#include "lcd1602.h"


/*
* 功  能：延时，若干毫秒
* 参  数：毫秒数
* 返回值：无
*/
void DelayMs(unsigned int i)	//一个延时函数，这个函数在11.0592M晶振下的延时时间大概为1ms
{
	unsigned int j,k;

	for(j=i; j>0; j--)
		for(k=114; k>0; k--);
}

/*
* 功  能：延时
* 参  数：延时的数量
* 返回值：无
*/
void delay(uint x)
{
	uint a,b;
	for(a=x;a>0;a--)
		for(b=10;b>0;b--); 
}

/*
* 功  能：1602的检查是否忙
* 参  数：无
* 返回值：无
*/
bit LCD_Check_Busy(void) 
{ 
	DataPort = 0xFF; 
	RS_CLR; 
	RW_SET; 
	EN_CLR; 
	_nop_(); 
	EN_SET;
	
	//return (bit)(DataPort & 0x80);
	return 0;
}

/*
* 功  能：1602的写命令函数
* 参  数：com:命令字
* 返回值：无
*/
void LCD_Write_Com(unsigned char com) 
{  
	while(LCD_Check_Busy()); //忙则等待
	RS_CLR; 
	RW_CLR; 
	EN_SET; 
	DataPort = com; 
	_nop_(); 
	EN_CLR;
}

/*
* 功  能：1602的写数据函数
* 参  数：Data:要写入的数据
* 返回值：无
*/
void LCD_Write_Data(unsigned char Data) 
{ 
	while(LCD_Check_Busy()); //忙则等待
	RS_SET; 
	RW_CLR; 
	EN_SET; 
	DataPort = Data; 
	_nop_();
	EN_CLR;
}

/*
* 功  能：1602 清除显示内容
* 参  数：无
* 返回值：无
*/
void LCD_Clear(void) 
{ 
	LCD_Write_Com(0x01); 
	delay(5);
}

/*
* 功  能：1602 初始化
* 参  数：无
* 返回值：无
*/
void LCD_Init(void) 
{
	EN = 0;
	LCD_Write_Com(0x38);    /*显示模式设置*/ 
	delay(5); 
	LCD_Write_Com(0x0E);    /*显示关闭*/ 
	delay(5); 
	LCD_Write_Com(0x06);    /*显示清屏*/ 
	delay(5); 
	LCD_Write_Com(0x01);    /*显示光标移动设置*/ 
	delay(5); 
	LCD_Write_Com(0x80);
	delay(5);
}
