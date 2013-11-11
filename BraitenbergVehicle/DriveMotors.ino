// updates the drive on the left and right motors
void DriveMotors(int leftDrive, int rightDrive)
{
 if (leftDrive > 0) 
 {  
  analogWrite(MotorA0Pin, leftDrive);
  digitalWrite(MotorA1Pin, LOW);
 }
 
 if (leftDrive < 0) 
 {  
  digitalWrite(MotorA0Pin, LOW);
  analogWrite(MotorA1Pin, map(leftDrive, 0, -255, 0, 255));
 }
 
 if (leftDrive == 0) 
 {  
  digitalWrite(MotorA0Pin, LOW);
  digitalWrite(MotorA1Pin, LOW); 
 }
  
 if (rightDrive > 0 ) 
 {
  analogWrite(MotorB0Pin, rightDrive);
  digitalWrite(MotorB1Pin, LOW);
 }
 
 if (rightDrive < 0 ) 
 {
  digitalWrite(MotorB0Pin, LOW);
  analogWrite(MotorB1Pin, map(rightDrive, 0, -255, 0, 255));
 }
 
 if (rightDrive == 0)
 {
  digitalWrite(MotorB0Pin, LOW);
  digitalWrite(MotorB1Pin, LOW);
 }
}

