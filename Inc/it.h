#include<reg51.h>
#include<stdio.h>
#define lcd P1
 
sbit IR=P3^2;
 
sbit rs=P3^6; //register select
sbit rw=P2^1; //RW
sbit en=P3^7; //enable
sbit buzzer = P3^5;
unsigned int count; 
void lcd_init();
void cmd(unsigned char);
void dat(unsigned char);
void delay();
void lcd_string(char *s);
void lcd_data(unsigned int i);
unsigned int rpm;// global variable 
unsigned char c;
int num[10];
/// interrupt 
void ISR_ex0(void) interrupt 0     
{ 
  	
	count ++;
	delay();
}

void main()
{   
	
		buzzer = 1;
    lcd_init();
	  IT0 = 0;
	  EX0 = 1;
	  EA  = 1;
	  IE = 0x01;
    lcd_string("  Starting..  ");
    while(1){
           //lcd_string("  RPM Reading...  ");
			     //cmd(0x01);
			     //delay();
			     unsigned int time =0;
					 time = count; 
			     cmd(0xc0);
			     lcd_string("Please Wait....");
					 rpm = time*30;
			     count = 0;
			     delay();
			     cmd(0x01);
					 lcd_string("RPM =");
			     delay();
					 lcd_data (rpm);
           delay();      
    }
}
 
void lcd_init()
{
    cmd(0x38);
    cmd(0x0e);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}
 
void cmd(unsigned char a)
{
    lcd=a;
    rs=0;
    rw=0;
    en=1;
    delay();
    en=0;
}
 
void dat(unsigned char b)
{
    lcd=b;
    rs=1;
    rw=0;
    en=1;
    delay();
    en=0;
}
 
void lcd_string(char *s)
{
    while(*s) {
       dat(*s++);
     }
}
 
void delay()
{
    unsigned int i;
    for(i=0;i<2000;i++);
}
//
void lcd_data(unsigned int i)     //Function to send data on LCD
{   int p;
int k=0;
while(i>0)
{
  num[k]=i%10;
  i=i/10;
  k++;
}
k--;
for (p=k;p>=0;p--)
{
  c=num[p]+48;
  lcd = c;
  rw = 0;
  rs = 1;
  en = 1;
  delay();
  en = 0;
}
return;
}