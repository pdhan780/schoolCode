#ifndef RENDER_H
#define RENDER_H

#include "model.h"

void render(Model* model, void *base);

void render_spaceship(const Spaceship *shipPtr, UINT16 *base);

void render_asteroid(const Asteroid *astPtr, UINT16 *base); 








#endif
