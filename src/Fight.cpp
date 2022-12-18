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
        this->move_position("run", sf::Keyboard::D);
        // std::cout << "RUN" << std::endl;
    }
    else if (check && !this->hero->get_is_ani_over())
    {
        this->skill_perform();
    }
    else
    {

        move_initial_position();

        // this->hero->set_is_ani_over(false);
        //   TODO:came back to init position
        //   change is ani over to false
        //   initial position -200;

        //
    }
}

void Fight::move_position(const std::string &ani_name, const sf::Keyboard::Key &move)
{
    this->hero->set_ani_name(ani_name);
    this->hero->move_left_right(move, 8.f); // go right with animation "run" & (velocity 8.f)
}

void Fight::skill_perform()
{
    if (this->key == sf::Keyboard::Q)
    {
        this->hero->set_ani_name("1_atk");
    }
    else if (this->key == sf::Keyboard::W)
    {
        this->hero->set_ani_name("2_atk");
    }
    else if (this->key == sf::Keyboard::R)
    {
        this->hero->set_ani_name("sp_atk");
    }
    else if (this->key == sf::Keyboard::E)
    {
        this->hero->set_ani_name("defend");
    }
}

void Fight::move_initial_position()
{
    if (hero->get_position_x() != -200.)
    {
        // std::cout << "RUN-LEFT" << std::endl;
        this->move_position("run_left", sf::Keyboard::A);
        this->is_key_pressed = false;
    }
    else
    {
        this->hero->set_is_ani_over(false);
        this->hero->set_ani_name("idle");
    }
}