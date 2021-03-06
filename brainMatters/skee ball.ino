#define BUTTON_NUM 6
#define MAX_SCORE 100

//functions for winner lights
void winnerLights();
void moveDown(int,int);
void moveUp(int,int);
void flashLED(int,int);
void turnOff();

//score points per button
const int scorePoints[BUTTON_NUM]={10,20,30,40,50,100};

//count of the score
int count=0;

// set pin numbers:
const int buttonPin[BUTTON_NUM]={14,15,16,17,18,19};

// the current reading from the input pin
int buttonState[BUTTON_NUM]={HIGH,HIGH,HIGH,HIGH,HIGH,HIGH};

// the previous reading from the input pin
int lastButtonState[BUTTON_NUM]={LOW,LOW,LOW,LOW,LOW,LOW};

//LED Pins and their respective numbers
const int ledPin1=2;
const int ledPin2 = 3;      
const int ledPin3=4;
const int ledPin4=5;
const int ledPin5=6;
const int ledPin6=7;
const int ledPin7=8;
const int ledPin8=9;
const int ledPin9=10;
const int ledPin10=11;
const int fan=13;
const int fantime=15000;
// Variables will change:
//int ledState = HIGH;         // the current state of the output pin


// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 5;    // the debounce time; increase if the output flickers

void setup() {
  for (int i=0; i<BUTTON_NUM;i++)
  {
    pinMode(buttonPin[i],INPUT);
    }
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
pinMode(ledPin5,OUTPUT);
pinMode(ledPin6,OUTPUT);
pinMode(ledPin7,OUTPUT);
pinMode(ledPin8,OUTPUT);
pinMode(ledPin9,OUTPUT);
pinMode(ledPin10,OUTPUT);
 pinMode(fan,OUTPUT); 
 Serial.begin(9600);
  // set initial LED state
  //digitalWrite(ledPin1, ledState);
  
}

void loop() {
  int reading[BUTTON_NUM];
  for (int i=0;i<BUTTON_NUM;i++)
  {
    reading[i]=digitalRead(buttonPin[i]);
    if(reading[i] !=lastButtonState[i])
    {
      lastDebounceTime=millis();
      }
    }

  if ((millis() - lastDebounceTime) > debounceDelay) 
  {
for (int i=0;i<BUTTON_NUM;i++)
{
  if(reading[i]!=buttonState[i])
  {
    buttonState[i]=reading[i];
    if(buttonState[i]==HIGH)
    {
      count+=scorePoints[i];
      Serial.println(count);
      if (count>=MAX_SCORE)
      {
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(500);
        winnerLights();
        //implemented fan turning on for 10 seconds
        digitalWrite(fan,HIGH);
        delay(fantime);
        digitalWrite(fan,LOW);
        count=0;
        turnOff();
        }
        else if(count>=90)
        {
          digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        //digitalWrite(ledPen10,HIGH);
          }
          else if(count>=80)
          {digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        //digitalWrite(ledPen9,HIGH);
        //digitalWrite(ledPen10,HIGH);
            }
            else if(count>=70)
          {digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        //digitalWrite(ledPen8,HIGH);
        //digitalWrite(ledPen9,HIGH);
        //digitalWrite(ledPen10,HIGH);
            }
            else if(count>=60)
          {digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        //digitalWrite(ledPen7,HIGH);
        //digitalWrite(ledPen8,HIGH);
        //digitalWrite(ledPen9,HIGH);
        //digitalWrite(ledPen10,HIGH);
            }
            else if(count>=50)
          {digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        //digitalWrite(ledPen6,HIGH);
        //digitalWrite(ledPen7,HIGH);
        //digitalWrite(ledPen8,HIGH);
        //digitalWrite(ledPen9,HIGH);
        //digitalWrite(ledPen10,HIGH);
            }
            else if(count>=40)
          {digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        //digitalWrite(ledPen5,HIGH);
        //digitalWrite(ledPen6,HIGH);
        //digitalWrite(ledPen7,HIGH);
        //digitalWrite(ledPen8,HIGH);
        //digitalWrite(ledPen9,HIGH);
        //digitalWrite(ledPen10,HIGH);
            }
            else if(count>=30)
          {digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        //digitalWrite(ledPen4,HIGH);
        //digitalWrite(ledPen5,HIGH);
        //digitalWrite(ledPen6,HIGH);
        //digitalWrite(ledPen7,HIGH);
        //digitalWrite(ledPen8,HIGH);
        //digitalWrite(ledPen9,HIGH);
        //digitalWrite(ledPen10,HIGH);
            }
            else if(count>=20)
          {digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        //digitalWrite(ledPen3,HIGH);
        //digitalWrite(ledPen4,HIGH);
        //digitalWrite(ledPen5,HIGH);
        //digitalWrite(ledPen6,HIGH);
        //digitalWrite(ledPen7,HIGH);
        //digitalWrite(ledPen8,HIGH);
        //digitalWrite(ledPen9,HIGH);
        //digitalWrite(ledPen10,HIGH);
            }
            else if(count>=10)
          {digitalWrite(ledPin1,HIGH);
        //digitalWrite(ledPen2,HIGH);
        //digitalWrite(ledPen3,HIGH);
        //digitalWrite(ledPen4,HIGH);
        //digitalWrite(ledPen5,HIGH);
        //digitalWrite(ledPen6,HIGH);
        //digitalWrite(ledPen7,HIGH);
        //digitalWrite(ledPen8,HIGH);
        //digitalWrite(ledPen9,HIGH);
        //digitalWrite(ledPen10,HIGH);
            }
      }
   /*   
    if (count>=(MAX_SCORE+10))
    {
      count=0;
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
      }
      */
    }
  }
   
  }

  // set the LED:
  //digitalWrite(ledPin1, ledState);
for (int i=0;i<BUTTON_NUM;i++)
{
  lastButtonState[i]=reading[i];
  }
  
}//end of void loop

void winnerLights()
{
  moveDown(250,1);
  moveUp(250,1);
  flashLED(250,2);
  moveDown(100,1);
  moveUp(100,1);
  flashLED(100,3);
  
  
  }//end of winnerLights function definition
void moveUp(int delayTime,int moveUp)
 {
  for(int i=0;i<moveUp;i++)
  {
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,LOW);
        delay(delayTime);
  }//end of move up for loop
  }//end of move up function
 void moveDown(int delayTime,int moveDown)
 {
  for(int i=0;i<moveDown;i++)
  {
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,LOW);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
  }//end of move down for loop
  }//end of move down function
 void flashLED(int delayTime,int flashTimes)
 {
  for (int i=0; i<flashTimes;i++)
  {
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,HIGH);
        delay(delayTime);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        delay(delayTime);            
    }//end of flash lights for loop
  }//end of flashLED function

 void turnOff()
 {
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);

  }
