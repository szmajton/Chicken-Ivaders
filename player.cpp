#include "player.h"


Player::Player()
{
    texture.loadFromFile("hero.png");
    sprite.setTexture(texture);
    sprite.setPosition(350,510);
    punkty = 0;
}

void Player::wykryj()
{
    sf::FloatRect playerbounds = sprite.getGlobalBounds();
    if(playerbounds.left < 0)
    {
        sprite.setPosition(0,sprite.getPosition().y);
    }
    if(playerbounds.left + playerbounds.width > 800)
    {
        sprite.setPosition(800-playerbounds.width,sprite.getPosition().y);
    }
}
