#include "main.h"
#include "ringSort.hpp"

// t3 bot red + finals goal rush
void red4(){
    //setup
    chassis.setPose(0,0,0);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);
    swiper.set_value(true);

    chassis.moveToPoint(0, 38, 2000, {.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    pros::Task skills_task1{[=]
    {
        while(intake_distance.get_distance()>50) pros::delay(10);
        set_intake_speed(0);
    }};
    // chassis.waitUntil(35);
    // chassis.cancelAllMotions();
    chassis.moveToPoint(0,20, 2000, {.forwards=false, .maxSpeed=70},false);
    swiper.set_value(false);
    left.brake();
    right.brake();
    pros::delay(200);
    

    chassis.turnToPoint(-22,37.5,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-22,37.5,4000,{.forwards = false,.maxSpeed=75});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();
    left.brake();
    right.brake();
    pros::delay(100);
    

    
    chassis.turnToPoint(-28, 6 ,2000, {.forwards=false, .minSpeed=5,.earlyExitRange=5},false);
    set_intake_speed(127);
    chassis.moveToPoint(-28, 6 ,2000, {.forwards=false},false);
    mogo.set_value(true);

    // -7 12
    chassis.turnToPoint(-7,11,1000,{.minSpeed=5,.earlyExitRange=3});
    
    chassis.moveToPoint(-7,11,2000,{.minSpeed=5,.earlyExitRange=3});

    // grab mogo
    chassis.turnToPoint(6,39,2000,{.forwards=false,.maxSpeed=35,.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(6,39,4000,{.forwards = false,.maxSpeed=70});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();
    
    left.brake();
    right.brake();
    pros::delay(100);
    
    
    // set_intake_speed(127);

    chassis.moveToPoint(-9,-1.5,2000,{}, false);
    chassis.turnToHeading(134,1000,{.minSpeed=5,.earlyExitRange=3}, false);
    // chassis.turnToPoint(0, -10, 2000, {.minSpeed=5, .earlyExitRange=3}, false);
    // set_intake_speed(0);
    chassis.moveDistance(10, 1000, {.forwards=false,.maxSpeed=80});
    swiper.set_value(true);
    chassis.moveDistance(18, 1000,{.maxSpeed=80});
    chassis.turnToHeading(37,1000,{.minSpeed=5,.earlyExitRange=3}, false);
    set_intake_speed(0);

    swiper.set_value(false);
    chassis.moveToPoint(2, 39, 4000);


}