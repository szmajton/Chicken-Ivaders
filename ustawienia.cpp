#include "ustawienia.h"
#include "enemy.h"
#include "skrzynia.h"



void Ustawienia::spawnEnemy(std::vector<std::unique_ptr<AnimatedSprite>>&a)
{
        std::unique_ptr<Enemy>e1 = std::make_unique<Enemy>();

        a.emplace_back(move(e1));
}

void Ustawienia::Rate(int pkt, sf::Clock &ec,std::vector<std::unique_ptr<AnimatedSprite>>&a)
{

    if(pkt <= 5)
    {
        if(ec.getElapsedTime().asSeconds()> 0.5)
        {
            spawnEnemy(a);
            ec.restart();
            std::cout<<"EnemySpawn"<<std::endl;

        }
    }
    if((pkt <= 10) && (pkt >5))
    {
        if(ec.getElapsedTime().asSeconds()> 4)
        {
            spawnEnemy(a);
            ec.restart();
            std::cout<<"EnemySpawn"<<std::endl;

        }
    }
    if((pkt <= 15) && (pkt >10))
    {

        if(ec.getElapsedTime().asSeconds()> 3)
        {
            spawnEnemy(a);
            ec.restart();
            std::cout<<"EnemySpawn"<<std::endl;

        }
    }
    if((pkt <= 20) && (pkt >15))
    {
        if(ec.getElapsedTime().asSeconds()> 2)
        {
            spawnEnemy(a);
            ec.restart();
            std::cout<<"EnemySpawn"<<std::endl;

        }
    }
    if(pkt >20)
    {
        if(ec.getElapsedTime().asSeconds()> 0.5)
        {
            spawnEnemy(a);
            ec.restart();
            std::cout<<"EnemySpawn"<<std::endl;

        }
    }

}

void Ustawienia::spawnDrop(std::vector<std::unique_ptr<AnimatedSprite>>&a)
{
    std::unique_ptr<Skrzynia>s1 = std::make_unique<Skrzynia>();
    a.emplace_back(move(s1));

}
void Ustawienia::spawnDropChance(std::vector<std::unique_ptr<AnimatedSprite>>&a, bool &isEnemyHit)
{
    if(isEnemyHit==true){
    int szansa = rand()%101;
    if(szansa < 50)
    {

        spawnDrop(a);
        std::cout<<"zrespiono drop"<<std::endl;
    }
    else
        std::cout<<"nie zrespiono dropu"<<std::endl;

   }

}

void Ustawienia ::jestSpowolniony(sf::Clock &bc, std::vector<std::unique_ptr<AnimatedSprite>>&a)
{

    for(const auto &s:a){
        if(s->name=="enemy"){
    if(s->spowolniony ==true)
    {
       s-> vy= 1;


        if(bc.getElapsedTime().asSeconds() > 5)
        {
            s->spowolniony=false;
        }
    }
    if(s->spowolniony ==false)
    {
       s-> vy=10;
    }
    }
    }
}







