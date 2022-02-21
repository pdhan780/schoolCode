#ifndef EVENTS_H
#define EVENTS_H
#include "model.h"

void sideCrash (struct Spaceship *shipPtr);

bool collisionDetect( struct Spaceship *shipPtr, struct Asteroid *astPtr);

bool bottomCrash (struct Asteroid *astPtr);

#endif
