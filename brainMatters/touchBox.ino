/*
    | Stephen Penkov | CISP440 | Arduino Project | 5/8/17 |
    Purpose: This portion of the Brain Matter project is a box that contains 
    3 buttons. The green LED lights up when the correct combination of two buttons
    are pressed simultaneously pressed. For the wrong inputs that we care about, the red
    LED will light up indicating a "false" input.
*/
//Constant variables that set the pin numbers. Buttons 2-4, LED's 5-6.
const int button1 = 4;     
const int button2 = 3;
const int button3 = 2;
const int green_LED = 5;
const int red_LED =  6;      
// variables that hold the current states
int state1 = 0, state2 = 0, state3 = 0;        
void setup(){
  
  //initialize the pushbuttons as the inputs.
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  //initialize the LED's as the outputs.
  pinMode(green_LED, OUTPUT);
  pinMode(red_LED, OUTPUT);
}
void loop(){
  
  //Get the button states. 
  state1 = digitalRead(button1);
  state2 = digitalRead(button2);
  state3 = digitalRead(button3);
  //For the wrong inputs that we care about, light up the red LED.
  if(state1 && state2 && !state3 || state1 && !state2 && state3 || state1 && state2 && state3) {
    digitalWrite(red_LED, HIGH);
    delay(500);
    digitalWrite(red_LED, LOW);
  }
  
  //if button's 2 and 3 are pressed, light up the green LED.
  if(state2 && state3 && !state1 ) {
    digitalWrite(green_LED, HIGH);
    delay(500);
    digitalWrite(green_LED, LOW);
  }
}
