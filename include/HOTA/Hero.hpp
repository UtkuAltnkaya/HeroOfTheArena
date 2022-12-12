#ifndef HERO_HPP
#define HERO_HPP

#include <SFML/Graphics.hpp>
#include "HOTA/AnimationCreator.hpp"

class Hero : public AnimationCreator
{
protected:
  // std::string ani_name[10] = {"idle", "1_atk", "2_atk", "sp_atk", "run", "roll", "jump_full", "defend", "death", "take_hit"};

  std::string ani_name;
  int health;
  int damage;
  int mana;
  int defense;
  float crit_chance;
  bool is_ani_over;

  void move(sf::Keyboard::Key key);
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
