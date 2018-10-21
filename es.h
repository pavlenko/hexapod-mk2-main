#ifndef ES_H_
#define ES_H_

#include <stdint.h>

typedef void (*es_handler_t) (void);

#ifndef ES_HANDLERS_MAX
#define ES_HANDLERS_MAX 30
#endif

#ifndef ES_EVENTS_MAX
#define ES_EVENTS_MAX 30
#endif

#define ES_EVENT_NOP 0
#define ES_EVENT_TIMER0_COMP 1

void initialize_es(void);

void es_attach(uint8_t code, void (*handler_ptr) (void));

void es_detach(uint8_t code);

void es_trigger(uint8_t code);

void es_dispatch(void);

#endif /* ES_H_ */
