#include <reg51.h>

void delay(){
	int i;
	for(i=0;i<10;i++){
	TMOD  = 0x01;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TR0 = 1;
  while(TF0 ==0);
	TR0 = 0;
  TF0 = 0;		
}
}

void main()
{
  char samples[] = {0x00,0x4b,0xffffff80,0xfa,0xcb,0x80,0x35,0x6,0x6,0x35,0x80};
	P2 = 0x00;
	while(1)
	{ int i;
    for(i=0;i<10;i++)
			{
          P2 = samples[i];
					delay();	
			}
	}
}