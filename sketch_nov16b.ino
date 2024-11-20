#include <Servo.h>

const int FSR_PIN = A0;
const int PRESSURE_PIN = A1;
const int SHOCK_PIN = 2;
const int SERVO_PIN = 9;
const int LED_PIN = 13;

Servo safetyServo;

const int FSR_THRESHOLD = 5;
const int PRESSURE_THRESHOLD = 800;
const int ALERT_DURATION = 2000;

int fsrReading;
int pressureReading;
bool shockDetected;
bool hazardState = false;

bool fsrHazard = false;
bool pressureHazard = false;
bool shockHazard = false;

void setup() {
    Serial.begin(9600);
    pinMode(FSR_PIN, INPUT);
    pinMode(PRESSURE_PIN, INPUT);
    pinMode(SHOCK_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    safetyServo.attach(SERVO_PIN);
    safetyServo.write(0);
    Serial.println("Multi-Sensor Safety System Initialized");
    Serial.println("FSR\tPressure\tShock\tStatus");
}

void loop() {
    fsrReading = analogRead(FSR_PIN);
    pressureReading = analogRead(PRESSURE_PIN);
    shockDetected = digitalRead(SHOCK_PIN);

    fsrHazard = (fsrReading >= FSR_THRESHOLD);
    pressureHazard = (pressureReading >= PRESSURE_THRESHOLD);
    shockHazard = shockDetected;

    printSensorReadings();

    if ((fsrHazard || pressureHazard || shockHazard) && !hazardState) {
        hazardState = true;
        triggerHazardAlert();
    } else if (!fsrHazard && !pressureHazard && !shockHazard) {
        hazardState = false;
        resetSystem();
    }

    delay(100);
}

void printSensorReadings() {
    Serial.print(fsrReading);
    Serial.print("\t");
    Serial.print(pressureReading);
    Serial.print("\t");
    Serial.print(shockDetected);
    Serial.print("\t");

    if (hazardState) {
        if (fsrHazard) Serial.print("FSR ALERT! ");
        if (pressureHazard) Serial.print("PRESSURE ALERT! ");
        if (shockHazard) Serial.print("SHOCK ALERT! ");
    } else {
        Serial.print("Safe");
    }
    Serial.println();
}

void triggerHazardAlert() {
    safetyServo.write(90);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("\n*** HAZARD DETECTED! ***");
    if (fsrHazard) {
        Serial.println("WARNING: Excessive Force Detected!");
        Serial.print("Force Reading: ");
        Serial.println(fsrReading);
    }
    if (pressureHazard) {
        Serial.println("WARNING: High Pressure Detected!");
        Serial.print("Pressure Reading: ");
        Serial.println(pressureReading);
    }
    if (shockHazard) {
        Serial.println("WARNING: Impact Detected!");
    }
    delay(ALERT_DURATION);
}

void resetSystem() {
    safetyServo.write(0);
    digitalWrite(LED_PIN, LOW);
}
