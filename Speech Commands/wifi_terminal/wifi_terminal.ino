#include <WiFi.h>
#include <stdio.h>
#include <stdlib.h>

const char* ssid     = "HERMANN 2.4GHz";
const char* password = "nino021712";

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED pin mode
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(21, OUTPUT);

  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_BUILTIN, HIGH);
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  String msg;
  if (client) {
    while (client.connected()) {            // loop while the client's connected
      while (client.available()) {

        digitalWrite(23, HIGH);
        delay(50);
        digitalWrite(23, LOW);
        delay(10);
        char in = client.read();
        
        if(in == '!'){
          delay(100);
          Serial.print("received : ");Serial.print(msg);
          Serial.print("\n");

          if(msg == "red"){
           digitalWrite(22, HIGH);
            }
          if(msg == "blue"){
            digitalWrite(21, HIGH);
            }
          if(msg == "off"){
            digitalWrite(21, LOW);
            digitalWrite(22, LOW);
            } 
          break;
        
        }else{
          msg = msg+in;
        }
      }
    msg="";
    }
  }

}
