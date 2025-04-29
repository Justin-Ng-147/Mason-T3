#include "main.h"

// t3 bot red - teamwork
void red1(){
   // setup
    chassis.setPose(0,0,143.5);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);

    //score ring
    chassis.moveDistance(5,1000);
    arm.move(127);
    pros::delay(800);
    arm.brake();

    // get mogo
    chassis.moveToPoint(-12.5, 32.7,4000,{.forwards = false,.maxSpeed=80});
    pros::delay(500);
    arm_move=false;
    global_target=100;
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);

    //get 2 rings
    set_intake_speed(127);
    chassis.turnToPoint(-26.5,44.5,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-26.5,44.5,1000,{.minSpeed=20,.earlyExitRange=3});
    chassis.turnToPoint(-45,46,500,{.minSpeed=20,.earlyExitRange=3});
    chassis.moveToPoint(-45,46,1000,{.minSpeed=20,.earlyExitRange=3});

    chassis.moveToPoint(-14, 38,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
    chassis.turnToPoint(-36,28,1000,{.minSpeed=20,.earlyExitRange=3});
    fast_move(-36,28,2000,true);

    //touch bar
    chassis.turnToPoint(11,11,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(11,11,2000,{.minSpeed=5,.earlyExitRange=3});

    chassis.turnToPoint(-18.69, 14.45, 2000, {.forwards=false, .minSpeed=5, .earlyExitRange=3});
    chassis.moveToPoint(-18.69, 14.45, 2000, {.forwards=false, .minSpeed=5, .earlyExitRange=3});

    chassis.turnToPoint(-3, 32, 2000, {.minSpeed=5, .earlyExitRange=3}, false);
    arm_move=false;
    global_target=15000;
    pros::delay(1000);
    arm_move=true;
    arm.move(0);
    chassis.moveToPoint(-3, 32, 4000, {.maxSpeed=60,.minSpeed=5, .earlyExitRange=3});

    return;
}