#include "HOTA/Fight.hpp"
#include "HOTA/Hero.hpp"
#include <iostream>

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
    sf::Keyboard::Key key;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        key = sf::Keyboard::Q;
        this->is_key_pressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        key = sf::Keyboard::W;
        this->is_key_pressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        key = sf::Keyboard::R;
        this->is_key_pressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        // this->is_key_pressed = false;
        this->hero->ani_name = "defend";
    }
    control_collide(key);

    //  else if (this->hero->is_collide(this->boss))
    //  {
    //      this->hero->move_left_right(sf::Keyboard::A, 8.f);
    //  }
}
void Fight::boss_attack()
{
}

void Fight::control_collide(sf::Keyboard::Key key)
{

    if (this->is_key_pressed && !this->hero->is_collide(this->boss))
    {
        skill_collide(key);
    }
    else
    {
        is_key_pressed = false;
        this->hero->ani_name = "idle";
    }
}

void Fight::skill_collide(sf::Keyboard::Key key)
{
    this->hero->ani_name = "run";
    this->hero->move_left_right(sf::Keyboard::D, 8.f);

    // if (key == sf::Keyboard::Q)
    // {
    //     this->hero->ani_name = "1_atk";
    // }
    // else if (key == sf::Keyboard::W)
    // {
    //     this->hero->ani_name = "2_atk";
    // }
    // else if (key == sf::Keyboard::R)
    // {
    //     this->hero->ani_name = "sp_atk";
    // }
}