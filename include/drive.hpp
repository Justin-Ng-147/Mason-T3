#ifndef _DRIVE_HPP_
#define _DRIVE_HPP_

#define LEFTMOTOR1PORT 1
#define LEFTMOTOR2PORT 5
#define LEFTMOTOR3PORT 2
#define RIGHTMOTOR1PORT 3
#define RIGHTMOTOR2PORT 6
#define RIGHTMOTOR3PORT 4

#define IMUPORT 12
#define VERTICALENCODERPORT 17
#define HORIZONTALENCODERPORT 18

extern lemlib::Chassis chassis;
extern pros::MotorGroup left;
extern pros::MotorGroup right;

#endif