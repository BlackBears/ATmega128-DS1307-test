/*! \file ds1307.h \brief DS1307, support for real-time clock for AVR */
//*****************************************************************************
//
//  File Name       : 'ds1307.h'
//  Title           : DS1307 real-time clock support for AVR        
//  Author          : Alan K. Duncan - Copyright (c) 2012
//  Created         : 2012-03-30
//  Modified        : 2012-04-03
//  Version         : 1.0
//  Target MCU      : Atmel AVR series
//
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//
//*****************************************************************************

#ifndef DS1307_H_
#define DS1307_H_

#include "global.h"

enum { kDS1307Mode12HR, kDS1307Mode24HR};
typedef u08 DS1307HourMode;

//! Initialize the DS1307 device with hour mode
void ds1307_init(DS1307HourMode mode);

//! Read the seconds register
u08 ds1307_seconds(void);

//! Read the minutes register
u08 ds1307_minutes(void);

//! Read the hours register
u08 ds1307_hours(void);

//! Read the date register
u08 ds1307_date(void);

//! Set the seconds
void ds1307_set_seconds(u08 seconds);

//! Set the minutes
void ds1307_set_minutes(u08 minutes);

//! Set the hours
void ds1307_set_hours(u08 hours);

//! Set the year
void ds1307_set_year(u08 year);

#endif /* DS1307_H_ */