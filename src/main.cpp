#include <Arduino.h>

// #include <WiFiManager.h> // https://github.com/tzapu/WiFiManager



void setup() {
    // WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
    // it is a good practice to make sure your code sets wifi mode how you want it.

    // put your setup code here, to run once:
    Serial.begin(115200);
    

    Serial.println("soft AP test ....");
    //WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
    // WiFiManager wm;

    // reset settings - wipe stored credentials for testing
    // these are stored by the esp library
    // wm.resetSettings();

    // Automatically connect using saved credentials,
    // if connection fails, it starts an access point with the specified name ( "AutoConnectAP"),
    // if empty will auto generate SSID, if password is blank it will be anonymous AP (wm.autoConnect())
    // then goes into a blocking loop awaiting configuration and will return success result

    // bool res;
    // // res = wm.autoConnect(); // auto generated AP name from chipid
    // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
    // res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

    

}

void loop() {
    // put your main code here, to run repeatedly: 
    if (Serial.available()) {

    // // 2024-07-25 : '\r', '\n' 이 없는 경우 무한 루프에 빠지지 않도록 한다.  
        // Serial.setTimeout(2000);  // Set a timeout of 1000 milliseconds (1 second)

        String command = Serial.readStringUntil('\n');
        command.trim();  // 공백 제거


        // Check if the command starts with "write serial#"
        if (command.startsWith("write version:")) {
            Serial.println("write version .... ");
        
        }
        else if(command.equals("read version")){
        Serial.println("read software version : ");
        
        
        }
        else{
          Serial.println("wrong command");
        }
    }
    delay(100);
  
} 