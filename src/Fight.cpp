#include "HOTA/Fight.hpp"
#include "HOTA/Hero.hpp"
#include <iostream>

Fight::Fight(Hero *&hero, Boss *&boss) : hero{hero}, boss{boss}, is_key_pressed{false}
{
    this->hero->fight_start();
    this->boss->fight_start();
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

    this->hero_control_collide(); // it's being called repeatedly to get closer to the boss so hero can perform the attack animation
}
void Fight::boss_attack()
{
    // TODO:boss
}

void Fight::hero_control_collide()
{
    bool check{this->hero->is_collide(this->boss)};
    this->boss->set_is_ani_over(false);
    if (this->is_key_pressed && !check) // if key is pressed, and boss and hero is not collided, call skill_collide
    {
        this->hero_move_position("run", sf::Keyboard::D);
    }
    else if (check && !this->hero->get_is_ani_over() && !this->boss->get_is_ani_over()) // TODO
    {
        this->hero_skill_perform();           // hero performs his/her skill.
        this->boss->set_ani_name("take_hit"); // Boss performs his/her skill.
    }
    else if (this->hero->get_is_ani_over())
    {
        std::cout << "A" << std::endl;
        this->hero_move_initial_position(); // hero returns back to initial position.
    }
}

void Fight::hero_move_position(const std::string &ani_name, const sf::Keyboard::Key &move)
{
    this->hero->set_ani_name(ani_name);
    this->hero->move_left_right(move, 8.f); // go right with animation "run" & (velocity 8.f)
}

void Fight::hero_skill_perform()
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

void Fight::hero_move_initial_position()
{
    if (this->hero->get_position_x() != -200.f)
    {
        this->hero_move_position("run_left", sf::Keyboard::A);
        this->is_key_pressed = false;
    }
    else
    {
        std::cout << "B" << std::endl; // called once
        // Start position
        this->hero->set_is_ani_over(false);
        this->hero->set_ani_name("idle");
    }
}
