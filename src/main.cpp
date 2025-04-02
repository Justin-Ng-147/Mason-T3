#include "main.h"




/*
true: display odometry data and will run the test auton
false: display competition screen to choose different autons
*/
bool testing = false;

int auton_status = 0;
int test_auton = -1;



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::delay(100);

	// chassis = init_drive();
	chassis.calibrate();
    pros::delay(100);
    // chassis.setPose(0,0,146);
	chassis.setPose(0,0,0);
	// chassis.setPose(0,0,-12);

	arm_to_pos();
	arm_control.set_position(0);
	mogo.set_value(true);
	intake.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_COAST);
	// sort(1);
	init_intake();
	// while(true){
    //     printf("%d\n",ring_color.get_proximity());
    //     pros::delay(10);
    //   }

	// sort_thrower.set_value(true);

	if(testing){
		// if (test_auton < 0) sort(REDCOLOR);
		// else sort(BLUECOLOR);
		pros::Task screen_task([&]() {
			while (true) {
				// print robot location to the brain screen
				pros::lcd::print(1, "X: %f", chassis.getPose().x); // x
				pros::lcd::print(2, "Y: %f", chassis.getPose().y); // y
				pros::lcd::print(3, "Theta: %f", chassis.getPose().theta); // heading
				// delay to save resources
				pros::delay(20);
			}
		});
	}
	else{
		chooser(auton_status);
		// if (auton_status < 0) sort(REDCOLOR);
		// else sort(BLUECOLOR);
		pros::lcd::set_text(1, "auton chosen");
	}

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	// if(!testing){
	// 	chooser(auton_status);
	// 	pros::lcd::set_text(1, "auton chosen");
	// }
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	if(testing) run_auton(test_auton);
	else run_auton(auton_status);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// intake_task->remove();
	
	arm.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
	left.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
    right.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_BRAKE);
	// mogo.set_value(true);

	bool pto_flag = true;
	bool pto_pressed = true;
	bool mogo_flag = true;
	bool mogo_pressed = true;
	bool claw_flag = true;
	bool claw_pressed = true;
	bool hang_flag = true;
	bool hang_pressed = true;
	bool deploy_flag = true;
	bool deploy_pressed = true;
	bool swiper_flag = false;
	bool swiper_pressed = true;

	bool b_pressed = true;
	bool y_pressed = true;

	bool arm_pressed = true;

	// if (intake_task != nullptr) {
	// 	intake_task->notify();
	// }
	// init_driver_intake();

	while (true) {
		#pragma region arcade
		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		left.move(dir+turn);
		right.move(dir-turn);
		#pragma endregion arcade

		
		if(master.get_digital(DIGITAL_L1)){
			if(!arm_pressed){
				arm.move(127);
				// intake.move(-127);
				set_intake_speed(-25);
				pros::delay(40);
				// intake.move(0);
				set_intake_speed(0);
				arm_pressed = true;
			}
			arm_move = true;
			arm.move(127);
			global_target=1;
		}
		else if(master.get_digital(DIGITAL_L2)){
			arm_move = true;
			arm.move(-127);
			global_target=1;
		}
		else if(master.get_digital(DIGITAL_L1) != 1 && arm_pressed){
			arm_pressed = false;
		}
		else{
			if(arm_move){
				arm.brake();
				global_target=1;
			}
		}



		#pragma region intake r1
		if(master.get_digital(DIGITAL_R1)){
			// intake.move(127);
			set_intake_speed(127,false);
		}
		else if(master.get_digital(DIGITAL_R2)){
			// intake.move(-127);
			set_intake_speed(-127,false);
		}
		else{
			// intake.move(0);
			set_intake_speed(0,false);
		}
		#pragma endregion intake


		#pragma region mogo x
		if(master.get_digital(DIGITAL_DOWN) && !mogo_pressed){
			mogo_flag = !mogo_flag;
			mogo.set_value(mogo_flag);
			mogo_pressed = true;
		}
		else if(master.get_digital(DIGITAL_DOWN) != 1 && mogo_pressed){
			mogo_pressed = false;
		}

		
		// else if(mogo_seated() && !mogo_flag && !mogo_pressed)
		// {
		// 	mogo.set_value(true);
		// 	mogo_flag = true;
		// }

		if(master.get_digital(DIGITAL_X) && !hang_pressed){
			hang_flag = !hang_flag;
			intake_lift.set_value(hang_flag);
			hang_pressed = true;
		}
		else if(master.get_digital(DIGITAL_X) != 1 && hang_pressed){
			hang_pressed = false;
		}
		
		#pragma endregion mogo

		if(master.get_digital(DIGITAL_RIGHT) && !swiper_pressed){
			swiper_flag = !swiper_flag;
			swiper.set_value(swiper_flag);
			swiper_pressed = true;
		}
		else if(master.get_digital(DIGITAL_RIGHT) != 1 && swiper_pressed){
			swiper_pressed = false;
		}


		#pragma region swiper b
		// if(master.get_digital(DIGITAL_B) && !swiper_pressed){
		// 	swiper_flag = !swiper_flag;
		// 	swiper.set_value(swiper_flag);
		// 	swiper_pressed = true;
		// }
		// else if(master.get_digital(DIGITAL_B) != 1 && swiper_pressed){
		// 	swiper_pressed = false;
		// }
		if(master.get_digital(DIGITAL_B) && !b_pressed){
			// swiper_flag = !swiper_flag;
			b_pressed = true;
			arm_move=false;
			
		
			global_target=100;
			// global_target=5000;
			
		}
		else if(master.get_digital(DIGITAL_B) != 1 && b_pressed){
			b_pressed = false;
		}

		if(master.get_digital(DIGITAL_Y) && !y_pressed){
			// hang_flag = !hang_flag;
			y_pressed = true;
			arm_move=false;
			

			global_target=3200;
		}
		else if(master.get_digital(DIGITAL_Y) != 1 && y_pressed){
			y_pressed = false;
		}

		if(master.get_digital(DIGITAL_LEFT)){
			chassis.moveDistance(8,1000,{.forwards=false});
			chassis.waitUntil(4);
			set_intake_speed(-25);
			arm_move=true;
			arm.move(127);
			pros::delay(1000);
			set_intake_speed(127);
			arm.move(0);
		}

		

		// if(master.get_digital(DIGITAL_DOWN) && !deploy_pressed){
		// 	deploy_flag = !deploy_flag;
		// 	deploy.set_value(deploy_flag);
		// 	deploy_pressed = true;
		// }
		// else if(master.get_digital(DIGITAL_DOWN) != 1 && deploy_pressed){
		// 	deploy_pressed = false;
		// }
		
		#pragma endregion swiper
		pros::delay(20);                               // Run for 20 ms then update
	}
}