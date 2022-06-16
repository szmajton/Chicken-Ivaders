#include "bullet.h"
#include "ustawienia.h"
Bullet::Bullet()
{

        texture.loadFromFile("pocisk2.png");
        sprite.setTexture(texture);
        sprite.setPosition(1500,1000);


}

void Bullet::enemyHit(int &pkt, std::vector<std::unique_ptr<AnimatedSprite>>&a)
{
    for(const auto &s : a)
    {
       sf::FloatRect bulletbounds = sprite.getGlobalBounds();
       if(s->name=="enemy"){
       sf::FloatRect enemybounds = s->sprite.getGlobalBounds();
       if(bulletbounds.intersects(enemybounds))
       {


            s->Zamiana();
           // s->spowolniony=false;
            strzal=false;
           // s->sprite.setPosition(-1111,-1000);
            sprite.setPosition(1000,1000);
            if(s->name=="enemy"){
            s->vx=0,s->vy=0;}
            pkt ++;



            std::cout<<pkt<<std::endl;



        }

       }
       if(s->name=="czas"&& s->name=="dynamit")
       {
           s->spowolniony=false;
       }
}



}
void Bullet::Szczal(const float &p)
{
    if(strzal==false)
    {
        vy = -20;
        sprite.setPosition(p + 17,480);
        strzal=true;
    }
}

void Bullet::isEnemyHitStatus()
{
    if(isEnemyHit==true)
    {
        isEnemyHit=false;
    }
}
void Bullet::isShooting()
{

    if(strzal==true)
    {

        sprite.move(vx,vy);

    }
    else
    {
        sprite.setPosition(1000,1000);
    }

}
void Bullet::wykryj()
{
    if(sprite.getPosition().y < -50) //to potem do klasy kuli dodaj latwiej bedzie
    {
        sprite.setPosition(1500,1000);
        strzal=false;
    }
}




