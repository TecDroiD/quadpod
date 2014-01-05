/*
 * servo.h
 *
 *  Created on: 04.01.2014
 *      Author: tecdroid
 */

#ifndef SERVO_H_
#define SERVO_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdlib.h>
#include <stdint.h>

#define TIMEBASE F_CPU/64
#define PAUSE (TIMEBASE/255)*12

typedef struct s_servo {
	volatile unsigned char *DDR;
	volatile unsigned char *PORT;
	volatile char pinmask;
	volatile uint16_t value;
} t_servo, *p_servo;


void init_servos (p_servo pservos, int cnt );
void init_servotimer (void);
void set_servo(int id, uint8_t value);
#endif /* SERVO_H_ */
