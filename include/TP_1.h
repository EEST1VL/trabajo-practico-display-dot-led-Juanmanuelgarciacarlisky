#include <Arduino.h>
#ifndef _PUNTO1_H_
#define _PUNTO1_H_


void Registro_de_desplazamiento(uint64_t val, uint8_t cant);

void config_TIMER0(void);

void enviar_mensaje(uint8_t *columna, uint8_t *mensaje);

void mostrado(uint8_t i, uint8_t val_fila, uint8_t cant);

void Multiplexado(uint16_t num);



#endif