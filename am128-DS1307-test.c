/*! \file   am128_DS1307_test.c \brief  Test DS1307 with ATmega128.          */
//*****************************************************************************
//
//  File Name       : 'am128_DS1307_test.c'
//  Title           : Test DS1307 with ATmega           
//  Author          : Alan K. Duncan - Copyright (c) 2012
//  Created         : 2012-04-03
//  Revised         : 2012-04-03
//  Version         : 1.0
//  Target MCU      : ATmega128
//
//  
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//
//*****************************************************************************

/*  Hardware requirements   */
/*  ATmega128, DS1307, and a vacuum fluorescent display (see vfd.h) */

#include <avr/io.h>
#include <util/delay.h>
#include "vfd.h"
#include "ds1307.h"
#include "i2c.h"
#include "global.h"

#define SET_CLOCK_ON_STARTUP 0
#define STARTUP_HOURS 13
#define STARTUP_MINS 02
#define STARTUP_SECS 15

/*  buffer to store time conversion */
char buffer[20];

int main(void)
{
    /*  initialize the I2C bus and the DS1307   */
	i2cInit();
	ds1307_init(kDS1307Mode24HR);
	
	/*  set the clock on startup (if desired    */
#if SET_CLOCK_ON_STARTUP
	ds1307_set_hours(STARTUP_HOURS);
	ds1307_set_minutes(STARTUP_MINS);
	ds1307_set_seconds(STARTUP_SECS);
#endif

    /*  initialize the VFD  */
	vfd_init();
	_delay_ms(100);
	vfd_puts("Hello");
	_delay_ms(1000);
	
    while(1)
    {
        /*  get data from the RTC   */
		u08 hour = ds1307_hours();
		u08 minute = ds1307_minutes();
		u08 second = ds1307_seconds();
		
		/*  format data and print to VFD    */
		sprintf(buffer,"%02d:%02d:%02d",hour,minute,second);
		vfd_cls();
		vfd_puts(buffer);
		
		_delay_ms(1000);
    }
}