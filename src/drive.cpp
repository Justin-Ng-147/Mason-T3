#include "main.h"


pros::MotorGroup left({LEFTMOTOR1PORT,-LEFTMOTOR2PORT,-LEFTMOTOR3PORT},pros::MotorGearset::blue);
pros::MotorGroup right({-RIGHTMOTOR1PORT,RIGHTMOTOR2PORT,RIGHTMOTOR3PORT},pros::MotorGearset::blue);

pros::Imu imu(IMUPORT);
pros::Rotation vertical_enc(-VERTICALENCODERPORT);
pros::Rotation horizontal_enc(-HORIZONTALENCODERPORT);

lemlib::Drivetrain drivetrain(&left, 
                              &right,
                              12.625, //track width
                              lemlib::Omniwheel::NEW_275, //wheel type
                              450, //rpm
                              2); //horizontal drift

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_enc,lemlib::Omniwheel::NEW_2, -2.25); //3.625 3.25 2.75
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_enc,lemlib::Omniwheel::NEW_2, .0625);

lemlib::OdomSensors sensors(&vertical_tracking_wheel,nullptr,&horizontal_tracking_wheel,nullptr,&imu);

lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              60, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

lemlib::ControllerSettings angular_controller(5.3, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              53, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              300, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);


lemlib::Chassis chassis(drivetrain,
                    lateral_controller,
                    angular_controller,
                    sensors);






