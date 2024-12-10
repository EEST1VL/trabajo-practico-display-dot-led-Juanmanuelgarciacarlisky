#include <Arduino.h>
#include "DISPLAY_DOT.h"

static uint8_t tabla[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // espacio
    0x00, 0x00, 0x5F, 0x00, 0x00, 0x00, // !
    0x00, 0x07, 0x00, 0x07, 0x00, 0x00, // "
    0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00, // #
    0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00, // $
    0x23, 0x13, 0x08, 0x64, 0x62, 0x00, // %
    0x36, 0x49, 0x55, 0x22, 0x50, 0x00, // &
    0x00, 0x05, 0x03, 0x00, 0x00, 0x00, // '
    0x00, 0x1C, 0x22, 0x41, 0x00, 0x00, // (
    0x00, 0x41, 0x22, 0x1C, 0x00, 0x00, // )
    0x14, 0x08, 0x3E, 0x08, 0x14, 0x00, // *
    0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, // +
    0x00, 0x50, 0x30, 0x00, 0x00, 0x00, // ,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x00, // -
    0x00, 0x60, 0x60, 0x00, 0x00, 0x00, // .
    0x20, 0x10, 0x08, 0x04, 0x02, 0x00, // /
    0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // 0
    0x00, 0x42, 0x7F, 0x40, 0x00, 0x00, // 1
    0x42, 0x61, 0x51, 0x49, 0x46, 0x00, // 2
    0x21, 0x41, 0x45, 0x4B, 0x31, 0x00, // 3
    0x18, 0x14, 0x12, 0x7F, 0x10, 0x00, // 4
    0x27, 0x45, 0x45, 0x45, 0x39, 0x00, // 5
    0x3C, 0x4A, 0x49, 0x49, 0x30, 0x00, // 6
    0x01, 0x71, 0x09, 0x05, 0x03, 0x00, // 7
    0x36, 0x49, 0x49, 0x49, 0x36, 0x00, // 8
    0x06, 0x49, 0x49, 0x29, 0x1E, 0x00, // 9
    0x00, 0x36, 0x36, 0x00, 0x00, 0x00, // :
    0x00, 0x56, 0x36, 0x00, 0x00, 0x00, // ;
    0x08, 0x14, 0x22, 0x41, 0x00, 0x00, // <
    0x14, 0x14, 0x14, 0x14, 0x14, 0x00, // =
    0x00, 0x41, 0x22, 0x14, 0x08, 0x00, // >
    0x02, 0x01, 0x51, 0x09, 0x06, 0x00, // ?
    0x32, 0x49, 0x79, 0x41, 0x3E, 0x00, // @
    0x7E, 0x09, 0x09, 0x09, 0x7E, 0x00, // A
    0x7F, 0x49, 0x49, 0x49, 0x36, 0x00, // B
    0x3E, 0x41, 0x41, 0x41, 0x22, 0x00, // C
    0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00, // D
    0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, // E
    0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, // F
    0x3E, 0x41, 0x49, 0x49, 0x7A, 0x00, // G
    0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, // H
    0x41, 0x41, 0x7F, 0x41, 0x41, 0x00, // I
    0x20, 0x40, 0x40, 0x40, 0x3F, 0x00, // J
    0x7F, 0x08, 0x14, 0x22, 0x41, 0x00, // K
    0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, // L
    0x7F, 0x02, 0x0C, 0x02, 0x7F, 0x00, // M
    0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, // N
    0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, // O
    0x7F, 0x09, 0x09, 0x09, 0x06, 0x00, // P
    0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00, // Q
    0x7F, 0x09, 0x19, 0x29, 0x46, 0x00, // R
    0x46, 0x49, 0x49, 0x49, 0x31, 0x00, // S
    0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, // T
    0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00, // U
    0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00, // V
    0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00, // W
    0x63, 0x14, 0x08, 0x14, 0x63, 0x00, // X
    0x07, 0x08, 0x70, 0x08, 0x07, 0x00, // Y
    0x61, 0x51, 0x49, 0x45, 0x43, 0x00, // Z
    0x00, 0x7F, 0x41, 0x41, 0x00, 0x00, // [
    0x02, 0x04, 0x08, 0x10, 0x20, 0x00, // "\"
    0x00, 0x41, 0x41, 0x7F, 0x00, 0x00, // ]
    0x04, 0x02, 0x01, 0x02, 0x04, 0x00, // ^
    0x40, 0x40, 0x40, 0x40, 0x40, 0x00, // _
    0x00, 0x01, 0x02, 0x04, 0x00, 0x00, // `
    0x20, 0x54, 0x54, 0x54, 0x78, 0x00, // a
    0x7F, 0x48, 0x44, 0x44, 0x38, 0x00, // b
    0x38, 0x44, 0x44, 0x44, 0x00, 0x00, // c
    0x38, 0x44, 0x44, 0x48, 0x7F, 0x00, // d
    0x38, 0x54, 0x54, 0x54, 0x18, 0x00, // e
    0x08, 0x7E, 0x09, 0x01, 0x02, 0x00, // f
    0x08, 0x14, 0x54, 0x54, 0x3C, 0x00, // g
    0x7F, 0x08, 0x04, 0x04, 0x78, 0x00, // h
    0x00, 0x44, 0x7D, 0x40, 0x00, 0x00, // i
    0x20, 0x40, 0x44, 0x3D, 0x00, 0x00, // j
    0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, // k
    0x00, 0x41, 0x7F, 0x40, 0x00, 0x00, // l
    0x7C, 0x04, 0x18, 0x04, 0x78, 0x00, // m
    0x7C, 0x08, 0x04, 0x04, 0x78, 0x00, // n
    0x38, 0x44, 0x44, 0x44, 0x38, 0x00, // o
    0x7C, 0x14, 0x14, 0x14, 0x08, 0x00, // p
    0x08, 0x14, 0x14, 0x18, 0x7C, 0x00, // q
    0x7C, 0x08, 0x04, 0x04, 0x08, 0x00, // r
    0x48, 0x54, 0x54, 0x54, 0x20, 0x00, // s
    0x04, 0x3F, 0x44, 0x40, 0x20, 0x00, // t
    0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00, // u
    0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00, // v
    0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00, // w
    0x44, 0x28, 0x10, 0x28, 0x44, 0x00, // x
    0x0C, 0x50, 0x50, 0x50, 0x3C, 0x00, // y
    0x44, 0x64, 0x54, 0x4C, 0x44, 0x00, // z
    0x00, 0x08, 0x36, 0x41, 0x00, 0x00, // {
    0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, // |
    0x00, 0x41, 0x36, 0x08, 0x00, 0x00, // }
};

