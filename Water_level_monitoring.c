#include <xc.h>
void data(char A);
void cmd (char A);
void delay();
void motor_delay();
void display(const char *P);
void level();
void clearAfterCursor();

void main(void) {
    ADCON1 = 0x0F;
      
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0xFF;
    TRISD = 0x00;
    
    cmd(0x38);//Function Set: 8-bit, 2 Line, 5×7 Dots
    cmd(0x80);//Force cursor to the beginning ( 1st line)
    cmd(0x01);//Clear Display 
    cmd(0x06);//Increment cursor (shift cursor to right)
    cmd(0x0E);//Display on, cursor on
    
        
    int prev_mode = -1;
    while(1){
        if( RC5 == 1){
            
            if( RC4 == 1){//Automatic mode
                
                if(prev_mode != 1){
                    prev_mode = 1;
                    cmd(0x01);
                    display("Automatic Mode");
                    cmd(0x01);
                    }
                
                    if( RC0 && RC1 && RC2 && RC3 == 1){
                        RD0 = 0;
                        cmd(0x80);
                       
                        display("MOTOR OFF");
                        clearAfterCursor();
                        
                        cmd(0xC0);
                        level();
                        
                    }else if( RC0 == 0 && RC1 == 0 && RC2 == 0 && RC3 == 1){
                        RD0 = 1;
                        cmd(0x80);
                       
                        display("MOTOR ON");
                        clearAfterCursor();
                        cmd(0x80);
                        cmd(0x0C);
                        cmd(0xC0);
                        level();
                        
                    }
                   
            }if( RC4 == 0){//Manual mode

                if(prev_mode != 0){
                    prev_mode = 0;
                    cmd(0x01);
                    display("Manual Mode");
                    cmd(0x01);
                }
                RD0 = 1;
                cmd(0x80);
                
                display("MOTOR ON");
                delay();
                
                cmd(0xC0);
                level();
                }   
        }else{
            PORTD = 0;
        }
    } 
return;
}

void data(char A){
    PORTB = A;
    RA0 = 1;// RS = high
    RA1 = 1;//Enable = high
    delay();
    RA1 = 0;//Clear Enable
}

void cmd (char A){
    PORTB = A;//To show that the variable A is passed to PORTB
    RA0 = 0;// RS = low
    RA1 = 1;//Enable = high
    delay();
    RA1 = 0;//Clear Enable
}

void delay(){
    for(int i=0;i<100;i++){
        for(int j=0;j<200;j++);
    }
}
void motor_delay(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++);
    }
}


void display(const char *P){//here const is given to show that address is fixed
    while(*P){
        data(*P++);
    }
}

void clearAfterCursor() {
    for (int i = 0; i < 2; i++) {
        data(' '); 
    }
    cmd(0x10);
}

void level(){
    
       display("level : ");
       cmd(0x0C);
    if( RC5 == 1){
        if( RC0 == 1 && RC1 == 1 && RC2 == 1 && RC3 == 1){
            display("100%");
//            cmd(0x0C);
        }else if(RC0 == 0 && RC1 == 1 && RC2 == 1 && RC3 == 1){
            display("50%");
//            cmd(0x0C);
        }else if(RC0 == 0 && RC1 == 0 && RC2 == 1 && RC3 == 1){
            display("25%");
//            cmd(0x0C);
        }else if(RC0 == 0 && RC1 == 0 && RC2 == 0 && RC3 == 1){
            display("0%");   
//            cmd(0x0C);
        }clearAfterCursor(); 
    }
}


