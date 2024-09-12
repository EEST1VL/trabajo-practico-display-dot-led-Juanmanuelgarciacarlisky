#include <Arduino.h>
void config_TIMER0(void);
#define MAX_COLUMN 40
#define MAX_FILA 7

uint8_t fila[7]{0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000};
uint8_t FILA;

uint8_t cnt;
uint8_t CONTADOR;

uint8_t columna[7]{0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, 0x00};

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




int main() {
    config_TIMER0();
    sei();
    DDRB |= (1<<PB0);
    DDRB |= (1<<PB1);
    DDRB |= (1<<PB2);
    DDRB |= (1<<PB3);
    DDRC |= (1<<PC3);
    while (1) {
    //000000000000000
    Registro_de_desplazamiento(0xDEADBEEF,40);
    Registro_de_desplazamiento(0b00010000,8);
    PORTB |= (1<<PB0);
    PORTB &= ~(1<<PB0);
     
    }
}
ISR(TIMER0_COMPA_vect) {
  cnt++;
  if(cnt == 2){
    FILA++;
    CONTADOR++;
    cnt = 0; 
    if(FILA == 7){
      FILA = 0;
    }
    if(CONTADOR == 7){
      CONTADOR = 0;
    }
  }
}

void config_TIMER0(void)
{
  TCCR0A = (1 << WGM01);  // Activa el bit CTC (clear timer on compare match)                        // del TCCR0A (timer counter/control register)
  OCR0A = 62;             // valor de comparacion de int cada 1ms
  TCCR0B = (1 << CS02);   // divido por 256 y generar interrupciones cada 1 ms
  TIMSK0 = (1 << OCIE0A); // Habilita las interrupciones entimer compare&=~
}