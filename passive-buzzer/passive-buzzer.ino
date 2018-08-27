/*
 * Passive Buzzer
 * 
 * Beeps a buzzer in alternate frequenices.
 */

#define BUZZER 9 // Needs to be a PWM pin

void setup() {
	pinMode(BUZZER, OUTPUT);
}

void loop() {
	for (int i = 0; i <= 255 / 2; i++) {
		delay(1000);
		analogWrite(BUZZER, i);
		delay(1000);
		analogWrite(BUZZER, 255 - i);
		delay(1000);
		analogWrite(BUZZER, LOW);
	}
}
