
//Photogrammetry Controller
//Version = V0.1


/*
Control a rotary table using an encoder through an LCD, and a DSLR Camera that takes number of pics from every angle.

//Required Hardware:
Arduino Mega
Encoder
I2C 16X2 LCD
Stepper Driver



Stepepr Calculation
20t to 60t pully @200 step per rev
*/


//Required Libraries:

//LiquidCrystal I2C library by Frank de Brabander
#include <LiquidCrystal_I2C.h>

//Accelstepper Library by McCauley
#include <AccelStepper.h>



//////Setup://////

////Encoder////
  // Rotary Encoder Inputs
    #define CLK 2
    #define DT 3
//Required Variables
  int counter = 0;
  int currentStateCLK;
  int lastStateCLK;
  String currentDir ="";


////Display////
  // set the LCD address to 0x3F for a 16 chars and 2 line display
   LiquidCrystal_I2C lcd(0x3F,16,2);


////Rotary Table////
  // Define pin connections
    #define platformDirPin  4;
    #define platformStepPin 5;

  // Define motor interface type
    #define platformMotorInterfaceType 1

  // Creates an instance
    AccelStepper myStepper(platformMotorInterfaceType, platformStepPin, platformDirPin);


////Shutter Control////
  //Define pin connections
    #define focus 6;
    #define shutter 7;



void setup() {

  
  ////Display////
    lcd.init();
    lcd.clear();         
    lcd.backlight();      // Make sure backlight is on
    
    // Print a message on both lines of the LCD.
    lcd.setCursor(2,0);
    lcd.print("Photogrammetry");
    lcd.setCursor(2,1);
    lcd.print("V0.1");

  ////Encoder////
    //IO
      pinMode(CLK, INPUT);
      pinMode(DT, INPUT);




  ////Rotary Table////
    //IO
      pinMode(platformDirPin, OUTPUT);
      pinMode(platformStepPin, OUTPUT);

    // set the maximum speed, acceleration factor,
    // initial speed and the target position
    myStepper.setMaxSpeed(1000);
    myStepper.setAcceleration(50);
    myStepper.setSpeed(200);
    myStepper.moveTo(200);

  

}

void loop() {
  // put your main code here, to run repeatedly:

}
