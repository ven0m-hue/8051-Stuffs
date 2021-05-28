#include<reg51.h>
sbit Pwm_Pin=P1^0;
sbit Pwm_B_00=P2^0;
sbit Pwm_B_20=P2^1;
sbit Pwm_B_40=P2^2; 
sbit Pwm_B_50=P2^3;
sbit Pwm_B_60=P2^4;
sbit Pwm_B_80=P2^5;
sbit Pwm_B_500=P2^6;
sbit Pwm_B_800=P2^7;
sbit Pwm_B_1000=P0^7;
void Pwm_Low()
{
Pwm_Pin=0;
TH0=0xFF;
TL0=0x47;
TR0=1;       //Run Timer-0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0;       //Clear Interrupt Flag
TR0=0;       //Stop Timer-0
}


void Pwm_High()
{
TR0=1;       //Run Timer-0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0;       //Clear Interrupt Flag
TR0=0;       //Stop Timer-0

Pwm_Low();
}

void main()
{
P0=0xFF;  //**** Port-0 Declared Input
P1=0x00;  //**** Port-1 Declared Output
P2=0xFF;  //**** Port-2 Declared Input 
P3=0x00;  //**** Port-3 Declared Output
P0=0xFF;  //**** Port-0 Declared Input

TMOD=0x01; //Timer-0, As 16-bit Timer.

while(1){

if(Pwm_B_00==0){
Pwm_Pin=1;
TH0=0x00;
TL0=0x00; Pwm_High();}

else if(Pwm_B_20==0){
Pwm_Pin=1;
TH0=0xFF;
TL0=0x47; Pwm_High();}

else if(Pwm_B_40==0){
Pwm_Pin=1;
TH0=0xFF;
TL0=0xB5; Pwm_High();}

else if(Pwm_B_50==0){
Pwm_Pin=1;
TH0=0xFF;
TL0=0x47; Pwm_High();}

else if(Pwm_B_60==0){
Pwm_Pin=1;
TH0=0xFE;
TL0=0xD8; Pwm_High();}

else if(Pwm_B_80==0){
Pwm_Pin=1;
TH0=0xFE;
TL0=0xB3; Pwm_High();}

else if(Pwm_B_500==0){
Pwm_Pin=1;
TH0=0xFC;
TL0=0x65; Pwm_High();}

else if(Pwm_B_800==0){
Pwm_Pin=1;
TH0=0xFA;
TL0=0x3C; Pwm_High();}

else if(Pwm_B_1000==0){
Pwm_Pin=1;
TH0=0xFF;
TL0=0xFF; Pwm_High();}
else
{}

}
}
