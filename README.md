# P.E.R.A-ARDUINO-CODE
 Software for implementation in the rocket launch data collection system
This software has the function of obtaining sensors data and proccesing and send to SD card.

The SD card data can be use to plot grafics and perform analysis after the flight, for after  the flight to improve the functioning of the device.
it has 3 sensors to measure acceleration, pressure, atmosfercial pressure, termometer and giroscope.
The communication is done with the I2C, the Arduino receives data, processes and sends it to the SD card.
the program must have the instant check for openinh the saety parachute, made through a servo motor.
