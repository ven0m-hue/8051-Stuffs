// Seven Segment Display
org 0000h
#define p1 0x90      //address 
#define p3 0x0b0     
#define p2 0x0a0
mov p2,#0xff          // set as i/p port 
mov p1,#0x00          // set as o/p port            
lcall readkey         // calling readkey function
lcall display         // calling display func
readkey: mov p2,#0x7f
mov a ,p2
cjne a,#0x77,secondkeyrow0           
mov a,#00h
ret
secondkeyrow0:cjne a,#07bh,thirdkeyrow0
mov a,#01h
ret
thirdkeyrow0:cjne a,#07dh,fourthkeyrow0
mov a,#02h
ret
fourthkeyrow0:cjne a,#07eh,firstkeyrow1
mov a,#03h
ret
firstkeyrow1:mov p2,#0xbf
mov a ,p2
cjne a,#0xb7,secondkeyrow1
mov a,#04h
ret
secondkeyrow1:cjne a,#0bbh,thirdkeyrow1
mov a,#05h
ret
thirdkeyrow1: cjne a,#0bdh,fourthkeyrow1
mov a,#06h
ret
fourthkeyrow1:cjne a,#0beh,firstkeyrow2
mov a,#07h
ret
firstkeyrow2:mov p2,#0xdf
mov a ,p2
cjne a,#0xd7,secondkeyrow2
mov a,#08h
ret
secondkeyrow2:cjne a,#0dbh,thirdkeyrow2
mov a,#09h
ret
thirdkeyrow2:cjne a,#0ddh,fourthkeyrow2
mov a,#0ah
ret
fourthkeyrow2:cjne a,#0deh,firstkeyrow3
mov a,#0bh
ret
firstkeyrow3:mov p2,#0xef
mov a ,p2
cjne a,#0xe7,secondkeyrow3
mov a,#0ch
ret
secondkeyrow3:cjne a,#0ebh,thirdkeyrow3
mov a,#0dh
ret
thirdkeyrow3:cjne a,#0edh,fourthkeyrow3
mov a,#0eh
ret
fourthkeyrow3:cjne a,#0eeh,readkey
mov a,#0fh
ret
display: setb p3.6
setb p3.7
mov dptr, #string
movc a,@a+dptr
mov p1,a
ret
string: db 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,0x7F,0x6F,0x5f,0x7c,0x39,0x5e,0x7b,0x71;
end
