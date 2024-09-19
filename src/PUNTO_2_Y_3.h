#include <Arduino.h>
#ifndef _PUNTO1_H_
#define _PUNTO1_H_

void mostrado(uint8_t i, uint8_t val_fila, uint8_t cant);

void enviar_mensaje(uint8_t *columna, uint8_t *mensaje);

void Multiplexado(uint16_t num);


#endif