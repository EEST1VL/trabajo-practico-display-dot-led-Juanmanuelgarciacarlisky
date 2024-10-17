#include <Arduino.h>

extern uint8_t fila[7];
extern char msj[];
extern uint8_t columna[128];
extern uint8_t FILA;
extern uint8_t p;
extern uint8_t aux;
extern uint8_t cnt;
extern uint16_t flag_tiempo, flag_END_TIME, flag_titilado;
extern uint8_t total_ms, flag1, flag2, flag3, old_cnt;
extern uint8_t flag_tiempo_suma, flag_tiempo_resta;
extern bool flag_estado_END_TIME;
extern uint16_t tiempo;
extern uint16_t cnt2;

void Registro_de_desplazamiento(uint64_t val, uint8_t cant);

void config_TIMER0(void);

void enviar_mensaje(uint8_t *columna, const char *mensaje);

void mostrado(uint8_t i, uint8_t val_fila, uint8_t cant);

void Multiplexado(uint16_t num);

 void enable(void);

 void puertos(void);

 void barrido_display(void);

 void Multiplexado_filas(void);

 void pulsadores(void);