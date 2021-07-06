//#include <reg51.h>
char a;
sbit ROW_0 = P2^7;
sbit ROW_1 = P2^6;
sbit ROW_2 = P2^5;
sbit ROW_3 = P2^4;
sbit COL_0 = P2^3;
sbit COL_1 = P2^2;
sbit COL_2 = P2^1;
sbit COL_3 = P2^0;

char readkey()
{
	while(1){
	COL_0 = 1;
	COL_1 = 1;
	COL_2 = 1;
	COL_3 = 1;
	ROW_0 = 0;
	ROW_1 = 1;
	ROW_2 = 1;
	ROW_3 = 1;
	
	if (COL_0 == 0)
	{
			a = 0;
		  return a;
	}
	if (COL_1 == 0)
	{
			a = 1;
		  return a;
	}
	if (COL_2 == 0)
	{
			a = 2;
		  return a;
	}
	if (COL_3 == 0)
	{
			a = 3;
		  return a;
	}
	ROW_0 = 1;
	ROW_1 = 0;
	ROW_2 = 1;
	ROW_3 = 1;
	
	if (COL_0 == 0)
	{
			a = 4;
		  return a;
	}
	if (COL_1 == 0)
	{
			a = 5;
		  return a;
	}
	if (COL_2 == 0)
	{
			a = 6;
		  return a;
	}
	if (COL_3 == 0)
	{
			a = 7;
		  return a;
	}
	ROW_0 = 1;
	ROW_1 = 1;
	ROW_2 = 0;
	ROW_3 = 1;
	
	if (COL_0 == 0)
	{
			a = 8;
		  return a;
	}
	if (COL_1 == 0)
	{
			a = 9;
		  return a;
	}
	if (COL_2 == 0)
	{
			a = 0x0a;
		  return a;
	}
	if (COL_3 == 0)
	{
			a = 0x0b;
		  return a;
	}
	ROW_0 = 1;
	ROW_1 = 1;
	ROW_2 = 1;
	ROW_3 = 0;
	
	if (COL_0 == 0)
	{
			a = 0x0c;
		  return a;
	}
	if (COL_1 == 0)
	{
			a = 0x0d;
		  return a;
	}
	if (COL_2 == 0)
	{
			a = 0x0e;
		  return a;
	}
	if (COL_3 == 0)
	{
			a = 0x0f;
		  return a;
	}	
	
}}