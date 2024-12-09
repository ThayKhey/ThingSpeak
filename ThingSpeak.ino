#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "SUBSTITUA_PELO_SEU_SSID";   // nome da sua rede WiFi
const char* password = "SUBSTITUA_PELA_SUA_SENHA";   // senha da sua rede WiFi

WiFiClient client;

unsigned long myChannelNumber = XXXXXXX;  // número do canal do ThingSpeak
const char * myWriteAPIKey = "XXXXXXXXXXXXXXXX";  // chave de API para escrita no ThingSpeak

// Variáveis do temporizador
unsigned long lastTime = 0;
unsigned long timerDelay = 15000;  // 15 segundos

// Variável para armazenar as leituras
float potenciometro;

void setup() 
{
  Serial.begin(115200);  // Inicializa o monitor serial
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Inicializa a comunicação com o ThingSpeak
}

void loop() 
{
  if ((millis() - lastTime) > timerDelay) 
  {
    // Conectar ou reconectar à rede WiFi
    if(WiFi.status() != WL_CONNECTED)
    {
      Serial.print("Tentando conectar");
      while(WiFi.status() != WL_CONNECTED)
      {
        WiFi.begin(ssid, password); 
        delay(5000);  // Espera 5 segundos antes de tentar novamente
      } 
      Serial.println("\nConectado.");
    }

    // Obter uma nova leitura do potenciômetro
    const int potPin = 34;  // Pino analógico 34
    int sensorValue = analogRead(potPin);  // Leitura do potenciômetro
    int potenciometro = map(sensorValue, 0, 4095, 0, 100);  // Mapeamento para 0-100
    Serial.print("Potenciômetro: ");
    Serial.println(potenciometro);

    // Enviar dados para o ThingSpeak
    int x = ThingSpeak.writeField(myChannelNumber, 1, potenciometro, myWriteAPIKey);

    if(x == 200)
    {
      Serial.println("Atualização do canal bem-sucedida.");
    }
    else
    {
      Serial.println("Problema ao atualizar o canal. Código de erro HTTP " + String(x));
    }
    lastTime = millis();  // Atualiza o tempo da última execução
  }
}
