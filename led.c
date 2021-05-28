#include <led.h>
declare_output_port=0x00;
led_array_ON=0xFF;     // LED ON
led_array_OFF=0x00;	  //  LED OFF
void delay(unsigned inttime_delay_milisecond);
void main()
{
P2=declare_output_port;
while(1)                  // While the loop is 1 it loops
{
P2=led_array_ON;         // led is turned ON
delay(1000);            // enter the delay value in milisecond
P2=led_array_OFF;				// led is turned OFF
delay(1000);
}
}