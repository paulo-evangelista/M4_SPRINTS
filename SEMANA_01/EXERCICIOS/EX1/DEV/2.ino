// USANDO O ESP32 COMO REFERENCIA

#include <iostream>

using namespace std;

// port: a porta onde está conectado o sensor
char readInput(int port){
    pinMode(port, INPUT)
    return analogRead(port)
}

void setup(){
    Serial.begin(9600)
}

void loop(){
    Serial.println(readInput(32))
}