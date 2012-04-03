/*
 * am128_DS1307_test.c
 *
 * Created: 4/3/2012 12:26:36 PM
 *  Author: Owner
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "vfd.h"
#include "ds1307.h"
#include "i2c.h"
#include "global.h"

char buffer[20];

int main(void)
{
	i2cInit();
	ds1307_init(kDS1307Mode24HR);
	
	ds1307_set_hours(13);
	ds1307_set_minutes(02);
	ds1307_set_seconds(15);
	vfd_init();
	_delay_ms(100);
	vfd_puts("Hello");
	_delay_ms(1000);
    while(1)
    {
		u08 hour = ds1307_hours();
		u08 minute = ds1307_minutes();
		u08 second = ds1307_seconds();
		sprintf(buffer,"%02d:%02d:%02d",hour,minute,second);
		vfd_cls();
		vfd_puts(buffer);
		_delay_ms(1000);
    }
}