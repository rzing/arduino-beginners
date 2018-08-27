/*
 * Distance Sensor LED Blink
 * 
 * Flashes an LED faster when some object is closer to a distance sensor.
 */

const int MIN_TRIG_MICROSECONDS_DELAY = 10; // We have to keep the trigger on for at least 10μs

#define DISTANCE_SENSOR_TRIGGER_PIN 7
#define DISTANCE_SENSOR_ECHO_PIN 8
#define LED 9

void setup() {
	pinMode(DISTANCE_SENSOR_TRIGGER_PIN, OUTPUT);
	pinMode(DISTANCE_SENSOR_ECHO_PIN, INPUT);
	digitalWrite(DISTANCE_SENSOR_TRIGGER_PIN, LOW);
}

unsigned long getDistance() {
	// This time, we don't care about the cm, only the pulse width.

	digitalWrite(DISTANCE_SENSOR_TRIGGER_PIN, HIGH);
	delayMicroseconds(MIN_TRIG_MICROSECONDS_DELAY);
	digitalWrite(DISTANCE_SENSOR_TRIGGER_PIN, LOW);

	pulseIn(DISTANCE_SENSOR_ECHO_PIN, HIGH);

	unsigned long pulse_width = pulseIn(DISTANCE_SENSOR_ECHO_PIN, LOW);

	return pulse_width;
}

void loop() {
	unsigned long dist = getDistance();
	dist = constrain(dist, 50, 8000); // constriain() limits a certain value to be between two values.
	// map() re-maps a number from one range to another.
	// In this example, a value of 50 would become 100, 8000 would become 1000, and anything in between
	// of 50 and 8000 would become in-betweens of 100 and 1000 on the same scale.
	unsigned long ledDelay = map(dist, 50, 8000, 100, 1000);
	digitalWrite(LED, HIGH);
	delay(ledDelay);
	digitalWrite(LED, LOW);
	delay(ledDelay);
}
