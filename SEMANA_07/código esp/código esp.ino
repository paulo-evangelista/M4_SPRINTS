#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

WebServer server(80);

const int yellowLed = 11;
const int blueLed = 3;
const int wifiLed = 21;
const int counterLed = 1;
const int buzzer = 45;
int blueScore = 0;
int yellowScore = 0;

void setupRouting(){

  server.enableCORS();
  server.on("/blueWon", handleBlueWin);
  server.on("/yellowWon", handleYellowWin);
  server.on("/reset", resetScore);
  server.begin();
}

void resetScore(){
  blueScore = 0;
  yellowScore = 0;
  tone(buzzer, 500, 100);
  delay(200);
  tone(buzzer, 500, 100);
  delay(200);
  tone(buzzer, 500, 100);
  server.send(200);
}

void handleYellowWin(){
  digitalWrite(wifiLed, LOW);
  server.send(200);
  tone(buzzer, 2000, 200);
  delay(600);
  tone(buzzer, 2000, 200);
  delay(600);
  tone(buzzer, 2000, 200);
  delay(600);
  digitalWrite(yellowLed, HIGH);
  delay(5000);
  digitalWrite(yellowLed, LOW);
  tone(buzzer, 500, 700);
  digitalWrite(wifiLed, HIGH);
  yellowScore++;
  displayScore(yellowScore);
}
void handleBlueWin(){
  digitalWrite(wifiLed, LOW);
  server.send(200);
  tone(buzzer, 2000, 200);
  delay(600);
  tone(buzzer, 2000, 200);
  delay(600);
  tone(buzzer, 2000, 200);
  delay(600);
  digitalWrite(blueLed, HIGH);
  delay(5000);
  digitalWrite(blueLed, LOW);
  tone(buzzer, 500, 700);
  digitalWrite(wifiLed, HIGH);
  blueScore++;
  displayScore(blueScore);
}

void displayScore(int score){
  for (int i = 0; i < score; i++){
    digitalWrite(counterLed, HIGH);
    delay(700);
    digitalWrite(counterLed, LOW);
    delay(700);
  }
}

void setup(void) {

  pinMode(wifiLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(counterLed, OUTPUT);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("Paulo", "pauleradixzz");


  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  digitalWrite(wifiLed, HIGH);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  setupRouting();
}

void loop(void) {
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks
}
