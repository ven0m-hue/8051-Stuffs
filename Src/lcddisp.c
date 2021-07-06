#include <reg51.h>
#define lcd P1;

sbit rs     = P3^6;
sbit re     = P3^7;
sbit buzzer = P3^5;

void cmd(unsigned char a)
{
    lcd = a;
    rs = 0;
//    rw=0;
    re = 1;
    delay(1000);
    re = 0;
}

void dat(unsigned char b)
	{ 
		lcd = b;
		rs = 1;
		re = 1;
    delay(1000);
		re = 0;
		delay(1000);
	}	
void init()
{
  cmd(0x38);
  cmd(0x10);
  cmd(0xc0);
  cmd(0x06);
	cmd(0x01);
}

void string(unsigned *s)
	{
		while(*s)
		{
				dat(s++);	
		}
	}
void delay(char f)
	{ 
		char i;
		TMOD = 0X01;
		for(i=0;i<f;i++)
		{
	  TF0  = 0XFC;
		TL0  = 0X66;
		TR0  = 1;
    while(TF0 ==1);
    TF0 = 0;
    TR0 = 0;
    }			
	}	
///

void main()
{
 P1  = 0x00;
// P3 =  0x00;	
 buzzer = 1;
 init();
 while(1)
	{
	  cmd(0x80);
	  string("Micro-LABlet");
		cmd(0xc0);
		string("E&E,NMAMIT NITTE");	
	}

}	