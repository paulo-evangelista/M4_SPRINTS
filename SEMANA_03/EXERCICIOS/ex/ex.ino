//  link do video demonstrando
//  https://photos.app.goo.gl/wDPqc1kGBqznuqfX8

// link do simulador
// https://wokwi.com/projects/346419810624602707


int ldr = 15;
int leds[4] = {14, 11, 46, 18};
int buzzer = 21;
int recordButton = 2;
int stopButton = 1;
int recordLed = 40;
int numeroDeSonsGravados = 0;
bool gravando = false;
int sonsGravados[10] = {99,99,99,99,99,99,99,99,99,99};

void getBinario(int num, int *vetor){
  
  int numero = num;

  for(int i = 0; i<4; i++){
    switch(i){

      case 0:
      vetor[0] = numero % 2;
      break;

      case 1:
      vetor[1] = numero % 2;
      break;

      case 2:
      vetor[2] = numero % 2;
      break;

      case 3:
      vetor[3] = numero % 2;
      break;
    }
    numero = numero / 2;
  }
}

int converte(float inputSensor){
  return truncf(inputSensor / 4063 * 15);
}

void lightLeds(int *vetor){
  for(int i = 0; i<4;i++){
    if (vetor[i]==1){
      digitalWrite(leds[i], LOW);
    } else{
      digitalWrite(leds[i], HIGH);
    }
  }
}

void playSound(int numero){
  switch(numero){
    case 0:
    tone(buzzer, 523 , 500);
    break;
    case 1:
    tone(buzzer, 587 , 500);
    break;
    case 2:
    tone(buzzer, 659 , 500);
    break;
    case 3:
    tone(buzzer, 783 , 500);
    break;
    case 4:
    tone(buzzer, 880 , 500);
    break;
    case 5:
    tone(buzzer, 971 , 500);
    break;
    case 6:
    tone(buzzer, 1046 , 500);
    break;
    case 7:
    tone(buzzer, 1174 , 500);
    break;
    case 8:
    tone(buzzer, 1318 , 500);
    break;
    case 9:
    tone(buzzer, 1396 , 500);
    break;
    case 10:
    tone(buzzer, 1598 , 500);
    break;
    case 11:
    tone(buzzer, 1760 , 500);
    break;
    case 12:
    tone(buzzer, 1943 , 500);
    break;
    case 13:
    tone(buzzer, 2093 , 500);
    break;
    case 14:
    tone(buzzer, 2349 , 500);
    break;
    case 15:
    tone(buzzer, 2637 , 500);
    break;
    
  }
  }

void indica(){

  for(int i = 0; i<4; i++) {

      digitalWrite(leds[i], LOW);

  }
  delay(500);

  for(int i = 0; i<4; i++) {

      digitalWrite(leds[i], HIGH);
      tone(buzzer, i*100, 100);
      delay(125);

  }
  delay(75);

  for(int i = 3; i>=0; i--) {

      digitalWrite(leds[i], LOW);
      tone(buzzer, i*100, 100);
      delay(125);

  }
  delay(1000);
}

void setup(){
  for(int i = 0; i<4; i++) pinMode(leds[i], OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(recordLed, OUTPUT);
  pinMode(recordButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop(){
  for (int i = 0; i<16; i++){

  delay(100);

  if(digitalRead(recordButton) == LOW && gravando == false){
      digitalWrite(recordLed, HIGH);
      indica();
      for(int i = 0; i<10; i++) sonsGravados[i] = 99;
      numeroDeSonsGravados = 0;
      gravando = true;
  }else if((digitalRead(stopButton) == LOW && gravando) || sonsGravados[9] != 99){
      digitalWrite(recordLed, LOW);
      gravando = false;
      indica();
      for(int i = 0; i<10; i++) {
        if (sonsGravados[i] != 99){
        playSound(sonsGravados[i]); 
        int vetorBinario[4] = {0,0,0,0};
        getBinario(sonsGravados[i], vetorBinario);
        lightLeds(vetorBinario);
        delay(600);
      }
      }
      for(int i = 0; i<10; i++) sonsGravados[i] = 99;
      indica();
  }
  }
  Serial.print(analogRead(ldr));
  int inputSensor = analogRead(ldr);
  // Serial.println(digitalRead(recordButton));
  int convertido = converte(inputSensor);
  int vetorBinario[4] = {0,0,0,0};
  getBinario(convertido, vetorBinario);
  lightLeds(vetorBinario);
  playSound(convertido);
  if(gravando){

      sonsGravados[numeroDeSonsGravados] = convertido;
      numeroDeSonsGravados++;

  }
}