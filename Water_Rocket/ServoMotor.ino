#ifdef ServoMotor

#define Servo_Pin 6 // PWM pin out for control to the servomotor

Servo SERVO; // Objecte for control 


void Servo_Setup()
{ 
  SERVO.attach(Servo_Pin);
  SERVO.write(0); // Setpoint inicialization
}


void Servo_Control()
{
  SERVO.write(90);
}

#endif
