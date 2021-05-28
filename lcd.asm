org 0000H
# define lcd_data p1      
buzzer_control EQU p3.5       
lcd_register_select EQU p3.6
lcd_enable EQU p3.7      
mov p1, #00h   // set as output port 
mov p3,#00h    // set as output port 
setb buzzer_control  // turn off the buzzer
lcall lcd_initialization  //initalize the lcd screen
mov a,#80h                  // command start from the first line
lcall lcd_command_write     // call the command line 
clr a                       
mov dptr,#message_one      // point the data pointer to the string message one
lcall lcd_message_write   //call the function to write the function
mov a,#0c0h
lcall lcd_command_write    
clr a
mov dptr,#message_two    // point the data pointer to the string message two
lcall lcd_message_write   // call the func to write the message whihc dptr is pointing 
here:sjmp here
lcd_initialization:mov a, #38h
lcall lcd_command_write    
mov a, #10h
lcall lcd_command_write
mov a, #0ch
lcall lcd_command_write
mov a, #01h
lcall lcd_command_write
ret
lcd_command_write:mov p1,a    // command write 
clr lcd_register_select       // to give the commands to the lcd always clr the register select     
setb lcd_enable
lcall delay
clr lcd_enable
lcall delay
ret
lcd_message_write:mov r1,#10h    // lcd message write 
mov r2,#00h
up:mov a,r2
movc a,@a+dptr         // call the string whihc is being pointed //index addressomg mode
mov p1,a
inc r2
setb lcd_register_select   // to input the data always select the register to set mode 
setb lcd_enable
lcall delay
clr lcd_enable
lcall delay
djnz r1,up
ret
delay: mov r5,#0ffh         // delay function
wait:djnz r5,wait            
ret
message_one: db" Micro-LABlet "        // strings of message to input to the lcd screen
message_two: db "E&E,NMAMIT NITTE"
end