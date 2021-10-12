#include <REGX52.H>
#include<intrins.h>
#include "lcd1602.h"


/*
* ��  �ܣ���ʱ�����ɺ���
* ��  ����������
* ����ֵ����
*/
void DelayMs(unsigned int i)	//һ����ʱ���������������11.0592M�����µ���ʱʱ����Ϊ1ms
{
	unsigned int j,k;

	for(j=i; j>0; j--)
		for(k=114; k>0; k--);
}

/*
* ��  �ܣ���ʱ
* ��  ������ʱ������
* ����ֵ����
*/
void delay(uint x)
{
	uint a,b;
	for(a=x;a>0;a--)
		for(b=10;b>0;b--); 
}

/*
* ��  �ܣ�1602�ļ���Ƿ�æ
* ��  ������
* ����ֵ����
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
* ��  �ܣ�1602��д�����
* ��  ����com:������
* ����ֵ����
*/
void LCD_Write_Com(unsigned char com) 
{  
	while(LCD_Check_Busy()); //æ��ȴ�
	RS_CLR; 
	RW_CLR; 
	EN_SET; 
	DataPort = com; 
	_nop_(); 
	EN_CLR;
}

/*
* ��  �ܣ�1602��д���ݺ���
* ��  ����Data:Ҫд�������
* ����ֵ����
*/
void LCD_Write_Data(unsigned char Data) 
{ 
	while(LCD_Check_Busy()); //æ��ȴ�
	RS_SET; 
	RW_CLR; 
	EN_SET; 
	DataPort = Data; 
	_nop_();
	EN_CLR;
}

/*
* ��  �ܣ�1602 �����ʾ����
* ��  ������
* ����ֵ����
*/
void LCD_Clear(void) 
{ 
	LCD_Write_Com(0x01); 
	delay(5);
}

/*
* ��  �ܣ�1602 ��ʼ��
* ��  ������
* ����ֵ����
*/
void LCD_Init(void) 
{
	EN = 0;
	LCD_Write_Com(0x38);    /*��ʾģʽ����*/ 
	delay(5); 
	LCD_Write_Com(0x0E);    /*��ʾ�ر�*/ 
	delay(5); 
	LCD_Write_Com(0x06);    /*��ʾ����*/ 
	delay(5); 
	LCD_Write_Com(0x01);    /*��ʾ����ƶ�����*/ 
	delay(5); 
	LCD_Write_Com(0x80);
	delay(5);
}
