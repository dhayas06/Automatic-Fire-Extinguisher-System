Testing Plan
1. Objective
The objective of this testing plan is to verify the basic operation and functionality of the ESP32-based fire detection prototype. The testing focuses on sensor readings, controller behaviour, detection logic, simulated warning outputs, and basic fault handling. It also helps identify hardware and software errors before further development.

2. Testing Scope
The testing covers the initialization of the ESP32, communication with connected sensors, reading and displaying sensor data, LED warning indication, detection logic, and basic error handling. The prototype is tested under safe and controlled environmental conditions. Real fire suppression performance is not included in the initial testing.

3. Required Components
The following components are required to perform the prototype tests:

ESP32 development board: Processes sensor inputs and executes the program.

MQ-2 smoke sensor: Provides smoke- and combustible-gas-related readings.

IR flame sensor: Detects suitable infrared radiation.

DHT11 sensor: Measures temperature and humidity.

LED and suitable resistor: Simulates the warning output.

USB cable and power source: Supplies power and enables programming.

Computer with Arduino IDE: Used to compile, upload, and debug the program.

The actual sensor models, pin assignments, and operating voltages must be verified before testing.

4. Pre-Test Checklist
Before starting the tests, the following checks should be completed:

Verify the ESP32 board model and GPIO pin assignments.

Check the power supply and sensor wiring.

Confirm that the LED has a suitable current-limiting resistor.

Install the required libraries in Arduino IDE.

Select the correct board and serial port.

Verify that the firmware compiles without errors.

Keep the suppression cartridge and activation mechanism disconnected.

These checks help prevent wiring errors and protect the electronic components from damage.

5. Test Cases
The following test cases are used to evaluate the prototype's basic functions.

TC-01: ESP32 Initialization Test — Verify that the ESP32 starts and executes the uploaded program.

TC-02: Sensor Initialization Test — Check whether the connected sensors initialize correctly.

TC-03: MQ-2 Sensor Test — Verify that sensor readings are displayed in the Serial Monitor.

TC-04: IR Flame Sensor Test — Check the sensor output under suitable, controlled test conditions.

TC-05: DHT11 Sensor Test — Verify that valid temperature and humidity values are displayed.

TC-06: LED Output Test — Confirm that the LED responds to the programmed warning condition.

TC-07: Fault-Handling Test — Check how the program responds to invalid or unavailable sensor data.

TC-08: Continuous Operation Test — Verify that sensor readings continue without unexpected program interruption.

TC-09: Detection Logic Test — Check whether the program identifies the defined input conditions correctly.

TC-10: Restart Test — Verify that the ESP32 resumes normal operation after a routine reset.

Each test should be marked Pass, Fail, or Pending based on the actual observations.

6. Testing Procedure
First, inspect the hardware connections and confirm that the circuit is safe to power on. Upload the firmware using Arduino IDE and open the Serial Monitor at the configured baud rate.

Next, observe the sensor readings under ordinary environmental conditions. Check whether the values are displayed correctly and whether they change appropriately during controlled, safe tests permitted by the sensor manufacturers.

After checking the sensors, verify the LED output using the implemented detection logic or a dedicated test mode. Examine any error messages and repeat relevant tests to check consistency. Record all observations, unexpected behaviour, and corrective actions.

7. Test Results
The results should be recorded in a test-results table for future reference.

Test ID

Test description

Observed result

Status

TC-01

ESP32 initialization

To be recorded

Pending

TC-02

Sensor initialization

To be recorded

Pending

TC-03

MQ-2 sensor reading

To be recorded

Pending

TC-04

Flame sensor reading

To be recorded

Pending

TC-05

Temperature and humidity

To be recorded

Pending

TC-06

LED warning output

To be recorded

Pending

TC-07

Fault handling

To be recorded

Pending

TC-08

Continuous operation

To be recorded

Pending

TC-09

Detection logic

To be recorded

Pending

TC-10

Restart and recovery

To be recorded

Pending

The results should be updated only after performing the corresponding tests. Any failure should be investigated, corrected, and retested where appropriate.

8. Safety Precautions
Safety precautions must be followed throughout the testing process.

Do not create an uncontrolled fire or hazardous smoke conditions.

Disconnect power before modifying circuit connections.

Ensure that sensor output voltages are compatible with the ESP32.

Avoid short circuits and incorrect polarity.

Keep real fire suppression hardware disconnected.

Follow the manufacturer's instructions for each component.

Do not consider successful sensor readings as proof of reliable fire detection.

The prototype should be treated as an experimental electronic system, not as a certified fire safety device.

9. Limitations
The testing plan evaluates only the basic functionality of the installed hardware and programmed firmware. Sensor readings may vary depending on environmental conditions, calibration, and component characteristics.

The tests do not establish the accuracy of fire detection under all conditions, long-term reliability, or the effectiveness of a real suppression system. Further testing, calibration, engineering evaluation, and compliance assessment would be necessary before practical deployment.

10. Conclusion
The testing plan provides a systematic method for evaluating the ESP32-based fire detection prototype. It verifies sensor communication, controller operation, warning indication, detection logic, and basic fault handling.

The recorded results help identify hardware and software problems and support future improvements. Successful completion of these tests demonstrates basic prototype functionality only; additional validation is required before the system can be considered for real-world fire safety applications.


