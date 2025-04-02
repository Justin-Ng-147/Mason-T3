#include "main.h"


// new bot red - teamwork
void red1(){
   // setup
    chassis.setPose(0,0,146);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    mogo.set_value(true);

    //score ring
    chassis.moveDistance(6.5,1000);
    arm.move(127);
    pros::delay(800);
    arm.brake();

    // get mogo
    chassis.moveToPoint(-17, 34,4000,{.forwards = false,.maxSpeed=80});
    pros::delay(500);
    arm_move=false;
    global_target=100;
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);

    //get 2 rings
    set_intake_speed(127);
    chassis.turnToPoint(-34,42.5,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(-34,42.5,1000,{.minSpeed=20,.earlyExitRange=3});
    chassis.turnToPoint(-48,42.5,1000,{.minSpeed=20,.earlyExitRange=3});
    chassis.moveToPoint(-48,42.5,1000,{.minSpeed=20,.earlyExitRange=3});

    chassis.moveToPoint(-14, 31,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
    chassis.turnToPoint(-36,27,1000,{.minSpeed=20,.earlyExitRange=3});
    fast_move(-36,27,2000,true);
    
    chassis.turnToPoint(-51,-10,1000);
    set_intake_speed(127,false);
    chassis.moveDistance(40,2000);
    chassis.moveDistance(40,1000);
    chassis.moveDistance(20,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false);

    //touch bar
    chassis.turnToPoint(10,13,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(10,13,2000,{.minSpeed=5,.earlyExitRange=3});
    pros::Task skills_task2{[=]
    {
        while(top_distance.get_distance()>100) pros::delay(10);
        pros::delay(500);
        set_intake_speed(0);
    }};
    //touch bar
    chassis.turnToHeading(-15,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(40,1000,{.maxSpeed=40});
}

//red finals code + for new bot
// void red1(){
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     chassis.setPose(0,0,-146);
//     left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
//     mogo.set_value(true);

//     //score ring
//     chassis.moveDistance(7,1000);
//     arm.move(127);
//     pros::delay(700);
//     arm.brake();

//     chassis.moveToPoint(16, 32,4000,{.forwards = false,.maxSpeed=80});
//     pros::delay(500);
//     arm_mutex.lock();
//     arm_move=false;
//     arm_mutex.unlock();

//     target_mutex.lock();
//     global_target=100;
//     target_mutex.unlock();
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
    

//     chassis.turnToPoint(39,28,1000,{.direction=lemlib::AngularDirection::CW_CLOCKWISE,.minSpeed=5,.earlyExitRange=3});
//     // mogo.set_value(false);
//     // set_intake_speed(127);
//     chassis.moveToPoint(39,28,2000,{.minSpeed=5, .earlyExitRange=3});
//     // // fast_move(38,30,2000,false);
//     // chassis.moveDistance(10,1000,{.forwards=false},false);
//     // mogo.set_value(true);
    
//     // chassis.moveDistance(10,1000);
    
    
//     // chassis.turnToPoint(42,45.5,1000,{.forwards=false},false);
//     // chassis.moveToPoint(42,45.5,4000,{.forwards = false,.maxSpeed=70});
//     // while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     // pros::delay(50);
//     // mogo.set_value(false);
//     // chassis.cancelMotion();

//     // chassis.moveDistance(5,1000,{.minSpeed=127,.earlyExitRange=3});
//     chassis.turnToPoint(38,-4,1000,{.minSpeed=5, .earlyExitRange=3},false);
//     chassis.moveToPoint(38,-4,2000,{.minSpeed=5, .earlyExitRange=3});
//     chassis.waitUntil(8);
//     set_intake_speed(-127);
//     chassis.moveDistance(7,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3});
//     // fast_move(38,0,2000,true);
    

//     chassis.turnToPoint(46,-4,1000,{.minSpeed=5,.earlyExitRange=3},false);
//     left.brake();
//     right.brake();
//     set_intake_speed(127);
//     chassis.moveDistance(40,1000);
//     // chassis.moveDistance(10,1000,{.forwards=false,.minSpeed=80,.earlyExitRange=3},false);

//     chassis.moveDistance(15,1000,{.forwards=false, .minSpeed=5, .earlyExitRange=3},false);
//     pros::delay(1000);
//     set_intake_speed(0);
//     swiper.set_value(true);
//     chassis.moveDistance(10,1000,{.minSpeed=5, .earlyExitRange=3});
//     chassis.turnToHeading(55,1000,{.minSpeed=5, .earlyExitRange=3},false);
//     swiper.set_value(false);
//     chassis.turnToPoint(42,35,1000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(42,35,2000,{.minSpeed=5, .earlyExitRange=3});
    
//     chassis.waitUntil(10);
//     mogo.set_value(true);
//     chassis.turnToHeading(180,1000);
    
//     // chassis.moveToPoint(5,41,3000,{.forwards=false});
//     // chassis.waitUntil(20);
//     // set_intake_speed(0);
//     // target_mutex.lock();
//     // global_target=6000;
//     // target_mutex.unlock();
//     // while(chassis.isInMotion()) pros::delay(10);
//     // arm_mutex.lock();
//     // arm_move=true;
//     // arm_mutex.unlock();
//     // arm.move(0);

//     // target_mutex.lock();
//     // global_target=20000;
//     // target_mutex.unlock();
//     // chassis.moveToPoint(10,8,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
//     // chassis.turnToPoint(10,40,1000,{.minSpeed=5,.earlyExitRange=3});
//     // arm_mutex.lock();
//     // arm_move=true;
//     // arm_mutex.unlock();
//     // arm.move(0);
//     // chassis.moveToPoint(10,40,1000);
// }









//dont use this is all the old stuff
// void red1(){
//     //setup
//     chassis.setPose(0,0,144);
//     intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
//     mogo.set_value(false);

//     //score ring
//     pto.set_value(true);
//     chassis.moveDistance(10,1000,{},false);
//     deploy.set_value(true);
//     claw.set_value(true);
//     pros::delay(200);

//     // get mogo
//     chassis.moveToPoint(-13, 31,4000,{.forwards = false,.maxSpeed=70});
//     intake.move(-127);
//     pros::delay(300);
//     intake.move(0);
//     deploy.set_value(false);
//     pto.set_value(false);

//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     chassis.cancelMotion();
//     pros::delay(50);
//     mogo.set_value(true);
//     pros::delay(50);
    

//     //get 2 rings
//     chassis.swingToPoint(-30,44,DriveSide::LEFT,2000,{.maxSpeed=80});
//     intake.move(127);
//     chassis.moveToPoint(-30,44,2000);
//     chassis.turnToHeading(271,1000);
//     chassis.moveDistance(15,2000,{},false);
//     // chassis.moveDistance(15,2000);

//     chassis.turnToPoint(-30,11,2000,{.minSpeed=5,.earlyExitRange=3});
//     // chassis.moveDistance(10,2000);
//     // pros::delay(1000);
//     // intake.move(127);
//     chassis.moveToPoint(-30,11,4000,{.maxSpeed=90});
//     // intake.move(0);

//     //28 -1
//     chassis.turnToPoint(28,-1,2000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(28,-1,2000,{.minSpeed=127,.earlyExitRange = 40},false);
//     mogo.set_value(false);
//     chassis.moveToPoint(28,-1,4000,{.maxSpeed = 40});
//     while(!(vision.get_by_sig(0,REDCOLOR).width>100 && distance.get_distance()<150)&&chassis.isInMotion()) pros::delay(10);
//     chassis.cancelMotion();


//     chassis.turnToPoint(38,29, 2000,{.forwards=false});
//     int move = 0;
//     while(vision.get_by_sig(0,REDCOLOR).width>100) {
//         if(!chassis.isInMotion()){
//             chassis.moveToPoint(38,29, 2000, {.forwards=false});
//             move = 1;
//         }
//         pros::delay(5);
//     }
//     intake.move(0);
//     if(move==0) chassis.moveToPoint(38,29, 2000, {.forwards=false});
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     chassis.cancelMotion();
//     pros::delay(50);
//     mogo.set_value(true);
//     pros::delay(50);

//     chassis.turnToPoint(60,22,2000,{.minSpeed=5,.earlyExitRange=3},false);
//     intake.move(127);
//     chassis.moveToPoint(60,22,2000);

//     chassis.moveToPoint(36,37,1000,{.forwards=false});
    
//     //38 29

//     // chassis.turnToPoint(25,30,2000);
//     // chassis.moveToPoint(25,30,2000);

//     // // -54 -6
//     // chassis.turnToPoint(-44,-5,4000);
//     // chassis.moveDistance(44,1000);
//     // chassis.moveDistance(20,2000,{.forwards=false});

//     // //26 1.5
//     // chassis.moveToPoint(35,6,4000,{.minSpeed=127,.earlyExitRange = 40});
//     // chassis.moveToPoint(35,6,4000,{.maxSpeed = 40},false);
//     // intake.move(0);
//     // // while(!(vision.get_by_sig(0,1).width < 100 && ringdistancesensor.get_distance()<75)) pros::delay(100);
//     // // chassis.cancelMotion();

//     // // chassis.moveToPoint(72,-10,4000,{.forwards = false},false);
//     // // intake.move(0);
//     // // mobo.set_value(false);
//     // // chassis.moveDistance(10,1500);
    
//     // swiper.set_value(true);
//     // chassis.turnToPoint(69,-8,2000);
//     // chassis.moveToPoint(69,-8,2000);
//     // chassis.turnToHeading(-45,1000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE},false);
//     // chassis.moveDistance(20,1000,{.forwards=false},false);
//     // mogo.set_value(false);
//     // pros::delay(200);
//     // chassis.moveDistance(10,1000);
// }