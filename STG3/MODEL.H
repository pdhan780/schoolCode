#ifndef MODEL_H
#define MODEL_H


typedef unsigned char bool;

#define true 1
#define false 0

#define MAX_SHIP 20
#define MAX_LEVEL 10

struct Spaceship
{

  unsigned int x, y;  /*position coordinates for player ship */

  int deltaX;         /*horizontal displacement for player ship*/

  unsigned int width; /*width and height for hitbox */ 

  unsigned int height; 
};




struct Asteroid
{

    unsigned int x, y;

    int deltaY;    /*vertical displacement for player ship*/

    unsigned int width;

    unsigned int height; 
};




struct Model
{

struct Spaceship gameShip; /*main player spaceship*/

struct Asteroid asteroids[MAX_LEVEL][MAX_SHIP]; /*game asteroids, MAX of 20 */
};


void move_spaceship(struct Spaceship *shipPtr);

void move_asteroid(struct Asteroid *asteroidPtr);

void move_fleet(struct Model *modelPtr, int colLevel, int rowLevel);



#endif

