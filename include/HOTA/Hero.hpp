#ifndef HERO_HPP
#define HERO_HPP

#include <SFML/Graphics.hpp>
#include "HOTA/AnimationCreator.hpp"

class Hero : public AnimationCreator
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
  void atk_character();
  void move_character();

public:
  Hero();
  Hero(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal);
  ~Hero();
  virtual void skill() = 0;
  virtual void upgrade() = 0;

  void update();
  void render(sf::RenderTarget &target);
  void poll_events(sf::Event &event);
  void poll_events_loop(sf::Event &event);
};

#endif

/**
 *  //

  // Getters
 *  std::string get_path();
  std::string get_ani_name();
  int get_health();
  int get_damage();
  int get_mana();
  int get_defense();
  float get_crit_chance();

  //
  int get_idle_num();
  int get_atk_one_num();
  int get_atk_two_num();
  int get_atk_sp_num();
  int get_run_num();
  int get_roll_num();
  int get_jump_num();
  int get_defend_num();
  int get_death_num();
  int get_take_dmg_num();

  //
  std::map<std::string, Animation *> &get_hero_ani();

  // Setters
  void set_path(std::string path);
  void set_health(int health);
  void set_damage(int damage);
  void set_mana(int mana);
  void set_defense(int defense);
  void set_crit_chance(float critChance);

  //
  void set_idle_num(int idleNum);
  void set_atk_one_num(int atkOneNum);
  void set_atk_two_num(int atkTwoNum);
  void set_atk_sp_num(int atkSpNum);
  void set_run_num(int runNum);
  void set_roll_num(int rollNum);
  void set_jump_num(int jumpNum);
  void set_defend_num(int defendNum);
  void set_death_num(int deathNum);
  void set_take_dmg_num(int takeDmgNum);

  //
  void set_hero_ani(std::pair<std::string, Animation *> pair);
*/