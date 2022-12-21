#ifndef HERO_HPP
#define HERO_HPP

#include <SFML/Graphics.hpp>
#include "HOTA/AnimationCreator.hpp"
#include "HOTA/Physics.hpp"
#include "HOTA/Boss.hpp"
#include "HOTA/Ui.hpp"

class Hero : public Physics
{
protected:
  Ui *ui;

  int health;
  int damage;
  int mana;
  int defense;       // TODO change name to defend_chance
  float crit_chance; // TODO change type to integer

  bool is_fight_start;
  bool is_ani_over;

  AnimationNames ani_name;

  void init_var();
  void atk_character();
  void move_character();
  void init_all_animations();
  const bool animation_guard();

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

  void update();
  void render(sf::RenderTarget &target);
  void poll_events(sf::Event &event, Boss *boss);
  void poll_events_loop(sf::Event &event);

  void fight_start();
  void decrease_heath(const int &number);

  bool get_is_ani_over();
  int get_health();
  int get_damage();

  void set_health(const int &health);
  void set_is_ani_over(const bool &is_ani_over);
  void set_ani_name(const AnimationNames &ani_name);
  const AnimationNames &get_ani_name();
};

#endif
