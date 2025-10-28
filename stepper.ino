#include <AccelStepper.h>
#define X_STEP_PIN 2
#define X_DIR_PIN 3
#define X_LIMIT_PIN 6
#define Y_STEP_PIN 4
#define Y_DIR_PIN 5
#define Y_LIMIT_PIN 7
#define GRIPPER_PIN 9
#define STEPS_PER_REV 200
#define MICROSTEPS 16
#define MAX_SPEED 1000.0
#define ACCELERATION 1000.0
AccelStepper xMotor(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);
AccelStepper yMotor(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN);
void setup() {
xMotor.setMaxSpeed(MAX_SPEED);
xMotor.setAcceleration(ACCELERATION);
yMotor.setMaxSpeed(MAX_SPEED);
yMotor.setAcceleration(ACCELERATION);
pinMode(X_LIMIT_PIN, INPUT_PULLUP);
pinMode(Y_LIMIT_PIN, INPUT_PULLUP);
pinMode(GRIPPER_PIN, OUTPUT)
homeMotors();
Serial.begin(9600);
}
void loop() {
if (Serial.available()) {
float xAngle = Serial.parseFloat();
float yAngle = Serial.parseFloat();
yAngle= -1*yAngle;
Serial.print("angle x:");
Serial.print(xAngle,'\n');
Serial.print(" angle y:");
Serial.println(yAngle,'\n');
if( xAngle>0 &&yAngle<0 )
{int xPos = angleToPosition(xAngle);
int yPos = angleToPosition(yAngle);
xMotor.moveTo(xPos);
yMotor.moveTo(yPos);}
while (xMotor.run() || yMotor.run()) {}
