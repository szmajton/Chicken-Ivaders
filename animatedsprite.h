#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class AnimatedSprite : public sf::Sprite
{public:
    int vx ;
    int vy ;
    bool spowolniony = false;
    bool endgame = false;
    sf::Texture texture;
    sf::Sprite sprite;
    std::string name;
    virtual ~AnimatedSprite()=default;
    void wykryj();
    void Koniec(sf::RenderWindow &window, sf::Sprite &p);
    void Zamiana();
    void ZbierzBonus(sf::Sprite &p, int &pkt, std::vector<std::unique_ptr<AnimatedSprite>>&a, sf::Clock &bc);





 };


#endif // ANIMATEDSPRITE_H
