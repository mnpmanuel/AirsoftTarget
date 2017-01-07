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
const int THRESHOLD = 25;

// these variables will change:
int HeadSensorReading = 0;      // variable to store the value read from the sensor pin
int TorsoSensorReading = 0;      // variable to store the value read from the sensor pin
int LegSensorReading = 0;      // variable to store the value read from the sensor pin
int HeadSensorReadingRandom = 0;      // variable to store the value read from the sensor pin
int TorsoSensorReadingRandom = 0;      // variable to store the value read from the sensor pin
int LegSensorReadingRandom = 0;      // variable to store the value read from the sensor pin
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
    delay(300);
    //  one hit for the random mode
    RandomON = RandomON + 1;
  }
  
  // if the sensor reading is greater than the threshold:
  if (TorsoSensorReading >= THRESHOLD) {
    // update the LED pin itself:
    digitalWrite(Led2yellowPin, 0);
    digitalWrite(Led2redPin, 0);
    digitalWrite(Led2greenPin, 1);
    delay(300);
    //  resets the count for the random mode
    RandomON = 0;
  }
  
  // if the sensor reading is greater than the threshold:
  if (LegSensorReading >= THRESHOLD) {
    // update the LED pin itself:
    digitalWrite(Led3yellowPin, 0);
    digitalWrite(Led3redPin, 0);
    digitalWrite(Led3greenPin, 1);
    delay(300);
    //  resets the count for the random mode
    RandomON = 0;
  }
  
  //  entered random game mode
  if (RandomON >= 10) {
    RandomON = 0;    //  resets the count for the random mode
    RandomOFF = 0;    //  resets the count for the random mode
    //  you have 10 targets to take out before the game mode ends
    while (RandomOFF < 10) {
      setColor(0, 0, 0);  // lights out
      //delay(100);
      RandomTime = random(500, 2000);  // set a random time to present next target between 500ms and 4s
      RandomTarget = random(1, 4);  // set a random target
      //RandomTarget = 1;  // set a random target
      
      switch (RandomTarget) {
        case 1:
          StartTime = millis();    //  start timer
          hit = 0;  // reset the number of times the target has been hit. you have 3 shots until it moves to the next one
          delay(RandomTime);
          while(hit < 3){
            //  read sensors for random mode
            HeadSensorReadingRandom = analogRead(HeadSensor);
            TorsoSensorReadingRandom = analogRead(TorsoSensor);
            LegSensorReadingRandom = analogRead(LegSensor);
            //  light the target to hit
            digitalWrite(Led1yellowPin, 1);
            digitalWrite(Led1redPin, 0);
            digitalWrite(Led1greenPin, 0);
            ActualTime = millis();  // measure the actual time
            Timeout = ActualTime - StartTime;   // calculate the time that has passed since the target was active
            // if the sensor reading is greater than the threshold:
            if (HeadSensorReadingRandom >= THRESHOLD) {
              // update the LED pin itself:
              wright(3);
              hit = 3;
            }         
            // if the sensor reading is greater than the threshold:
            if (TorsoSensorReadingRandom >= THRESHOLD || LegSensorReadingRandom >= THRESHOLD) {
              // update the LED pin itself:
              wrong(3);
              hit = hit + 1;
            }
            //if the target has been active for too long (more than 45s), you've timed out
            if (Timeout >= 20000) {
              wrong(3);
              hit = 3;
            }
          }
          //  one less target to the end of random mode
          RandomOFF = RandomOFF + 1;
          break;
          
        case 2:
          StartTime = millis();    //  start timer
          hit = 0;  // reset the number of times the target has been hit. you have 3 shots until it moves to the next one
          delay(RandomTime);
          while(hit < 3){
            //  read sensors for random mode
            HeadSensorReadingRandom = analogRead(HeadSensor);
            TorsoSensorReadingRandom = analogRead(TorsoSensor);
            LegSensorReadingRandom = analogRead(LegSensor);
            //  light the target to hit
            digitalWrite(Led2yellowPin, 1);
            digitalWrite(Led2redPin, 0);
            digitalWrite(Led2greenPin, 0);
            ActualTime = millis();  // measure the actual time
            Timeout = ActualTime - StartTime;   // calculate the time that has passed since the target was active
            // if the sensor reading is greater than the threshold:
            if (TorsoSensorReadingRandom >= THRESHOLD) {
              // update the LED pin itself:
              wright(3);
              hit = 3;
            }   
            // if the sensor reading is greater than the threshold:
            if (HeadSensorReadingRandom >= THRESHOLD || LegSensorReadingRandom >= THRESHOLD) {
              // update the LED pin itself:
              wrong(3);
              hit = hit + 1;
            }
            //if the target has been active for too long (more than 45s), you've timed out
            if (Timeout >= 20000) {
              wrong(3);
              hit = 3;
            }
          }
          //  one less target to the end of random mode
          RandomOFF = RandomOFF + 1;
          break;
          
        case 3:
          StartTime = millis();    //  start timer
          hit = 0;  // reset the number of times the target has been hit. you have 3 shots until it moves to the next one
          delay(RandomTime);
          while(hit < 3){
            //  read sensors for random mode
            HeadSensorReadingRandom = analogRead(HeadSensor);
            TorsoSensorReadingRandom = analogRead(TorsoSensor);
            LegSensorReadingRandom = analogRead(LegSensor);
            //  light the target to hit
            digitalWrite(Led3yellowPin, 1);
            digitalWrite(Led3redPin, 0);
            digitalWrite(Led3greenPin, 0);
            ActualTime = millis();  // measure the actual time
            Timeout = ActualTime - StartTime;   // calculate the time that has passed since the target was active
            // if the sensor reading is greater than the threshold:
            if (LegSensorReadingRandom >= THRESHOLD) {
              // update the LED pin itself:
              wright(3);
              hit = 3;
            } 
            // if the sensor reading is greater than the threshold:
            if (HeadSensorReadingRandom >= THRESHOLD || TorsoSensorReadingRandom >= THRESHOLD) {
              // update the LED pin itself:
              wrong(3);
              hit = hit + 1;
            }
            //if the target has been active for too long (more than 45s), you've timed out
            if (Timeout >= 20000) {
              wrong(3);
              hit = 3;
            }
          }
          //  one less target to the end of random mode
          RandomOFF = RandomOFF + 1;
          break;
      }
    }
  }
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
void wright(int TimesFlashWright)
{ 
  for (int x = 0; x <= 3; x++) {
    setColor(0,0,1);
    delay(50);
    setColor(0,0,0);
    delay(50);
  }
}

//function to flash red light
void wrong(int TimesFlashWrong)
{
  for (int x = 0; x <= TimesFlashWrong; x++) {
    setColor(0,1,0);
    delay(50);
    setColor(0,0,0);
    delay(50);
  }
}
