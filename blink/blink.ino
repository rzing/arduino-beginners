/*
 * Blink
 * 
 * Flashes an LED.
 */

// Define what pin we'll be using for the LED.
#define LEDPIN 10

// This function runs initially, when the Arduino starts
void setup() {
	// Set the pin as an output
	pinMode(LEDPIN, OUTPUT); // It can be set as either OUTPUT/INPUT.
}

// This code runs forever, in a loop.
void loop() {
	// Turns on the pin
	digitalWrite(LEDPIN, HIGH); // It can be set to HIGH (on) or LOW (off)
	delay(1000); // Waits for 1000 milliseconds - one second.
	digitalWrite(LEDPIN, LOW); // Turns off the pin
	delay(1000);
	// After the delay, since the loop() runs repeatedly, the LED will turn on again.
}

