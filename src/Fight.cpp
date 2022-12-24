#include "HOTA/Fight.hpp"
#include "HOTA/Hero.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Fight::Fight(Hero *&hero, Boss *&boss) : hero{hero}, boss{boss}, is_key_pressed{false}, is_turn_hero{true}, is_boss_attack{true}, is_boss_dead{false}, is_hero_dead{false}
{
    this->hero->fight_start();
    this->boss->fight_start();
    std::srand(std::time(NULL));
}

Fight::~Fight()
{
}

void Fight::poll_events()
{
    // TODO
    //    if (this->is_fight_over)
    //    {
    //    }
    if (this->is_turn_hero && !is_hero_dead)
    {
        this->hero_attack();
    }
    else if (!this->is_turn_hero && !is_boss_dead)
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
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            // TODO
            // increase hero mana 100
            // split boss damage for one round
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

void Fight::hero_control_collide()
{
    bool is_hero_hit{this->hero->get_is_ani_over()};
    bool check{this->hero->is_collide(this->boss)};
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
        this->boss_skill_perform();
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
        this->hero_is_dead(); // check if hero is dead after decreasing health, if so end fight.
        this->is_turn_hero = true;
        this->boss->set_is_ani_over(false);
        this->boss->set_ani_name(AnimationNames::IDLE);
        this->hero->set_is_ani_over(false);
        this->hero->set_is_ani_stop(false);
    }
}

// HERO
void Fight::hero_decrease_health()
{
    this->hero->decrease_heath(this->boss->get_damage());                        // for UI hero health
    this->hero->set_health(this->hero->get_health() - this->boss->get_damage()); // for stats hero health
}

void Fight::hero_decrease_mana()
{
    if (this->key == sf::Keyboard::R)
    {
        this->hero->decrease_mana(300);                     // for UI hero mana
        this->hero->set_mana(this->hero->get_mana() - 300); // for stats hero mana
    }
    else if (this->key == sf::Keyboard::W)
    {
        this->hero->decrease_mana(200);                     // for UI hero mana
        this->hero->set_mana(this->hero->get_mana() - 200); // for stats hero mana
    }
}

// BOSS
void Fight::boss_decrease_health()
{
    this->boss->decrease_heath(this->hero->get_damage());                        // for UI Boss health
    this->boss->set_health(this->boss->get_health() - this->hero->get_damage()); // for stats boss health
}

void Fight::hero_crit_attack_control()
{
    int temp_crit_chance{1 + std::rand() % 10}; // if crit_chance is higher than or equal to 7, hero will perform double damage for one round
    this->hero->set_crit_chance(temp_crit_chance);

    if (this->hero->get_crit_chance() >= 7)
    {
        this->hero_double_damage();
    }
}

void Fight::hero_double_damage()
{
    int temp_damage{this->hero->get_damage()};
    temp_damage *= 2;
    this->hero->set_damage(temp_damage);
}

void Fight::hero_split_damage()
{
    int temp_damage{this->hero->get_damage()};
    temp_damage /= 2;
    this->hero->set_damage(temp_damage);
}

void Fight::hero_defense_chance_control()
{

    int temp_defense_chance{1 + std::rand() % 10};
    this->hero->set_defense_chance(temp_defense_chance);

    if (this->hero->get_defense_chance() >= 7)
    {
        this->hero_perform_defense();
    }
}

void Fight::hero_perform_defense()
{
    this->hero->set_ani_name(AnimationNames::DEFEND);
    if (this->hero->get_que() == this->hero->get_defend_position()) // Stop animation
    {
        // TODO
        //  this->hero->increase_mana();
        this->hero->set_is_ani_stop(true);
        this->is_key_pressed = false;
        this->is_turn_hero = false;
        this->is_boss_attack = true;
        this->key = sf::Keyboard::Unknown;
    }
}

void Fight::hero_is_dead()
{
    std::cout << "hero_is_dead" << std::endl;
    if (this->hero->get_health() <= 0)
    {
        this->hero_perform_death();
    }
}

void Fight::hero_perform_death()
{
    std::cout << "hero_perform_death" << std::endl;
    this->is_hero_dead = true;
    this->hero->set_ani_name(AnimationNames::DEATH);
}

void Fight::boss_crit_attack_control()
{
    int temp_crit_chance{1 + std::rand() % 10};
    this->boss->set_crit_chance(temp_crit_chance);
    if (this->boss->get_crit_chance() >= 7)
    {
        this->boss_double_damage();
    }
}

void Fight::boss_double_damage()
{
    int temp_damage{this->boss->get_damage()};
    temp_damage *= 2;
    this->boss->set_damage(temp_damage);
}

void Fight::boss_split_damage()
{
    int temp_damage{this->boss->get_damage()};
    temp_damage /= 2;
    this->boss->set_damage(temp_damage);
}

void Fight::boss_is_dead()
{
    std::cout << "boss_is_dead" << std::endl;
    if (this->boss->get_health() <= 0)
    {
        this->boss_perform_death();
    }
}

void Fight::boss_perform_death()
{
    this->is_boss_dead = true;
    std::cout << "boss_perform_death" << std::endl;

    this->boss->set_ani_name(AnimationNames::DEATH);
}