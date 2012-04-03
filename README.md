This application is a simple test of two interfaces:

*  DS1307  Real-time clock
*  NEC FC20x2JA-AB 20x2 vacuum fluorescent display

Hardware setup
--------------
The setup for the DS1307 simply uses the parameters from the datasheet.  You need connections to VCC (+5V) and GND.  The setup requires a connection to the ATmega128 I2C pins. (SCL = PD0, SDA = PD1)

In parallel mode, the VFD requires multiple pins which are specified in the vfd header file.  We use PORTE for the data port (VFD_D0 = PE0, etc.) and PORTA as the control port:

*  VFD_CS   =>  PA2
*  VFD_A0   =>  PA1
*  VFD_WR   =>  PA0
*  VFD_BUSY =>  PA3
