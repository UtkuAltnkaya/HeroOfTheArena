#ifndef HERO_HPP
#define HERO_HPP

#include <SFML/Graphics.hpp>
#include "HOTA/AnimationCreator.hpp"
#include "HOTA/Physics.hpp"

class Hero : public Physics
{
protected:
  std::string ani_name;
  int health;
  int damage;
  int mana;
  int defense;
  float crit_chance;
  bool is_ani_over;

  void init_var();
  void atk_character();
  void move_character();

public:
  Hero();
  Hero(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal);
  virtual ~Hero();
  virtual void skill() = 0;
  virtual void upgrade() = 0;

  void update();
  void render(sf::RenderTarget &target);
  void poll_events(sf::Event &event);
  void poll_events_loop(sf::Event &event);
};

#endif
