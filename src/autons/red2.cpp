#include "main.h"

//new bot red - finals 5 ring
void red2(){
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
    chassis.turnToPoint(-34,42.5,500,{.minSpeed=5,.earlyExitRange=3});
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
    chassis.moveDistance(20,1000,{.forwards=false,.maxSpeed=60,.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveDistance(15,1000);
    chassis.moveDistance(10,1000,{.forwards=false,.maxSpeed=60,.minSpeed=5,.earlyExitRange=3});


    chassis.turnToPoint(30,15,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(30,15,2000,{.minSpeed=5,.earlyExitRange=3});
    pros::Task skills_task2{[=]
    {
        while(top_distance.get_distance()>100) pros::delay(10);
        pros::delay(500);
        set_intake_speed(0);
    }};

    //go to corner
    // chassis.moveToPoint(60,-5,2000);
    chassis.moveToPoint(72,-13,2000);
    swiper.set_value(true);
    chassis.turnToHeading(-40,1000,{},false);
    set_intake_speed(0);
    // mogo.set_value(true);
    swiper.set_value(false);
    // set_intake_speed(-127);
}



// void red2(){
//     chassis.setPose(0,0,12);
//     mogo.set_value(true);

//     chassis.moveDistance(44,2000,{.maxSpeed=80});
//     chassis.waitUntil(30);
//     arm.move(127);
//     pros::delay(1000);
//     arm.brake();

//     chassis.turnToPoint(-12,28,2000,{.forwards=false},false);
//     arm_mutex.lock();
//     arm_move=false;
//     arm_mutex.unlock();

//     target_mutex.lock();
//     global_target=100;
//     target_mutex.unlock();
//     // chassis.moveToPoint(-12,28,2000,{.forwards=false});
//     chassis.moveDistance(40,3000,{.forwards=false,.maxSpeed=60});
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(50);
//     mogo.set_value(false);
//     chassis.cancelMotion();
// }

// void red2(){
//     //get contested mogo
//     chassis.setPose(0,0,12);
//     mogo.set_value(false);
//     chassis.moveToPoint(6,40,4000,{.minSpeed=20,.earlyExitRange=5},false);
//     swiper.set_value(true);
//     left.move(-127);
//     right.move(-127);
//     pros::delay(100);
//     left.move(0);
//     right.move(0);
    

//     //get mogo
//     chassis.turnToPoint(-12,28,2000,{.forwards=false},false);
    
//     // chassis.moveToPoint(-12,28,2000,{.forwards=false});
//     chassis.moveDistance(40,3000,{.forwards=false,.maxSpeed=60});
//     swiper.set_value(false);
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(100);
//     mogo.set_value(true);
//     pros::delay(100);
//     chassis.cancelMotion();

//     //20 36
//     //intake ring
//     chassis.moveToPoint(15,32,2000);
//     pros::delay(200);
//     intake.move(127);
//     // intake.move(0);

//     //start
//     // chassis.turnToPoint(5,-3,2000,{.forwards=false,.minSpeed = 10,.earlyExitRange=5});
//     // chassis.moveToPoint(5,-3,2000,{.forwards=false},false);
//     // chassis.turnToPoint(22,-9,2000,{},false);
//     // swiper.set_value(true);
//     // chassis.moveToPoint(22,-9,2000,{},false);
//     // intake.move(0);
//     // chassis.turnToHeading(35,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
//     // left.move(127);
//     // right.move(-127);
//     // pros::delay(50);
//     // left.move(0);
//     // right.move(0);
//     // swiper.set_value(false);
//     // intake.move(127);
//     // chassis.moveDistance(12,2000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3});
//     // chassis.turnToPoint(32,28,3000);
//     // chassis.moveDistance(40,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);
//     //end




//     chassis.turnToPoint(-4,-5,2000,{.forwards=false,.minSpeed = 10,.earlyExitRange=5});
//     chassis.moveToPoint(-4,-5,2000,{.forwards=false},false);
//     chassis.turnToPoint(22,-12,2000,{},false);
//     swiper.set_value(true);
//     chassis.moveToPoint(22,-12,2000,{},false);
//     intake.move(0);
//     chassis.turnToHeading(40,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
//     left.move(127);
//     right.move(-127);
//     pros::delay(50);
//     left.move(0);
//     right.move(0);
//     swiper.set_value(false);
//     intake.move(127);
//     chassis.moveDistance(12,2000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3});
//     chassis.turnToPoint(32,28,3000);
//     chassis.moveDistance(6,1000,{.forwards=false,.minSpeed=30,.earlyExitRange=3});
//     chassis.moveDistance(42,10000,{.maxSpeed=30,.minSpeed=30,.earlyExitRange=3},false);

    

//     chassis.moveDistance(15,2000,{.forwards=false},false);
//     pros::delay(500);
//     mogo.set_value(false);

//     chassis.turnToPoint(20,40,2000,{.forwards=false});
//     chassis.moveToPoint(20,40,2000,{.forwards = false,.maxSpeed=60});
//     if(mogo_seated()){
//         pros::delay(50);
//         mogo.set_value(true);
//         pros::delay(50);
//         // chassis.cancelMotion();
//     }

//     // pros::delay(500);
//     // mogo.set_value(false);
//     // chassis.turnToPoint(-23,39,2000,{.minSpeed=30,.earlyExitRange=3},false);
//     // intake.move(0);
//     // chassis.moveToPoint(-23,39,2000);
// }

// //finals no suck
// void red2(){
//     //get contested mogo
//     chassis.setPose(0,0,12);
//     mogo.set_value(false);
//     chassis.moveToPoint(6,40,4000,{.minSpeed=5,.earlyExitRange=5},false);
//     swiper.set_value(true);
//     left.move(-127);
//     right.move(-127);
//     pros::delay(100);
//     left.move(0);
//     right.move(0);
    

//     //get mogo
//     chassis.turnToPoint(-12,28,1000,{.forwards=false},false);
    
//     // chassis.moveToPoint(-12,28,2000,{.forwards=false});
//     chassis.moveDistance(40,3000,{.forwards=false,.maxSpeed=60});
//     // chassis.waitUntil(15);
//     swiper.set_value(false);
//     while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
//     pros::delay(100);
//     mogo.set_value(true);
//     pros::delay(100);
//     chassis.cancelMotion();

//     //20 36
//     //intake ring
//     // chassis.moveToPoint(-10,30,2000,{.minSpeed=5,.earlyExitRange=3});
//     chassis.moveToPoint(18,32,2000);
//     set_intake_speed(127);
//     // pros::delay(200);
//     // intake.move(127);
//     // intake.move(0);




//     chassis.turnToPoint(-4,-5,2000,{.forwards=false,.minSpeed = 10,.earlyExitRange=5});
//     chassis.moveToPoint(-4,-5,2000,{.forwards=false},false);
//     chassis.turnToPoint(22,-12,2000,{},false);
//     swiper.set_value(true);
//     chassis.moveToPoint(22,-12,2000);
//     // intake.move(0);
//     set_intake_speed(0);
//     chassis.turnToHeading(45,3000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE, .minSpeed=127, .earlyExitRange = 3},false);
//     left.move(127);
//     right.move(-127);
//     pros::delay(50);
//     left.move(0);
//     right.move(0);
//     swiper.set_value(false);
//     // //get one ring
//     // intake.move(127);
//     set_intake_speed(127);
//     chassis.moveDistance(12,2000,{.maxSpeed=30},false);
//     pros::delay(1000);
//     // mogo.set_value(false);

//     chassis.turnToPoint(32,28,3000);
//     set_intake_speed(0);
// //     chassis.moveDistance(6,1000,{.forwards=false,.minSpeed=30,.earlyExitRange=3});
//     chassis.moveDistance(30,10000,{},false);
//     set_intake_speed(127);
//     chassis.moveDistance(10,1000,{.forwards=false});
//     mogo.set_value(false);

// }

