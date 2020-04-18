/*
  RGB Blink
  Turns on LEDs on for one second, then off for one second, repeatedly.
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi

  modified 20 Feb 2019
  by Jim Town
*/
const int red=11;
const int green=10;
const int blue=9;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
  digitalWrite(green,HIGH);
  delay(1000);  
  digitalWrite(blue,HIGH);
  delay(1000);                       // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  digitalWrite(green,LOW);
  delay(1000);  
  digitalWrite(blue,LOW);
  delay(1000);                       // wait for a second
}
