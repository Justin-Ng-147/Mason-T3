#include "main.h"

// red finals code + for new bot
void red6(){
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(0,0,-146);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);

    chassis.moveToPoint(16, 32,4000,{.forwards = false,.maxSpeed=80});
    pros::delay(500);
    arm_move=false;

    global_target=100;
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();

    set_intake_speed(127);
    chassis.moveToPoint(-10,12,2000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(0);

    chassis.turnToPoint(45,29,1000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    chassis.moveToPoint(45,29,2000,{.minSpeed=5, .earlyExitRange=3});
    chassis.waitUntil(20);
    pros::Task red_pos_task{[=]
        {
            while(distance.get_distance()>100) pros::delay(10);
            set_intake_speed(0);
        }};
    

    chassis.turnToPoint(47,-5,1000,{.minSpeed=5, .earlyExitRange=3},false);
    chassis.moveToPoint(47,-5,2000,{.minSpeed=5, .earlyExitRange=3});

    chassis.turnToHeading(135,1000);
    set_intake_speed(127,false);
    chassis.moveDistance(40,1000);
    chassis.moveDistance(20,1000,{.forwards=false,.maxSpeed=60,.minSpeed=5,.earlyExitRange=3},false);
    swiper.set_value(true);
    chassis.moveDistance(15,1000);
    // pros::Task red_pos_task2{[=]
    //     {
    //         while(top_distance.get_distance()>50) pros::delay(10);
    //         pros::delay(500);
    //         set_intake_speed(0);
    //     }};
    chassis.turnToHeading(-45,2000,{.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE},false);
    set_intake_speed(0);
    swiper.set_value(false);
    chassis.moveDistance(11,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(true);
    pros::delay(200);

    // chassis.turnToPoint(42,25,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(42,30,2000,{.minSpeed=5, .earlyExitRange=3});
    chassis.turnToHeading(180,1000);
        
}