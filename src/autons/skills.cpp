#include "main.h"
#include "ringSort.hpp"


void skills(){
    //set up
    chassis.setPose(0, 0, 131.5);
    intake.set_encoder_units_all(MOTOR_ENCODER_ROTATIONS);
    left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    
    //score preload
    arm.move(127);
    pros::delay(800);
    arm.brake();

    //get mogo 1
    chassis.moveDistance(20,1000,{.forwards = false,.maxSpeed=80});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();
    left.brake();
    right.brake();
    pros::delay(100);

    //mogo 1 move arm back to start position
    arm_move=false;
    global_target=100;

    //mogo 1 get ring 1
    chassis.turnToPoint(-11,30,1000,{.minSpeed=5,.earlyExitRange=3},false);
    set_intake_speed(127);
    fast_move(-11,30,2000,false);

    //mogo 1 get ring 2 move to half way point to avoid hang post
    chassis.turnToPoint(-31,56,1000,{.minSpeed=5,.earlyExitRange=3},false);
    fast_move(-31,56,1000,true);
    //mogo 1 move arm to load ring
    arm_move=false;
    global_target=1800;
    //mogo 1 get ring 2 move to ring
    set_intake_speed(127,false);
    fast_move(-36,90,2000,true);
    // pros::delay(300);

    //mogo 1 task that when the ring is on the arm lift the arm up out of the way of other intaked rings
    pros::Task skills_task1{[=]
    {
        while(intake_distance.get_distance()>50) pros::delay(10);
        pros::delay(800);
        global_target=3000;
        set_intake_speed(-25);
        pros::delay(500);
        set_intake_speed(0);
    }};

    //mogo 1 move to stake
    chassis.moveToPoint(-32.5,58,2000,{.forwards=false},false);
    chassis.turnToHeading(-90,1000, {}, false);
    global_target=8000;
    chassis.moveDistance(20,2000,{.maxSpeed = 60});
    chassis.waitUntil(12);
    set_intake_speed(127);
    global_target=15000;
    int count = 0;
    while(arm_control.get_position()<11000 && chassis.isInMotion()) pros::delay(10);
    while(chassis.isInMotion()){
        if(count > 30){
            chassis.cancelMotion();
            break;
        } 
        count +=1;
        pros::delay(10);
    }
    
    //mogo 1 back away from stake and move arm back to start pos
    chassis.moveDistance(17,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false); 
    global_target=7000;
    
    //mogo 1 get 3 rings in a line
    chassis.turnToPoint(-36,0,1000,{.minSpeed=3,.earlyExitRange=3}, false);
    set_intake_speed(127);
    chassis.moveToPoint(-36,0,2000,{.minSpeed=50,.earlyExitRange=20});
    chassis.moveToPoint(-36,0,2000,{.maxSpeed=30},false);

    //mogo 1 get last ring and set up to drop off mogo
    chassis.turnToPoint(-48, 7, 2000,{.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveToPoint(-48,7,2000,{.minSpeed=5,.earlyExitRange=3},false);
    chassis.turnToHeading(12,1000,{.minSpeed=5,.earlyExitRange=3});
    

    //mogo 1 score mogo
    chassis.moveDistance(8,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(true);
    pros::delay(200);
    set_intake_speed(0);
    //mogo 1 move away from corner
    chassis.moveDistance(14,1000,{.minSpeed=5,.earlyExitRange=3});

    global_target =100;

    //get new mogo 2                             
    chassis.turnToPoint(45,10,1000,{.forwards=false});
    // global_target=3200;
    chassis.moveToPoint(45,10,4000,{.forwards=false,.minSpeed=5,.earlyExitRange=40});
    chassis.moveToPoint(45,10,3200,{.forwards=false,.maxSpeed=70});
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(50);
    mogo.set_value(false);
    chassis.cancelMotion();
    set_intake_speed(127);

    // skills_task50.notify();

    //mogo 2 get 1st ring
    chassis.turnToPoint(36,34,1000,{.minSpeed=5,.earlyExitRange=3},false);
    // set_intake_speed(127,false);
    fast_move(36,34,2000,true);
    

    //mogo 2 get ring 2 move to half way point to avoid hang post
    chassis.turnToPoint(56,58,1000,{},false);
    fast_move(56,58,1000,true);
    //mogo 2 move arm to load ring
    arm_move=false;
    global_target=1800;
    //mogo 2 get ring 2 move to ring
    set_intake_speed(127,false);
    fast_move(60.5,92,1000,true);
    // pros::delay(300);

    //mogo 2 task that when the ring is on the arm lift the arm up out of the way of other intaked rings
    pros::Task skills_task2{[=]
    {
        while(intake_distance.get_distance()>50) pros::delay(10);
        pros::delay(800);
        global_target=3000;
        set_intake_speed(-25);
        pros::delay(500);
        set_intake_speed(0);
    }};
    
    //mogo 2 move to stake
    chassis.moveToPoint(59,61,2000,{.forwards=false},false);
    chassis.turnToHeading(90,1000, {}, false);
    global_target=8000;
    // set_intake_speed(127);
    chassis.moveDistance(20,2000,{.maxSpeed = 60});
    chassis.waitUntil(12);
    set_intake_speed(127);
    global_target=15000;
    count = 0;
    while(arm_control.get_position()<11000 && chassis.isInMotion()) pros::delay(10);
    while(chassis.isInMotion()){
        if(count > 30){
            chassis.cancelMotion();
            break;
        } 
        count +=1;
        pros::delay(10);
    }

    //mogo 2 back away from stake and move arm back to start pos
    chassis.moveDistance(16,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3},false); 
    global_target=7000;
    

    //mogo 2 get 3 rings in a line
    set_intake_speed(127);
    chassis.turnToPoint(62,0.5,1000,{.minSpeed=3,.earlyExitRange=5});
    chassis.moveToPoint(62,0.5,2000,{.minSpeed=50,.earlyExitRange=20});
    chassis.moveToPoint(62,0.5,2000,{.maxSpeed=30},false);
    
    //mogo 2 get last ring and set up to drop off mogo
    chassis.turnToPoint(72, 9, 2000, {.minSpeed=5,.earlyExitRange=3},false);
    chassis.moveToPoint(72,9,2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.turnToHeading(-15,1000,{.minSpeed=5,.earlyExitRange=3});

    //mogo 2 score mogo
    chassis.moveDistance(9,1000,{.forwards=false},false);
    set_intake_speed(-127);
    mogo.set_value(true);
    pros::delay(200);

    //mogo 2 move away from corner
    chassis.moveDistance(5,1000,{.minSpeed=5,.earlyExitRange=3});
    global_target=100;

    //mogo 3 go through center and get ring 1 & 2
    // chassis.turnToHeading(-45, 2000, {}, false);
    // chassis.moveDistance(20, 1000, {.maxSpeed=80});

    // Original moveToPoints before changing to turnToHeading
    chassis.turnToPoint(-6.31,82.44,1000, {}, false);
    chassis.moveToPoint(-6.31,82.44,4000,{.maxSpeed=80,.minSpeed=5,.earlyExitRange=35});

    set_intake_speed(127,false);

    pros::Task skills_task5{[=]
        {
            while(intake_distance.get_distance()>50 &&chassis.isInMotion()) pros::delay(10);
            set_intake_speed(0);
        }};


    // Original moveToPoints before changing to turntoHeading
    chassis.moveToPoint(-6.31, 82.44, 2000,{.maxSpeed=70,.minSpeed=5,.earlyExitRange=25},false);
    chassis.moveToPoint(-6.31, 82.44, 2000,{.maxSpeed=65,.minSpeed=5,.earlyExitRange=15},false);
    chassis.moveToPoint(-6.31, 82.44, 2000,{.maxSpeed=45,.minSpeed=5,.earlyExitRange=8},false);
    chassis.moveToPoint(-6.31, 82.44, 2000,{.maxSpeed=30},false);

    //put ring in arm
    global_target=1800;
    pros::delay(1000);
    set_intake_speed(127,false);
    pros::delay(700);
    global_target=8000;
    set_intake_speed(-25);
    pros::delay(600);
    set_intake_speed(127);



    // pros::Task skills_task7{[=]
    //     {
    //         while(intake_distance.get_distance()>50) pros::delay(10);
    //         pros::delay(600);
    //         global_target=8000;
    //         // set_intake_speed(-25);
    //         // pros::delay(500);
    //         // set_intake_speed(127);
    //     }};

    // while(intake_distance.get_distance()>50) pros::delay(10);
    // set_intake_speed(-25);
    // set_intake_speed(-25);
    // pros::delay(700);
    // while(arm_control.get_position()<3600)pros::delay(10);

    //mogo 3 intake 2nd ring
    // set_intake_speed(127,false);
    chassis.moveDistance(20,1000, {.maxSpeed=50});

    pros::Task skills_task6{[=]
        {
            while(intake_distance.get_distance()>50 &&chassis.isInMotion()) pros::delay(10);
            set_intake_speed(0);
        }};

    // pros::Task skills_task3{[=]
    // {
    //     while(true){
    //         if(pros::Task::notify_take(true, 10)) break;
    //         if(distance.get_distance() < 100 || intake_distance.get_distance() < 100){
    //             set_intake_speed(0);
    //             break;
    //         }
    //     }
    // }};

    //get mogo 3
    chassis.turnToPoint(18,114,1000,{.forwards=false}, false);
    chassis.moveToPoint(18,114,4000,{.forwards=false,.maxSpeed=60}, false);
    while(!mogo_seated() && chassis.isInMotion()) pros::delay(10);
    pros::delay(100);
    mogo.set_value(false);
    // skills_task3.notify();
    set_intake_speed(127);

    //mogo 3 face alliance stake
    chassis.turnToHeading(0,1000,{},false);
    set_intake_speed(0);
    //mogo 3 score on alliance stake
    chassis.moveDistance(20,1000,{.maxSpeed = 70});
    chassis.moveDistance(8,1000,{.forwards=false}, false);
    // chassis.waitUntil(3);
    set_intake_speed(-25);
    arm_move=true;
    arm.move(127);
    pros::delay(1000);
    set_intake_speed(127);
    arm.brake();

    //mogo 3 get 2nd ring that dropped in front of alliance stake
    chassis.moveDistance(4,1000,{.forwards=false,.minSpeed=60,.earlyExitRange=3},false);
    arm_move=false;
    global_target=7000;

    // return;
    // chassis.moveDistance(14,1000,{.minSpeed=60,.earlyExitRange=3});
    // chassis.moveDistance(22,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    

    //mogo 3 get ring on far side
    // chassis.turnToPoint(-42,117,1000,{.minSpeed=3,.earlyExitRange=5});
    // fast_move(-42,117,3200,true);

    //mogo 3 move to 4th ring
    chassis.turnToPoint(40,87,1000,{.minSpeed=3,.earlyExitRange=5});
    // fast_move(8,107,2000,true);
    fast_move(40,87,2000,true);

    // fast_move(56,93,2000,true);

    // chassis.moveToPoint(38,95,1000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});

    //mogo 3 get 5th ring
    chassis.turnToPoint(57,111,1000,{.minSpeed=3,.earlyExitRange=5});
    fast_move(57,111,2000,true); 
    //mogo 3 get 6th ring
    chassis.turnToHeading(8,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(14,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(5,1000,{.forwards=false,.minSpeed=60});
    // chassis.moveToPoint(53,110,100,{.forwards=false,.minSpeed=60});
    chassis.moveToPoint(78,90,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});

    //mogo 3 swipe corner
    // chassis.turnToHeading(10,1000,{.minSpeed=5,.earlyExitRange=3},false);
    chassis.turnToPoint(78,122,1000,{.minSpeed=5,.earlyExitRange=3});
    swiper.set_value(true);
    pros::delay(500);
    // chassis.moveDistance(30,2000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveToPoint(78, 122, 2000,{.minSpeed=5,.earlyExitRange=3});
    pros::Task skills_task4{[=]
        {
            while(true){
                if(pros::Task::notify_take(true, 10)) break;
                if(intake_distance.get_distance() < 50){
                    pros::delay(800);
                    set_intake_speed(0);
                    break;
                }
            }
        }};
    
    chassis.turnToHeading(210,1000,{.direction=AngularDirection::CCW_COUNTERCLOCKWISE},false);
    left.move(127);
    right.move(-127);
    pros::delay(100);
    skills_task4.notify();
    //mogo 3 score mogo
    chassis.moveDistance(15,500,{.forwards=false});
    set_intake_speed(-127);
    mogo.set_value(true);
    chassis.moveDistance(20,1000,{.minSpeed=5,.earlyExitRange=3});
    set_intake_speed(127);
    swiper.set_value(false);

    //push mogo 4
    fast_move(-4,122,2000,true);
    set_intake_speed(-127);
    chassis.turnToHeading(-80,1000,{.minSpeed=5,.earlyExitRange=3});
    chassis.moveDistance(48,1500,{.minSpeed=100},false);
    set_intake_speed(60);
    // chassis.moveDistance(10,1000,{.forwards=false},false);

    return;
    //hang
    // chassis.turnToPoint(-20,92,1000,{.forwards=false,.minSpeed=20,.earlyExitRange=3});
    chassis.moveToPoint(-18,95,2000,{.forwards=false,.minSpeed=5,.earlyExitRange=3});
    chassis.waitUntil(15);
    global_target=20000;
    set_intake_speed(0);
    chassis.turnToHeading(313,1000,{.minSpeed=20,.earlyExitRange=3});
    chassis.moveDistance(50,1000,{.forwards=false,.maxSpeed=100});
    
    

    
    // -9 127 285
}

