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

    bool is_fight_start;
    bool is_ani_over;

    void atk_boss();
    void init_all_animations();

private:
    void init_fight_animations();
    void init_game_animations();

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

    void fight_start();

    bool get_is_ani_over();
    void set_is_ani_over(const bool &is_ani_over);
    void set_ani_name(const std::string &ani_name);

    const int &get_damage();
};

#endif
