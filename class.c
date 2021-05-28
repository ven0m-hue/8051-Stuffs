// add 2 24 bit no.
#include <reg.51.h>
void main()
{
	double idata *im1 = 0x20, *im2 = 0x21, *im3 = 0x22, a,b,c;
	a = *im1;
	b = *im2;
	
	c = a+b;
	
	*im3 = c;

}