#include <DHT.h>

#define DHTPIN 2      // DHT22
#define DHTTYPE DHT22 // DHT

#define TRIGPIN 5     // Trigger do sensor Ultrassônico
#define ECHOPIN 6     // Echo do sensor Ultrassônico
#define LED_RED 13    // LED Vermelho (Perigo)
#define LED_GREEN 11  // LED Verde (Segurança)
#define BUZZER 12     // Buzzer

DHT dht(DHTPIN, DHTTYPE); // Inicializa oDHT22

long duration;
int distance;
int rainValue;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // Medir o nível de água usando o sensor ultrassônico
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = duration * 0.034 / 2; // para cm

  
  rainValue = dht.readHumidity(); 

  // Verificar se a leitura do sensor de umidade foi bem-sucedida
  if (isnan(rainValue)) {
    Serial.println("Falha na leitura do sensor de umidade!");
    return;
  }

  // Exibir os valores no console
  Serial.print("Distância (cm): ");
  Serial.println(distance);
  Serial.print("Umidade (chuva): ");
  Serial.println(rainValue);

  // Logica para ativar os alertas
  if (distance < 20 || rainValue > 70) {  // Se o nível de água for alto ou umidade for alta
    digitalWrite(LED_RED, HIGH);  // Acende o LED vermelho
    digitalWrite(LED_GREEN, LOW); // Desliga o LED verde
    digitalWrite(BUZZER, HIGH);   // Ativa o buzzer (alerta sonoro)
    Serial.println("Alerta! Nível de água ou umidade alta.");
  } else {
    digitalWrite(LED_RED, LOW);   // Desliga o LED vermelho
    digitalWrite(LED_GREEN, HIGH); // Acende o LED verde
    digitalWrite(BUZZER, LOW);    // Desliga o buzzer
    Serial.println("Nível seguro.");
  }

  delay(10000); // 10 segundos pra le dnv
}
