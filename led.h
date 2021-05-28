sfr P2 = 0xA0;
sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0 = 0x8A;
sfr TL1 = 0x8B;
sfr TH0 = 0x8C;
sfr TH1 = 0x8D;
/* TCON */
sbit TF1 = TCON^7;
sbit TR1 = TCON^6;
sbit TF0 = TCON^5;
sbit TR0 = TCON^4;
// 1 milisecond delay program
timer_lowerbyte=0x61;
timer_higherbyte=0xFC;
timer_enable=1;
timer_disable=0;
timer_reset=0;
timer_count;
void delay(unsigned inttime_delay_milisecond)
{
TMOD=0x10;
//set the timer#1 in mode#1
for (timer_count =0; timer_count<time_delay_milisecond;
timer_count ++)
{
TL1=timer_lowerbyte;
TH1=timer_higherbyte;
TR1=timer_enable;
while(TF1==0); //monitoring the timer flag
for timer overflow
TR1=timer_disable;
TF1=timer_reset;
}
}