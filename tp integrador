#include <Arduino.h>
#include "libjuan.h"

static inline void initADC0(void);
int main()
{

  config_TIMER0();
  initADC0();
  initInterrupts();

  ADCSRA |= (1 << ADSC);
  Config_Puertos();

  /*uint8_t aux;*/

  estado = ANALOGICO_DIGITAL;
  enviar_mensaje(columna,"0.000V");

  while (1)
  {

    switch (estado)
    {
    case STOP:
      Multiplexado(cnt);
      enviar_mensaje(columna, msj); // muestra 00m:00s

      if (angle >= 4)
      {
        cnt = angle / 4;
      }
      if (angle < 4)
      {
        angle = 4;
      }

      if ((PINC & (1 << PC5)) == 0 && flag1 == 0 && total_ms == 50) // suma
      {
        flag1 = 1;
        angle = angle + 4;
        tiempo = 0;

        total_ms = 0;
      }

      if ((PINC & (1 << PC5)) != 0 && flag1 == 1 && total_ms == 50)
      {
        flag1 = 0;
        total_ms = 0;
      }

      // resta
      if ((PINC & (1 << PC4)) == 0 && flag2 == 0 && total_ms == 50)
      {
        flag2 = 1;
        if (angle > 4)
        {
          angle = angle - 4;
        }
        tiempo = 0;
        total_ms = 0;
      }

      if ((PINC & (1 << PC4)) != 0 && flag2 == 1 && total_ms == 50)
      {
        flag2 = 0;
        total_ms = 0;
      }

      if (flag1 == 1)
      { // si el boton de suma esta presionado por 3 segundos
        if (tiempo == 3000)
        {
          estado = BOTON_SPEED;
          flag_tiempo_suma = 0;
        }
      }
      if (flag2 == 1)
      { // si el boton de resta esta presionado por 3 segundos
        if (tiempo == 3000)
        {
          estado = BOTON_SPEED;
          flag_tiempo_resta = 0;
        }
      }

      // comienza la cuenta regresiva
      if ((PIND & (1 << PD4)) == 0 && flag3 == 0 && total_ms == 50)
      {
        flag3 = 1;
        estado = START;

        enviar_mensaje(columna,msj);
        old_angle = angle;
        flag_tiempo = 0;
        total_ms = 0;
      }

      if ((PIND & (1 << PD4)) != 0 && flag3 == 1 && total_ms == 50)
      {
        flag3 = 0;
        total_ms = 0;
      }

      // cambia a ver la tension del adc
      if ((PIND & (1 << PD5)) == 0 && flag5 == 0 && total_ms == 50)
      {
        flag5 = 1;
        estado = ANALOGICO_DIGITAL;

        enviar_mensaje(columna2,"0.000V");

        global = 0;
        flag = 0;

        total_ms = 0;
      }

      if ((PIND & (1 << PD5)) != 0 && flag5 == 1 && total_ms == 50)
      {
        flag5 = 0;
        total_ms = 0;
      }
      break;

    case ANALOGICO_DIGITAL:

      if (flag >= 32)
      { // despues de 32 mediciones saca el promedio
        temperatura2 = (global / 32);
        global = 0;
        flag = 0;
      }

      Conversion(temperatura2); // muestra el promedio de las 32 mediciones
      enviar_mensaje(columna, msj);           // muestra en pantalla

      // cambia a stop
      if ((PIND & (1 << PD5)) == 0 && flag5 == 0 && total_ms == 50)
      {
        flag5 = 1;
        estado = STOP;
        enviar_mensaje(columna,"00m:00s");

        global = 0;
        flag = 0;

        total_ms = 0;
      }

      if ((PIND & (1 << PD5)) != 0 && flag5 == 1 && total_ms == 50)
      {
        flag5 = 0;
        total_ms = 0;
      }

      break;

    case START:

      if (flag_tiempo == 1000)
      { // por cada 1 segundo resta uno en el numero de la pantalla
        angle = angle - 4;
        flag_tiempo = 0;
        if (angle == 0)
        { // titila
          estado = END_TIME;
          flag_END_TIME = 0;
          flag_titilado = 0;
        }
      }

      // cambio de estado
      if ((PIND & (1 << PD4)) == 0 && flag3 == 0 && total_ms == 50)
      {
        flag3 = 1;
        estado = STOP;
        angle = old_angle;
        flag_tiempo = 0;
        total_ms = 0;
      }

      if ((PIND & (1 << PD4)) != 0 && flag3 == 1 && total_ms == 50)
      {
        flag3 = 0;
        total_ms = 0;
      }
      break;

      break;

    case END_TIME:

      // cada 500 ms titila entre ENDTIEM y nada
      if (flag_estado_END_TIME == 0)
      {
        enviar_mensaje(columna, "ENDTIME");
      }
      if (flag_estado_END_TIME == 1)
      {
        enviar_mensaje(columna, "       ");
      }
      if (flag_titilado == 500)
      {
        flag_estado_END_TIME = !flag_estado_END_TIME;
        flag_titilado = 0;
      }
      if (flag_END_TIME == 1000)
      { // cambia a stop luego de estar un segundo en este estado
        estado = STOP;
        angle = old_angle;
        flag_END_TIME = 0;
        flag_estado_END_TIME = 0;
        flag_titilado = 0;
      }

      break;

    case BOTON_SPEED:
      Multiplexado(cnt);
      enviar_mensaje(columna, msj);
      if (angle >= 4)
      {
        cnt = angle / 4;
      }
      if (angle < 4)
      { // si en el contador pone un segundo, no resta
        angle = 4;
      }

      if (flag1 == 1)
      {
        if (flag_tiempo_suma == 250)
        { // cada 250ms le resta uno al contador
          angle = angle + 4;
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

      if (flag2 == 1)
      {
        if (flag_tiempo_resta == 250)
        { // cada 250ms le resta uno al contador
          if (angle > 4)
          {
            angle = angle - 4;
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

    mostrado(FILA, fila[FILA], 128, columna);

    PORTB |= (1 << PB0);
    PORTB &= ~(1 << PB0);
    /*if(p == 250){
       aux = columna[0];
     for(uint8_t i=0 ; i<120 ;i++){
       columna[i]= columna[i+1];
     }
     columna[120] = aux;
    }*/
    if (cnt2 == 1)
    {

      FILA++;
      cnt2 = 0;
      if (FILA == 7)
      {
        FILA = 0;
      }
    }
    if (total_ms >= 50)
    {
      total_ms = 50;
    }
  }
}

ISR(INT0_vect) // me interrumpio el PD2
{
  (PIND & 0b00001000) ? angle-- : angle++; // le pregunto el estado al PD3
}

ISR(INT1_vect) // me interrumpio el PD3
{
  (PIND & 0b00000100) ? angle++ : angle--; // le pregunto el estado al PD2
}

ISR(TIMER0_COMPA_vect)
{
  cnt2++;
  // p++;
  total_ms++;
  flag_tiempo++;
  flag_END_TIME++;
  flag_titilado++;
  tiempo++;
  flag_tiempo_resta++;
  flag_tiempo_suma++;
}



ISR(ADC_vect)
{
  flag++;
  valorAdc = ADC;
  global = global + valorAdc;
}

static inline void initADC0(void)
{
  /* usamos como referencia el valor de AVCC */
  ADMUX |= (1 << REFS0);
  /* ADC clock prescaler 16MHz/128 = 125KHz */
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  /* Habilito las interrupciones del conversor AD con ADIE y fijo el modo freerunning con ADATE*/
  ADCSRA |= (1 << ADIE) | (1 << ADATE);
  /* Habillitamos el ADC */
  ADCSRA |= (1 << ADEN);
}
