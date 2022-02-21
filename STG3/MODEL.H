#ifndef MODEL_H
#define MODEL_H

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
typedef unsigned char bool;

#define true 1
#define false 0



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

struct Asteroid asteroids[20]; /*game asteroids, MAX of 20 */


};

void move_spaceship(struct Spaceship *shipPtr);

void move_asteroid(struct Asteroid *asteroidPtr);


#endif
