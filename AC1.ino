//leds
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

//adição de botão
const int botao1 = 2;
const int botao2 = 3;
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const int botaoDelay = 100;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  //saída led azul
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  Serial.begin(9600);
	
  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: NOME AQUI               ");
}
//apagar e acender led vermelho

void loop()
{
  //toque do botão 1
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
  	Serial.println("produção iniciada");
    ledVermelho(true);
  	lastDebounceTime1 = millis();
  }
 
  //toque do botão 2
  if((millis() - lastDebounceTime2) > botaoDelay && digitalRead(botao2)){
  	Serial.println("produção parada");
    ledVermelho(false);
  	lastDebounceTime2 = millis();
  }
   //verificador de tempetura
  if(getTemperatura() > 15){
    ledAzul(true);
    Serial.println("Temperatura acima");
  }else{
  	ledAzul(false); 
    Serial.println("temperatura ok");
} 
    	
  delay(10);
}


void ledVermelho(bool estado){
  digitalWrite(vermelho,estado);
}
void ledVerde(){
 //precisa fazer  
}
void ledAzul(bool estado){
	digitalWrite(azul,estado);
}


//função de leitura de temperatura
int getTemperatura(){
  	int temperaturaC;
	temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  	return temperaturaC;
} 
//funcao de leitura da luminosidade
int getLuminosidade(){
  	int luminosidade;
	luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  	return luminosidade;
}
  
  
