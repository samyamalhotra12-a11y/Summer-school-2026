​ LED Blink Project
​This repository contains the code and documentation for the foundational "LED Blink" project. The goal of this project is to verify the hardware setup, test the development environment, and demonstrate basic digital output control by making an LED turn on and off at regular intervals.
​
Hardware Required

​Arduino Uno 
​LED (Light Emitting Diode, any color)
​Resistor (220Ω)
​Breadboard
Potentiometer(10kΩ)
​Jumper wires
​USB data cable

​Circuit Diagram Description
​Connect the LED anode (+) to Arduino digital pin 13 through a 220 Ω resistor.
Connect the LED cathode (−) to GND.
Connect one outer pin of the potentiometer to 5V.
Connect the opposite outer pin of the potentiometer to GND.
Connect the middle (wiper) pin of the potentiometer to analog pin A0.
​
How to Upload Code
​Connect the Arduino Uno to the computer using a USB cable.
Open the Arduino IDE.
Open the led_blink.ino sketch.
Select Tools → Board → Arduino Uno.
Select the correct COM port under Tools → Port.
Click the Verify button to compile the code.
Click the Upload button to upload the program to the Arduino.
Open the Serial Monitor (9600 baud) to view the blink count.

Expected Output
The LED blinks continuously.
The potentiometer changes the blinking speed.
The Serial Monitor displays:
Blink count: 1
Blink count: 2
Blink count: 3
...

​Troubleshooting Tips
​Verify that the correct Arduino board and COM port are selected.
Check all wiring connections, especially the LED polarity and potentiometer connections.
Ensure the baud rate of the Serial Monitor is set to 9600.
Confirm that the resistor is connected in series with the LED.
If the LED does not blink, verify that the code has been uploaded successfully.
​The LED is very dim (or immediately burnt out): Verify your resistor value. If you used a resistor with too high of a value (e.g., 10kΩ), the LED will be incredibly dim. If you bypassed the resistor completely, the LED likely drew too much current and burnt out, requiring a replacement.
