#ifndef FIGHT_HPP
#define FIGHT_HPP

#include "HOTA/Physics.hpp"
#include "HOTA/Hero.hpp"
#include "HOTA/Boss.hpp"

class Fight
{
private:
    Hero *hero;
    Boss *boss;

    bool is_key_pressed;
    sf::Keyboard::Key key;

    void hero_attack();
    void boss_attack();

public:
    Fight(Hero *&hero, Boss *&boss);
    ~Fight();
    void move_position(const std::string &ani_name, const sf::Keyboard::Key &move);
    void control_collide();
    void poll_events();
    void skill_perform();
    void move_initial_position();
};

#endif