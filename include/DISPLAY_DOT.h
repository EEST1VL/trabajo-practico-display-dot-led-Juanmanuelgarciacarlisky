#include <Arduino.h>

typedef enum
{
  STOP,
  START,
  ANALOGICO_DIGITAL,
  END_TIME,
  BOTON_SPEED
} ESTADO;
ESTADO estado;
uint16_t cnt = 2;

int16_t angle;
uint16_t old_angle;

uint8_t p;
uint8_t fila[7]{0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000};
uint8_t FILA;
uint8_t i;
uint8_t columna2[128]{48, 46, 48, 48, 86},
msj2[] = {48, 46, 48, 48, 86};
uint8_t columna[128]{
    48,
    48,
    109,
    58,
    48,
};
char msj[] = {48, 48, 109, 58, 48, 48, 115};
//uint8_t columna[128]{

//},
//msj[100] = {};
uint8_t cnt2;
uint8_t CONTADOR;
uint8_t cant_fila;
uint8_t val_fila;
uint8_t mensaje, temporal;
uint32_t valorAdc;
uint16_t flag_tiempo, flag_END_TIME, flag_titilado, global, temperatura2, flag;
uint8_t total_ms = 50, flag1, flag2, flag3, old_cnt, flag4, flag5;
uint8_t flag_tiempo_suma, flag_tiempo_resta;
bool flag_estado_END_TIME;
uint16_t tiempo;

/*Funciones */
void Config_Puertos(void);

void Conversion(uint16_t temperatura2);
void enviar_mensaje(uint8_t *columna, const char *mensaje);
void mostrado(uint8_t i, uint8_t val_fila, uint8_t cant,uint8_t *columna);
void Multiplexado(uint16_t num);
void config_TIMER0(void);
/*Funciones relacionadas a interrupciones */
void initInterrupts(void);

/*
 * TABLAS PRIVADAS AL MODULO
 */
/**
 * @brief Tabla de caracteres para mostrar en la matriz de puntos
 * @date ${date}
 * @author Nicolas Ferragamo nferragamo@frba.utn.edu.ar
 */
