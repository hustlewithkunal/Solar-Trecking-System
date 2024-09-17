Solar Tracking System
This project implements a solar tracking system that dynamically adjusts the position of a solar panel based on the sun’s direction, optimizing energy absorption throughout the day. Using LDR sensors to detect sunlight intensity and a motorized mechanism, the system ensures that the panel stays oriented toward the sun for maximum efficiency.

Project Overview
Solar tracking systems can significantly improve the efficiency of solar panels by ensuring they are always positioned at the optimal angle to capture the most sunlight. This project uses a combination of sensors and motors to automatically move the panel throughout the day.

Components
4 x LDR Sensors: Light-dependent resistors are used to detect the intensity of sunlight from different directions.
1 x DC Motor (200 RPM): Controls the horizontal rotation of the solar panel.
1 x Servo Motor: Adjusts the vertical tilt of the solar panel.
1 x Solar Panel: The primary energy collector.
1 x Arduino UNO: The microcontroller that processes data from the sensors and controls the motors.
1 x L298N Motor Driver: Used to drive the DC motor.
1 x 9V Battery: Powers the system.

Working Principle
The system continuously reads the values from four LDR sensors positioned in different orientations around the solar panel. Based on the light intensity detected by each sensor, the Arduino UNO calculates the direction in which the panel should move. The DC motor and the servo motor work together to rotate the panel horizontally and adjust its vertical tilt to align with the direction of the brightest sunlight.

This dynamic adjustment allows the solar panel to face the sun throughout the day, maximizing energy capture.

Circuit Diagram
File is attached in the repo.

Installation

Hardware Setup:
Connect the LDR sensors to the Arduino's analog pins.
Attach the DC motor to the motor driver (L298N) and connect the motor driver to the Arduino.
Connect the servo motor to one of the Arduino's PWM pins.
Power the system with a 9V battery.

Code:
Code file has been uploaded in the repo.
The code includes logic to read the LDR sensors, process the data, and control the motors.


Future Improvements
Add support for real-time clock (RTC) to improve system accuracy in cloudy conditions.
Implement wireless monitoring and control via a mobile app or web interface.
Increase battery capacity for longer autonomous operation.

Conclusion
This solar tracking system offers a simple yet effective way to boost solar panel efficiency by ensuring continuous alignment with the sun’s position. With minimal components and an easy-to-understand codebase, this project serves as an excellent introduction to renewable energy systems and embedded electronics.
