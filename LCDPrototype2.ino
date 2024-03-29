#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
// Connect K = -ve/gnd ; A = +ve ; Potentiometer(10K) middle lane = Vo ; Vss = -ve ; RW = gnd ; Vdd = +veconst 
int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;
void setup() {
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print("  cm");

lcd.setCursor(0,1);
lcd.print("Distance: ");
lcd.print(distanceInch);
lcd.print(" inch");
delay(100);
if(distanceCm<=20){
  tone(6,1000);       // This will feed buzzer the information on when to beep.
  delay(100);
}
else 
noTone(6);
}

/* Modified by-
  Dilpreet Singh on 11/08/2019
  Feature added:- Buzzer makes noise of 1000Hz frequency ,if distance in centemeters is lesser than the safe distance.(for vehical's bumper)  
*/
