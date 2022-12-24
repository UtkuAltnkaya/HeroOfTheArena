#include "HOTA/Fight.hpp"
#include "HOTA/Hero.hpp"
#include <iostream>

Fight::Fight(Hero *&hero, Boss *&boss) : hero{hero}, boss{boss}, is_key_pressed{false}, is_turn_hero{true}, is_boss_attack{true}
{
    this->hero->fight_start();
    this->boss->fight_start();
}

Fight::~Fight()
{
    std::cout << "Test" << std::endl;
}

void Fight::poll_events()
{
    if (this->is_turn_hero)
    {
        this->hero_attack();
    }
    else
    {
        this->boss_attack();
    }
}

void Fight::hero_attack()
{
    if (this->hero->get_ani_name() == AnimationNames::IDLE)
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
            this->is_key_pressed = true; // TODO
        }
    }

    this->hero_control_collide();
    // it's being called repeatedly to get closer to the boss so hero can perform the attack animation
}

void Fight::hero_control_collide()
{
    bool is_hero_hit{this->hero->get_is_ani_over()};
    bool check{this->hero->is_collide(this->boss)};

    // std::cout << check << " " << is_hero_hit << " " << this->is_turn_hero << " " << this->hero->get_ani_name() << std::endl;

    this->boss->set_is_ani_over(false);
    if (this->is_key_pressed && !check) // if key is pressed, and boss and hero is not collided, call hero_move_position
    {
        this->hero_move_position(AnimationNames::RUN, sf::Keyboard::D);
    }
    else if (check && !is_hero_hit && !this->boss->get_is_ani_over()) // TODO
    {
        this->hero_skill_perform();                         // hero performs his/her skill.
        this->boss->set_ani_name(AnimationNames::TAKE_HIT); // Boss performs his skill.
    }
    else if (is_hero_hit)
    {
        // std::cout << "A" << std::endl;
        this->hero_move_initial_position(); // hero returns back to initial position.
    }
}

void Fight::hero_skill_perform()
{
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
    else if (this->key == sf::Keyboard::E)
    {
        this->hero->set_ani_name(AnimationNames::DEFEND);
    }
}

void Fight::hero_move_position(const AnimationNames &ani_name, const sf::Keyboard::Key &move)
{
    this->hero->set_ani_name(ani_name);
    this->hero->move_left_right(move, 8.f); // go right with animation "run" & (velocity 8.f)
}

void Fight::hero_move_initial_position()
{
    if (this->hero->get_position_x() != -200.f)
    {
        this->hero_move_position(AnimationNames::RUN_LEFT, sf::Keyboard::A);
        this->is_key_pressed = false;
    }
    else
    {
        this->boss_decrease_health();
        this->hero_decrease_mana();
        this->is_turn_hero = false;
        this->hero->set_is_ani_over(false);
        this->hero->set_ani_name(AnimationNames::IDLE);
        this->is_boss_attack = true;
    }
}

void Fight::boss_attack()
{
    this->boss_control_collide();
}

void Fight::boss_control_collide()
{
    bool check{this->boss->is_collide(this->hero)};
    bool is_boss_hit{this->boss->get_is_ani_over()};
    // std::cout << check << " " << is_boss_hit << " " << this->hero->get_is_ani_over() << std::endl;
    if (!check && this->is_boss_attack)
    {
        this->boss_move_position(AnimationNames::RUN_LEFT, sf::Keyboard::A);
    }
    else if (check && !is_boss_hit && !this->hero->get_is_ani_over())
    {
        this->boss_skill_perform();
        this->hero->set_ani_name(AnimationNames::TAKE_HIT);
    }
    else if (is_boss_hit)
    {
        this->boss_move_initial_position();
    }
}

void Fight::boss_move_position(const AnimationNames &boss_ani_name, const sf::Keyboard::Key &move)
{
    this->boss->set_ani_name(boss_ani_name);
    this->boss->move_left_right(move, 8.f);
}

void Fight::boss_skill_perform()
{
    this->boss->set_ani_name(AnimationNames::ONE_ATK);
    this->is_boss_attack = true;
}

void Fight::boss_move_initial_position()
{
    if (this->boss->get_position_x() != 800.f) // Until Boss goes back to his initial position , move his position with "run" animation
    {
        this->hero->set_ani_name(AnimationNames::IDLE);
        this->is_boss_attack = false;
        this->boss_move_position(AnimationNames::RUN, sf::Keyboard::D);
    }
    else // Boss has arrived to his initial position
    {
        this->hero_decrease_health();
        this->is_turn_hero = true;
        this->boss->set_is_ani_over(false);
        this->boss->set_ani_name(AnimationNames::IDLE);
        this->hero->set_is_ani_over(false);
    }
}

void Fight::hero_decrease_health()
{
    this->hero->decrease_heath(this->boss->get_damage());
}

void Fight::boss_decrease_health()
{
    this->boss->decrease_heath(this->hero->get_damage());
}

void Fight::hero_decrease_mana()
{
    this->hero->decrease_mana(100);
}
