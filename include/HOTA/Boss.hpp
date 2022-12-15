#ifndef BOSS_HPP
#define BOSS_HPP

#include <SFML/Graphics.hpp>
#include "HOTA/Physics.hpp"

class Boss : public Physics
{
protected:
    std::string ani_name;
    int health;
    int damage;
    int mana;
    int defense;
    float crit_chance;
    bool is_ani_over;

    void atk_boss();
    void init_all_animations();

private:
    void init_fight_animation();
    void init_game_animation();

public:
    Boss();
    Boss(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal);
    virtual ~Boss();
    virtual void skill() = 0;
    virtual void upgrade() = 0;

    void update();
    void render(sf::RenderTarget &target);
    void poll_events(sf::Event &event);
    void poll_events_loop(sf::Event &event);
};

#endif
