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

sbit RS = P2^4;   //����˿� 
sbit RW = P2^5;
sbit EN = P2^6;

void DelayMs(unsigned int i);	//һ����ʱ���������������11.0592M�����µ���ʱʱ����Ϊ1ms
void delay(uint x);//��ʱ
bit LCD_Check_Busy(void); //1602�ļ���Ƿ�æ
void LCD_Write_Com(unsigned char com); //1602��д�����
void LCD_Write_Data(unsigned char Data); //1602��д���ݺ���
void LCD_Clear(void); //1602 �����ʾ����
void LCD_Init(void); //1602 ��ʼ��
void show_freq(uchar freq);//��ʾƵ��

#endif
