#include "lib/es.h"
//#include "timer0.h"

#include "Leg.h"

int main(void)
{
	ES.initialize();
	LegClass::attach();
	//initialize_es();
	//initialize_timer0();
	//TODO initialize es, frame, TWI, remote control
}
