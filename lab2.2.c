#include<experiment#2.h>
charidata *r1=0x01,*internalmemory1=0X30,
*internalmemory2=0x31,*internalmemory3=0x32,
*internalmemory4=0x33,*internalmemory5=0x34;
charidata*internalmemory6=0X35,
*internalmemory7=0X36,*internalmemory8=0X37;
charidataa,b=0x0b,c=0x02; //any value in b and c can be
given
main()
{
a=b+c;
*r1=psw;
*internalmemory1=*r1&0x80; //carry of additionstored
in memory location 30h
*internalmemory2=a; //addition result stored in
memory location 31h
a=b-c;
*r1=psw;
*internalmemory3=*r1&0x80; //carry of subtraction
stored in memory location 32h
*internalmemory4=a; //subtraction result stored
inmemory location 33h
a=b * c;
*internalmemory5=a; //LSB of multiplication
stored in memory location34h
*internalmemory6=B; //MSB of multiplication
stored in memory location 35h
a=b / c;
*internalmemory7=a; //quotient of division
stored in memory location 36h
*internalmemory8=B; //remainder of division
stored in memory location 37h
}