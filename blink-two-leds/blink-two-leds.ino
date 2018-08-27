/*
 * Two LED Blink
 * 
 * Flashes two LEDs alternately.
 */

// Define the pins of both the LEDs.
#define LED1PIN 2
#define LED2PIN 3

void setup() {
	// Turn them both into OUTPUTs.
	pinMode(LED1PIN, OUTPUT);
	pinMode(LED2PIN, OUTPUT);
}

void loop() {
	digitalWrite(LED1PIN, HIGH);
	digitalWrite(LED2PIN, LOW);
	delay(500);
	digitalWrite(LED1PIN, LOW);
	digitalWrite(LED2PIN, HIGH);
	delay(500);
}



