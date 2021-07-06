//M[40h]=04h;
//M[41h] = 05h;
//M[42h] = 06h;
// 1. Calculate the sum of all the above these values and store those values in M[43h];
// 2. Calculate the average of all the above these values and store those values in M[44];
// 3. Calculate the square of the content in M[44h] and store those values in M[45h];

org 0000h
	// Sum of three numbers				//	 BE        :: AE
	mov r0, #40h; 					//   r0=00h		  ro=40h
	mov r1, #41h;					//   r1=00h 	  r1=41h
	mov a, @r0;						//   r0[40]=00    r0[40]=23h
	add a, @r1;				    	//   r1[40]=00    r0[40]=32h
									//   a=M[40]      a=M[40]+M[41]
	mov 43h, a;						//  a=M[40]+M[41] M[43]=M[40]+M[41]
	
	//Average of three numbers
	mov 0f0h, #3;					// b=00           b=03
	div ab;							// a/b            a=1c  b=  
	mov 44h, a;                    // a=1c            M[44]=1c  
	
	//square of a number
	mov 0f0h, 44h;                 // b=00            b=1c
	mul ab;						   // multiply a*b = 1c*1c
	mov 45h, a;					   // M[45h]=00       M[45h]=10	
	
end