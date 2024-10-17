#include <Arduino.h>
#include "DISPLAY_DOT.h"
#define PUNTO_1 1
#define PUNTO_2_y_3 2
#define PUNTO_4 3
#define DISPLAY PUNTO_4


#if DISPLAY == PUNTO_1
int main()
{
  config_TIMER0();
  sei();
  puertos();

  while (1)
  {
    // 000000000000000
    Registro_de_desplazamiento(0xDEADBEEF, 40);
    Registro_de_desplazamiento(0b00010000, 8);
    enable();
  }
}
ISR(TIMER0_COMPA_vect)
{
}
#endif


#if DISPLAY == PUNTO_2_y_3

int main()
{
 
  config_TIMER0();
  sei();
  puertos();
uint8_t aux;
    enviar_mensaje(columna,"ETAPA DE POTENCIA");
  while (1)
  {



    mostrado(FILA, fila[FILA], 128);
   
    enable();
    barrido_display();
    Multiplexado_filas();
}
}
ISR(TIMER0_COMPA_vect)
{
  cnt++;
  p++;
}

         





#endif


#if DISPLAY == PUNTO_4

int main()
{

  config_TIMER0();
  sei();
  DDRB |= (1 << PB0);
  DDRB |= (1 << PB1);
  DDRB |= (1 << PB2);
  DDRB |= (1 << PB3);
  DDRC &= ~(1 << PC3);
  DDRC &= ~(1 << PC4);
  DDRC &= ~(1 << PC5);
  PORTC |= (1 << PC3);
  PORTC |= (1 << PC4);
  PORTC |= (1 << PC5);

  
  

  while (1)
  {
    Multiplexado(cnt);
    enviar_mensaje(columna, msj);
    mostrado(FILA, fila[FILA], 128);
    pulsadores();
   enable();
    /*if(p == 250){
       aux = columna[0];
     for(uint8_t i=0 ; i<120 ;i++){
       columna[i]= columna[i+1];
     }
     columna[120] = aux;
    }*/
   Multiplexado_filas();
  }
}
ISR(TIMER0_COMPA_vect)
{
  cnt2++;
  //p++;
  total_ms++;
  flag_tiempo++;
  flag_END_TIME++;
  flag_titilado++;
  tiempo++;
  flag_tiempo_resta++;
  flag_tiempo_suma++;
}


#endif
