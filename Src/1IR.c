#include <reg51.h>
// Polling mode IR sensor 
 sbit IR = P2^2;
 sbit buzzer = P3^5;
 //char   count; 
 char rpm;
 int count()
 {
    unsigned int i,j;
    unsigned int count=0;
    for(i=0;i<1000;i++) 
    {
      for(j=0;j<1227;j++)
      {
       if(IR == 0)
       {
         count++;
         while(IR==0);
       }
    }
  }
    return count;
} 
  
 void main()
 { 
	 while(1)
	 {
		unsigned int time=0, rpm = 0;
		buzzer = 1;
		while(1)
		{ 
		 if(IR == 0)
		 {
			time = count(); 		 
			rpm = time; 
		 }
		 
		   if (rpm == 5)
			 {
					buzzer = 0;
			 }
		 
		}
		
	}
 }
