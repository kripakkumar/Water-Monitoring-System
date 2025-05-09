# Water Level Monitoring System

This project simulates a water level monitoring system using the PIC18F4580 microcontroller. It features both **Manual** and **Automatic** modes to control a motor based on the water level.

## Features
- **Automatic mode:** Turns the motor ON/OFF based on predefined water level thresholds.
- **Manual mode:** The User can control the motor regardless of the water level.
- Designed for **efficient water usage** and **flood prevention** in tanks.

## Tools & Technologies
- **Microcontroller:** PIC18F4580
- **Simulation Software:** Proteus
- **Compiler:** MPLAB IDE
- **Programming Language:** Embedded C

## Working Principle
1. Water level is sensed (simulated using sensors in Proteus).
2. In **Automatic Mode**, the system turns the motor ON if the water level drops below a set point, and OFF if it exceeds another.
3. In **Manual Mode**, the user can override automatic control to operate the motor manually.

## Circuit Overview
- Input: Water level sensors (simulated)
- Output: Motor (simulated with LED or motor symbol)
- Switches to toggle between manual and auto modes

## Future Enhancements
- Real hardware implementation using PIC microcontroller
- Add buzzer or GSM alert for critical levels
- Display system status on an LCD

**Kripa K Kumar**

> Feel free to fork, modify, or suggest improvements!
