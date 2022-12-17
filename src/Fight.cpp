#include "HOTA/Fight.hpp"

Fight::Fight(Hero *hero, Boss *boss) : hero{hero}, boss{boss}, is_key_pressed{false}
{
    this->hero->fight_start();
}

Fight::~Fight()
{
}

void Fight::poll_events(sf::Event &event)
{
    this->hero_attack();
    this->boss_attack();
}

void Fight::hero_attack()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        this->is_key_pressed = true;
    }
    if (this->is_key_pressed && !this->hero->is_collide(this->boss))
    {
        this->hero->move_left_right(sf::Keyboard::D, 8.f);
    }
    else
    {
        this->is_key_pressed = false;
    }
    // else if (this->hero->is_collide(this->boss))
    // {
    //     this->hero->move_left_right(sf::Keyboard::A, 8.f);
    // }
}
void Fight::boss_attack()
{
}
