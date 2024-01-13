/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       lapto                                                     */
/*    Created:      1/12/2024, 4:36:05 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
motor l1 = motor(PORT10,ratio6_1,true);
motor l2 = motor(PORT9,ratio6_1,true);
motor l3 = motor(PORT8,ratio6_1,true);
motor r1 = motor(PORT3,ratio6_1,false);
motor r2 = motor(PORT4,ratio6_1,false);
motor r3 = motor(PORT5,ratio6_1,false);
controller declan = controller();
motor intake = motor(PORT7,ratio6_1,false);
motor cata = motor(PORT7,ratio6_1,false);

// define your global instances of motors and other devices here


int main() {

    while(true){
        l1.spin(forward,declan.Axis3.position()+declan.Axis1.position(),pct);
        l2.spin(forward,declan.Axis3.position()+declan.Axis1.position(),pct);
        l3.spin(forward,declan.Axis3.position()+declan.Axis1.position(),pct);
        r1.spin(forward,declan.Axis3.position()-declan.Axis1.position(),pct);
        r2.spin(forward,declan.Axis3.position()-declan.Axis1.position(),pct);
        r3.spin(forward,declan.Axis3.position()-declan.Axis1.position(),pct);

        if(declan.ButtonL1.pressing()){
            intake.spin(forward,100,pct);
        }
        else if(declan.ButtonR1.pressing()){
            intake.spin(reverse,100,pct);
        }
        else{
            intake.stop();
        }

        if(declan.ButtonL2.pressing()){
            cata.spin(forward,100,pct);
        }
        else{
            cata.stop();
        }

        wait(10,msec);
    }
}
