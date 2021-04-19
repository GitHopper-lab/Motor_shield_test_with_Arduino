#include <Servo.h>
#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
Servo servo1;

const int trigPin = 4;
const int echoPin = 3;

long duration;
int distance;
int left, right, front;

void setup() {
  
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);

  pinMode(5,INPUT);
  servo1.attach(9);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

}


void loop() {
  sonor();  
motorpause();
delay(3000);

motorforward();
delay(3000);

motorbackward();
delay(3000);

motorleft();
delay(3000);

motorright();
delay(3000);
}


void sonor()
{
  digitalWrite(trigPin, LOW); //CLEARE THE TRIGPIN
  delayMicroseconds(2);//SET THE TRIGPIN ON HIGH STATE FOR 10 SECONDS

  digitalWrite(trigPin, HIGH); //WRITE THE TRIGGER FOR MCU ON MODULE
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //READS THE ECHOPIN, RETURNS THE SOUND WAVE TRAVEL TIME IN MICROSECONDS

  duration = pulseIn(echoPin, HIGH); //USING THE FORMULA
  distance = duration * 0.034 / 2;
  
}


void motorpause()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
void motorforward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
void motorbackward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}
void motorleft()
{
    motor1.run(RELEASE);
    motor2.run(FORWARD);
}
void motorright()
{
    motor1.run(FORWARD);
    motor2.run(RELEASE);
}
