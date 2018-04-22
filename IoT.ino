#include <Wire.h>
#include "SSD1306.h"
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const int Out = 5;
const int in = 4;
const char* host = "192.168.43.115";

WiFiClient clients;
SSD1306 display;

void setup() {
  // put your setup code here, to run once:
  pinMode(Out, OUTPUT);
  pinMode(in, INPUT);

  Serial.begin(115200);
  WiFi.begin("nodemcu", "passwordnodemcu"); 
  display.init();
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting for connection");
  }

}
  
void loop() {
  // put your main code here, to run repeatedly:
  // create variable
  int httpPort = 80;
  if(!clients.connect(host, httpPort)) {
    Serial.println("Connection failed!");
    return;
  }
  
  long duration, inches, cm;

  digitalWrite(Out, LOW);
  delayMicroseconds(2);
  digitalWrite(Out, HIGH);
  delayMicroseconds(5);
  digitalWrite(Out, LOW);

  duration = pulseIn(in, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCm(duration);

  Serial.print("Inc: ");
  Serial.println(inches);

  Serial.print("Cm: ");
  Serial.println(cm);
  
  // Create url for request
  String url = "http://192.168.43.115/data/includes/add.php?datacm=";
  url += cm;
  url += "&datainch=";
  url += inches;

  Serial.print("Requesting URL: ");
  Serial.println(url);
  clients.print(String("GET ") + url + " HTTP/1.1\r\n" + 
              "Host:" + host + "\r\n"
              "Connection: close\r\n\r\n");
  
  unsigned long timeout = millis();
  while(clients.available() == 0) {
    if(millis() - timeout > 5000) {
      Serial.println(">>> Client timeout!");
      clients.stop();
      return;
    }
  }
  
  // convert from int to string
  String Inches = String(inches);
  Inches += " inches";
  
  String Cm = String(cm);
  Cm += " cm";
  
  
  // display data in oled
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.drawString(1, 12, Inches);
  display.display();
  
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display.drawString(1, 12, Cm);
  display.display();
  display.clear();
  
  delay(20000);
}

long microsecondsToInches(long microseconds)
{
  return microseconds/ 74 /2;
}

long microsecondsToCm(long microseconds)
{
  return microseconds /29/ 2;
}
