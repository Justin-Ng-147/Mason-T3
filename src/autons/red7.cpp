#include "main.h"
#include "ringSort.hpp"

// t3 bot red + finals alliance stake (04.25.2025)
void red7(){
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






//new bot red + 4 ring 3 goal
// void red7(){
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     chassis.setPose(0,0,-146);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(true);

//     //score ring
//     chassis.moveDistance(6.5,1000);
//     arm.move(127);
//     pros::delay(800);
//     arm.brake();

//     chassis.moveToPoint(16, 32,4000,{.forwards = false,.maxSpeed=80});
//     pros::delay(500);
//     arm_move=false;

//     global_target=100;
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(false);
//     chassis.cancelMotion();


//     // -18 11
//     //get 2 ring red
//     // chassis.turnToPoint(-18,11,2000,{},false);
//     // set_intake_speed(127);
//     // chassis.moveToPoint(-18,11,2000,{.maxSpeed=70});

//     set_intake_speed(127);
//     // chassis.moveToPoint(-23,-5,2000,{.minSpeed=5,.earlyExitRange=40});
//     // chassis.moveToPoint(-23,-5,2000,{.maxSpeed=50,.minSpeed=5,.earlyExitRange=3},false);
//     chassis.moveToPoint(-10,12,2000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(39,28,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
//     chassis.moveDistance(15,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=5});
    

//     chassis.turnToPoint(39,28,2000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3});
//     // mogo.set_value(false);
//     // set_intake_speed(127);
//     chassis.moveToPoint(39,28,2000);
//     // fast_move(38,30,2000,false);
//     chassis.moveDistance(10,1000,{.forwards=false},false);
//     mogo.set_value(true);
//     set_intake_speed(-127);
//     chassis.moveDistance(10,1000);
    
    
//     chassis.turnToPoint(42,45.5,1000,{.forwards=false},false);
//     chassis.moveToPoint(42,45.5,4000,{.forwards = false,.maxSpeed=70});
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(false);
//     chassis.cancelMotion();

//     // chassis.moveDistance(5,1000,{.minSpeed=127,.earlyExitRange=3});
//     fast_move(38,-4,2000,true);
//     chassis.moveDistance(7,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3});
//     // fast_move(38,0,2000,true);

//     chassis.turnToPoint(46,-4,1000,{.minSpeed=5,.earlyExitRange=3},false);
//     left.brake();
//     right.brake();
//     set_intake_speed(127);
//     chassis.moveDistance(40,1000);
//     // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3},false);

//     chassis.moveToPoint(5,41,3000,{.forwards=false});
//     chassis.waitUntil(20);
//     set_intake_speed(0);
//     global_target=6000;
//     while(chassis.isInMotion()) pros::delay(10);
//     arm_move=true;
//     arm.move(0);

// }