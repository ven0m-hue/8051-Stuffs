//#include <reg51.h>
char b;
sbit ROW_01 = P2^7;
sbit ROW_11= P2^6;
sbit ROW_21 = P2^5;
sbit ROW_31 = P2^4;
sbit COL_01 = P2^3;
sbit COL_11 = P2^2;
sbit COL_21 = P2^1;
sbit COL_31 = P2^0;

char readkey1()
{
	COL_01 = 1;
	COL_11 = 1;
	COL_21 = 1;
	COL_31 = 1;
	ROW_01 = 0;
	ROW_11 = 1;
	ROW_21 = 1;
	ROW_31 = 1;
	
	if (COL_01 == 0)
	{
			b = 0;
		  return b;
	}
	if (COL_11 == 0)
	{
			b = 1;
		  return b;
	}
	if (COL_21 == 0)
	{
			b = 2;
		  return b;
	}
	if (COL_31 == 0)
	{
			b = 3;
		  return b;
	}
	ROW_01 = 1;
	ROW_11 = 0;
	ROW_21 = 1;
	ROW_31 = 1;
	
	if (COL_01 == 0)
	{
			b = 4;
		  return b;
	}
	if (COL_11 == 0)
	{
			b = 5;
		  return b;
	}
	if (COL_21 == 0)
	{
			b = 6;
		  return b;
	}
	if (COL_31 == 0)
	{
			b = 7;
		  return b;
	}
	ROW_01 = 1;
	ROW_11 = 1;
	ROW_21 = 0;
	ROW_31= 1;
	
	if (COL_01 == 0)
	{
			b = 8;
		  return b;
	}
	if (COL_11 == 0)
	{
			b = 9;
		  return b;
	}
	if (COL_21 == 0)
	{
			b = 0x0a;
		  return b;
	}
	if (COL_31 == 0)
	{
			b = 0x0a;
		  return b;
	}
	ROW_01 = 1;
	ROW_11 = 1;
	ROW_21 = 1;
	ROW_31 = 0;
	
	if (COL_01 == 0)
	{
			b = 0x0c;
		  return b;
	}
	if (COL_11 == 0)
	{
			b = 0x0d;
		  return b;
	}
	if (COL_21 == 0)
	{
			b = 0x0e;
		  return b;
	}
	if (COL_31 == 0)
	{
			b = 0x0f;
		  return b;
	}	
	return b;
}