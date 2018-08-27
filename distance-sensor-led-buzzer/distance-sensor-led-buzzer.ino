/*
 * Blink LED with Buzzer Distance Sensor.
 * 
 * Flashes an LED faster, and gradually makes a buzzer more annyoing, when some object is closer to a distance sensor.
 */

const int MIN_TRIG_MICROSECONDS_DELAY = 10; // We have to keep the trigger on for at least 10μs

#define DISTANCE_SENSOR_TRIGGER_PIN 7
#define DISTANCE_SENSOR_ECHO_PIN 8
#define LED 9
#define BUZZER 10

void setup() {
	pinMode(DISTANCE_SENSOR_TRIGGER_PIN, OUTPUT);
	pinMode(DISTANCE_SENSOR_ECHO_PIN, INPUT);
	digitalWrite(DISTANCE_SENSOR_TRIGGER_PIN, LOW);
}

unsigned long getDistance() {
	digitalWrite(DISTANCE_SENSOR_TRIGGER_PIN, HIGH);
	delayMicroseconds(MIN_TRIG_MICROSECONDS_DELAY);
	digitalWrite(DISTANCE_SENSOR_TRIGGER_PIN, LOW);

	pulseIn(DISTANCE_SENSOR_ECHO_PIN, HIGH);
	unsigned long pulse_width = pulseIn(DISTANCE_SENSOR_ECHO_PIN, LOW);

	return pulse_width;
}

void loop() {
	unsigned long dist = getDistance();
	dist = constrain(dist, 50, 8000);
	unsigned long ledDelay = map(dist, 50, 8000, 100, 1000);

	digitalWrite(LED, HIGH);
	delay(ledDelay);
	digitalWrite(LED, LOW);
	delay(ledDelay);
}
