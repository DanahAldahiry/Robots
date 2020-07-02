#include <Servo.h>
Servo motor_1;
Servo motor_2;
float theta_1; // angle in degree.
float theta_2; // angle in degree.
float L1;
float L2;
float x_coor;
float y_coor;
float theta;
float theta_r;
float theta_r1; // angle in radian.
float theta_r2; // angle in radian.
float x_coor_2;
float y_coor_2;
float L1_2;
float L2_2;
// Two ways of calculating the movement of the arm:
// 1- Forward Kinematic: by finding the values of (x & y).
// 2- Inverse Kinematic: by finding the values of (theta_1 & theta_2).

int calculate; // the choice between forward or inverse kinematic.
void setup()
{
Serial.begin(9600);
motor_1.attach(9);
motor_2.attach(8);
Serial.println("Enter the calculation method: (1) forward/(10) Inverse");
while (Serial.available()==0){}
calculate=Serial.parseInt();
// Method 1: Forward Kinematic
if (calculate==1){
  Serial.println("Enter the 1st length L1: ");
  while (Serial.available()==0){}
  L1=Serial.parseFloat();
  Serial.println("Enter the 2nd length L2: ");
  while (Serial.available()==0){}
  L2=Serial.parseFloat();
  Serial.println("Enter the 1st angle: ");
  while (Serial.available()==0){};
  theta_1=Serial.parseFloat(); 
  theta_r1=theta_1*3.14/180;
  Serial.println("Enter the 2nd angle: ");
  while (Serial.available()==0) {};
  theta_2=Serial.parseFloat();
  // degree to radian.
  theta_r2=theta_2*3.14/180;
   Serial.println(theta_r1);
   Serial.println(theta_r2);
  // calculate the x coordinat value.
  x_coor=L1*cos(theta_r1)+L2*cos(theta_r1+theta_r2);
  Serial.print("x coordinate= ");
  Serial.println(x_coor);
  // calculate the y coordinate value.
  y_coor=L1*sin(theta_r1)+L2*sin(theta_r1+theta_r2);
  Serial.print("y coordinate= ");
   Serial.println(y_coor);
  }
    
else if (calculate==10){
  Serial.println("Enter the 1st length L1: ");
  while (Serial.available()==0){}
  L1=Serial.parseFloat();
  Serial.println("Enter the 2nd length L2: ");
  while (Serial.available()==0){}
  L2=Serial.parseFloat();   
  Serial.println("Enter the angle: ");
  while (Serial.available()==0) {};
  theta=Serial.parseFloat();
  Serial.println("Enter the x coordinate: ");
  while (Serial.available()==0){};
  x_coor=Serial.parseFloat();
  Serial.println("Enter the y coordinate: ");
  while (Serial.available()==0){};
  y_coor=Serial.parseFloat();
  // calculate theta_2:
   x_coor_2=pow(x_coor,2);
   y_coor_2=pow(y_coor,2);
   L1_2=pow(L1,2);
   L2_2=pow(L2,2);
  float n= x_coor_2+y_coor_2-L1_2-L2_2; // the equation's numerator.
  float d=2*L1*L2; // the equation's denominator.
  theta_r2= acos(n/d);
  theta_2=theta_r2*180/3.14;
  Serial.print("the 2nd angle= ");
  Serial.println(theta_2);
  Serial.print("the 1st angle= ");
  theta_1=theta-theta_2;
  Serial.println(theta_1);
}
}

void loop()
{
  motor_1.write(theta_1);
  motor_2.write(theta_2);
 
}
