#include "main.h"

// t3 bot red + finals alliance stake (04.25.2025)
void red3(){
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(0,0,-146);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);

    //score ring
    chassis.moveDistance(5,1000);
    arm.move(127);
    pros::delay(500);
    arm.brake();

    // get mogo
    chassis.moveToPoint(10.5, 25.5, 2000, {.forwards=false,.maxSpeed=80,.minSpeed=5,.earlyExitRange=3});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    arm_move=false;
    global_target=100;

    // intake red ring
    set_intake_speed(127);
    chassis.turnToPoint(39, 31.5, 2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(39, 31.5, 2000);
    pros::delay(2000);

    // move to hold blue ring

    chassis.turnToPoint(37.7, -5, 2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(37.7, -5, 2000);
    chassis.waitUntil(15);
    pros::Task skills_task2{[=]
        {
            while(intake_distance.get_distance()>30) pros::delay(10);
            set_intake_speed(0);
        }};

    // setup swiper, drop mogo, and go to corner
     
    chassis.turnToPoint(48, -8, 2000,{.minSpeed=5,.earlyExitRange=1}, false);
    swiper.set_value(true);
    mogo.set_value(true);
    pros::delay(200);

    chassis.moveToPoint(48,-8,1500,{.maxSpeed=80}, false);
    chassis.turnToHeading(36,1000,{.minSpeed=5,.earlyExitRange=3});
    pros::delay(200);
    swiper.set_value(false);

    // grab mogo 2 while clearing obstacles
    chassis.turnToPoint(43, 32, 2000);
    set_intake_speed(127);
    chassis.moveToPoint(43, 32, 2000);

    chassis.turnToPoint(41, 49.78, 2000, {.forwards=false,.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(41, 49.78, 2000, {.forwards=false}, false);

    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    left.brake();
    right.brake();
    chassis.cancelMotion();

}