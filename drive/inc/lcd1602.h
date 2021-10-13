#ifndef LCD1602_H
#define LCD1602_H

#define uchar unsigned char
#define uint unsigned int

#define RS_CLR RS = 0 
#define RS_SET RS = 1

#define RW_CLR RW = 0 
#define RW_SET RW = 1 

#define EN_CLR EN = 0
#define EN_SET EN = 1

#define DataPort P0

sbit RS = P2^4;   //定义端口 
sbit RW = P2^5;
sbit EN = P2^6;

void DelayMs(unsigned int i);	//一个延时函数，这个函数在11.0592M晶振下的延时时间大概为1ms
void delay(uint x);//延时
bit LCD_Check_Busy(void); //1602的检查是否忙
void LCD_Write_Com(unsigned char com); //1602的写命令函数
void LCD_Write_Data(unsigned char Data); //1602的写数据函数
void LCD_Clear(void); //1602 清除显示内容
void LCD_Init(void); //1602 初始化
void show_freq(uchar freq);//显示频率

#endif
