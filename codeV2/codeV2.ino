/*
Airsoft Target System - by Manuel Palmeira
This system uses piezos and RGY LEDs. For more information on this project and the circuit please check out the
instructibles page.

Feel free to use and change this code. Just don't use it to exploit others.
Since I just need simple colors (the 3 primary ones with the LED), I've coded the colors in a ON/OFF base.
If you want to have more color variations make sure to connect the LEDs to PWM pins and change the values on the
color functions according to the color that you want.
*/

//setting the pins for the LED interface
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

//setting the pins for the piezos input.
const int HeadSensor = A0;
const int TorsoSensor = A1;
const int LegSensor = A2;

//Adjust this value to change the sensitivity of the piezos
const int THRESHOLD = 50;

// these variables will change:
int HeadSensorReading = 0;      // variable to store the value read from the sensor pin
int TorsoSensorReading = 0;      // variable to store the value read from the sensor pin
int LegSensorReading = 0;      // variable to store the value read from the sensor pin
int RandomON = 0;              //variable to count the shots required to enter competition mode
int RandomOFF = 0;             //variable to count the shots required to exit competition mode
int RandomTarget = 0;          //variable to decide the next target
int RandomTime = 0;          //variable to decide the delay until next random target
int hit = 0;                //variable to tell if the right target was hit
unsigned long StartTime;       //variable to know when the target started to be active
unsigned long ActualTime;       //variable to know what time it is
unsigned long Timeout;       //variable to know if the target has been active for too long
 
void setup()
{
  //set the LED pins as outputs
  pinMode(Led1yellowPin, OUTPUT);
  pinMode(Led1redPin, OUTPUT);
  pinMode(Led1greenPin, OUTPUT);
  pinMode(Led2yellowPin, OUTPUT);
  pinMode(Led2redPin, OUTPUT);
  pinMode(Led2greenPin, OUTPUT);
  pinMode(Led3yellowPin, OUTPUT);
  pinMode(Led3redPin, OUTPUT);
  pinMode(Led3greenPin, OUTPUT); 
}
 
