#ifndef ENEMY_H
#define ENEMY_H

#include "animatedsprite.h"

class Enemy : public AnimatedSprite
{
public:


    int px=rand()%750;
    int py=(rand()%600 +1)*-1;
    int identyfier =1;
    void setIdentity()
    {
        this->identyfier = 1;
    }

    Enemy();




};

#endif // ENEMY_H
