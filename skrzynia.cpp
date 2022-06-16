#include "skrzynia.h"

Skrzynia::Skrzynia()
{
    int Random = rand()% 2;
    if(Random ==0)
    {
        texture.loadFromFile("dynamit.png");
        sprite.setTexture(texture);
        name= "dynamit";
    }
    if(Random ==1)
    {
        name = "spowolnienie";
        texture.loadFromFile("skrzynia.png");
        sprite.setTexture(texture);

    }
    sprite.setPosition(10,10);
    vx=0;
    vy=5;


}
