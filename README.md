# Airsoft Target System - by Manuel Palmeira @ EAS

Public code for a simple, smart, airsoft target system. This project was ment to be free and openly available to anyone interested in it. Feel free to use and change this code/project.
**_Just don't use it to exploit others!_**

This system uses piezos and RGY LEDs. It has to working modes:
- In the first one, every target has a red light on and when you hit it it turns green for a brief moment.
- To enter the second one, you have to hit 10 times straight a specific target. If you do that you enter a random mode. Here you have all the lights off and randomly (time and target) a target will show a yellow light. You have 3 trys to hit the right one or 20 seconds, after this you move to the next randomly selected target. This mode lasts for 100 targets.
For more information on this project and the circuit please check out the instructibles page (soon to be added).

Since I just need simple colors (the 3 primary ones with the LED), I've coded the colors in a ON/OFF base.
If you want to have more color variations make sure to connect the LEDs to PWM pins and change the values on the
color functions according to the color that you want.

What's left on the project:
- [x] Write and upload the source code (currently v1.0)
- [ ] Design and print circuit board
- [ ] Build the actual targets
- [ ] Install and calibrate system
- [ ] Write and publish instructables page

I based the code on the Arduino Knock Sensor. Sources of inspiration:
- https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/overview
- https://www.arduino.cc/en/Tutorial/KnockSensor

Be sure to check:
- http://engineeredairsoft.com
- https://www.facebook.com/Engineered-Airsoft-Solutions
