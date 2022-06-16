#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <animatedsprite.h>


class Player : public AnimatedSprite
{public:
   int vx=15;
   int vy=0;
   int punkty=0;
   Player();
   void wykryj();

};

#endif // PLAYER_H
