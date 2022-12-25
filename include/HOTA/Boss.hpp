#ifndef BOSS_HPP
#define BOSS_HPP

#include <SFML/Graphics.hpp>
#include "HOTA/Physics.hpp"
#include "HOTA/Ui.hpp"
#include <thread>
class Boss : public Physics
{
protected:
    Ui *ui;

    AnimationNames ani_name;
    int health;
    int damage;
    int mana;
    int defense_chance;
    int crit_chance;

    bool is_fight_start;
    bool is_ani_over;

    void atk_boss();
    void init_all_animations();

private:
    void load_fight_multi_thread(const AnimationNames num, std::string type, std::string file, int num_of_png, bool is_repeated);
    void init_fight_animations();
    void init_game_animations();

public:
    Boss();
    Boss(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, int critChanceVal);
    virtual ~Boss();
    virtual void skill() = 0;
    virtual void upgrade() = 0;

    void update();
    void render(sf::RenderTarget &target);
    void poll_events(sf::Event &event);
    void poll_events_loop(sf::Event &event);

    void fight_start();
    void decrease_heath(const int &number);
    void delete_ui();

    // Getters
    bool get_is_ani_over();
    const int &get_damage();
    int get_health();
    int get_defense_chance();
    int get_crit_chance();
    const size_t &get_que();
    const AnimationNames &get_ani_name();

    // Setters
    void set_is_ani_over(const bool &is_ani_over);
    void set_ani_name(const AnimationNames &ani_name);
    void set_damage(const int &damage);
    void set_health(const int &health);
    void set_defense_chance(const int &defense_chance);
    void set_crit_chance(const int &crit_chance);
    void set_is_ani_stop(const bool &is_ani_stop);
};

#endif
