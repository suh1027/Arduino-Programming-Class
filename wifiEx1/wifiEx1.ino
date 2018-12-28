#include <doxygen.h>
#include <ESP8266.h>


#include <SoftwareSerial.h>

#define SSID        "MULTI_GUEST"
#define PASSWORD    "guest1357"
#define HOST_NAME   "70.12.110.74"
#define HOST_PORT   (8090)

SoftwareSerial mySerial(2, 3);
ESP8266 wifi(mySerial);

void setup(void)
{
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

void loop(void)
{
    uint8_t buffer[128] = {0};
    static uint8_t mux_id = 0;
    
    if (wifi.createTCP(mux_id, HOST_NAME, HOST_PORT)) {
        Serial.print("create tcp ");
        Serial.print(mux_id);
        Serial.println(" ok");
    } else {
        Serial.print("create tcp ");
        Serial.print(mux_id);
        Serial.println(" err");
    }

//    hello => 문자열로 이름 , 핸드폰번호 전송 -> 저장시 시간으로 방문일자 결정
    char *hello = "방문자1,010-1234-5678"; 
    if (wifi.send(mux_id, (const uint8_t*)hello, strlen(hello))) {
        Serial.println("send ok");
    } else {
        Serial.println("send err");
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
