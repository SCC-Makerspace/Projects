//Smooth rainbow
//by Jim Town
const int red=11;
const int green=10;
const int blue=9;

int redVal,blueVal,greenVal;
bool redUp,greenUp,blueUp;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  redVal=255;
  greenVal=0;
  blueVal=0;
  redUp=true;
  greenUp=true;
  blueUp=false;
  Serial.begin(9600);
}

void loop() {
   
    updateVal(redUp,redVal);
    updateVal(greenUp,greenVal);
    updateVal(blueUp,blueVal);

    if (redUp && greenUp && redVal==255 && greenVal==255){ //RO -> YG
      redUp=false;
    }

    if (!redUp && greenUp && redVal==0 && greenVal==255){ //G->C
      blueUp=true;
    }

    if (blueUp && greenUp && blueVal==255 && greenVal==255){ // C->B
      greenUp=false;
    }

    if (!greenUp && blueUp && greenVal==0 && blueVal==255){
      redUp=true;
    }

    if (redUp && blueUp && redVal==255 && blueVal==255){
      blueUp=false;
    }

    if (redUp && !blueUp && redVal==255 && blueVal==0){
      greenUp=true;
    }
    
    analogWrite(red,redVal);
    analogWrite(green,greenVal);
    analogWrite(blue,blueVal);
    Serial.print(redVal);
    Serial.print(", ");
    Serial.print(greenVal);
    Serial.print(", ");
    Serial.println(blueVal);
    delay(250);
  
}

void updateVal(bool isUp, int &val){
     if (isUp){
      if (val<255){
         val+=5;
      }
    } else if (val>0){
        val-=5;
    }
}


