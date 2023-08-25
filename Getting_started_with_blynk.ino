#define BLYNK_TEMPLATE_ID "TMPL6-vecMc1N"
#define BLYNK_TEMPLATE_NAME "Getting started with Blynk V2"
#define BLYNK_AUTH_TOKEN "wno7Mrhl8CvE-l9cOe-Mv94T8SXoDW_Q"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
int pot=A0;
int led=D3;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "theinfoflux";
char pass[] = "12345678";



void setup()
{
   
  // Debug console
  Serial.begin(115200);
 pinMode(pot,INPUT);
 pinMode(led,OUTPUT);
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
  int  potvalue=analogRead(pot);
  Blynk.virtualWrite(V0,potvalue);
 delay(1000);
}

BLYNK_WRITE(V1)
{
  int pinValue=param.asInt();
  digitalWrite(led,pinValue);
  }
