
// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin1 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A1;
const int analogOutPin = 13; // LED is attached to (or relay)
const int threshold = 1600;

int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;
int outputValue = 0;        // o

void setup() {
  pinMode(analogOutPin,OUTPUT);
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  outputValue=sensorValue1+sensorValue2;
  
  // change the analog out value:
  if (outputValue>threshold){
    digitalWrite(analogOutPin, HIGH);
  }
  else{
    digitalWrite(analogOutPin, LOW);
  }
  // print the results to the serial monitor:
  Serial.print("sensor1 = ");
  Serial.print(sensorValue1);
  Serial.print("\t sensor2 = ");
  Serial.print(sensorValue2);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  delay(20);
}
