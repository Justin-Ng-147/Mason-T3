#include "main.h"


void blue3(){
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(0,0,146);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);

    //score ring
    chassis.moveDistance(6,1000);
    arm.move(127);
    pros::delay(500);
    arm.brake();

    // get mogo
    chassis.moveToPoint(-10.5, 25.5, 2000, {.forwards=false,.maxSpeed=80,.minSpeed=5,.earlyExitRange=3});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    arm_move=false;
    global_target=100;
    set_intake_speed(127);

    chassis.moveToPoint(20,12, 2000, {.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-25.7,3, 2000, {.forwards=false, .minSpeed=5,.earlyExitRange=3},false);
    pros::delay(150);
    mogo.set_value(true);
    chassis.moveToPoint(-36,32.7, 2000, {.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    pros::Task redg45grj4g4_pos_task{[&]
        {
    while(intake_distance.get_distance()>30) pros::delay(5);
    set_intake_speed(0);
        }};
    chassis.moveToPoint(-36.5,51,2000,{.forwards=false, .maxSpeed=60, .minSpeed=5,.earlyExitRange=3},false);
    if(mogo_seated()){
        mogo.set_value(false);
        set_intake_speed(127);
    }
    set_intake_speed(127);
    chassis.moveToPoint(-45,16,1500,{.minSpeed=5,.earlyExitRange=3},false);

    swiper.set_value(true);
    chassis.moveToPoint(-49.5,2.9,1500,{.minSpeed=5,.earlyExitRange=3}, false);
    set_intake_speed(0);
    chassis.turnToHeading(-316.4,1500, {.minSpeed=5,.earlyExitRange=3}, false);

    
   

}