void loop()
{
  //standart mode, all targets are red
  setColor(0, 1, 0);  // red
  
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
    //  one hit for the random mode
    RandomON = RandomON + 1;
  }
  
  // if the sensor reading is greater than the threshold:
  if (TorsoSensorReading >= THRESHOLD) {
    // update the LED pin itself:
    digitalWrite(Led2yellowPin, 0);
    digitalWrite(Led2redPin, 0);
    digitalWrite(Led2greenPin, 1);
    delay(600);
  }
  
  // if the sensor reading is greater than the threshold:
  if (LegSensorReading >= THRESHOLD) {
    // update the LED pin itself:
    digitalWrite(Led3yellowPin, 0);
    digitalWrite(Led3redPin, 0);
    digitalWrite(Led3greenPin, 1);
    delay(600);
  }
  
  //  entered random game mode
  if (RandomON >= 10) {
    //  you have 10 targets to take out before the game mode ends
    while(RandomOFF < 10){
      setColor(0, 0, 0);  // lights out
      RandomTime = random(500, 4000);  // set a random time to present next target between 500ms and 4s
      RandomTarget = random(1, 3);  // set a random target
      
      delay(RandomTime);
      switch (RandomTarget) {
        case 1:
          //  start timer
          StartTime = millis();
          hit = 0;  // reset the number of times the target has been hit. you have 3 shots until it moves to the next one
          while (hit != 1) {
            //  light the target to hit
            digitalWrite(Led1yellowPin, 1);
            digitalWrite(Led1redPin, 0);
            digitalWrite(Led1greenPin, 0);
            ActualTime = millis();  // measure the actual time
            Timeout = ActualTime - StartTime;   // calculate the time that has passed since the target was active
            //if the target has been active for too long (more than 45s), you've timed out
            if (Timeout >= 45000) {
              hit = 1;
            }
            
            // if the target is hit
            if (HeadSensorReading >= THRESHOLD) {
              // flash green lights 3 times
              wright;
              wright;
              wright;
              hit = 1;
            }
            // if you hit the wrong target
            if (TorsoSensorReading >= THRESHOLD) {
              // flash red lights 3 times
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            // if you hit the wrong target
            if (LegSensorReading >= THRESHOLD) {
              // flash red lights 3 times
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            //  if the maximum amount of tries has passed, move to the next target
            if (hit = 3) {
              wrong;
              wrong;
              wrong;
              hit = 1; 
            }
          }
          //  one less target to the end of random mode
          RandomOFF = RandomOFF + 1;
          break;
        
        case 2:
          //  start timer
          StartTime = millis();
          hit = 0;  // reset the number of times the target has been hit. you have 3 shots until it moves to the next one
          while (hit != 1) {
            //  light the target to hit
            digitalWrite(Led2yellowPin, 1);
            digitalWrite(Led2redPin, 0);
            digitalWrite(Led2greenPin, 0);
            ActualTime = millis();  // measure the actual time
            Timeout = ActualTime - StartTime;   // calculate the time that has passed since the target was active
            //if the target has been active for too long (more than 45s), you've timed out
            if (Timeout >= 45000) {
              hit = 1;
            }
            
            // if the target is hit
            if (TorsoSensorReading >= THRESHOLD) {
              // flash green lights 3 times
              wright;
              wright;
              wright;
              hit = 1;
            }
            // if you hit the wrong target
            if (HeadSensorReading >= THRESHOLD) {
              // flash red lights 3 times
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            // if you hit the wrong target
            if (LegSensorReading >= THRESHOLD) {
              // flash red lights 3 times
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            //  if the maximum amount of tries has passed, move to the next target
            if (hit = 3) {
              wrong;
              wrong;
              wrong;
              hit = 1; 
            }
          }
          //  one less target to the end of random mode
          RandomOFF = RandomOFF + 1;
          break;
        
        case 3:
          //  start timer
          StartTime = millis();
          hit = 0;  // reset the number of times the target has been hit. you have 3 shots until it moves to the next one
          while (hit != 1) {
            //  light the target to hit
            digitalWrite(Led3yellowPin, 1);
            digitalWrite(Led3redPin, 0);
            digitalWrite(Led3greenPin, 0);
            ActualTime = millis();  // measure the actual time
            Timeout = ActualTime - StartTime;   // calculate the time that has passed since the target was active
            //if the target has been active for too long (more than 45s), you've timed out
            if (Timeout >= 45000) {
              hit = 1;
            }
            
            // if the target is hit
            if (LegSensorReading >= THRESHOLD) {
              // flash green lights 3 times
              wright;
              wright;
              wright;
              hit = 1;
            }
            // if you hit the wrong target
            if (HeadSensorReading >= THRESHOLD) {
              // flash red lights 3 times
              wrong;
              wrong;
              wrong;
              hit = hit + 1;
            }
            // if you hit the wrong target
            if (TorsoSensorReading >= THRESHOLD) {
              // flash red lights 3 times
              wrong;
              wrong;
              wrong;
              hit = hit + 1; 
            }
            //  if the maximum amount of tries has passed, move to the next target
            if (hit = 3) {
              wrong;
              wrong;
              wrong;
              hit = 1; 
            }
          }
          //  one less target to the end of random mode
          RandomOFF = RandomOFF + 1;
          break;
        
        default:
          setColor(0, 0, 0);  // lights out
          break;
      }
      //  to exit the random mode just shoot any target. each shot here counts for 2 targets
      if (HeadSensorReading >= THRESHOLD && TorsoSensorReading >= THRESHOLD && LegSensorReading >= THRESHOLD) {
        setColor(1, 0, 0);  // yellow
        delay(500);
        RandomOFF = RandomOFF + 2;
      }
    }
    RandomON = 0;
  }
  
  delay(10);  // delay to avoid overloading the serial port buffer
}

//easy way to set the color on the LEDs 
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

//function to flash green light
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

//function to flash red light
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
