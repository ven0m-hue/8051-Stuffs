#include <reg51.h>

void ext_int() interrupt 0
{
   P2 = ~ P2;
}

void main()
{
    EA = 1;
	  EX0 = 1;
	  IT1 = 0;
	  P2 = 0xff;
	  while(1);
}