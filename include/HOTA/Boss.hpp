#ifndef BOSS_HPP
#define BOSS_HPP

#include <SFML/Graphics.hpp>
#include "HOTA/AnimationCreator.hpp"

class Boss : public AnimationCreator
{
protected:
    // std::string ani_name[10] = {"idle", "1_atk", "2_atk", "sp_atk", "run", "roll", "jump_full", "defend", "death", "take_hit"};

    //
    std::string ani_name;
    int health;
    int damage;
    int mana;
    int defense;
    float crit_chance;
    bool is_ani_over;

    //
    void move(sf::Keyboard::Key key);
    void atk_boss();
    void move_boss();

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
