#include "main.h"

pros::Task *sort_task = nullptr;
int intake_speed = 0;
int sorting = 0;

pros::vision_signature_s_t RED_SIG =
    pros::Vision::signature_from_utility(1, 11049, 12603, 11826, -1625, -703, -1164, 5, 0);

pros::vision_signature_s_t BLUE_SIG =
    pros::Vision::signature_from_utility(2, -3785, -3395, -3590, 5827, 7261, 6544, 6.000, 0);

void setup()
{
  // vision.set_signature(1, &RED_SIG);
  // vision.set_signature(2, &BLUE_SIG);
  // intake.set_encoder_units_all(pros::E_MOTOR_ENCODER_ROTATIONS);
  // vision.get_object_count();
  // pros::delay(100);
  // sort_thrower.set_value(true);
  ring_color.set_led_pwm(100);
  ring_color.set_integration_time(20);
  pros::delay(30);
}

/*
 *return 1 if ready to be tossed
 *return 2 if already tossed
 *return 0 if none
 */
int ring_tossed(double start)
{
  double dif = fabs(intake.get_position()) - fabs(start);
  // printf("%f\n",dif);
  if (dif > 1.2)
    return 2;
  else if (dif > 0)
    return 1;
  else
    return 0;
}

void sort(int color_type)
{
  if (sort_task == nullptr)
  {
    sort_task = new pros::Task{[=]
    {
      ring_color.set_integration_time(20);
      ring_color.set_led_pwm(100);
      // intake.set_brake_mode_all(MOTOR_BRAKE_HOLD);
      bool color = false;
      
      while(true){
        // printf("R:%f G:%f B:%f\ distance:%d \n",ring_color.get_rgb().red,ring_color.get_rgb().green,ring_color.get_rgb().blue,ring_color.get_proximity());
        // printf("%f\n",ring_color.get_rgb().red-ring_color.get_rgb().blue);
        // if(ring_color.get_rgb().red-ring_color.get_rgb().blue > 100 ) color = true;
        if(color_type==1)
          if((ring_color.get_hue()>330 || ring_color.get_hue()<30) && top_distance.get_distance()<30) color = true;
        if(color_type==2)
          if((ring_color.get_hue()>210 && ring_color.get_hue()<270) && top_distance.get_distance()<30) color = true;
        if(color){
          int prev_intake_speed = intake_speed;
          // pros::delay(10);
          sorting = 1;
          // int start = intake.get_position();
          // while(abs(intake.get_position()-start)<50) pros::delay(5);
          sorting = 2;
          // intake.brake();
          pros::delay(1000);
          sorting = 0;
          pros::delay(100);
          color = false;
          // set_intake_speed(prev_intake_speed);
        }
        pros::delay(10);
      }
    }};
  }
}

bool mogo_seated()
{
  return mogo_distance.get_distance() < 25;
}


bool antijam = true;
pros::Task *intake_task = nullptr;

void init_intake()
{
  if (intake_task == nullptr)
  {
    intake_task = new pros::Task{[=]
                                 {
                                   int count = 0;
                                   int prev_speed = 0;
                                   while (!pros::Task::notify_take(true, 10))
                                   {
                                     int speed = intake_speed;
                                     bool antijam_temp = antijam;
                                     if(sorting == 0)
                                      intake.move(speed);
                                     else if(sorting == 1){
                                      intake.move(0);
                                     }
                                     else if(sorting == 2)
                                      intake.move(-60);
                                     if (speed != prev_speed)
                                       pros::delay(100);
                                     prev_speed = speed;

                                     if (speed > 0 && intake.get_efficiency() < 1 && antijam_temp)
                                     {
                                       count += 1;
                                     }
                                     if (count > 10 && antijam_temp)
                                     {
                                       intake.move(-127);
                                       pros::delay(500);
                                       intake.move(0);
                                       prev_speed = 0;
                                       count = 0;
                                     }
                                   }
                                 }};
  }
}

void set_intake_speed(int speed, bool jam)
{
                            intake_speed = speed;
                            antijam = jam;
  // intake_task2.remove();
  // delete &intake_task2;
}

void fast_move(float x, float y, int timeout, bool async = true)
{
  chassis.moveToPoint(x, y, timeout, {.minSpeed = 5, .earlyExitRange = 10});
  chassis.moveToPoint(x, y, timeout, {.maxSpeed = 30, .minSpeed = 5, .earlyExitRange = 3}, async);
}

// void init_driver_intake(){
//     pros::Task driver_intake{[=]{
//       while(true){
//         if(master.get_digital(DIGITAL_R1)){
//           intake_control.lock();
//           intake.move(127);
//           intake_control.unlock();
//           // set_intake_speed(127);
//         }
//         else if(master.get_digital(DIGITAL_R2)){
//           intake_control.lock();
//           intake.move(-127);
//           intake_control.unlock();
//           // set_intake_speed(-127);
//         }
//         else{
//           sort_task->notify();
//           intake_control.lock();
//           intake.move(0);
//           intake_control.unlock();
//           // set_intake_speed(0);
//         }
//       }
//     }};
// }

int global_target = 0;
bool arm_move = true;

void arm_to_pos()
{
  pros::Task arm_task_0{[=]
    {
      lemlib::PID arm_pid(.07,0,.2);
      arm_pid.reset();
      arm.set_brake_mode_all(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
      int target;
      int pos = arm_control.get_position();
      int error = target - pos;
      int prev_error = error;
      float speed;
      int count = 0;
      int prev_target;
      while (true)
      {

        target = global_target;
        pos = arm_control.get_position();
        error = target - pos;
        if(prev_target!=target || arm_move){
          count = 0;
          prev_error = error;
        }
        prev_target = target;
        // if(abs(error)<100) error = 0;
        speed = arm_pid.update(error);
        if (speed > 127)
          speed = 127;
        if (speed < -127)
          speed = -127;
        if(count < 1){
          if (!arm_move)
            arm.move(speed);
          // if(abs(error)<300)
          if(error*prev_error<0)
              count++;
        }
        else{
          if (!arm_move)
            arm.brake();
        }
        prev_error = error;
        pros::delay(10);
      }
    }};
}