#include "main.h"
#include "pros/adi.hpp"


pros::MotorGroup intake({-7,10});
pros::Motor arm(9);
pros::ADIDigitalOut mogo('A');
pros::ADIDigitalOut twopto('B');
pros::ADIDigitalOut swiper('C');
pros::ADIDigitalOut hangpto('D');
pros::ADIDigitalOut push('E');

pros::Rotation arm_control(19);
pros::Distance distance(8);
pros::Distance intake_distance(16);
pros::Distance mogo_distance(15);
pros::Optical ring_color(1);
pros::Rotation intake_control(20);

pros::Controller master(pros::E_CONTROLLER_MASTER);

