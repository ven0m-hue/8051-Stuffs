#include<reg51.h>
#include<string.h>

sbit rs = ;					// rs pin of LCD
sbit en = ;					// en pin of LCD
///sbit rw = ;					// rw pin of LCD
sbit b = ;					// busy flag 
///sbit led = ;				// led indication
//port for ir sensor 
sbit IR = ;
unsigned char counter; 

//unsigned int flag=0; 			// rpm flag

void msdelay(unsigned int t)					// 1 sec delay
  {
  unsigned int i,j;
		for (i=0;i<t;i++)
		for (j=0;j<1275;j++)
  }
void delay()
{
	unsigned int i,j;
	for (i=0;i<1000;i++);
}

//set up lcd
void writecmd(unsigned char a)	// send command byte to LCD
{
	P1 = a;
	rs = 0;
	//rw = 	
	en = 1;
	msdelay(1);
	en = 0;
}
void writedata(unsigned char b)	// send data byte to LCD
{
	rs = 1;
	//rw = 0;
	P1 = b;	
	en = 1;
	msdelay(1);
	en = 0;	
}

////////////////////////////////
//function wrtie on lcd 
void writestr(unsigned char *s)	// write string / message to LCD
{
	unsigned char l,i;
	l = strlen(s);
	for(i=0;i<l;i++)
	{
		writedata(*s);
		s++;		
	}
}

////////////////////////////////
// fishy 
// interrupt part 
void ISR_ex0(void) interrupt 0     
{
	counter = 0;
	delay();
	counter ++;
}


  void main()
    {
			// setup 
		  IE=0x81;                // Enable INT0
      IT0=1;                 // Set Falling Edge Trigger for INT0
			
			while(1)
			{
			rpm = counter * 60;
			counter = 0;	
	
	}	 
}