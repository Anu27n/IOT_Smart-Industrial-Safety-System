1.COMPONENTS USED:
1.
Arduino (Microcontroller): The central processing unit of the system that processes input from various sensors and controls the system's responses. It processes data from sensors like the shock, pressure, and force sensors and triggers actions like emergency shutdowns or alerts.
2.
Shock Sensor: Detects sudden movements or shocks, typically caused by machinery malfunctions. This sensor plays a crucial role in identifying potential hazards in industrial machinery.
3.
Pressure Sensor: Monitors the pressure in pipes, valves, or tanks to prevent accidents caused by pressure overload. It provides real-time pressure data to ensure safe operating conditions.
4.
Force Sensor: Used to detect the amount of force applied to machinery or objects. It helps ensure workers do not interact with hazardous equipment inappropriately.
5.
Relay Module: Acts as an interface between the microcontroller and machinery or other high-power systems, allowing the system to trigger an emergency shutdown or control heavy equipment.
6.
Buzzer/Alarm: A loud sound indicator used to alert workers in case of a detected hazard or emergency condition.
7.
LCD/LED Display: Displays real-time data from the sensors, as well as system status, to provide operators with a visual indication of the safety system's operation.
8.
Servo Motor: Serves as an actuator to perform physical actions like shutting down machinery in response to detected hazards or closing the valves of pipe.
9.
Jumper Wires: Used to connect various components (such as sensors and the relay) to the Arduino, ensuring proper electrical signal transfer across the circuit.
10.
USB Power Supply: Provides power to the Arduino and connected components, ensuring the system operates continuously in an industrial environment.
2.CIRCUIT SETUP:
2.1. Force-Sensitive Resistor (FSR): Connect the FSR to the Arduino UNO:
• SIG (FSR) → A0 (Arduino) for analog force detection.
• VCC (FSR) → 5V (Arduino).
• GND (FSR) → GND (Arduino).
2.2. Pressure Sensor: Connect the pressure sensor to the Arduino UNO:
• SIG (Pressure Sensor) → A1 (Arduino) for analog pressure data.
• VCC (Pressure Sensor) → 5V (Arduino).
• GND (Pressure Sensor) → GND (Arduino).
2.3. Shock Sensor: Connect the shock sensor to the Arduino UNO:
• OUT (Shock Sensor) → Digital Pin 2 (Arduino).
• VCC (Shock Sensor) → 5V (Arduino).
• GND (Shock Sensor) → GND (Arduino).
2.4. Servo Motor:
•
SIG (Servo) → Digital Pin 9 (PWM Pin) on Arduino.
•
Power Pins connected to 5V and GND on Arduino.
2.5. LED: The LED is connected to Pin 13 for visual hazard alerts.
2.6. Buzzer: The Arduino code monitors sensor readings for force, pressure, and shock. On detecting a hazard:
• The onboard LED turns on.
• Specific alerts are logged to the Serial Monitor, displaying the source of the hazard.
2.6. Testing and Adjustment:
• Test the thresholds (FSR_THRESHOLD, PRESSURE_THRESHOLD) and adjust based on the sensor outputs for accurate hazard detection.