uint8_t fila[7]{0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000};
char msj[] = {48, 48, 109, 58, 48, 48, 115};
uint8_t columna[128]{
    48,
    48,
    109,
    58,
    48,
};
uint8_t FILA;
uint8_t p;
uint8_t aux;

uint16_t flag_tiempo, flag_END_TIME, flag_titilado;
uint8_t total_ms = 50, flag1, flag2, flag3, old_cnt;
uint8_t flag_tiempo_suma, flag_tiempo_resta;
bool flag_estado_END_TIME;
uint16_t tiempo;
uint16_t cnt2;

uint8_t i;
uint8_t cnt;

uint8_t cant_fila;
uint8_t val_fila;



typedef enum
{
  STOP,
  START,
  END_TIME,
  BOTON_SPEED
} ESTADO;
ESTADO estado;


void config_TIMER0(void)
{
  TCCR0A = (1 << WGM01);  // Activa el bit CTC (clear timer on compare match)                        // del TCCR0A (timer counter/control register)
  OCR0A = 62;             // valor de comparacion de int cada 1ms
  TCCR0B = (1 << CS02);   // divido por 256 y generar interrupciones cada 1 ms
  TIMSK0 = (1 << OCIE0A); // Habilita las interrupciones entimer compare&=~
}

void enviar_mensaje(uint8_t *columna, const char *mensaje)
{

  uint8_t indice, i = 0;
  for (uint8_t j = 0; mensaje[j] != '\0'; j++)
  {

    indice = mensaje[j] - 32;

    for (uint8_t j = 0; j < 6; j++)
    {
      columna[i] = tabla[indice * 6 + j]; // columna[n] = columna[n+1]
      i++;
    }
  }
}


void mostrado(uint8_t i, uint8_t val_fila, uint8_t cant)
{

  uint8_t j;
  for (j = 128; j > 0; j--)
  {
    if (((columna[j] >> i) & 0x01) == 1)
    {
      PORTB |= (1 << PB2); // data
    }
    else
    {
      PORTB &= ~(1 << PB2);
    }
    PORTB |= (1 << PB1); // clock
    PORTB &= ~(1 << PB1);
  }

  if (((columna[0] >> i) & 0x01) == 1)
  {
    PORTB |= (1 << PB2); // data
  }
  else
  {
    PORTB &= ~(1 << PB2);
  }
  PORTB |= (1 << PB1); // clock
  PORTB &= ~(1 << PB1);

  for (uint8_t e = 0; e < 9; e++)
  {
    if (val_fila & 1)
    {
      PORTB |= (1 << PB2); // data
    }
    else
    {
      PORTB &= ~(1 << PB2);
    }
    val_fila >>= 1;

    PORTB |= (1 << PB1); // clock
    PORTB &= ~(1 << PB1);
  }
}



void Multiplexado(uint16_t num)
{
  uint8_t umil, cent, dec, uni;

  umil = num / 600;
  cent = num / 60;

  dec = ((num % 60) % 100) / 10;
  uni = ((num % 1000) % 100) % 10;

  if (num >= 600)
  {
    cent = (num % 600) / 60;
  }
  else
  {
    cent = num / 60;
  }
    msj[0] = umil + 48;
  msj[1] = cent + 48;

  msj[4] = dec + 48;
  msj[5] = uni + 48;
}



