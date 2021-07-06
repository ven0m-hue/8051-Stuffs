#include <reg51.h>

sbit PWM_pin  =  P1^0; //cn6
sbit PWM_00   =  P2^0; 
sbit PWM_20   =  P2^1;
sbit PWM_50   =  P2^2;
sbit PWM_80   =  P2^3;
sbit PWM_100  =  P2^4;
sbit PWM_Full =  P2^5;

void PWM_low()      // initalization of pwm low 
{										// pwm low is set to 250us delay. (user defined)
	PWM_pin = 0;
	TH0     = 0xFF;    //
	TL0     = 0x13;    // 
	TR0     =1;
	while(!TF0);
	
		TF0 = 0;
		TR0 = 0;
	
}

void PWM_high()  // just the initialization of pwm high 
{								// duty cycle to be defined later (by calculating for the high time delay) 
	TR0 = 1;         
	while(!TF0);
	
		TF0 = 0;
		TR0 = 0;
	
PWM_low();
	
}
/*
	Calculations: 1.time frequncy: f of oscillator/ 12 = 11.0592x10^6/12 = 921600
								2.time required to excecute on instrcution = 1/time frequency = 1/921600 = 1.085x10^-6
								3.Delay/time req per inst = 20^10-3/1.085x10^-6 = 18434
								4. 65535(16bit) - 18434 = 47101 >> convert to hex >> B7FD 
								5. TH0 = B7  TL0 = FD 
	The above instructions generate required high time delay.
*/	

	
void main()
{
		
	  P1=0x00;  // Port-1 Declared Output
    P2=0xFF;  // Port-2 Declared Input 
			
	TMOD = 0x01;     // 16-bit timmer mode 1

			// main portion of the prgram, here we set user defined high delays 
			while(1)
			{ 
				if(PWM_00 == 0)      // zero because it is grounded 
				{                       
					PWM_pin = 1;
					TH0     = 0xFF;
					TL0     = 0xFF;
					PWM_high();
				}
			  else if(PWM_20 == 0)
				{
					PWM_pin = 1;
					TH0     = 0xFF;
					TL0     = 0xCF;
					PWM_high();
				}
				else if(PWM_50 == 0)
				{
					PWM_pin = 1;
					TH0     = 0xFF;
					TL0     = 0x13;
					PWM_high();
				}
				else if(PWM_80 == 0)
				{
					PWM_pin = 1;
					TH0     = 0xFF;
					TL0     = 0x42;
					PWM_high();
				}
			  else if(PWM_100 == 0)
				{
					PWM_pin = 1;
					TH0     = 0x00;
					TL0     = 0x00;
					PWM_high();
				}
				else if (PWM_Full == 0)    // just for clarification, not required.
					{
						PWM_pin = 1;
				  }
				
			}

}