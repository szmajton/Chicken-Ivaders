#ifndef BULLET_H
#define BULLET_H

#include "animatedsprite.h"

class Bullet : public AnimatedSprite
{
public:
    int vx=0;
    int vy;
    bool strzal = false;
    bool isEnemyHit= false;
    void enemyHit(int &pkt, std::vector<std::unique_ptr<AnimatedSprite>>&a);
    void Szczal(const float &p);
    void isShooting();
    void wykryj();
    void isEnemyHitStatus();

    Bullet();

};

#endif // BULLET_H
