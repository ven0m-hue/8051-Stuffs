// Task 7 LCD display using seven segment

#include <reg51.h>
#define lcd P1
#include <readkey.h> 
sbit rs=P3^6; //register select
sbit en=P3^7; //enable
sbit buzzer = P3^5;
void lcd_init();
void cmd(unsigned char);
void dat(unsigned char);
void lcd_string(char *s);
void lcd_data(unsigned char x); 
int timer_count;// global variable 
void delay(unsigned int time_delay_milisecond)
{
TMOD=0x10; //set the timer#1 in mode#1
for (timer_count =0; timer_count<time_delay_milisecond; timer_count ++){
	TL1=0x61;  //this function generates 1ms delay
	TH1=0xFC;
	TR1=1;
	while(TF1==0); //monitoring the timer flag for timer
	TR1=0;
	TF1=0;}
}
void main()
{   
	  char x = 0, b[3],m=0,l=0,i=0,t1=0,t2=0;
		buzzer = 1;  //buzzer turned off
    lcd_init();  //initialization 
    lcd_string("  Starting..  ");   
	  delay(200);
    while(1){
						cmd(0x01);
			     for(i = 0; i<2; i++)
			{
				b[i] = readkey();    // value from the keypad 
				delay(200);        // to overcome the switch debounce 
			}
				t1 = b[0];    // temp variable for first digit 
			  t2 = b[1];    //temp for second 
			  x = b[0] + b[1];      // result of two no.
			     lcd_data(t1);      // display firt digit 
			     delay(200);
			     lcd_string("+");    // operator 
			     delay(200);
			     lcd_data(t2);      //second digit
			     delay(200);
			     lcd_string("=");    // equals to
			     delay(200);
			     lcd_data(x);        // summation 
					 delay(20000);
    }
}
 
void lcd_init()
{
    cmd(0x38);           //  use 2 lines 
    cmd(0x0e);           // display on
    cmd(0x06);           // increment cursor
    cmd(0x01);           // command to clear the lcd screen
    cmd(0x80);           // command to goto new line
}
 
void cmd(unsigned char a)
{
    lcd=a;
    rs=0;                         // command value in hex goes to lcd port 
		en=1;                          	// made zero to give command															// enable the lcd ports  
	  delay(200);                      
    en=0;														
    
}
 
void dat(unsigned char b)
{
    lcd=b;
    rs=1;        // enabled to input the data 
    //rw=0;
    en=1;
    delay(200);
    en=0;
}
 
void lcd_string(char *s)
{
    while(*s) {
       dat(*s++);       //string function to input alphabets 
     }
}
 
//
void lcd_data(unsigned char x)     //Function to send numeric data on LCD
{
  // acii values from 0 to f
  unsigned char hex_code[] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x61, 0x62, 0x63, 0x64, 0x64, 0x65, 0x66};
	dat(hex_code[x]);                        
  delay(10);   
}