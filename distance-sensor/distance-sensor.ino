/*
 * Distance Sensor
 * 
 * Prints out the distance to an object using a distance senor.
 */

const int MIN_TRIG_MICROSECONDS_DELAY = 10; // We have to keep the trigger on for at least 10μs

#define DISTANCE_SENSOR_TRIGGER_PIN 7
#define DISTANCE_SENSOR_ECHO_PIN 8

void setup() {
	pinMode(DISTANCE_SENSOR_TRIGGER_PIN, OUTPUT);
	pinMode(DISTANCE_SENSOR_ECHO_PIN, INPUT);
	digitalWrite(DISTANCE_SENSOR_TRIGGER_PIN, LOW); // Don't tell the sensor to start just yet.

	// Begin serial connection
	Serial.begin(9600);
}

/*
 * Just like setup() and loop(), getDistance() here is a function. However, it doesn't run
 * automatically like setup() and loop() do. You need to "call" the function to run it, either
 * from setup() or loop(). In fact, things like pinMode() and digitalWrite() and delay(), that we've been using,
 * are functions. We'll call a function like getDistance in a similar way to how we call pinMode()
 * and digitalWrite() - using its name followed by an opening parentheses, the function's inputs,
 * and closing parentheses. In this case, getDistance requires no input, so we just call it like this -
 * 
 * getDistance();
 * 
 * In loop(), we'll see how to get the result that this function gives us back.
 * 
 * Generally, we make seperate functions like this in order to put some code that may be
 * complicated or very low-level, so that we don't have to worry about it again. 
 */
float getDistance() {
	// Send a HIGH to the trigger pin for the duration of the trigger delay.
	digitalWrite(DISTANCE_SENSOR_TRIGGER_PIN, HIGH);
	delayMicroseconds(MIN_TRIG_MICROSECONDS_DELAY); // delayMicroseconds() works like delay(), except it waits for microseconds instead of milliseconds.
	digitalWrite(DISTANCE_SENSOR_TRIGGER_PIN, LOW);

	// Now we wait for a pulse to come back on the echo pin. This means that the sensor's ready.
	pulseIn(DISTANCE_SENSOR_ECHO_PIN, HIGH); // pulseIn waits for the specified pin to go HIGH.

	// The closer something is, the longer the echo pin will be HIGH. Measure that amount of time.
	// Wait for it to go LOW this time

	/*
	 * Long variables, unlike ints, can go very big. They're able to hold up to the number 2,147,483,647.
	 * Compare that to the int, which can hold only up to 65,535 (on the Uno, the board we're using).
	 * While that may seem, well, long (pun intended), we'll be measuring the time in microseconds -
	 * so we never know when the time might be too long. So, to be safe, we're using an
	 * "unsigned long" - a long that can go up to 4,294,967,29. Be aware, though, that
	 * unsigned longs can't be negative - but in this instance, we don't care anyway, since if time
	 * becomes negative, or starts going backwards, we'll have bigger things to worry about than distance sensors.
	 */
	unsigned long pulse_width = pulseIn(DISTANCE_SENSOR_ECHO_PIN, LOW); // Now pulse_width is the amount of microseconds the sensor took to become LOW again.

	// This formular comes from the datasheet of the sensor. The datasheet of some piece of hardware
	// is often the best place to get useful information about using the sensor. For example,
	// the method we used above, we got from the the datasheet. Usually, Googling the name of
	// the sensor followed by "datasheet" should get you the result.

	// A "float" means it can be decimal.
	float cm = pulse_width / 58.0;

	// Now, to give back this result to whoever called us, we need to use "return".
	return cm;
}

void loop() {
	// This'll store the results of getDistance() into a variable. The results mean whatever getDistance has returned, using the return statement.
	float dist = getDistance();
	Serial.print(dist);
	Serial.println(" cm");
	// Wait for a second so we can read the results.
	delay(1000);
}
