// Decending Counter 
org 0000h
		  mov r1,#0ah;
		  
	start: mov r0,#30h;
	   l2: mov a,@r0;
	       inc r0;
		   subb a,@r0;
		   jnc l1;
		   jc l2;
	   l1: mov a,@r0;
		   dec r0;
		   xch a,@r0;
		   inc r0;
		   mov @r0,a;
		   djnz r1,start;
		   end