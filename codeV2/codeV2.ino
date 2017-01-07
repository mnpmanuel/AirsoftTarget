/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
const int Led1yellowPin = 8;
const int Led1redPin = 7;
const int Led1greenPin = 6;
const int Led2yellowPin = 5;
const int Led2redPin = 4;
const int Led2greenPin = 3;
const int Led3yellowPin = 2;
const int Led3redPin = 1;
const int Led3greenPin = 0;
 
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

const int HeadSensor = A0;
const int TorsoSensor = A1;
const int LegSensor = A2;

//Adjust this value to change the sensitivity of the piezos
const int THRESHOLD = 100;
//Set this value to the number of microseconds you want each MIDI note to last for
const int LightsOn = 50;

// these variables will change:
int HeadSensorReading = 0;      // variable to store the value read from the sensor pin
int TorsoSensorReading = 0;      // variable to store the value read from the sensor pin
int LegSensorReading = 0;      // variable to store the value read from the sensor pin
int MozambiqueCount = 0;      //variable to count the shots required to enter competition mode
int MozambiqueCountExit = 0;    //variable to count the shots required to exit competition mode
int RandomTarget = 0;          //variable to decide the next target
int RandomTime = 0;          //variable to decide the delay until next random target
int hit = 0;                //variable to tell if the right target was hit
 
void setup()
{
  pinMode(Led1yellowPin, OUTPUT);
  pinMode(Led1redPin, OUTPUT);
  pinMode(Led1greenPin, OUTPUT);
  pinMode(Led2yellowPin, OUTPUT);
  pinMode(Led2redPin, OUTPUT);
  pinMode(Led2greenPin, OUTPUT);
  pinMode(Led3yellowPin, OUTPUT);
  pinMode(Led3redPin, OUTPUT);
  pinMode(Led3greenPin, OUTPUT); 
 
  Serial.begin(9600);
}
 
