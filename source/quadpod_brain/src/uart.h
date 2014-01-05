/*
 * uart.h
 *
 *  Created on: 04.01.2014
 *      Author: tecdroid
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdlib.h>
#include <stdint.h>

#ifndef BAUDRATE
#define BAUDRATE 9600
#endif
#define BUBRR F_CPU/16/BAUDRATE-1

void uart_init();
void uart_recv(char *p);
void uart_send(char *p);

void uart_set_recv(void (*func)(char p));
void uart_set_send(void (*func)(void));
#endif /* UART_H_ */
