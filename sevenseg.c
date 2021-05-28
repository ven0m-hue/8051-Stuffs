#include <sevensegment.h>
declare_output_port=0x00;  // to declare output port 
sbit buzzer_control = P3^5;
sbit disp1_enable= P3^6 ;
sbit disp2_enable=P3^7 ;
sbit disp1_disable= P3^6 ;
sbit disp2_disable=P3^7 ;
void delay(unsigned int time_delay_milisecond) ;  // function to create a delay of miliscecond,  
char i,j,b,c;
void main()
{
unsigned char hexcode_digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,
0x7D, 0x07,0x7F, 0x6F } ;
//Hex code to display 0- 9 digit
P1=declare_output_port; // P1 declared as output port 
buzzer_control = 0; //to turn off buzzer
while(1)
{
for (i=0;i<=9;i++)
{
b=i/2;                          // MSB 
c=i%10;                         // LSB            
for(j=0;j<=50;j++)
{
disp1_enable=1;
disp2_disable=0;
P1= hexcode_digit [b];   // MSB
delay(1000);    // delay of 1 second 
disp1_disable=0;
disp2_enable=1;
P1= hexcode_digit [c];   //LSB
delay(10);        // delay of 10 mili 
}
}
}
}