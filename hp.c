#include "hp.h"

#include <avr/io.h>

volatile leg_t legs[6];

//TODO remove after
uint8_t servomotor_attach(volatile uint8_t *port, uint8_t pin, uint16_t angle, uint8_t reverse)
{
	return 0;
}

void initialize_hp(void)
{
	//TODO configure remote legs (connected via i2c)
	//legs[HP_LEG_FRONT_LEFT].c = servomotor_attach(&PORTL, PL3, 130, 1);//130
	//legs[HP_LEG_FRONT_LEFT].f = servomotor_attach(&PORTL, PL2, -60, 1);//-60
	//legs[HP_LEG_FRONT_LEFT].t = servomotor_attach(&PORTL, PL1, -80, 0);//-80

	//legs[HP_LEG_FRONT_RIGHT].c = servomotor_attach(&PORTK, PK4, 80, 1);//80
	//legs[HP_LEG_FRONT_RIGHT].f = servomotor_attach(&PORTK, PK3, -270, 1);//-540????
	//legs[HP_LEG_FRONT_RIGHT].t = servomotor_attach(&PORTK, PK2, -330, 0);//-330

	//legs[HP_LEG_MIDDLE_LEFT].c = servomotor_attach(&PORTF, PF2, 220, 1);//220
	//legs[HP_LEG_MIDDLE_LEFT].f = servomotor_attach(&PORTF, PF1, -190, 1);//-190
	//legs[HP_LEG_MIDDLE_LEFT].t = servomotor_attach(&PORTF, PF0, -170, 0);//-170

	legs[HP_LEG_MIDDLE_RIGHT].c = servomotor_attach(&PORTA, PA7, -10, 0);//-10
	legs[HP_LEG_MIDDLE_RIGHT].f = servomotor_attach(&PORTA, PA6, -70, 0);//-70
	legs[HP_LEG_MIDDLE_RIGHT].t = servomotor_attach(&PORTA, PA5, 120, 1);//120

	legs[HP_LEG_BACK_LEFT].c = servomotor_attach(&PORTA, PA4, -130, 0);//-130
	legs[HP_LEG_BACK_LEFT].f = servomotor_attach(&PORTA, PA3, -140, 0);//-140
	legs[HP_LEG_BACK_LEFT].t = servomotor_attach(&PORTA, PA2, -50, 1);//-50

	legs[HP_LEG_BACK_RIGHT].c = servomotor_attach(&PORTB, PB4, -110, 0);//-110
	legs[HP_LEG_BACK_RIGHT].f = servomotor_attach(&PORTB, PB5, -210, 0);//-210
	legs[HP_LEG_BACK_RIGHT].t = servomotor_attach(&PORTB, PB6, -40, 1);//-40

}
