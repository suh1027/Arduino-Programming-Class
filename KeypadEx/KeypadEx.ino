#include <Key.h>

#include <Keypad.h>

const byte ROWS=4;
const byte COLS=4;

char keys[ROWS][COLS] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
int led_pin = 13;
boolean blink = false;

int i = 0 ;
int count = 0;

char code[] = {'1','2','3','4'};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  keypad.addEventListener(listener);  
}

void loop() {
//   put your main code here, to run repeatedly:
  char key = keypad.getKey();

  
}

void listener(KeypadEvent key){

  
  switch(keypad.getState()){
    
    case PRESSED:
    Serial.println(key);
    Serial.print("----");
    Serial.println(count);
    if(key == code[count]){
      i++;
      count++;
    }
    else if(key != code[count]){
      count++;
    }
    
    if(count == 5){
      if(i == 4){
        if(key == 'A'){
          Serial.println("Correct");
        }
        else{
          Serial.println("Fail");
        }
      }
      else{
        Serial.println("Fail");
      }
      
    }
    


    break;

    case RELEASED:
    
    if(key == '*'){
      digitalWrite(led_pin,false);
      Serial.println("RELEASED");
    }
    break;

    case HOLD:
    if(key == '*'){
      Serial.println("HOLDING");
    }
    
   
  }
}
