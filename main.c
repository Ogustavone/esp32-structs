// 4-pins -> led control
// structs: pins, leds

#include <stdio.h>
#include <unistd.h>

// número do pino: int, nome: char
struct pins {
  int pin;
  char name[5];
};

// Array de leds usando a struct anterior
struct pins leds[4] = {
  {14, "led1"},
  {13, "led2"},
  {12, "led3"},
  {11, "led4"},
};

// Inicialização (setup pinmode: output) - Arduino
void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 4; i++) {
    Serial.println("Adicionando" + String(leds[i].name) + "no pino" + String(leds[i].pin));
    pinMode(leds[i].pin, OUTPUT);
  }
};

// Função loop - Arduino
void loop() {
  Serial.println("Ligando todos os leds sequencialmente");
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i].pin, HIGH);
    delay(200);
  };

  Serial.println("Desligando todos os leds");
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i].pin, LOW);
    delay(200);
  };

  // Delay 1 segundo entre os loops
  delay(1000);
};
