#ifndef FIGHT_HPP
#define FIGHT_HPP

#include "HOTA/Physics.hpp"
#include "HOTA/BaseFight.hpp"
#include "HOTA/Hero.hpp"
#include "HOTA/Boss.hpp"

class Fight : public BaseFight
{
private:
    Hero *hero;
    Boss *boss;
    void hero_attack();
    void hero_control_collide();
    void hero_move_position(const AnimationNames &ani_name, const sf::Keyboard::Key &move);
    void hero_skill_perform();
    void hero_move_initial_position();

    void boss_attack();
    void boss_move_position(const AnimationNames &boss_ani_name, const sf::Keyboard::Key &move);
    void boss_move_initial_position();
    void boss_control_collide();

public:
    Fight(Hero *&hero, Boss *&boss);
    ~Fight();
    void poll_events() override;
};

#endif