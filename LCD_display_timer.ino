/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorPin = A0;    // input A0 for reading from the Potentiometer
int sensorValue = 0;  //  save the value from the A0
int outputValue = 0;  //save the map value scaled from 0 to 255

const int buttonPin = 9; // pushbutton pin in arduino

int counter = 0;
int alarm_triggered = 0;
int ledPin = 7;

int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, Hongyun!");

  //initialize button
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin (9600);
  Serial.println("Start");
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  while (buttonState == LOW) {
    Serial.print("inside while loop.  button pressed");
    counter++;
    delay(1000);
    buttonState = digitalRead(buttonPin);
  }

  if (counter !=0) {
    alarm_triggered = 1;
    Serial.print("alarm triggerd!");

  }
  
  lcd.setCursor(0, 0);
  lcd.print("Counter Set: ");
  lcd.print(counter);
  delay(1000);

  while (counter != 0) {
   Serial.print("while loop 2nd. Couting down");
   lcd.print("Counting Down: ");
   lcd.print(counter);
   counter--;
   delay(1000);
  }

  if (alarm_triggered == 1) {
     Serial.print("Blinking!");

    lcd.print("Alarm On!");

    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);

    lcd.print("Alarm Off!");
    alarm_triggered = 0;
  }
  Serial.print("End of the Loop");

  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}
