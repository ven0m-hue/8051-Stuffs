
int timer_count;
void delay(unsigned int time_delay_milisecond)
{
TMOD=0x10; //set the timer#1 in mode#1
for (timer_count =0; timer_count<time_delay_milisecond; timer_count ++)
{
TL1=0x61;
TH1=0xFC;
TR1=1;
while(TF1==0); //monitoring the timer flag for timer
TR1=0;
TF1=0;
}
}