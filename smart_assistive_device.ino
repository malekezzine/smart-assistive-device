// ================================================
// SMART ASSISTIVE DEVICE FOR VISUALLY IMPAIRED USERS
// Lunettes Intelligentes d'Assistance
// ================================================
// Author : Ezzine Malek
// School : IT Business School, Nabeul
// Year   : 2025-2026
// Board  : Arduino Nano (ATmega328P)
// ================================================

const int trigPin   = 2;
const int echoPin   = 3;
const int buzzerPin = 4;
const int motorPin  = 5;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(motorPin, LOW);
  Serial.begin(9600);
}

int getDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  distance = getDistanceCm();
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  // --------- Gestion du BUZZER en fonction de la distance ---------
  if (distance > 0 && distance < 100) {
    // On limite la distance dans [10, 100] pour éviter les valeurs extrêmes
    int distLimitee = distance;
    if (distLimitee < 10)  distLimitee = 10;
    if (distLimitee > 100) distLimitee = 100;

    // Plus on est proche, plus le délai est petit -> bips plus rapides
    // 10 cm  ->  50 ms
    // 100 cm -> 600 ms
    int delai = map(distLimitee, 10, 100, 50, 600);

    // BIP
    tone(buzzerPin, 2000);  // fréquence 2 kHz
    delay(delai);
    noTone(buzzerPin);
    delay(delai);
  } else {
    noTone(buzzerPin);
  }

  // --------- Gestion du MOTEUR VIBRANT ---------
  // Moteur ON si distance < 50 cm
  if (distance > 0 && distance < 50) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

  // Pas besoin de delay(50) ici, c'est déjà géré par les delays du buzzer
}
