#include "main.h"

// T3 BLUE + CORNER
void blue4(){
    chassis.setPose(0,0,0);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);
    swiper.set_value(true);
    set_intake_speed(65);

    // grab mogo with swiper
    chassis.moveToPoint(0.5, 37.5, 2000, {}, false);
    pros::Task skills_task1{[=]
        {
            while(intake_distance.get_distance()>50) pros::delay(10);
        set_intake_speed(0);
        }};
    chassis.moveToPoint(1,19,2000, {.forwards=false, .maxSpeed=75},false);
    swiper.set_value(false);
    pros::delay(100);
    chassis.turnToPoint(18,20.5,1000,{.forwards=false},false);
    chassis.moveToPoint(18,20.5,1000,{.forwards=false, .maxSpeed=80},false);
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    set_intake_speed(127);
    chassis.moveToPoint(0.4,-10, 1500, {},false);
    mogo.set_value(true);
    set_intake_speed(100);
    pros::Task skills_task2{[=]
        {
            while(intake_distance.get_distance()>50) pros::delay(10);
            set_intake_speed(0);
        }};
    chassis.turnToHeading(10, 1000, {}, false);
   
    chassis.moveToPoint(8,17,2000,{},false);
    chassis.turnToHeading(-166,1000,{},false);
    chassis.moveDistance(20,1000,{.forwards=false},false);
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    set_intake_speed(127);
    chassis.moveToPoint(-14,18.5,2000,{},false);
    swiper.set_value(true);
    set_intake_speed(0);
    chassis.moveDistance(20,1500,{},false);
    chassis.turnToHeading(-310,2000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE},false);
    swiper.set_value(false);
    chassis.moveDistance(40,1000,{},false);
    
    

}