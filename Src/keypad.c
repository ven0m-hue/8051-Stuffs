#include <reg51.h>        ////////////////// Seven segment Hexkeypad task 
#include <readkey.h>      /////////////////// Task to find the difference of two numbers
#include <display.h>
sbit buzzer_control = P3^5;
int timer_count;
char readkey();
void display(char n1, char n2);
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
	while(1){
	char result = 0, b[3],m=0,l=0,i=0;
P1= 0x00;
P2= 0xFF;
buzzer_control = 1;   //buzzer turned off 

for(i=0;i<2;i++)	
	{
	 b[i] = readkey();  // the key pressed in keypad will be stored in the array of b
	 delay(200);   // to overcome the switch debounce of the keypad
	}
	 
	result = b[0] - b[1];  //difference of 2 no.s
  m = result/10;    //masking msb
	l = result%10;    // masking lsb
  display(m,l);	    // display the msb and lsb in two segments 
}}
