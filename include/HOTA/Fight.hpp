#ifndef FIGHT_HPP
#define FIGHT_HPP

#include "HOTA/Physics.hpp"
#include "HOTA/Hero.hpp"
#include "HOTA/Boss.hpp"

enum class TYPE
{
    HERO,
    BOSS
};

class Fight
{
private:
    Hero *hero;
    Boss *boss;

    bool is_key_pressed;
    sf::Keyboard::Key key;

    TYPE type;

    void hero_attack();
    void hero_control_collide();
    void hero_move_position(const std::string &ani_name, const sf::Keyboard::Key &move);
    void hero_skill_perform();
    void hero_move_initial_position();

    void boss_attack();

public:
    Fight(Hero *&hero, Boss *&boss);
    ~Fight();
    void poll_events();
};

#endif