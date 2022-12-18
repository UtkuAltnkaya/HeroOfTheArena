#include "HOTA/Fight.hpp"
#include "HOTA/Hero.hpp"
#include <iostream>

std::string BOSS{"boss"};
std::string HERO{"hero"};

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

    this->control_collide(HERO); // it's being called repeatedly to get closer to the boss so hero can perform the attack animation
}
void Fight::boss_attack()
{
    this->control_collide(BOSS);
}

void Fight::control_collide(std::string type)
{
    if (type == "hero")
    {
        bool check{this->hero->is_collide(this->boss)};

        if (this->is_key_pressed && !check) // if key is pressed, and boss and hero is not collided, call skill_collide
        {
            this->move_position("run", sf::Keyboard::D, HERO);
            // std::cout << "RUN" << std::endl;
        }
        else if (check && !this->hero->get_is_ani_over())
        {
            this->skill_perform(HERO); // hero performs his/her skill.
            this->boss->set_ani_name("take_hit");

            // if (!this->boss->get_is_ani_over())
            // {
            //     this->boss->set_ani_name("take_hit");
            // }
        }
        // else if (!this->boss->get_is_ani_over() && this->hero->get_is_ani_over())
        // {
        //     this->boss->set_ani_name("take_hit");
        // }

        else
        {
            this->move_initial_position(HERO); // hero returns back to initial position.
        }
    }
    if (type == "boss")
    {
    }
}

void Fight::move_position(const std::string &ani_name, const sf::Keyboard::Key &move, std::string type)
{
    if (type == "hero")
    {
        this->hero->set_ani_name(ani_name);
        this->hero->move_left_right(move, 8.f); // go right with animation "run" & (velocity 8.f)
    }
}

void Fight::skill_perform(std::string type)
{
    if (type == "hero")
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
}

void Fight::move_initial_position(std::string type)
{
    if (type == "hero")
    {
        if (hero->get_position_x() != -200.)
        {
            // std::cout << "RUN-LEFT" << std::endl;
            this->move_position("run_left", sf::Keyboard::A, HERO);
            this->is_key_pressed = false;
        }
        else
        {
            this->hero->set_is_ani_over(false);
            this->hero->set_ani_name("idle");
            this->boss->set_is_ani_over(false);
        }
    }
}