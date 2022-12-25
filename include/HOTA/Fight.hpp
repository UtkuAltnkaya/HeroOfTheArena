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
    bool is_turn_hero;
    bool is_boss_attack;
    bool is_boss_dead;
    bool is_hero_dead;
    int max_hero_mana;
    sf::Keyboard::Key key;

    void hero_attack();
    void hero_control_collide();
    void hero_move_position(const AnimationNames &ani_name, const sf::Keyboard::Key &move);
    void hero_skill_perform();
    void hero_move_initial_position();

    void boss_attack();
    void boss_skill_perform();
    void boss_move_position(const AnimationNames &boss_ani_name, const sf::Keyboard::Key &move);
    void boss_move_initial_position();
    void boss_control_collide();

    // UI
    void hero_decrease_health();
    void hero_decrease_mana();
    void hero_increase_mana();
    void boss_decrease_health();

    // Gameplay
    void hero_crit_attack_control();
    void hero_double_damage();
    void hero_split_damage();
    void hero_defense_chance_control();
    void hero_perform_defense();
    void hero_is_dead();
    void hero_perform_death();

    void boss_crit_attack_control();
    void boss_double_damage();
    void boss_split_damage();
    void boss_is_dead();
    void boss_perform_death();

public:
    Fight(Hero *&hero, Boss *&boss);
    ~Fight();
    void poll_events();
};

#endif