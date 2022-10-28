//LINK WOKWI
// -->    https://wokwi.com/projects/346419810624602707

//fiz o exercicio na segunda, e depois percebi que deviei um pouco da proposta.
//mas meu programa toca sons infinitamente. Não é necessário apertar o botão.
//quando apertar o botão de gravar, ele irá salvar os proximos 10 sons ou até que o outro botão seja apertado.
//quando apertar o botão vermelho, ele irá tocar os sons gravados.


// variaveis com as pinagens
int ldr = 25;
int leds[4] = {14, 27, 33, 32};
int buzzer = 21;
int recordButton = 4;
int stopButton = 19;
int recordLed = 5;
int numeroDeSonsGravados = 0;
bool gravando = false;
int sonsGravados[10] = {99,99,99,99,99,99,99,99,99,99};

//funçaõ que transforma um número de 0 a 15 em binário
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

//função que converte o input do sensor em um numero de 0 a 15
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
// função que toca um som dependendo do número.
// as frequencias são "hardcoded" pois quis que cada numero tocasse uma nota musical maior perfeita
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

//função que faz um aviso sonoro e visual para quando a gravação começa e termina
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

//a cada 100ms chega se algum botão foi apertado, e toca um som a cada 1,6s
void loop(){
  for (int i = 0; i<16; i++){

  delay(100);
    //se o botão de gravar estiver apertado, começa a gravar
  if(digitalRead(recordButton) == LOW && gravando == false){
      digitalWrite(recordLed, HIGH);
      indica();
      for(int i = 0; i<10; i++) sonsGravados[i] = 99;
      numeroDeSonsGravados = 0;
      gravando = true;

      //se o botão de parar estiver apertado, para de gravar e reproduz 
  }else if((digitalRead(stopButton) == LOW && gravando) || sonsGravados[9] != 99){
      digitalWrite(recordLed, LOW);
      gravando = false;
      indica();
      for(int i = 0; i<10; i++) {
        playSound(sonsGravados[i]);
        delay(400);
      }
      for(int i = 0; i<10; i++) sonsGravados[i] = 99;
      indica();
  }
  }
  //toca o som com base nas infos do sensor
  int inputSensor = analogRead(ldr);
  int convertido = converte(inputSensor);
  int vetorBinario[4] = {0,0,0,0};
  getBinario(convertido, vetorBinario);
  lightLeds(vetorBinario);
  Serial.println(convertido);
  playSound(convertido);

  //se estiver gravando, salva o som tocado no vetor
  if(gravando){

      sonsGravados[numeroDeSonsGravados] = convertido;
      numeroDeSonsGravados++;

  }
}