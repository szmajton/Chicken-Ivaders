#ifndef SKRZYNIA_H
#define SKRZYNIA_H

#include "animatedsprite.h"

class Skrzynia : public AnimatedSprite
{
public:
   int vx=0;
   int vy=5;
    Skrzynia();
    void wykryj();
};

#endif // SKRZYNIA_H
