#include<reg51.h>
#include<string.h>
sbit rs = P3^5;					// rs pin of LCD
sbit en = P3^2;					// en pin of LCD
sbit rw = P3^7;					// rw pin of LCD
sbit b = P1^7;					// busy flag 
sbit led = P3^0;				// led indication
unsigned int flag=0; 			// rpm flag

void delay()					// 1 sec delay
  {
  	int k;
	TL1 = 0xAF;					// load value 15535=3CAF
	TH1 = 0x3C;
	TR1 = 1;
	for(k=0;k<20;k++)
	  {
		while(TF1==0);
		TF1 = 0;
		TL1 = 0xAF;
		TH1 = 0x3C;
	  }
	TR1 = 0;
  }
void busy()	   					// check busy flag
{
	en = 0;
	P1 = 0xFF;
	rs = 0;
	rw = 1;
	while(b==1)
	{
	 en=0;
	 en=1;
	}
	en=0;
}
void writecmd(unsigned char a)	// send command byte to LCD
{
	busy();
	rs = 0;
	rw = 0;
	P1 = a;	
	en = 1;
	delay();
	en = 0;
}
void writedata(unsigned char b)	// send data byte to LCD
{
	busy();
	rs = 1;
	rw = 0;
	P1 = b;	
	en = 1;
	delay();
	en = 0;	
}
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



void int1(void) interrupt 2		// external interrupt 1 function
{
	EA=0;
	// first disable interrupts
	led=0;						    // give indication
	writecmd(0x01);	
	writestr("counting RPM....");   // display message
	TR0=1;						    // start timer 0
	delay();					    // give 1 sec delay
	TR0=0;							// stop timer
	writecmd(0x80);	
	writestr("counting finish ");   // display message
	led=1;
	if(TL0>0xA6)
	  {							    // if value more then 166
	  	writecmd(0xC0);	
		writestr("RPM out of range");// send message
	  }
	else flag=1;  				     // if not then set the flag
 }

 void display()						 // convert hex to desimal and 
  {									 // decimal to ascii
  	unsigned int tmp1,tmp2,t,t1,i,j;
	unsigned char asci[4];	
	tmp1 = (TL0 & 0x0F);  			 // get lower nibble of TL0
	tmp2 = TL0 >> 4; 				 // get upper nibble of TL0
	tmp2 = tmp2*16;					 // multiply upper nibble with 16
	t = tmp1+tmp2;				     // get decimal number
	t=t*60;						     // multiply it with 60
	i=3;
	if(t>=1000)						 // if more then 4 digits
	  {
		while(t>10)
		  {		
			t1=t%10;
			asci[i]=t1+0x30;		 // convert them one by one 
			t=t/10;					 // into ASCII
			i--;
		  }
		asci[0]=t+0x30;
	  }
	else	  						 // otherwise convert
	  {
		while(t>10)
		  {		
			t1=t%10;
			asci[i]=t1+0x30;	    // last three digits
			t=t/10;
			i--;
		  }
		asci[1]=t+0x30;
		asci[0]=0x30;			   // and put first digit as 0
	  }
	writecmd(0xC0);	
    writestr("currentRPM:");	  // display current RPM and
	for(j=0;j<4;j++)
		writedata(asci[j]);		  // all four digits one by one
  }
  void main()
    {
		TMOD=0x15;	  			  // timer 0 in 16 bit counter and timer 1 in 16 bit counter
		P1 = 0x00;				  // P1 as output port
		rs=0;					  // clear all LCD control pins
		en=0;
		rw=0;	
		writecmd(0x3C);			  // initialize LCD
		writecmd(0x0E);
		writecmd(0x82);
		writestr("RPM Counter");  // initially display message
		TH0=0x00;				  // clear T0
		TL0=0x00;
		IE=0x84;				  // enable external interrupt 1
	  while(flag==0);			  // remain withine loop till rpm flag is clear
		display();				  // when flag is set display current RPM value
		while(1);				  // continuous loop
	}	 
