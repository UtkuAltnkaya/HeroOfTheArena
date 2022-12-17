#include "HOTA/Fight.hpp"
#include "HOTA/Hero.hpp"
#include <iostream>

Fight::Fight(Hero *&hero, Boss *&boss) : hero{hero}, boss{boss}, is_key_pressed{false}
{
    this->hero->fight_start();
}

Fight::~Fight()
{
}

void Fight::poll_events()
{
    this->hero_attack();
    this->boss_attack();
}

void Fight::hero_attack()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->key = sf::Keyboard::Q;
        this->is_key_pressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->key = sf::Keyboard::W;
        this->is_key_pressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        this->key = sf::Keyboard::R;
        this->is_key_pressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        this->key = sf::Keyboard::E;
        this->is_key_pressed = true;
    }

    control_collide(); // it's being called repeatedly to get closer to the boss so hero can perform the attack animation

    // if (this->is_stop == true && this->is_key_pressed == false) // if hero is stopped now hero can perform his skill.
    // {
    //     std::cout << "INSIDE IF CONDITION" << std::endl;
    //     skill_perform();
    // }

    //  else if (this->hero->is_collide(this->boss))
    //  {
    //      this->hero->move_left_right(sf::Keyboard::A, 8.f);
    //  }
}
void Fight::boss_attack()
{
}

void Fight::control_collide()
{
    bool check{this->hero->is_collide(this->boss)};
    if (this->is_key_pressed && !check) // if key is pressed, and boss and hero is not collided, call skill_collide
    {
        this->skill_collide();
    }
    else if (check && !this->hero->is_ani_over)
    {
        this->skill_perform();
    }
    else
    {
        this->is_key_pressed = false;
        this->hero->ani_name = "idle";
    }
}

void Fight::skill_collide()
{
    this->hero->ani_name = "run";
    this->hero->move_left_right(sf::Keyboard::D, 8.f); // go right with animation "run" & (velocity 8.f)
}

void Fight::skill_perform()
{
    if (this->key == sf::Keyboard::Q)
    {
        this->hero->ani_name = "1_atk";
    }
    else if (this->key == sf::Keyboard::W)
    {
        this->hero->ani_name = "2_atk";
    }
    else if (this->key == sf::Keyboard::R)
    {
        this->hero->ani_name = "sp_atk";
    }
    else if (this->key == sf::Keyboard::E)
    {
        this->hero->ani_name = "defend";
    }
}