/* 
  Credit for musical effects and framework to:
  Arduino Mario Bros Tunes With Piezo Buzzer and PWM
  by: Dipto Pratyaksa
  last updated: 31/3/13
*/
 
/*************************************************
 * Public Constants
 *************************************************/

const int blueLED =  4;      // the number of the LED pin
const int greenLED = 5;
const int yellowLED = 6;
const int redLED = 7;
int ledState = LOW;         // set default position of LED to off
const int blueButton = 8;
const int greenButton = 9;
const int yellowButton = 10;
const int redButton = 11;

int fantime=20000;
int maxWrong=22;

const int fan = 13;
#define melodyPin 12

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0, 0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12
};

int mainLedScheme[] = {
  blueLED, blueLED, 0, blueLED,
  0, greenLED, blueLED, 0,
  yellowLED, 0, 0, 0,
  yellowLED, 0, 0, 0,

  greenLED, 0, 0, yellowLED,
  0, 0, blueLED, 0,
  0, redLED, 0, greenLED,
  0, redLED, redLED, 0,

  yellowLED, blueLED, yellowLED,
  redLED, 0, yellowLED, yellowLED,
  0, blueLED, 0, greenLED,
  yellowLED, redLED, 0, 0
};

int buttonScheme[] = {
  blueButton, blueButton, 0, blueButton,
  0, greenButton, blueButton, 0,
  yellowButton, 0, 0, 0,
  yellowButton, 0, 0, 0,

  greenButton, 0, 0, yellowButton,
  0, 0, blueButton, 0,
  0, redButton, 0, greenButton,
  0, redButton, redButton, 0,

  yellowButton, blueButton, yellowButton,
  redButton, 0, yellowButton, yellowButton,
  0, blueButton, 0, greenButton,
  yellowButton, redButton, 0, 0
};

int moveRecord[] = {
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,

  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,

  0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0,
  0, 0, 0, 0
};
 
void setup(void)
{
  pinMode(redLED, OUTPUT); //Red led
  pinMode(yellowLED, OUTPUT); //Yellow led
  pinMode(greenLED, OUTPUT); //Green led
  pinMode(blueLED, OUTPUT); //Blue led
  pinMode(fan, OUTPUT); //win state signal
  pinMode(12, OUTPUT);//buzzer
  //pinMode(13, OUTPUT);//led indicator when singing a note 
  pinMode(redButton, INPUT);
  pinMode(yellowButton, INPUT);
  pinMode(greenButton, INPUT);
  pinMode(blueButton, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int buttonState = digitalRead(redButton);
  if(buttonState == HIGH) {
    //play game
    game();
    bool winner = gradeScore();
    if(winner) {
      digitalWrite(fan, HIGH);
      delay(fantime);
      digitalWrite(fan, LOW);
    }
    delay(1000);
    reset();
  }
  delay(100);
  
}

void reset() {
  Serial.print("reset called");
  int arraySize = sizeof(moveRecord) / sizeof(int);
  for(int i = 0; i < arraySize; i++) {
    moveRecord[i] = 0;
  }
}

bool gradeScore() {
  int arraySize = sizeof(mainLedScheme) / sizeof(int);
  int wrongAnswers = 0;
  
  for(int i = 0; i < arraySize; i++) {
    if(buttonScheme[i] != moveRecord[i]) {
      wrongAnswers++;  
    }
  }

   Serial.println(wrongAnswers);

  //out of 24
  if(wrongAnswers > maxWrong) {
    return false;
  }

  return true;
}
 
void game() {
  // iterate over the notes of the melody:
  Serial.println(" 'Mario Theme'");
  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    //note duration
    int noteDuration = 1000 / tempo[thisNote];

    //start tone
    buzz(melodyPin, melody[thisNote], mainLedScheme[thisNote], noteDuration);
    
    // pause between notes
    int pauseBetweenNotes = noteDuration * 3.0;

    readButtonPress(pauseBetweenNotes, buttonScheme[thisNote], thisNote);

    // stop the tone playing:
    buzz(melodyPin, 0, mainLedScheme[thisNote], noteDuration);
  }
}

void readButtonPress(int pauseLength, int buttonPin, int moveRecordIndex) {
  int sectionPause = pauseLength / 5;
  int timesPaused = 0;
  if(buttonPin != 0) {
    for(timesPaused = 1; timesPaused <= 5; timesPaused++) {
      delay(sectionPause);
      
      //Read button state (pressed or not pressed?)
      int buttonState = digitalRead(buttonPin);
      //If button pressed...
      if (buttonState == HIGH) { 
          moveRecord[moveRecordIndex] = buttonPin;
          break;
      }
    }
  }

  delay(sectionPause * (5 - timesPaused + 1));
}
 
void buzz(int targetPin, long frequency, int ledPin, long length) {
  digitalWrite(12, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    digitalWrite(ledPin, HIGH);    // led on
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    digitalWrite(ledPin, LOW);    // led off
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(12, LOW);
 
}
