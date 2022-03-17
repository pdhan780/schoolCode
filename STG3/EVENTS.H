#ifndef EVENTS_H
#define EVENTS_H
#include "model.h"

void sideCrash (struct Spaceship *shipPtr);

bool collisionDetect( struct Spaceship *shipPtr, struct Asteroid *astPtr);

bool bottomCrash (struct Asteroid *astPtr);

bool collision_detect_fleet(const struct Model *model, int colLevel, int rowLevel );

#endif
