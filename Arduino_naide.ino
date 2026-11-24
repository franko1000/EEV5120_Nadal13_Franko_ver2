/*
 * Nimetus: Harjutus 1
 * Kirjeldus: LED1 hämardamine vastavalt potele R1 ja nupule S1
 * Autor: Vahur Maask
 * Täiendaja: Franko Dosugov
 * Kuupäev: 24.11.2026
 * Versioon: v1.0
 */
// Defineerime sisendid ja väljundid
#define LED1 9
#define S1 2
#define R1 A0
// Defineerime globaalsed muutujad
byte LED1_on = 0; // LED1 olekumuutuja
byte S1_on = 0;   // S1 eelmine olek
void setup()
{
    // Andmeside jadaliidese käivitamine
    Serial.begin(9600);
    // Algseadistus
    pinMode(LED1, OUTPUT);
    pinMode(S1, INPUT);
    digitalWrite(LED1, LOW); // Alguses LED1 kustus
}
void dimmer()
{
    // LED1 hämardamine
    int pote = analogRead(R1);                    // Leiame R1 väärtuse
    int LED_v22rtus = map(pote, 0, 1023, 0, 255); // Viime R1 väärtuse õigesse
    vahemikku
        analogWrite(LED1, LED_v22rtus * LED1_on); // Tekitame vastava PWM
    signaali
}
void lylitus()
{
    // Lülitame väljundit vastavalt sisendile
    byte lyli = digitalRead(S1); // Nupu S1 sisend
    if (LED1_on)
    { // Kas LED1 põleb?
        if (lyli && !S1_on)
        {              // Nuppu on vajutatud
            delay(10); // Viivitus 10 ms
            if (digitalRead(S1))
            {                // Kontrollime lülitust
                LED1_on = 0; // Lülitame LED1 välja
                S1_on = 1;   // Eelmine tsükkel S1 oli vajutatud

                // Programmi kontrollimine Serial Monitoriga
                Serial.print("LED1 olek: ");
                Serial.println(LED1_on);
            }
        }
    }
    else
    {
        if (lyli && !S1_on)
        {              // Nuppu on vajutatud
            delay(10); // Viivitus 10 ms
            if (digitalRead(S1))
            {                // Kontrollime lülitust
                LED1_on = 1; // Lülitame LED1 sisse
                S1_on = 1;   // Eelmine tsükkel S1 oli vajutatud
            }
        }
    }
    if (!lyli)
    {              // Nuppu S1 ei vajutatud
        S1_on = 0; // S1 olekumuutuja nullimine
    }
}
void loop()
{
    lylitus(); // Lülituse kontrollfunktsioon
    dimmer();  // LED1 hämardusfunktsioon
}