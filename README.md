# Multi-Sensor Safety System  

## Overview  
The **Multi-Sensor Safety System** is designed to monitor industrial environments for hazardous conditions. Utilizing force, pressure, and shock sensors, the system provides real-time alerts and takes preventative actions to enhance safety.  

---

## Components  

1. **Arduino (Microcontroller)**  
   - Processes input from sensors and triggers actions like alerts or shutdowns.  

2. **Shock Sensor**  
   - Detects sudden movements or machinery malfunctions.  

3. **Pressure Sensor**  
   - Monitors pressure in pipes, valves, or tanks to prevent overload.  

4. **Force Sensor (FSR)**  
   - Detects applied force to ensure safe interaction with equipment.  

5. **Relay Module**  
   - Interfaces with high-power systems for emergency shutdowns.  

6. **Buzzer/Alarm**  
   - Alerts workers audibly in case of hazards.  

7. **LCD/LED Display**  
   - Displays real-time sensor data and system status.  

8. **Servo Motor**  
   - Performs physical actions like shutting down machinery or closing valves.  

9. **Jumper Wires**  
   - Connects components to the Arduino for signal transfer.  

10. **USB Power Supply**  
    - Powers the Arduino and components for continuous operation.  

---

## Circuit Setup  

### 1. Force-Sensitive Resistor (FSR)  
- **SIG** → `A0` (Arduino)  
- **VCC** → `5V` (Arduino)  
- **GND** → `GND` (Arduino)  

### 2. Pressure Sensor  
- **SIG** → `A1` (Arduino)  
- **VCC** → `5V` (Arduino)  
- **GND** → `GND` (Arduino)  

### 3. Shock Sensor  
- **OUT** → Digital Pin `2` (Arduino)  
- **VCC** → `5V` (Arduino)  
- **GND** → `GND` (Arduino)  

### 4. Servo Motor  
- **SIG** → Digital Pin `9` (PWM Pin)  
- Power connected to `5V` and `GND`  

### 5. LED  
- Connected to Pin `13` for hazard alerts.  

---

## Features  

- **Real-Time Monitoring**: Continuously monitors force, pressure, and shock levels.  
- **Alerts**:  
  - Visual (LED) and audible (buzzer) alerts for hazards.  
  - Logs hazard details to the Serial Monitor.  
- **Automated Responses**:  
  - Activates the servo motor to perform safety actions.  
- **Customizable Thresholds**: Configure `FSR_THRESHOLD` and `PRESSURE_THRESHOLD` to adapt to specific use cases.  

---

## Testing and Adjustments  

1. **Threshold Calibration**  
   - Adjust `FSR_THRESHOLD` and `PRESSURE_THRESHOLD` by observing sensor outputs in the Serial Monitor.  

2. **System Validation**  
   - Simulate hazards to test alert mechanisms and servo motor responses.  

---

## How to Use  

1. Assemble the circuit as described in the **Circuit Setup** section.  
2. Upload the Arduino code to the microcontroller.  
3. Power the Arduino via USB or an external power supply.  
4. Monitor real-time data and alerts in the Serial Monitor.  

---

## Circuit Diagram  

![image](https://github.com/user-attachments/assets/cf62b7a3-0876-4622-9861-28832a9e387a)


---

## Screenshots  

![image](https://github.com/user-attachments/assets/4a7cd466-0b97-44e3-9be9-ccef89897c1e)




---

## Future Enhancements  

- Add wireless communication (e.g., Wi-Fi or Bluetooth) for remote monitoring.  
- Integrate data logging for hazard analysis.  
- Add a camera module for visual inspection during alerts.  

---

