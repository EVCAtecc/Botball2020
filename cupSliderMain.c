#include <kipr/wombat.h>
/*
move backwards for about 2 seconds, then rotate left and continue to rotate and when sensor input is <1 rotate for
about 8-10 seconds then drive up ramp and use line follwoing program (:
*/

int motorL = 0;
int motorR = 1;

int tail = 1;

int rangeS = 0;
int touch = 2;

int dist2pvc = 2000;

int main()
{
    printf("Hello World\n");
    
    enable_servos(); 
    set_servo_position(tail, 845);
    
    //turn to angle towards the ramp
    /*
    motor(motorL, 50); 
    motor(motorR, -50); 
    msleep(700); */ 
    
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
