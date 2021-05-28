org 0000h
#define p1 0x90 //define port1 address
#define p3 0x0b0 //define port3 address
start: mov r0,#0ah; //to keep count of 10
mov r1,#00h; //to start count from 0
repeat:mov a,r1;
anl a,#0fh; //to mask LSB
mov r2,a;
mov a,r1;
anl a,#0fh; //to mask MSB
swap a;
mov r3,a;
mov r6,#30h; //count to make display at visible rate
up:setb p3.7; //activate display#1
clr p3.6;
mov a,r2;
lcall display   // this jump is called to display the value on the seven seg
lcall delay     // this gives the approprtiate amount of delay, which can be set
clr p3.7;
setb p3.6; //activate display#2
mov a,r3;
lcall display
lcall delay
djnz r6,up;
inc r1;
djnz r0,repeat;
ajmp start
display: mov dptr, #string
movc a,@a+dptr;
mov p1,a;
ret
delay: mov tmod, #10h; //timer1 mode1   // operating timer mode at timer 1 and mode 1 13bit timer 
mov th1, #0D8h;                         // gives a delay of 10 mili sec
mov tl1,#0F0h;							// which can be calculated using the formula 		
setb tr1;                               // since it is a 16 bit no. it is stored in two, th1 and tl1
wait: jnb tf1,wait;
clr tf1;
clr tr1;
ret
string: db 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,0x7F, 0x6F; // These are the numbeers to be displayed on the seven segment

end