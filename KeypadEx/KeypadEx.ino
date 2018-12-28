#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Key.h>
#include <Keypad.h>
#include <dht11.h>
#include <doxygen.h>
#include <ESP8266.h>
#include <SoftwareSerial.h>

//WIFI 통신
//멀티캠퍼스 WIFI 주소, 비밀번호 , TCP 서버의 주소, 통신포트
#define SSID        "MULTI_GUEST"
#define PASSWORD    "guest1357"
#define HOST_NAME   "70.12.110.74"
#define HOST_PORT   (8090)

SoftwareSerial mySerial(0, 1);
ESP8266 wifi(mySerial);


//키패드 상수, 키 설정
const byte ROWS=4;
const byte COLS=4;

char keys[ROWS][COLS] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

//보낼 Value값들 초기화
String buff = "";
String nValue = "";
String pValue = "";
String value = "";


//temperature
int DHT11PIN = 10;
dht11 DHT11;

//LCD
LiquidCrystal_I2C lcd(0x27,16,2);

//button
int sendBtn = 11;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(sendBtn,INPUT);
  
  lcd.begin();   
  lcd.clear();
  lcd.print("input name,pn :");
  lcd.setCursor(0,1);
  
  keypad.addEventListener(listener);

  // WIFI
  Serial.begin(9600);
  Serial.print("setup begin\r\n");

  Serial.print("FW Version: ");
  Serial.println(wifi.getVersion().c_str());
  
  
  if (wifi.setOprToStationSoftAP()) {
      Serial.print("to station + softap ok\r\n");
  } else {
      Serial.print("to station + softap err\r\n");
  }

  if (wifi.joinAP(SSID, PASSWORD)) {
      Serial.print("Join AP success\r\n");
      Serial.print("IP: ");       
      Serial.println(wifi.getLocalIP().c_str());
  } else {
      Serial.print("Join AP failure\r\n");
  }
  
  if (wifi.enableMUX()) {
      Serial.print("multiple ok\r\n");
  } else {
      Serial.print("multiple err\r\n");
  }
  
  Serial.print("setup end\r\n");


}

void loop() {
//   put your main code here, to run repeatedly:
  char key = keypad.getKey();
  if(digitalRead(sendBtn) == HIGH){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("SENDING"); 
     uint8_t buffer[128] = {0};
     static uint8_t mux_id = 0;

     delay(1000);
     
     if (wifi.createTCP(mux_id, HOST_NAME, HOST_PORT)) {
        Serial.print("create tcp ");
        Serial.print(mux_id);
        Serial.println(" ok");
        lcd.clear();
        lcd.print("Server Connected");
      
     } else {
         Serial.print("create tcp ");
         Serial.print(mux_id);
         Serial.println(" err");
         lcd.clear();
         lcd.print("Create tcp error");
    
     }
    
    float temp = (float)DHT11.temperature;
    String tempMsg = String(temp);
    String msg = "hi";
    
  //    sendMsg => 문자열로 이름 , 핸드폰번호, 온도 전송 -> 저장시 시간으로 방문일자 결정
    char *sendMsg = "hi";
    if (wifi.send(mux_id, (const uint8_t*)sendMsg, strlen(sendMsg))) {
        Serial.println("send ok");
        //lcd.clear();
        //lcd.print("Send OK");
        
    } else {
        Serial.println("send err");
        lcd.clear();
        lcd.print("Send Error");
    }
    
    uint32_t len = wifi.recv(mux_id, buffer, sizeof(buffer), 10000);
    if (len > 0) {
        Serial.print("Received:[");
        for(uint32_t i = 0; i < len; i++) {
            Serial.print((char)buffer[i]);
        }
        Serial.print("]\r\n");
    }
  
    if (wifi.releaseTCP(mux_id)) {
        Serial.print("release tcp ");
        Serial.print(mux_id);
        Serial.println(" ok");
    } else {
        Serial.print("release tcp ");
        Serial.print(mux_id);
        Serial.println(" err");
    }
  
    delay(3000);
    mux_id++;
    if (mux_id >= 5) {
        mux_id = 0;
    }
     
  }
}

void listener(KeypadEvent key){  
  
  switch(keypad.getState()){
    case PRESSED:
      if(key){
        if(key == '#'){
          nValue = buff;
          buff = "";
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("input name,pn :");
          lcd.setCursor(0,1);
        }
        else if(key == '*'){
          pValue = buff;
          buff = "";
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("input name,pn :");
          lcd.setCursor(0,1);
        }
        else{
          buff = buff + key;
        }
      }
      Serial.println("key");   
      Serial.println(key);
      Serial.println("buff");
      Serial.println(buff);   
      Serial.println("nameValue");
      Serial.println(nValue);
      Serial.println("phoneNumber");
      Serial.println(pValue);
      break;
    
    case RELEASED:
      lcd.print(buff);
      break;
    case HOLD:
    
      break;  
    
  }
  lcd.setCursor(0,1);
  value = nValue + "," + pValue;
  lcd.print(value);
}
