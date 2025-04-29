#include "main.h"

void blue2(){
    // setup
    chassis.setPose(0,0,-143.5);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);

    //score ring
    chassis.moveDistance(4.5,1000);
    arm.move(127);
    pros::delay(800);
    arm.brake();

    // get mogo
    chassis.moveToPoint(16, 32.7,4000,{.forwards = false,.maxSpeed=80});
    pros::delay(500);
    arm_move=false;
    global_target=100;
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);

    //get 2 rings
    set_intake_speed(127,false);
    chassis.turnToPoint(30,43.5,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(30,43.5,1000,{.minSpeed=20,.earlyExitRange=3});
    // chassis.turnToPoint(49,43.5,500,{.minSpeed=20,.earlyExitRange=3},false);
    chassis.turnToPoint(49,45,1000,{.minSpeed=20,.earlyExitRange=3},false);
    // pros::delay(200);
    chassis.moveToPoint(49,45,5000,{.minSpeed=20,.earlyExitRange=3});

    chassis.moveToPoint(16,38,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
    chassis.turnToPoint(40,28,1000,{.minSpeed=20,.earlyExitRange=3});
    fast_move(40,28,2000,true);

    chassis.turnToPoint(-19,14,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-19,14,5000,{.minSpeed=5,.earlyExitRange=3});
    chassis.waitUntil(36);
    mogo.set_value(true);

    chassis.turnToPoint(-38,33,1000,{.forwards=false});
    chassis.moveToPoint(-38,33,3200,{.forwards=false,.maxSpeed=70});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();

    chassis.turnToPoint(-57,31,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-57,31,5000,{.minSpeed=5,.earlyExitRange=3});
    
    chassis.turnToPoint(-30,36,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-30,36,5000,{.minSpeed=5,.earlyExitRange=3});
    arm_move=false;
    global_target=15000;
    pros::delay(1000);
    arm_move=true;
    arm.move(0);
    return;
}