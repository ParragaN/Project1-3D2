// A basic everyday NeoPixel strip test program.

/* Strandtest example code modified Jan 2021 Doug Whitton
 *  This example is a barebones version of the Adafruit sample code
 *  It lights up a strip of 2 neopixels  
 *  The colour is random 
 *  Thee colorWipe method is called from the loop()
 *  strip is a variable name for an Adafruit_NeoPixel object
 *  
*/
#include <Servo.h>
#include <Adafruit_NeoPixel.h>




Servo topservoMotor;       // creates an instance of the servo object to control a servo
int tservoPin = 9;       // Control pin for servo motor
int topservoAngle = 0;     // variable for changing the angle of the servo 0 - 180


//
//Servo botservoMotor;       // creates an instance of the servo object to control a servo
//int bservoPin = 10;       // Control pin for servo motor
//int botservoAngle = 0;     // variable for changing the angle of the servo 0 - 180
//
// 
 

int green =0;
int value=0;



#define LED_PIN    6 

#define LED_COUNT 2

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);



// setup() function -- runs once at startup --------------------------------

void setup() {

  topservoMotor.attach(tservoPin);  // attaches the servo on pin 9 to the servo object

topservoMotor.write(0);


  botservoMotor.attach(bservoPin);  // attaches the servo on pin 10 to the servo object

botservoMotor.write(130);

  
  strip.begin();           
  strip.show();            
  strip.setBrightness(150); //play with brigthness and materials
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {



int x = 1;
   for (int i = 0; i > -1; i = i + x){
    topservoMotor.write(i);                 //set the angle of the servo to i
      
      if (i == 100) x = -1;             // switch direction at the max 180 degree point
      delay(7);                         // change the delay to speed up or slow down
      Serial.println(i);                // print i to the serial monitor to make sure the numbers are OK
      
   }  

//int y = 1;
//   for (int i = 0; i > -1; i = i + y){
//    botservoMotor.write(i);                 //set the angle of the servo to i
//      
//      if (i == 130) y = -1;             // switch direction at the max 180 degree point
//      delay(12);                         // change the delay to speed up or slow down
//      Serial.println(i);                // print i to the serial monitor to make sure the numbers are OK
//      
//   }  



  
  fireWipe(strip.Color(255,green,0), 5);  

}



void fireWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(5);    
    

if (green == 145)
{
   value = -1;
}
if (green == 0)
{
   value = 1;
}
green = green + value;

   
  }
}
