#ifndef USTAWIENIA_H
#define USTAWIENIA_H
#include "animatedsprite.h"

class Ustawienia
{
public:
    void spawnEnemy(std::vector<std::unique_ptr<AnimatedSprite>>&a);
    void Rate(int pkt, sf::Clock &ec,std::vector<std::unique_ptr<AnimatedSprite>>&a);
    void spawnDrop(std::vector<std::unique_ptr<AnimatedSprite>>&a);
    void spawnDropChance(std::vector<std::unique_ptr<AnimatedSprite>>&a, bool &isEnemyHit);
    void jestSpowolniony(sf::Clock &bc,std::vector<std::unique_ptr<AnimatedSprite>>&a);


};

#endif // USTAWIENIA_H
