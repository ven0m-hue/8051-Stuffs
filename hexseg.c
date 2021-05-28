#include <reg51.h>
#include <readkey.h>
#include <display.h>
sbit buzzer_ctrl = P3^5;
char b;
char readkey();
void display();
void main()
{
			P1 = 0x00;
			P2 = 0xff;
			buzzer_ctrl = 1;
			while(1)
			{
				b = readkey();
				c = readkey();
				display();
			
			}

}