#include "HOTA/Fight.hpp"
#include "HOTA/Hero.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Fight::Fight(Hero *&hero, Boss *&boss) : BaseFight{hero, boss}, hero{hero}, boss{boss}
{
    std::srand(std::time(NULL));
}

Fight::~Fight()
{
}

void Fight::poll_events()
{
    if (this->is_turn_hero && !this->is_hero_dead)
    {
        this->hero_attack();
    }
    else if (!this->is_turn_hero && !this->is_boss_dead)
    {
        this->boss_attack();
    }
    if (this->is_hero_dead) // Hero is dead
    {
        if (this->hero->get_que() == this->hero->get_death_position()) // Stop animation
        {
            this->hero->set_is_ani_stop(true);
            this->is_fight_over = true;
        }
    }

    if (this->is_boss_dead) // Boss is dead
    {

        if (this->boss->get_que() == 20) // Stop animation
        {
            this->boss->set_is_ani_stop(true);
            this->is_fight_over = true;
        }
    }
}

void Fight::hero_attack()
{

    if (this->hero->get_ani_name() == AnimationNames::IDLE)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            this->key = sf::Keyboard::Q;
            this->hero_split_damage();
            this->is_key_pressed = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (this->hero->get_mana() >= 200)
            {
                this->key = sf::Keyboard::W;
                this->is_key_pressed = true;
            }
            else
            { // TODO
                std::cout << "Don't have enough mana for W" << std::endl;
                // this->key = sf::Keyboard::Unknown;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            if (this->hero->get_mana() >= 300)
            {
                this->hero_double_damage();
                this->key = sf::Keyboard::R;
                this->is_key_pressed = true;
            }
            else
            { // TODO
                std::cout << "Don't have enough mana for R" << std::endl;
                // this->key = sf::Keyboard::Unknown;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            this->key = sf::Keyboard::E;
            this->is_key_pressed = true;
        }
    }
    if (this->key == sf::Keyboard::E)
    {
        return this->hero_perform_defense(this->key);
    }

    this->hero_control_collide();
    // it's being called repeatedly to get closer to the boss so hero can perform the attack animation
}

void Fight::hero_control_collide()
{ // Hero collide with boss
    bool is_hero_hit{this->hero->get_is_ani_over()};
    bool check{this->hero->is_collide(this->boss)};
    this->boss->set_is_ani_over(false);

    if (this->is_key_pressed && !check) // if key is pressed, and boss and hero is not collided, call hero_move_position
    {
        this->hero_move_position(AnimationNames::RUN, sf::Keyboard::D);
    }
    else if (check && !is_hero_hit && !this->boss->get_is_ani_over())
    {
        this->hero_skill_perform();                         // hero performs his/her skill.
        this->boss->set_ani_name(AnimationNames::TAKE_HIT); // Boss performs his skill.
    }
    else if (is_hero_hit)
    {
        this->hero_move_initial_position(); // hero returns back to initial position.
    }
}

void Fight::hero_skill_perform()
{ // Setting animation name with key value
    if (this->key == sf::Keyboard::Q)
    {
        this->hero->set_ani_name(AnimationNames::ONE_ATK);
    }
    else if (this->key == sf::Keyboard::W)
    {
        this->hero->set_ani_name(AnimationNames::TWO_ATK);
    }
    else if (this->key == sf::Keyboard::R)
    {
        this->hero->set_ani_name(AnimationNames::SP_ATK);
    }
}

void Fight::hero_move_position(const AnimationNames &ani_name, const sf::Keyboard::Key &move)
{
    this->hero->set_ani_name(ani_name);
    this->hero->move_left_right(move, 8.f); // go right with animation "run" & (velocity 8.f)
}

void Fight::hero_move_initial_position()
{
    if (this->hero->get_position_x() != -200.f) // Return hero initial position
    {
        this->hero_move_position(AnimationNames::RUN_LEFT, sf::Keyboard::A);
        this->is_key_pressed = false;
    }
    else
    {
        this->boss_decrease_health();

        if (this->key == sf::Keyboard::Q)
        {
            this->hero_double_damage();
        }
        else if (this->key == sf::Keyboard::R)
        {
            this->hero_split_damage();
        }
        this->boss_is_dead(); // After decreasing boss health check whether is he dead if so, fight must end. Problem: (NOT CALLED IN LOOP)
        this->hero_decrease_mana();

        this->is_turn_hero = false;
        this->hero->set_is_ani_over(false);
        this->hero->set_ani_name(AnimationNames::IDLE);
        this->is_boss_attack = true;
    }
}
