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
    if (this->is_turn_hero && !is_hero_dead)
    {
        this->hero_attack();
    }
    else if (!this->is_turn_hero && !is_boss_dead)
    {
        this->boss_attack();
    }
    if (this->is_hero_dead)
    {
        if (this->hero->get_que() == this->hero->get_death_position()) // Stop animation
        {
            this->hero->set_is_ani_stop(true);
            std::cout << "hero_dead" << std::endl;
            this->is_fight_over = true;
        }
    }

    if (this->is_boss_dead)
    {
        if (this->boss->get_que() == 20) // Stop animation
        {
            this->boss->set_is_ani_stop(true);
            std::cout << "boss_dead" << std::endl;
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
            {
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
            {
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
        return this->hero_perform_defense();
    }

    this->hero_control_collide();
    // it's being called repeatedly to get closer to the boss so hero can perform the attack animation
}

// bool Fight::leaf_fight()
// {
//     if (this->hero->get_path() != "image/Leaf Archer")
//     {
//         return false;
//     }
//     this->hero_skill_perform();
//     if (this->hero->get_ani_name() == AnimationNames::ONE_ATK)
//     {
//         this->boss->set_ani_name(AnimationNames::TAKE_HIT);
//     }

//     // this->hero_move_initial_position();
//     return true;
// }

void Fight::hero_control_collide()
{
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
        std::cout << " before boss_health: " << boss->get_health() << std::endl;

        this->boss_decrease_health();

        std::cout << " after boss_health: " << boss->get_health() << std::endl;

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

void Fight::boss_attack()
{
    this->boss_control_collide();
}

void Fight::boss_control_collide()
{
    bool check{this->boss->is_collide(this->hero)};
    bool is_boss_hit{this->boss->get_is_ani_over()};

    if (!check && this->is_boss_attack)
    {
        this->boss_move_position(AnimationNames::RUN_LEFT, sf::Keyboard::A);
    }
    else if (check && !is_boss_hit && !this->hero->get_is_ani_over())
    {
        this->boss->set_ani_name(AnimationNames::ONE_ATK);
        this->is_boss_attack = true;
        if (this->key != sf::Keyboard::Unknown)
        {
            this->hero->set_ani_name(AnimationNames::TAKE_HIT);
        }
    }
    else if (is_boss_hit)
    {
        // TODO
        // after boss performed his skill hero must perform take hit animation once
        this->boss_move_initial_position();
    }
}

void Fight::boss_move_position(const AnimationNames &boss_ani_name, const sf::Keyboard::Key &move)
{
    this->boss->set_ani_name(boss_ani_name);
    this->boss->move_left_right(move, 8.f);
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
        std::cout << this->boss->get_damage() << std::endl;

        if (this->key == sf::Keyboard::Unknown) // if E is pressed boss will split damage before attacking
        {
            this->boss_double_damage(); // and after attacking damage will be doubled up to its default value
        }

        this->hero_is_dead(); // check if hero is dead after decreasing health, if so end fight.
        this->is_turn_hero = true;
        this->boss->set_is_ani_over(false);
        this->boss->set_ani_name(AnimationNames::IDLE);
        this->hero->set_is_ani_over(false);
        this->hero->set_is_ani_stop(false);
    }
}

// HERO
