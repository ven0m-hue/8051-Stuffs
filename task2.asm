// Task 2
// write an alp code to perfrom the following 
// given data in M[30] 
//check if data is odd or even
//if odd store 01h in M[35]  
//if even store 0ffh in M[35]

org 0000h							//	BE       ||        AE		
	mov r0,#30h;				   // r0=0              r0=#30h
	mov a, @r0;					   // a=00h             a=30h	 
	
	jb 0e0h, odd;                  // jump bit if A is odd to label "odd"
	jnb 0e0h, evenn;			   // iump bit if A is even to label "evenn"	
	
odd:mov 35h, #01h;					// 35h=00           35h=#01h
	ajmp terminate;					// absolute jump and terminate 
evenn: mov 35h, #0ffh;              // 35h=00            35h=#0ffh
terminate: nop;						// no operation

end 