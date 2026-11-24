/*
 * Nimetus: Harjutus 1
 * Kirjeldus: LED1 hämardamine vastavalt potele R1 ja nupule S1
 * Autor: Franko1000
 * Kuupäev: 24.11.2026
 * Versioon: v1.0
 */
// Defineerime sisendid ja väljundid

const int LED1 = 9;      // PWM väljund
const int S1 = 2;        // Nupp
const int R1 = A0;       // Potentsiomeeter

bool ledSees = false;
bool eelmineNupuOlek = HIGH;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(S1, INPUT_PULLUP);
  digitalWrite(LED1, LOW);
}

void loop() {
  bool nupuOlek = digitalRead(S1);

  // Nupu vajutuse tuvastamine
  if (eelmineNupuOlek == HIGH && nupuOlek == LOW) {

    if (ledSees) {
      // LED välja
      ledSees = false;
      digitalWrite(LED1, LOW);
    } else {
      // LED sisse
      ledSees = true;
    }

    delay(50); // debounce
  }

  eelmineNupuOlek = nupuOlek;

  // Kui LED on sees, muuda heledust potentsiomeetriga
  if (ledSees) {
    int potValue = analogRead(R1);

    // Teisenda 0..1023 -> 0..255
    int brightness = map(potValue, 0, 1023, 0, 255);

    analogWrite(LED1, brightness);
  }
}