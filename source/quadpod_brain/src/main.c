/*
 * main.c
 *
 *  Created on: 01.01.2014
 *      Author: tecdroid
 */
#include <avr/io.h>
#include <util/delay.h>

#include <stdlib.h>
#include <stdint.h>

#include "servo.h"
#include "uart.h"

t_servo servos[] = {
		{&DDRB, &PORTB, (1<<PB0), 0},
		{&DDRB, &PORTD, (1<<PD5), 0},
		{&DDRB, &PORTD, (1<<PD6), 0},
		{&DDRB, &PORTD, (1<<PD7), 0},

		{&DDRB, &PORTB, (1<<PB1), 0},
		{&DDRB, &PORTB, (1<<PB2), 0},
		{&DDRB, &PORTB, (1<<PB3), 0},
		{&DDRB, &PORTB, (1<<PB4), 0}

};

static const int CNT_SERVOS = 8;


int main(int argc, char **argv){
	int cnt;

	// Programmierpause
	_delay_ms(1000);

	// Servos initialisieren
	init_servos (servos, CNT_SERVOS);


	// UART initialisieren
	uart_init();

	// TODO: GPIOs initialisieren
	// TODO: Steuerprotokoll erfinden

	// Interrupts aktivieren
	sei();
	// eventloop
	while (1) {
	}
}


