# 

'Stay Safe' LED display (created in response to Covid-19).


## Hardware
* 1 x 5mm DC Jack socket
* 1 x L7805CV 5V voltage regulator
* 1 x 10µF electrolytic capacitor
* 1 x 100µF electrolytic capacitor
* 1 x Ardiuno Nano ATmega168 5V 16MHz
* 1 x Momentary switch / push button
* 1 x 10KΩ resistor
* 1 x ULN2803A Darlington Array
* 1 x Piezo buzzer
* 3 x 1x3 headers
* 1 x 1x2 headers
* 7 x 4608X-102-331LF resistor network ( each with 4 x 330Ω elements) 
* 39 x 3mm yellow LED
* 39 x 3mm green LED

### Block diagram

![](https://github.com/alicraigmile/stay-safe/raw/master/stay-safe.svg "Block diagram of the required hardware")

### Circuit diagram

![](https://github.com/alicraigmile/stay-safe/raw/master/control.svg "Circuit diagram showing individual pin connections in control circuit")

![](https://github.com/alicraigmile/stay-safe/raw/master/stay.svg "Circuit diagram showing 'stay' LED arrangement")

![](https://github.com/alicraigmile/stay-safe/raw/master/safe.svg "Circuit diagram showing 'safe' LED arrangement")

### Connections

1. The system is powered via a 12V power supply which is connected to pins 1 and 2 of the 5V regulator (U1) via the 1x2 header block.
2. A 100µF electrolytic capacitor is connected across the input of Q1, and 10µF electrolytic capacitor is connected across its output.
2. VIN of the arduino is is connected to the output of Q1 (pin 3), and ground.
3. The buzzer is connected to D6 of the arduno, and ground.
4. The push button is connected between D2 of the arduino and 5v (U1 pin 3). D2 also has a 10KΩ pull-down resistor to ground.
5. D8 and D9 of the arduino connect to input pins 1 and 3 of the darlington transistor IC (Q1).
6. Q1 com pin connects to 12V. Q3 gnd pin connects to ground.
7. Q1 outputs are pin 2 (stay LEDs) and pin 4 (safe LEDs) and these are connected to the first 2 pins of a 1x3 header, with 12V connected to the 3rd.
8. Stay LEDs are connected 13P3S formation, each chain running through a 330Ω resistor. +ve connection to 12V (via header block).
9. Safe LEDs the same.
10. -ve connection of Stay LEDs is to pin 2 of Q3 (via header block).
11. -ve connection of Safe LEDs is to pin 4 of Q3 (via header block).

## Software

Download the following code and upload it to the Arduino:

https://github.com/alicraigmile/stay-safe/tree/master/src/stay-safe

### How exactly?

See https://www.arduino.cc/en/Guide/ArduinoNano#toc5

### Dependancies

My arduino was a clone and so I needed drivers for the USB serial interface - https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver

## Usage

Power it up and watch the display.

Pushing the button changes between 3 patterns. The buzzer will sound to tell you which pattern is active.

## Acknowledgements

'Stay safe' is inspired by the work of so many - from local and national government, the NHS, emergency services and further afield - who looked out for us during the Covid-19 pandemic. 




