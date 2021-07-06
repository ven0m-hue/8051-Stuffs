#include<experiment#2.h>
char idata *im = 0x30;
char temp, temp1, a;
main()
{
	a = 0x05;
	*im = a&0x55;
	*im ++;
	a = 0x05;
	*im = a|0x55;
	*im++;
	a = 0x05;
	*im = a^0x55;
	*im++;
	a = 0x05;
	*im =~a;
	*im++;
	a = 0x05;
	*im = a & 0x0f;
	temp = *im;
	*im ++;
	a = 0xa0;
	*im = a&0xF0;
	temp=temp|*im ;
	*im ++;
	*im =temp;
	*im ++;      //exchange
	a = 0xff;
	*im = 0xaa;
	temp1= *im ;
	*im = a;
	a = temp1;
	a = *im ;
}