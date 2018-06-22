##Print trigger for scanner or shock machine

import serial
#import sys, os #only import if this wasn't done previously
from time import sleep

#identify and open USB/serial port
device = 'COM3' #coded to address COM3
ser = serial.Serial(device, 57600, timeout=0)

#send trigger. note: this code doesn't work without a delay between port opening and trigger send. Not clear why, but account fot this by opening port in advance if you want trigger to be instantaneous with timing of a specific task event
sleep(2) #in seconds, builds in necessary delay

ser.write('s');# send out pulse

ser.close()# close port again

