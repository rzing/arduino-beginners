/*
 * Active Buzzer
 * 
 * Beeps a buzzer using only HIGH and LOW.
 */

#define BUZZER 9

void setup() {
	pinMode(BUZZER, OUTPUT);
}

void loop() {
	digitalWrite(BUZZER, HIGH);
	delay(1000);
	digitalWrite(BUZZER, LOW);
	delay(1000);
}

