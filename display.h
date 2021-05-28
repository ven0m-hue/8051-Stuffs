//#include <reg51.h> 
	unsigned char hexcode_digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,
                                  0x7D, 0x07,0x7F, 0x6F,0x5f,0x7c,0x39,0x5e,0x7b,0x71 } ; // hex code from 0 to 15
	sbit disp1_enable = P3^6;															 
	sbit disp2_enable = P3^7;																 
	void delay(unsigned int time_delay_milisecond);																
  void display(char n1, char n2)  // it takes 2 parameters lsb and msb
	{ while(1){
		 disp1_enable = 1;
		 disp2_enable = 0;
 		 P1 = hexcode_digit[n1];   //msb
		 delay(10);                // delay to display the output 
		 disp2_enable = 1;
		 disp1_enable = 0;
		 P1 = hexcode_digit[n2];  //lsb
		 delay(10);
	}}

