
---

## Descrição

Este código é um exemplo de como usar um **ESP32** para ler um valor de um potenciômetro e enviar os dados para a plataforma **ThingSpeak** via WiFi. Ele se conecta a uma rede WiFi, lê o valor de um potenciômetro conectado a um pino analógico do ESP32 e envia esse valor para um canal do ThingSpeak a cada 15 segundos.

## Requisitos

- **ESP32** ou outro microcontrolador compatível com a biblioteca `WiFi.h` e `ThingSpeak.h`.
- Conta no **ThingSpeak** para criar um canal e obter o número do canal e a chave API de escrita.
- Potenciômetro conectado ao pino analógico de um ESP32 (neste caso, o pino 34).
- Rede WiFi com SSID e senha configurados.

## Dependências

- **WiFi.h**: Biblioteca para conectar o ESP32 a redes WiFi.
- **ThingSpeak.h**: Biblioteca para interagir com a API do ThingSpeak.

## Instruções

1. **Instalar as Bibliotecas**:
   - Para usar o código, você precisa instalar a biblioteca **ThingSpeak**. Para isso, vá até o Gerenciador de Bibliotecas do Arduino IDE e instale a biblioteca `ThingSpeak`.
   - A biblioteca **WiFi.h** já está incluída na instalação do ESP32 no Arduino IDE.

2. **Configuração do ThingSpeak**:
   - Crie uma conta no [ThingSpeak](https://thingspeak.com/).
   - Crie um canal e anote o **número do canal** (Channel Number) e a **chave API de escrita** (Write API Key) fornecida pelo ThingSpeak.

3. **Configuração do código**:
   - Substitua `"REPLACE_WITH_YOUR_SSID"` e `"REPLACE_WITH_YOUR_PASSWORD"` pelo SSID e pela senha da sua rede WiFi.
   - Substitua o número do canal (`myChannelNumber`) e a chave API (`myWriteAPIKey`) pelos valores fornecidos pelo ThingSpeak.

4. **Conectar o Potenciômetro**:
   - Conecte um potenciômetro ao pino analógico **34** (ou outro pino compatível) do seu ESP32.

5. **Upload do código**:
   - Faça o upload do código no ESP32 e abra o monitor serial.

6. **Verificação**:
   - O código vai conectar o ESP32 à sua rede WiFi e, em seguida, começar a enviar o valor lido do potenciômetro para o ThingSpeak a cada 15 segundos.

## Funcionalidade

- O código se conecta à rede WiFi configurada e se comunica com a plataforma ThingSpeak para enviar dados de leitura.
- O valor do potenciômetro (mapeado de 0 a 100) é lido e enviado para o canal do ThingSpeak.
- O processo é repetido a cada 15 segundos.
  
### Observações

- A cada leitura do potenciômetro, o valor é mapeado para um intervalo de 0 a 100 antes de ser enviado.
- O código utiliza a biblioteca `WiFi` para conectar-se à rede e a biblioteca `ThingSpeak` para enviar os dados para a plataforma.
- Se a conexão com a rede WiFi falhar, o código tenta se reconectar até obter uma conexão bem-sucedida.



### Melhorias possíveis

- Aumentar a frequência de atualização, alterando o valor de `timerDelay`.
- Adicionar mais sensores, como sensores de temperatura ou luminosidade, para enviar múltiplos dados para o ThingSpeak.



---
