#include <kipr/wombat.h>

int motorL = 0;
int motorR = 1;

int tail = 1;

int rangeS = 0;
int touch = 2;

int dist2pvc = 1400;

int main()
{
    printf("Hello World\n");
    
    enable_servos(); 
    set_servo_position(tail, 990);
    
    //go forward until close enough to pvc
    while (analog(rangeS)<= dist2pvc){
        motor(motorL, -50);
        motor(motorR, -50);
    }
    
    //turn until touch sensor pressed
    while (digital(touch) != 1) { 
    	motor(motorL, -50);
   		motor(motorR, 50); 
    }
    
    //move cup 
    motor(motorL, -50);
    motor(motorR, 50);
    msleep(4000);
    
    disable_servos(); 
    ao();
    
    return 0;
}
