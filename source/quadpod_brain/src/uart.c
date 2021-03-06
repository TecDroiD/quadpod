/*
 * uarth.c
 *
 *  Created on: 04.01.2014
 *      Author: tecdroid
 */

#include "uart.h"

void (*_isr_recv)(char p) = 0;
void (*_isr_send)(void) = 0;

void uart_init() {
	// Setze Baudrate 9600
	UBRRH = (unsigned char )BAUDRATE >> 8;
	UBRRL = (unsigned char )BAUDRATE;

	// Enable send, receive
	UCSRB |= (1<<RXCIE) | (1<<RXEN) | (1<<TXEN);

	// 8 Bit-Daten, 1 Stopbit
	UCSRC |= (1<<UCSZ1) | (1>>UCSZ0);

}

void uart_recv(char *p) {
	while(! (UCSRA & (1<<RXC)) );
		*p = UDR;
}

void uart_send(char *p) {
	while(! (UCSRA & (1<<UDRE)) );
		UDR = *p;
}

void uart_set_recv(void (*func)(char p)) {
	_isr_recv = func;
}

void uart_set_send(void (*func)(void)) {
	_isr_send = func;
}

ISR(USART_RXC_vect) {
	if (_isr_recv != 0) {
		char x = UDR;
		_isr_recv(x);
	}
}

ISR(USART_TXC_vect) {
	if (_isr_send != 0) {
		_isr_send();
	}
}
