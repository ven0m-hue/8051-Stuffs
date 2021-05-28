#include <reg51.h>
#define  lcd P1

sbit rs     = P3^6;
sbit re     = P3^7;
sbit buzzer = P3^5;

void init();
void cmd(unsigned char);
void dat(unsigned char);
void delay(unsigned char);
void string( char *s);
///

void main()
{
 buzzer = 1;
 init();
	string("Starting...");
 while(1)
	{
	  cmd(0x80);
	  string("Micro-LABlet");
		cmd(0xc0);
		string("E&E,NMAMIT NITTE");	
	}

}	

void cmd(unsigned char a)
{   
    lcd = a;
    rs = 0;
    re = 1;
    delay(10);
    re = 0;
}
void init()
{
  cmd(0x38);
    cmd(0x0e);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}
void dat(unsigned char b)
	{ 
		lcd = b;
		rs = 1;
		re = 1;
    delay(10);
		re = 0;
	}	

void string(char *s)
	{
		while(*s)
		{
				dat(*s++);	
		}
	}
void delay(unsigned char f)
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