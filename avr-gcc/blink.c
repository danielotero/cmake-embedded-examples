#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5

int main() {
  DDRB |= 1 << LED_PIN; // Set PC2 as an output pin
  while (1) {
    PORTB &= ~(1 << LED_PIN); // LED_PIN Low
    _delay_ms(500);
    PORTB |= 1 << LED_PIN; // LED_PIN High
    _delay_ms(500);
  }
  return 0;
}
