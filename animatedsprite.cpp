#include "animatedsprite.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
void AnimatedSprite::Koniec(sf::RenderWindow &window, sf::Sprite &p)
{
    sf::FloatRect enemybounds = sprite.getGlobalBounds();
    sf::FloatRect playerb = p.getGlobalBounds();
    if(((enemybounds.top + enemybounds.height > 600) || enemybounds.intersects(playerb)) && name== "enemy")
    {
        endgame = true;

    }
    if(endgame==true)
    {
        window.close();
        std::cout<<"LOSE"<<std::endl;
    }

}

void AnimatedSprite::ZbierzBonus(sf::Sprite &p, int &pkt,std::vector<std::unique_ptr<AnimatedSprite>>&a, sf::Clock &bc)
{

    sf::FloatRect enemybounds = sprite.getGlobalBounds();
    sf::FloatRect playerb = p.getGlobalBounds();

    if(enemybounds.intersects(playerb) && name =="dynamit")
    { sprite.setPosition(-1111,-1111);
        vx=0,vy=0;

for(const auto &s : a){
    if(s->sprite.getPosition().y > 45 && s->name=="enemy"){
            s->sprite.setPosition(-1111,-1111);
            s->vy=0;
            s->vx=0;
pkt=pkt+1;
    }

}
    }

    if((enemybounds.intersects(playerb)) && name == "czas")
    { sprite.setPosition(-1111,-1111);
        vx=0,vy=0;
bc.restart();
        for(const auto &s : a)
        {
            if( s->spowolniony==false)
            {

                s->spowolniony=true;

            }


        }




    }


}
void AnimatedSprite::wykryj()
{
    sf::FloatRect enemybounds = sprite.getGlobalBounds();
    sprite.move(this->vx,this->vy);
    if(enemybounds.left < 0)
    {
        vx=abs(vx);
    }
    if(enemybounds.left + enemybounds.width > 800)
    {
        vx=-abs(vx);
    }


}
void AnimatedSprite::Zamiana()
{
    int random = 86;//rand()%100;
    std::cout<<"random nuber"<<random<<std::endl;
    if(random < 15 )
    {   name="dynamit";
        texture.loadFromFile("dynamit.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0,0,29,29));
        sprite.move(vx,vy);
        spowolniony=false;
    }
    if(random > 85)
    {   name="czas";
        texture.loadFromFile("skrzynia.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0,0,29,29));
        sprite.move(vx,vy);
        spowolniony = false;
    }
    if(random >= 15 && random<=85)
    {
        sprite.setPosition(-1111,-1111);
        sprite.move(0,0);
    }

}
