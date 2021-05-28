//TASK 3
// Write an ALP for blinking led in particular sequence 
// ON_OFF_ON_OFF_OFF_ON

org 0000h
	#define p2 0x0a0
	start: mov p2, #0ffh;     // led is turned on 
		   lcall delay		  // jumps to delay label 	
		   mov p2, #00h;	 // led turns off
		   lcall delay       
		   mov p2, #0ffh;  // led is on
		   lcall delay		 
		   mov p2, #00h; 	// led is off
		   lcall delay
		   mov p2, #00h;   // led is off
		   lcall delay
		   ajmp start     // looped back to the begining 
		   
    delay:mov r3, #0ah;   // here we are setting the delay values, so that it will blink at desired rate
	l3:   mov r1, #0ffh;  
	l1:	  mov r2, #0ffh;
	l2:   djnz r2, l2;
		  djnz r1, l1;
		  djnz r3, l3;
		  ret 
		  end 