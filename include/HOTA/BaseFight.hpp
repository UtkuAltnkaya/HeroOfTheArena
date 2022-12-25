#ifndef BASE_FIGHT
#define BASE_FIGHT

#include <SFML/Graphics.hpp>
#include "HOTA/Hero.hpp"
#include "HOTA/Boss.hpp"
#include "HOTA/AnimationNames.hpp"
#include "HOTA/LeafArcher.hpp"

class BaseFight
{
private:
  Hero *hero;
  Boss *boss;

protected:
  bool is_key_pressed;
  bool is_turn_hero;
  bool is_boss_attack;
  bool is_boss_dead;
  bool is_hero_dead;
  int max_hero_mana;
  bool is_fight_over;
  sf::Keyboard::Key key;

  void boss_attack();
  void boss_move_position(const AnimationNames &boss_ani_name, const sf::Keyboard::Key &move);
  void boss_move_initial_position();
  void boss_control_collide();

  // UI
  void hero_decrease_health();
  void hero_decrease_mana();
  void hero_increase_mana();
  void boss_decrease_health();

  //
  void hero_crit_attack_control();
  void hero_double_damage();
  void hero_split_damage();
  void hero_defense_chance_control();
  void hero_perform_defense();
  void hero_is_dead();

  //
  void boss_crit_attack_control();
  void boss_double_damage();
  void boss_split_damage();
  void boss_is_dead();

public:
  BaseFight(Hero *hero, Boss *boss);
  BaseFight(LeafArcher *hero, Boss *boss);
  virtual ~BaseFight();
  bool get_is_fight_over();
  virtual void poll_events() = 0;
};

#endif