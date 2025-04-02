#include "main.h"

//new bot blue + teamwork 
void blue4(){
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    chassis.setPose(0,0,146);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);

    //score ring
    chassis.moveDistance(6.5,1000);
    arm.move(127);
    pros::delay(800);
    arm.brake();

    chassis.moveToPoint(-16, 32,4000,{.forwards = false,.maxSpeed=80});
    pros::delay(500);
    arm_move=false;

    global_target=100;
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();

    set_intake_speed(127);
    chassis.moveToPoint(11,10,2000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(0);

    chassis.turnToPoint(-45,29,1000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    chassis.moveToPoint(-45,29,2000,{.minSpeed=5, .earlyExitRange=3});
    chassis.waitUntil(20);
    pros::Task red_pos_task{[=]
        {
            while(distance.get_distance()>100) pros::delay(10);
            set_intake_speed(0);
        }};
   
    chassis.turnToPoint(-46,-4,1000,{.minSpeed=5, .earlyExitRange=3},false);
    chassis.moveToPoint(-46,-4,2000,{.minSpeed=5, .earlyExitRange=3});

    chassis.turnToHeading(-135,1000);
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
    chassis.turnToHeading(45,2000,{.direction=lemlib::AngularDirection::CCW_COUNTERCLOCKWISE},false);
    set_intake_speed(0);
    swiper.set_value(false);
    chassis.moveDistance(11,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(true);
    pros::delay(200);

    global_target=21000;
    chassis.moveToPoint(0,40.5,2000,{},false);
    arm_move=true;
    arm.move(0);
}


// // 3 goal - side
// void blue4(){
//     // setup
//     chassis.setPose(0,0,-146);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(false);

//     //score ring
//     pto.set_value(true);
//     chassis.moveDistance(11,1000,{},false);
//     deploy.set_value(true);
//     claw.set_value(true);
//     pros::delay(200);

//     // get mogo
//     chassis.moveToPoint(16, 31,4000,{.forwards = false,.maxSpeed=60});
//     pto.set_value(false);
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(true);
//     // pros::delay(50);
//     chassis.cancelMotion();
//     left.brake();
//     right.brake();
//     deploy.set_value(false);
//     pros::delay(100);
    

//     //get 2 rings
//     set_intake_speed(127);
//     chassis.swingToPoint(30,42,DriveSide::RIGHT,2000,{.maxSpeed=80, .minSpeed=5, .earlyExitRange = 10});
//     chassis.turnToPoint(30,42,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(30,42,1000,{});
//     chassis.turnToPoint(46,42,1000,{.minSpeed=40,.earlyExitRange=3});
//     chassis.moveToPoint(46,42,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.turnToHeading(95,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(18,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(15,2000);

//     chassis.turnToHeading(80,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveDistance(30,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     chassis.turnToPoint(37,25,1000,{.minSpeed=20,.earlyExitRange=3});
//     fast_move(37,25,2000,true);



//     //28 -1
//     chassis.turnToPoint(-20,8,1000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveToPoint(16,16,2000);
//     fast_move(-20,8,2000,true);
//     mogo.set_value(false);
//     // chassis.moveToPoint(28,-1,4000,{.maxSpeed = 40});
//     while(!(vision.get_by_sig(0,BLUECOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
//     set_intake_speed(0);


//     chassis.turnToPoint(-38,29, 1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(-38,29,2000,{.forwards=false,.maxSpeed=60});
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(true);
//     pros::delay(50);
//     chassis.cancelMotion();

//     chassis.turnToPoint(-65,28,2000,{.minSpeed=5,.earlyExitRange=3});
//     set_intake_speed(127);
//     chassis.moveToPoint(-65,28,2000,{},false);
//     pros::delay(500);

//     chassis.moveToPoint(-26,35,2000,{.forwards=false},false);
//     set_intake_speed(0);

// }