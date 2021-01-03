/*
 * ArduinoIncludes.h
 *
 *  Created on: 10 abr. 2020
 *      Author: Diego
 */

#ifndef DEBUG_MOCKLIBRARY_ARDUINOINCLUDES_H_
#define DEBUG_MOCKLIBRARY_ARDUINOINCLUDES_H_
	#include "FS.h"
	#define S(string_literal) string_literal
	#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#endif /* DEBUG_MOCKLIBRARY_ARDUINOINCLUDES_H_ */
