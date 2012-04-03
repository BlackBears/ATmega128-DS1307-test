
// global AVRLIB defines
#include "avrlibdefs.h"
// global AVRLIB types definitions
#include "avrlibtypes.h"

//#define DEBUG 1

#ifndef F_CPU
	#define F_CPU 8000000L
#endif

#ifndef _BV
	#define _BV(bit) (1 << (bit))
#endif

#ifndef bit_is_set
	#define bit_is_set(u08, bit) (u08 & _BV(bit))
#endif

#define __ATtiny4313__

