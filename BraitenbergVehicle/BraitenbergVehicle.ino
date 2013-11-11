// ------------------ HARDWARE MAPPING CONSTANTS --------------------//

// ----------- Excitatory/Inhibitory Pins -------------- //
int LeftMotorExcitatoryPin = 1;
int RightMotorExcitatoryPin = 2;
int LeftMotorInhibitoryPin = 3;
int RightMotorInhibitoryPin = 4;

// ----------- Motor  Pins -------------- //
int MotorA0Pin = 6;
int MotorA1Pin = 11;
int MotorB0Pin = 3;
int MotorB1Pin = 5;

// ----------- Bumper  Pins ------------- //
int LeftBumperPin = 8;
int RightBumperPin = 7;

// ------------------ CALIBRATION CONSTANTS -------------------- //
// -- VARY THE MAXIMUM VALUES TO GET THE ROBOT TO GO STRAIGHT -- //
int LeftMaxSpeed = 255;
int RightMaxSpeed = 255;
int LeftMinSpeed = 0;
int RightMinSpeed = 0;

// --------------------- SENSOR VARIABLES ---------------------- //

// ----------- Excitation/Inhibition -------------- //
int leftMotorInhibition;
int rightMotorInhibition;
int leftMotorExcitation;
int rightMotorExcitation;

// --------------- Bumper State -------------- //
int leftBumperState;
int rightBumperState;


// ---------------------- MOTOR VARIABLES ----------------------- //

// ------------- Motor Drive ---------------- //
int leftMotorDrive;
int rightMotorDrive;


// ----------------------- INITIALIZATION ----------------------- //
void setup()
{
  Serial.begin(9600);
  
  //declare motor pins as outputs
  pinMode(MotorA0Pin, OUTPUT);
  pinMode(MotorA1Pin, OUTPUT);
  pinMode(MotorB0Pin, OUTPUT);
  pinMode(MotorB1Pin, OUTPUT);

  // declare frontal bumpers as inputs
  pinMode (LeftBumperPin, INPUT);
  pinMode (RightBumperPin, INPUT);  
  
  // activate internal resistance of bumper pins
  digitalWrite(LeftBumperPin, HIGH);
  digitalWrite(RightBumperPin, HIGH);
  
  delay(1000);
}

// ------------------------ CONTROL LOOP ------------------------- //
void loop()
{
  // Sample excitation/inhibition levels
  leftMotorExcitation = analogRead (LeftMotorExcitatoryPin);
  rightMotorExcitation = analogRead (RightMotorExcitatoryPin);
  leftMotorInhibition = analogRead (LeftMotorInhibitoryPin);
  rightMotorInhibition = analogRead (RightMotorInhibitoryPin);
    
  // Sample bumper state
  leftBumperState = digitalRead(LeftBumperPin);
  rightBumperState = digitalRead(RightBumperPin);

  // Map excitation levels to motor drive
  leftMotorDrive = map (leftMotorExcitation, 0, 1023, LeftMinSpeed, LeftMaxSpeed);
  rightMotorDrive = map (rightMotorExcitation, 0, 1023, RightMinSpeed, RightMaxSpeed);

  // Suppress motor drive according to current inhibition levels
  leftMotorDrive -= map (leftMotorInhibition, 0, 1023, LeftMinSpeed, LeftMaxSpeed);
  rightMotorDrive -= map (rightMotorInhibition, 0, 1023, RightMinSpeed, RightMaxSpeed);
    
  DriveMotors(leftMotorDrive, rightMotorDrive);
  delay(10);
}