void Registro_de_desplazamiento(uint64_t val, uint8_t cant)
{
	uint8_t i;

	for (i = 0; i < cant; i++)  {
      if(val & 1){
        PORTB |= (1 << PB2); //data
      }
      else
      {
        PORTB &= ~(1 << PB2);
      }
			val >>= 1;
		
			PORTB |= (1 << PB1); //clock
      PORTB &= ~(1 << PB1);
  }
}


 void enable(void){
     PORTB |= (1<<PB0);
    PORTB &= ~(1<<PB0);
    }


    void puertos(void){
    DDRB |= (1<<PB0);
    DDRB |= (1<<PB1);
    DDRB |= (1<<PB2);
    DDRB |= (1<<PB3);
    DDRC |= (1<<PC3);
    }


void barrido_display(void){
      if(p == 250){
       aux = columna[0];
     for(uint8_t i=0 ; i<120 ;i++){
       columna[i]= columna[i+1];
     }
     columna[120] = aux;
    }
    }

    void Multiplexado_filas(void){
    if (cnt == 1)
    {
  
      FILA++;
      cnt = 0;
      if (FILA == 7)
      {
        FILA = 0;
      }
    }
  }


  void pulsadores(void){
    switch (estado)
    {
    case STOP:
    
    //suma
      if ((PINC & (1 << PC5)) == 0 && flag1 == 0 && total_ms == 50)
      {
      flag1 = 1;
      cnt++;
      tiempo = 0;
      
      total_ms = 0;
      }

      if ((PINC & (1 << PC5)) != 0 && flag1 == 1 && total_ms == 50)
      {
      flag1 = 0;
      total_ms = 0;
      }


    //resta
      if ((PINC & (1 << PC4)) == 0 && flag2 == 0 && total_ms == 50)
      {
      flag2 = 1;
      cnt--;
      tiempo = 0;
      total_ms = 0;
      }

      if ((PINC & (1 << PC4)) != 0 && flag2 == 1 && total_ms == 50)
      {
      flag2 = 0;
      total_ms = 0;
      }

      if(flag1 == 1){
        if(tiempo == 3000){
        estado = BOTON_SPEED;
        flag_tiempo_suma = 0;
        }
      }
      if(flag2 == 1){
        if(tiempo == 3000){
        estado = BOTON_SPEED;
        flag_tiempo_resta = 0;
        }
      }

    //cambio de estado
      if ((PINC & (1 << PC3)) == 0 && flag3 == 0 && total_ms == 50)
      {
      flag3 = 1;
      estado = START;
      old_cnt = cnt;
      flag_tiempo = 0;
      total_ms = 0;
      }

      if ((PINC & (1 << PC3)) != 0 && flag3 == 1 && total_ms == 50)
      {
      flag3 = 0;
      total_ms = 0;
      }
      break;

    case START:
    if(flag_tiempo == 1000){
      cnt--;
      flag_tiempo = 0;
      if(cnt == 0){
        estado = END_TIME;
        flag_END_TIME = 0;
        flag_titilado = 0;
      }
    }

    //cambio de estado
      if ((PINC & (1 << PC3)) == 0 && flag3 == 0 && total_ms == 50)
      {
      flag3 = 1;
      estado = STOP;
      cnt = old_cnt;
      flag_tiempo = 0;
      total_ms = 0;
      }

      if ((PINC & (1 << PC3)) != 0 && flag3 == 1 && total_ms == 50)
      {
      flag3 = 0;
      total_ms = 0;
      }
      break;
    
    

      break;

    case END_TIME:
    if(flag_estado_END_TIME == 0){
    enviar_mensaje(columna, "ENDTIME");  
    }
    if(flag_estado_END_TIME == 1){
    enviar_mensaje(columna, "       ");
    }
    if(flag_titilado == 500){
      flag_estado_END_TIME = !flag_estado_END_TIME;
      flag_titilado = 0;
    }
    if(flag_END_TIME == 1000){
      estado = STOP;
      cnt = old_cnt;
      flag_END_TIME = 0;
      flag_estado_END_TIME = 0;
      flag_titilado = 0;
    }
    


      break;

    case BOTON_SPEED:
    if(flag1 == 1){
      if(flag_tiempo_suma == 250){
        cnt++;
        flag_tiempo_suma = 0;
      }
    }
    if ((PINC & (1 << PC5)) != 0 && flag1 == 1 && total_ms == 50)
      {
      flag1 = 0;
      estado = STOP;
      flag_tiempo_suma = 0;
      total_ms = 0;
      }
     

    if(flag2 == 1){
      if(flag_tiempo_resta == 250){
        if(cnt != 0){
        cnt--;
        }
        flag_tiempo_resta = 0;
      } 
    }
    if ((PINC & (1 << PC4)) != 0 && flag2 == 1 && total_ms == 50)
      {
      flag2 = 0;
      estado = STOP;
      flag_tiempo_resta = 0;
      total_ms = 0;
      }

      break;
      
    }
    }