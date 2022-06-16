#include "enemy.h"

Enemy::Enemy()
{
    texture.loadFromFile("hero.png");
    sprite.setTexture(texture);
    sprite.setPosition(px,py);
    name = "enemy";
    vy=10;
    vx = rand()%4 - 2;
   // spowolniony = false;


}
