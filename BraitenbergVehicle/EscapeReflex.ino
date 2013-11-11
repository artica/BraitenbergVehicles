// activates the escape reflex, given a bumper pin number
void EscapeReflex(int bumperPin)
{
  // drive back for some amount of time
  DriveMotors(-LeftMaxSpeed, -RightMaxSpeed);
  delay(500);
  
  // if the left bumper was activated, turn to the right
  if (bumperPin == LeftBumperPin)
  {
    DriveMotors(-LeftMaxSpeed, RightMaxSpeed);
  }
  
  // if the right bumper was activated, turn to the left
  if (bumperPin == RightBumperPin)
  {
    DriveMotors(LeftMaxSpeed, -RightMaxSpeed);
  }
  
  // wait for turn to finish
  delay(250);
}