void loop()
{
  /*setColor(1, 0, 0);  // yellow
  delay(1000);*/
  setColor(0, 1, 0);  // red
  /*setColor(0, 0, 1);  // green
  delay(1000);*/
  
  // read the sensor and store it in the variable sensorReading:
  HeadSensorReading = analogRead(HeadSensor);
  TorsoSensorReading = analogRead(TorsoSensor);
  LegSensorReading = analogRead(LegSensor);
  
  // if the sensor reading is greater than the threshold:
  if (HeadSensorReading >= THRESHOLD) {
    // update the LED pin itself:
    digitalWrite(Led1yellowPin, 0);
    digitalWrite(Led1redPin, 0);
    digitalWrite(Led1greenPin, 1);
    delay(600);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock Head!");
    //one hit for the random mode
    MozambiqueCount = MozambiqueCount + 1;
  }
  
  // if the sensor reading is greater than the threshold:
  if (TorsoSensorReading >= THRESHOLD) {
    // update the LED pin itself:
    digitalWrite(Led2yellowPin, 0);
    digitalWrite(Led2redPin, 0);
    digitalWrite(Led2greenPin, 1);
    delay(600);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock Torso!");
  }
  
  // if the sensor reading is greater than the threshold:
  if (LegSensorReading >= THRESHOLD) {
    // update the LED pin itself:
    digitalWrite(Led3yellowPin, 0);
    digitalWrite(Led3redPin, 0);
    digitalWrite(Led3greenPin, 1);
    delay(600);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock Leg!");
  }
  
  if (MozambiqueCount >= 10) {
    while(MozambiqueCountExit < 10){
      setColor(0, 0, 0);  // lights out
      RandomTime = random(500, 4000);
      RandomTarget = random(1, 3);
      delay(RandomTime);
      
      switch (RandomTarget) {
        case 1:
          digitalWrite(Led1yellowPin, 1);
          digitalWrite(Led1redPin, 0);
          digitalWrite(Led1greenPin, 0);
          hit = 0;
          while (hit != 1) {
            // if the sensor reading is greater than the threshold:
            if (HeadSensorReading >= THRESHOLD) {
              // update the LED pin itself:
              wright;
              wright;
              wright;
              hit = 1;
            }
            // if the sensor reading is greater than the threshold:
            if (TorsoSensorReading >= THRESHOLD) {
              // update the LED pin itself:
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            // if the sensor reading is greater than the threshold:
            if (LegSensorReading >= THRESHOLD) {
              // update the LED pin itself:
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            if (hit = 3) {
              hit = 1; 
            }
          }
          break;
        
        case 2:
          digitalWrite(Led2yellowPin, 1);
          digitalWrite(Led2redPin, 0);
          digitalWrite(Led2greenPin, 0);
          hit = 0;
          while (hit != 1) {
            // if the sensor reading is greater than the threshold:
            if (TorsoSensorReading >= THRESHOLD) {
              // update the LED pin itself:
              wright;
              wright;
              wright;
              hit = 1;
            }
            // if the sensor reading is greater than the threshold:
            if (HeadSensorReading >= THRESHOLD) {
              // update the LED pin itself:
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            // if the sensor reading is greater than the threshold:
            if (LegSensorReading >= THRESHOLD) {
              // update the LED pin itself:
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            if (hit = 3) {
              hit = 1; 
            }
          }
          break;
        
        case 3:
          digitalWrite(Led3yellowPin, 1);
          digitalWrite(Led3redPin, 0);
          digitalWrite(Led3greenPin, 0);
          hit = 0;
          while (hit != 1) {
            // if the sensor reading is greater than the threshold:
            if (LegSensorReading >= THRESHOLD) {
              // update the LED pin itself:
              wright;
              wright;
              wright;
              hit = 1;
            }
            // if the sensor reading is greater than the threshold:
            if (HeadSensorReading >= THRESHOLD) {
              // update the LED pin itself:
              wrong;
              wrong;
              wrong;
              hit = hit + 1;
            }
            // if the sensor reading is greater than the threshold:
            if (TorsoSensorReading >= THRESHOLD) {
              // update the LED pin itself:
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            if (hit = 3) {
              hit = 1; 
            }
          }
          break;
        
        default:
          setColor(1, 0, 0);  // yellow
          break;
      }
    }
  }
  
  delay(10);  // delay to avoid overloading the serial port buffer
}
 
void setColor(int yellow, int red, int green)
{
  #ifdef COMMON_ANODE
    yellow = 1 - yellow;
    red = 1 - red;
    green = 1 - green;
  #endif
  digitalWrite(Led1yellowPin, yellow);
  digitalWrite(Led1redPin, red);
  digitalWrite(Led1greenPin, green);
  digitalWrite(Led2yellowPin, yellow);
  digitalWrite(Led2redPin, red);
  digitalWrite(Led2greenPin, green);
  digitalWrite(Led3yellowPin, yellow);
  digitalWrite(Led3redPin, red);
  digitalWrite(Led3greenPin, green);
}

void wright()
{
  digitalWrite(Led1yellowPin, 0);
  digitalWrite(Led1redPin, 0);
  digitalWrite(Led1greenPin, 1);
  digitalWrite(Led2yellowPin, 0);
  digitalWrite(Led2redPin, 0);
  digitalWrite(Led2greenPin, 1);
  digitalWrite(Led3yellowPin, 0);
  digitalWrite(Led3redPin, 0);
  digitalWrite(Led3greenPin, 1);
  delay(100);
}
void wrong()
{
  digitalWrite(Led1yellowPin, 0);
  digitalWrite(Led1redPin, 1);
  digitalWrite(Led1greenPin, 0);
  digitalWrite(Led2yellowPin, 0);
  digitalWrite(Led2redPin, 1);
  digitalWrite(Led2greenPin, 0);
  digitalWrite(Led3yellowPin, 0);
  digitalWrite(Led3redPin, 1);
  digitalWrite(Led3greenPin, 0);
  delay(100);
}
