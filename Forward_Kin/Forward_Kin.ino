#include <Servo.h>
#include <math.h>

int i, j, k; //Generic variables for loops

const int DOF = 6; // Defines degrees of freedom
int pwm_pins[] = {11, 10, 9, 6, 5, 3}; // Available pwm pins
Servo Joints [6]; // Number of joints

float jointAngles [6]; // Array to store joint angles

void calculate_joint_angles(double t){
  // Implement forward kinematics
  int jointAmp = 80;
  for(i = 0; i < DOF; i++){
    jointAngles[i] = jointAmp*sin(t);
    Serial.print(jointAngles[i]);
    Serial.print('\t');
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);
  for(i = 0; i < DOF; i++){
    Joints[i].attach(pwm_pins[i]);
  }
}

void loop() { 
  for(i = 0; i < DOF; i++){
    Joints[i].write(jointAngles[i]);
  }
  calculate_joint_angles(millis());
  //update_joints();
  if(Serial.read() == 115) {
    while(Serial.read() != 115){      
    }
  }
  delay(10);
}
