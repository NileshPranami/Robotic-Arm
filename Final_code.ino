

#define SW_VERSION "ServoCtrlBlynk_V.1" 
#include <ESP8266WiFi.h>
char ssid [] = "californium";
char pass [] = "californium98";

#include<Servo.h>

#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial   
char auth [] = "6399d3cfad8047e1ae9abee789856640";
#define servo0Pin D0
#define servo1Pin D1
#define servo2Pin D2
#define servo3Pin D3
Servo servo0,servo1,servo2,servo3;

int potReading = 0;




BLYNK_WRITE(V0) 
{
  servo0.write(param.asInt());
}
BLYNK_WRITE(V1){
  servo1.write(param.asInt());
  }

BLYNK_WRITE(V2){
  servo2.write(param.asInt());
}
BLYNK_WRITE(V3){
  servo3.write(param.asInt());
  }


void setup () 
{
  Serial.begin(115200); 
  servo0.attach(servo0Pin);
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
 }
