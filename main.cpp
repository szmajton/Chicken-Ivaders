#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <animatedsprite.h>
#include <ustawienia.h>



int main() {

    std::vector<std::unique_ptr<AnimatedSprite>>huj;

    sf::FloatRect granice;
sf:: Clock EnemyClock,MainClock,BonusClock;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(30);
    Player player;
    Bullet b1;
    Ustawienia u;
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

   b1.wykryj();
   u.spawnDropChance(huj,b1.isEnemyHit);
   b1.isEnemyHitStatus();

        }


       b1.isShooting();


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.sprite.move(-player.vx,player.vy);

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.sprite.move(player.vx,player.vy);

        }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      {
          b1.Szczal(player.sprite.getPosition().x);
      }


     b1.enemyHit(player.punkty,huj);
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
player.wykryj();
window.draw(player.sprite);
u.Rate(player.punkty,EnemyClock,huj);
u.jestSpowolniony(BonusClock,huj);

//u.spawnDrop(huj);
for(const auto &s : huj)
        {
            window.draw(s->sprite);
            s->wykryj();
            s->ZbierzBonus(player.sprite,player.punkty,huj,BonusClock);
           // if(s->name=="enemy"){
           // s->Koniec(window, player.sprite);
           // }
        }

std::cout<<BonusClock.getElapsedTime().asSeconds()<<std::endl;

window.draw(b1.sprite);
        // end the current frame
        window.display();
    }

    return 0;
}
