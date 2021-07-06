// Digital to Analog Converter 
org 0000h
repeat: mov P2, #00h;
	    mov P2, #0ffh;
		lcall delay
		mov P2, #7fh;
		lcall delay
		sjmp repeat 
delay:  mov TMOD, #01h;
        mov TH0 , #0fch;
		mov TL0 , #6bh;
		setb TR0;
here:   jnb TF0, here;
        clr TF0;
		clr TR0;
		ret
        end 		