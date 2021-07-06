char a;
sbit Row0 = P2^7;
sbit Row1 = P2^6;
sbit Row2 = P2^5;
sbit Row3 = P2^4;
sbit Column0 = P2^3;
sbit Column1 = P2^2;
sbit Column2 = P2^1;
sbit Column3 = P2^0;
charreadkey()
{
Column0=1;
Column1=1;
Column2=1;
Column3=1;
Row0=0;
Row1=1;
Row2=1;
Row3=1;

if(Column0==0)
	{
	a=0;
	return a;
	}
if(Column1==0)
	{a=1;
	return a;
	}
if(Column2==0)
	{
	a=2;
	return a;
	}
if(Column3==0)
	{
	a=3;
	return a;
	}
	
Row0=1;
Row1=0;
Row2=1;
Row3=1;
if(Column0==0)
	{
	a=4;
	return a;
	}
if(Column1==0)
	{
	a=5;
	return a;
	}
if(Column2==0)
	{
	a=6;
	return a;
	}
if(Column3==0)
	{
	a=7;
	return a;
	}
	
Row0=1;
Row1=1;
Row2=0;
Row3=1;
if(Column0==0)
	{
	a=8;
	return a;
	}
if(Column1==0)
	{
	a=9;
	return a;
	}
if(Column2==0)
	{
	a=0x0a;
	return a;
	}
if(Column3==0)
	{
	a=0x0b;
	return a;
	}
	
Row0=1;
Row1=1;
Row2=1;
Row3=0;

if(Column0==0)
	{
	a=0x0c;
	return a;
	}
if(Column1==0)
	{
	a=0x0d;
	return a;}
if(Column2==0)
	{
	a=0x0e;
	return a;
	}
if(Column3==0)
	{
	a=0x0f;
	return a;
	}
}