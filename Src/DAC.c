// Digital to Analog Converter
#include <reg51.h>
void delay()
{
  TMOD = 0x10;
	TH1 = 0XFC;
	TL1 = 0XFB;
  TR1 = 1;
	while(TF1 ==0);
	TF1 = 0;
	TR1 = 0;

}
void main()
{
  P2 = 0x00;
	while(1)
	{
	  P2 = 0xFF;
		
		delay();
		
		P2 = 0x7F;
		
		delay();
	
	}
}
