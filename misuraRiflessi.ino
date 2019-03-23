#include <LiquidCrystal.h>
//LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

int button = 8;
int led = 9;
int buzzer = 7;
int stato;
int tSuono;
int tempoLed;
int randomLed;
int randomBuzz;

//int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  stato = LOW;
  Serial.println("Premi bottone per cominciare test led");
  while (stato == LOW) 
  {
    if (digitalRead(button) == HIGH)
    {
      stato = HIGH;
    }

  }
  Serial.println("Premi appena si accende il led");
  randomLed = random(1000, 6000);
  delay(randomLed);
  digitalWrite(led, HIGH);
  tempoLed = millis();
  stato = LOW;
  while (stato == LOW)
  {
    if (digitalRead(button) == HIGH)
    {
      stato = HIGH;
    }
  }
  if (stato == HIGH)
  {
    digitalWrite(led, LOW);
    tempoLed = millis() - tempoLed;
    Serial.println(tempoLed);
    if (tempoLed > 60000)
    {
      Serial.println("Bocciato nel test del led");
    }
    else
    {
      lcd.setCursor(12, 0);
      Serial.println("Promosso nel test del led");
    }
  }
  stato = LOW;
  Serial.println("Premi appena senti il buzzer suonare");
  randomBuzz = random(1000, 6000);
  delay(randomBuzz);
  digitalWrite(buzzer, HIGH);
  tSuono = millis();
  while (stato == LOW)
  {
    stato = digitalRead(button);
    if (stato == HIGH)
    {
      digitalWrite(buzzer, LOW);
      tSuono = millis() - tSuono;
      Serial.println(tSuono);
      if (tSuono > 5000)
      {
        Serial.println("Bocciato");
      }
      else
      {
        Serial.println("Promosso");
      }
    }
  }

}
