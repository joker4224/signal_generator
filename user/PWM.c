//#include <reg51.h>
#include <STC12C5A60S2.h>
#include "lcd1602.h"
#include "interrupt.h"
#include "math.h"
#define u8 unsigned char
#define u16 unsigned   int 
#define u32 unsigned long  int
#define y    211524
sbit key1=P3^2;
sbit key2=P3^3;
u8	addr_s,mn=0,f;
u32	sum=0,step;
u8	es_buf[10];
//u16		sin16;
u8	xdata	sin_buf[3][256];
//u32		sum=0,step=0;
main()						 //m1:m0  00=��׼��   01=���죻   10=���룻   11=��©���
{
	u16		i=0;
	u16		temp=0;
	float		sinv=0;
	float		sinv2=0;
	//m1:m0  00=��׼��   01=���죻   10=���룻   11=��©���
	P0M1 = 0X00;
	P0M0 = 0Xff;
	P2M1 = 0X00;
	P2M0 = 0Xff; //�趨P0,P2�������
	//P3M1 = 0Xff;
	//P3M0 = 0X00;
	P1M1 = 0x01;
	P1M0 = 0x08;

	AUXR=0xc0; //ѡ��1Tָ��ϵͳ
  	//ET0 = 1;  //����ʱ��0�ж�
	AUXR1=AUXR1|0x04;
	P1ASF=0x01;
	//////
	// 9600	 ������
	//TH1=0xfd;
	//TL1=0xfd;
	TH1=0xdc;
	TL1=0xdc;
//  	TMOD = 0X21; //�趨��ʱ��1Ϊ8λ��ʽ,T0Ϊ16λ����    
//	SCON = 0x50;  //8λ�����ʿɱ�
//	PCON = 0X00; //�����ʲ��ӱ�
//   	TR1=1;
//	ES=1;�����ж�
	TH0=0;
	TL0=0;
	ET0=1;//����ʱ��0�ж�
	//��ʼ��PWM
	CCON = 0;
	CL = 0;
	CH = 0;
	CMOD = 0X08; //������ʱ��Ϊϵͳʱ�ӣ��жϲ�ʹ��
	CCAP0H = 0X80;//��ʼ��ռ�ձ�Ϊ50%
	CCAP0L = 0X80;
	CCAPM0 = 0X42;//�趨PWM0���
	CCAP1H = 0X80;//��ʼ��ռ�ձ�Ϊ50%
	CCAP1L = 0X80;
	//CCAPM1 = 0X42;//�趨PWM0���
	CCAPM1 = 0X00;//�趨PWM1�����
	PCA_PWM0 = 0;
	PCA_PWM1 = 0;
	CR = 1;
	//	 ��ʼ������	 ��PWM����ɹ�
	//����һ�����ڵ����Ҳ�����
		for(i=0;i<256;i++)
		{
				sinv=(float)i*3.1415926/128.0;
				sin_buf[0][i]=(u8)((sin(sinv)+1.0)*127);
		}
		for(i=0;i<256;i++)
		{
			sin_buf[1][i]=i>128? 255:0;
		}
		for(i=0;i<256;i++)
		{
			sin_buf[2][i]=255-i;
		}
				for(i=0;i<256;i++)
		{
			sin_buf[3][i]=i>127? i*2:-2*(i-255);
		}


		 //M=4294967296
		//stepf=3354.489*100000;//	n=M/step	t=n*x	f=step/y
		//y=step/f
		//y=229824.8767

		f=10;//��ʼƵ��
		step=f*y;
		//step=0x1000000;
		//step=stepf;
		//step=0x1000000;	//16777216

  	
			IT0=1;
			EX0=1;
			
			IT1=1;
			EX1=1;
			
			PX0=1;
			PX1=1;
		LCD_Init(); //1602 ��ʼ��
		LCD_Clear();
		show_freq(f);
		
		EA = 1;	  //�����ж�
	while(1)
	{	
					sum=sum+step;
					addr_s=sum>>24;
					CCAP0H=sin_buf[0][addr_s];					
		  
	}
}
//void es_isp() interrupt 4	 using		2	 //13λ��ʱ�ж�
//{
//	//u8	temp;
//	if(RI)
//	{
//		RI=0;
//		es_buf[mn]=SBUF;
//		mn++;
//		TH0=0;
//		TR0=1;
//		//SBUF=f;
//		//step=f*y;
//		return;
//	}
//	if(TI)
//		TI=0;	

//}

//void t0_isp() interrupt 1	 using		3	 //16��λʱ�ж�
//{
//   TR0=0;
//   mn=0;
//   step=((u16)es_buf[0]+(u16)es_buf[1]*256)*y;

//}
/*
 void pca_isp() interrupt 7	   //using	1	   //��ʱ��ʼ�ж�
{
	//CF = 0;
	//CCAP0H=mn;
	//CCAP0H++;
}
  
void int0_isp() interrupt 0	   using	1	   //��ʱ��ʼ�ж�
{
}
void int1_isp() interrupt 2		using		3		//��ʱ�����ж�
{
}

 void t1_isp() interrupt 3	   //using	1	   //��ʱ��ʼ�ж�
{

}
*/
void interrupt0() interrupt 0
{
	DelayMs(100);
	if(key1==0)
	{
		f=f+1;
	if(f>100) f=1;
	step=f*y;
	show_freq(f);
	}
}

void interrupt1() interrupt 2
{
	DelayMs(100);
	if(key2==0)
	{
		f=f+10;
		if(f>100) f=10;
		step=f*y;
		show_freq(f);
	}
}