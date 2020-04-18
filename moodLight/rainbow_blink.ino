// Rainbow Blink
// by Jim Town

const int red=9;   //~ pin
const int green=10;//~ pin
const int blue=11;  //~ pin

const int numColors=8; // number of colors
              // r   o   y   g   b   i   v   w
int redSeq[]=  {255,255,255,  0,  0, 64,255,255};
int greenSeq[]={  0,065,100,128,  0,  0,  0,255};
int blueSeq[]= {  0,  0,  0,  0,255,255,255,255};

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  for (int i=0; i<numColors; i++){ //for each color
    analogWrite(red,redSeq[i]); //write red value
    analogWrite(green,greenSeq[i]); //write green value
    analogWrite(blue,blueSeq[i]); //write blue value
    delay(2000); //wait 2 seconds
  }
  digitalWrite(red,LOW); //turn red off
  digitalWrite(green,LOW); //turn green off
  digitalWrite(blue,LOW); //turn blue off
  delay(2000); //wait 2 seconds
}
