#ifndef HERO_HPP
#define HERO_HPP

#include <SFML/Graphics.hpp>
#include "HOTA/AnimationCreator.hpp"
#include "HOTA/Physics.hpp"
#include "HOTA/Boss.hpp"

class Hero : public Physics
{
protected:
  int health;
  int damage;
  int mana;
  int defense;
  float crit_chance;

  bool is_fight_start;

  void init_var();
  void atk_character();
  void move_character();
  void init_all_animations();

private:
  void init_fight_animations();
  void init_game_animations();
  void game_events();

public:
  Hero();
  Hero(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal, int actualWidth, int actualHeight);
  virtual ~Hero();
  virtual void skill() = 0;
  virtual void upgrade() = 0;
  std::string ani_name; // TODO

  void update();
  void render(sf::RenderTarget &target);
  void poll_events(sf::Event &event, Boss *boss);
  void poll_events_loop(sf::Event &event);
  void fight_events();
  void fight_start();
  bool is_ani_over; // TODO
};

#endif
