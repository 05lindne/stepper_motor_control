
#include <Arduino.h>
#undef abs  //neutralizes an error with <StandardCPlusplus> caused by a #define abs in <Arduino.h>. Has to appear right after #include <Arduino.h>
            //error looks like: expected ")" before long in cstdlib

#include "KeyboardController.h"


void KeyboardMotorController::read_signal(MotorController::signal_type signal) {

	  switch(signal)
        {
            case 'W':
            case 'w':
                Serial.println( "y-UP was pressed");
                // std::cout << "y-UP was pressed \n"; 
                motor.set_forward("y");
                motor.do_step("y");               
                break;
            case 'A':
            case 'a':
                Serial.println( "x-Down was pressed");
                // std::cout << "x-DOWN was pressed \n";
                motor.set_backward("x");
                motor.do_step("x");     
                break;
            case 's':
            case 'S':
                Serial.println( "y-Down was pressed");
                // std::cout << "y-DOWN was pressed \n";
                motor.set_backward("y");
                motor.do_step("y");     
                break;
            case 'D':
            case 'd':
                Serial.println( "x-UP was pressed");
                // std::cout << "x-UP was pressed \n";
                motor.set_forward("x");
                motor.do_step("x");     
                break;
            case 'R':
            case 'r':
                Serial.println( "z-UP was pressed");
                // std::cout << "z-UP was pressed \n";    
                motor.set_forward("z");
                motor.do_step("z");       
                break; 
            case 'F':
            case 'f':
                Serial.println( "z-Down was pressed");
                // std::cout << "z-DOWN was pressed \n";     
                motor.set_backward("z");
                motor.do_step("z");
                break;
            case '1':
            case '!':
                Serial.println( "speed FULL was pressed");
                // std::cout << "speed FULL was pressed \n";     
                motor.set_pin_configuration_all("full");
                break;
            case '2':
            case '@':
                Serial.println( "speed HALF was pressed");
                // std::cout << "speed HALF was pressed \n";     
                motor.set_pin_configuration_all("half");
                break;
            case '3':
            case '#':
                Serial.println( "speed QUARTER was pressed");
                // std::cout << "speed QUATER was pressed \n";     
                motor.set_pin_configuration_all("quarter");
                break;
            case '4':
            case '$':
                Serial.println( "speed EIGHT was pressed");
                // std::cout << "speed EIGHT was pressed \n";     
                motor.set_pin_configuration_all("eight");
                break;
            case 'Z':
            case 'z':
                Serial.println("x axis locked/unlocked was pressed");
                // std::cout << "x axis locked/unlocked was pressed \n";     
                motor.lock("x");
                break;
            case 'X':
            case 'x':
                Serial.println("y axis locked/unlocked was pressed");
                // std::cout << "y axis locked/unlocked was pressed \n";     
                motor.lock("y");
                break;
            case 'C':
            case 'c':
                Serial.println("z axis locked/unlocked was pressed");
                // std::cout << "z axis locked/unlocked was pressed \n";     
                motor.lock("z");
                break;
            case 'V':
            case 'v':
                Serial.println("all axes locked/unlocked was pressed");
                // std::cout << "all axes locked/unlocked was pressed \n";     
                motor.lock_all();
                break;
            case '*':
            case '8':
                Serial.println( "x motor SLEEP was pressed");
                // std::cout << "x motor SLEEP was pressed \n";     
                motor.sleep("x");
                break;
            case '(':
            case '9':
                Serial.println( "y motor SLEEP was pressed");
                // std::cout << "y motor SLEEP was pressed \n";     
                motor.sleep("y");
                break;
            case ')':
            case '0':
                Serial.println("z motor SLEEP was pressed");
                // std::cout << "z motor SLEEP was pressed \n";     
                motor.sleep("z");
                break;
            case '~':
            case '`':
                Serial.println( "RESET was pressed");
                // std::cout << "RESET was pressed \n";     
                motor.sleep("z");
                

        }


}