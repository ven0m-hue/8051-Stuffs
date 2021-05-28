#include<reg51.h>
#define lcd P1
 
 
sbit rs=P3^6; //register select
sbit en=P3^7; //enable
sbit buzzer = P3^5;  // buzzer pin
void lcd_init();    // initialization function
void cmd(unsigned char);  //command function 
void dat(unsigned char);  // data function  
void delay();   //delay function 
void lcd_string(char *s);  //string function 
void displays(char result);
void main()
{   
	
		buzzer = 1;   //buzzer turned off
    lcd_init();   //initialize the lcd screen by giving lcd commands
	  cmd(0x80);    //start from the new line
    
	  delay();     //200 ms delay
    while(1){
           lcd_string(" start");
           delay();			
			     cmd(0x01);  //command to clear the line
			     
			     delay();
			     //cmd(0x01);
    }
}
 
void lcd_init()
{
    cmd(0x38);    //
    cmd(0x0e);    //
    cmd(0x06);    // 
    cmd(0x01);    // 
    cmd(0x80);    // 
}
 
void cmd(unsigned char a)
{
    lcd=a;             // command value in hex goes to lcd port 
    rs=0;              // made zero to give commands 
    en=1;              // enable the lcd ports
    delay();
    en=0;
}
 
void dat(unsigned char b)
{
    lcd=b;         // data is given to the lcd ports
    rs=1;          // is enabled when data needs to be displayed
    en=1;
    delay();
    en=0;
}
 
void lcd_string(char *s)  // function to write the string 
{
    while(*s) {
       dat(*s++);
     }
}
 
void delay()   //delay function of 200ms 
{
    unsigned int i;
    for(i=0;i<20000;i++);
}
//
/*void lcd_data(unsigned int i)     //Function to send data on LCD
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
}*/
void displays(char result)
{
  
 

}