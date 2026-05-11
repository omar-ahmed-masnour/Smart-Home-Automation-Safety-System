# Smart-Home-Automation-Safety-System
A comprehensive smart home solution built on the **ATmega32** microcontroller that automates lighting, climate control, and fire safety protocols using a layered software architecture.

## Key Features
*   **Automatic Lighting Control**: Utilizes an **LDR sensor** to monitor ambient light intensity, dynamically toggling a 3-LED array (Red, Green, Blue) based on four specific brightness thresholds.
*   **Climate-Responsive Fan Control**: Monitors room temperature via an **LM35 sensor** and adjusts DC motor speed proportionally (25%, 50%, 75%, or 100%) using **PWM signals**.
*   **Fire Detection & Alarm**: Integrates a **flame sensor** to detect fire hazards, triggering an audible buzzer alarm and a "Critical alert!" visual warning on the LCD.
*   **Real-Time Status Dashboard**: A 16x2 LCD provides live updates on fan state, temperature (Celsius), and light intensity percentage.

---

## Technical Specifications
*   **Microcontroller**: ATmega32 (System Frequency: 16 MHz).
*   **Software Architecture**: Implemented using a **Layered Model** (Application $\rightarrow$ HAL $\rightarrow$ MCAL/Drivers).
*   **Core Drivers**:
    *   **ADC**: Configured with an internal 2.56V reference and a $$F_{CPU}/128$$ prescaler for high-accuracy sensor readings.
    *   **PWM**: Utilizes **Timer0** in non-inverting mode with a $$F_{CPU}/1024$$ prescaler to drive the fan motor.
    *   **LCD**: Operated in **8-bit data mode** for high-speed display updates.
    *   **Motor Control**: Driven via an **H-Bridge** circuit to manage fan rotation and speed.

---

## Operational Logic

### Lighting Thresholds
| Ambient Light Intensity | LED Status |
| :--- | :--- |
| < 15% | All 3 LEDs ON |
| 16% — 50% | Red and Green LEDs ON |
| 51% — 70% | Only Red LED ON |
| > 70% | All LEDs OFF |


### Fan Speed Thresholds
| Temperature | Fan Speed |
| :--- | :--- |
| $\ge$ 40°C | 100% Speed |
| 35°C — 39°C | 75% Speed |
| 30°C — 34°C | 50% Speed |
| 25°C — 29°C | 25% Speed |
| < 25°C | Fan OFF |
