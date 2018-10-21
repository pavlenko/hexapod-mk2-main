#ifndef HP_H_
#define HP_H_

#include <stdint.h>

#define HP_LEG_FRONT_LEFT 0
#define HP_LEG_FRONT_RIGHT 1
#define HP_LEG_MIDDLE_LEFT 2
#define HP_LEG_MIDDLE_RIGHT 3
#define HP_LEG_BACK_LEFT 4
#define HP_LEG_BACK_RIGHT 5

typedef struct {
	uint8_t c;
	uint8_t f;
	uint8_t t;
} leg_t;

void initialize_hp(void);

#endif /* HP_H_ */
