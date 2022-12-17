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

    void hero_attack();
    void boss_attack();

public:
    Fight(Hero *hero, Boss *boss);
    ~Fight();
    void skill_collide(sf::Keyboard::Key key);
    void control_collide(sf::Keyboard::Key key);

    void poll_events(sf::Event &event);
};

#endif