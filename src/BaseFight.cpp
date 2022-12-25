#include "HOTA/BaseFight.hpp"
#include <iostream>

BaseFight::BaseFight(Hero *hero, Boss *boss) : hero{hero}, boss{boss}, is_key_pressed{false}, is_turn_hero{true}, is_boss_attack{true}, is_boss_dead{false}, is_hero_dead{false}, max_hero_mana{this->hero->get_mana()}, is_fight_over{false}
{
  this->hero->fight_start();
  this->boss->fight_start();
}

BaseFight::BaseFight(LeafArcher *hero, Boss *boss) : hero{hero}, boss{boss}, is_key_pressed{false}, is_turn_hero{true}, is_boss_attack{true}, is_boss_dead{false}, is_hero_dead{false}, max_hero_mana{this->hero->get_mana()}, is_fight_over{false}
{
  this->hero->fight_start();
  this->boss->fight_start();
}

BaseFight::~BaseFight()
{
}

void BaseFight::boss_attack()
{
  this->boss_control_collide();
}

void BaseFight::boss_control_collide()
{
  bool check{this->boss->is_collide(this->hero)};
  bool is_boss_hit{this->boss->get_is_ani_over()};

  if (!check && this->is_boss_attack)
  {
    this->boss_move_position(AnimationNames::RUN_LEFT, sf::Keyboard::A);
  }
  else if (check && !is_boss_hit && !this->hero->get_is_ani_over())
  {
    this->boss->set_ani_name(AnimationNames::ONE_ATK);
    this->is_boss_attack = true;
    if (this->key != sf::Keyboard::Unknown)
    {
      this->hero->set_ani_name(AnimationNames::TAKE_HIT);
    }
  }
  else if (is_boss_hit)
  {
    // TODO
    // after boss performed his skill hero must perform take hit animation once
    this->boss_move_initial_position();
  }
}

void BaseFight::boss_move_position(const AnimationNames &boss_ani_name, const sf::Keyboard::Key &move)
{
  this->boss->set_ani_name(boss_ani_name);
  this->boss->move_left_right(move, 8.f);
}

void BaseFight::boss_move_initial_position()
{
  if (this->boss->get_position_x() != 800.f) // Until Boss goes back to his initial position , move his position with "run" animation
  {
    this->hero->set_ani_name(AnimationNames::IDLE);
    this->is_boss_attack = false;
    this->boss_move_position(AnimationNames::RUN, sf::Keyboard::D);
  }
  else // Boss has arrived to his initial position
  {
    this->hero_decrease_health();
    std::cout << this->boss->get_damage() << std::endl;

    if (this->key == sf::Keyboard::Unknown) // if E is pressed boss will split damage before attacking
    {
      this->boss_double_damage(); // and after attacking damage will be doubled up to its default value
    }

    this->hero_is_dead(); // check if hero is dead after decreasing health, if so end fight.
    this->is_turn_hero = true;
    this->boss->set_is_ani_over(false);
    this->boss->set_ani_name(AnimationNames::IDLE);
    this->hero->set_is_ani_over(false);
    this->hero->set_is_ani_stop(false);
  }
}

void BaseFight::hero_decrease_health()
{
  this->hero->decrease_heath(this->boss->get_damage());                        // for UI hero health
  this->hero->set_health(this->hero->get_health() - this->boss->get_damage()); // for stats hero health
}

void BaseFight::hero_decrease_mana()
{
  if (this->key == sf::Keyboard::R)
  {
    this->hero->decrease_mana(300);                     // for UI hero mana
    this->hero->set_mana(this->hero->get_mana() - 300); // for stats hero mana
  }
  else if (this->key == sf::Keyboard::W)
  {
    this->hero->decrease_mana(200);                     // for UI hero mana
    this->hero->set_mana(this->hero->get_mana() - 200); // for stats hero mana
  }
}

void BaseFight::hero_increase_mana()
{
  int temp_mana{this->hero->get_mana()};

  if (temp_mana != this->max_hero_mana)
  {
    temp_mana += 100;
    this->hero->set_mana(temp_mana);
  }
}

// BOSS
void BaseFight::boss_decrease_health()
{
  this->boss->decrease_heath(this->hero->get_damage());                        // for UI Boss health
  this->boss->set_health(this->boss->get_health() - this->hero->get_damage()); // for stats boss health
}

void BaseFight::hero_crit_attack_control()
{
  int temp_crit_chance{1 + std::rand() % 10}; // if crit_chance is higher than or equal to 7, hero will perform double damage for one round
  this->hero->set_crit_chance(temp_crit_chance);

  if (this->hero->get_crit_chance() >= 7)
  {
    this->hero_double_damage();
  }
}

void BaseFight::hero_double_damage()
{
  int temp_damage{this->hero->get_damage()};
  temp_damage *= 2;
  this->hero->set_damage(temp_damage);
}

void BaseFight::hero_split_damage()
{
  int temp_damage{this->hero->get_damage()};
  temp_damage /= 2;
  this->hero->set_damage(temp_damage);
}

void BaseFight::hero_defense_chance_control()
{

  int temp_defense_chance{1 + std::rand() % 10};
  this->hero->set_defense_chance(temp_defense_chance);

  if (this->hero->get_defense_chance() >= 7)
  {
    this->hero_perform_defense();
  }
}

void BaseFight::hero_perform_defense()
{
  this->hero->set_ani_name(AnimationNames::DEFEND);
  if (this->hero->get_que() == this->hero->get_defend_position()) // Stop animation
  {
    std::cout << "Hero increase mana UI" << std::endl;
    this->boss_split_damage();
    this->hero->increase_mana(); // Ui
    this->hero_increase_mana();  // stats
    this->hero->set_is_ani_stop(true);
    this->is_key_pressed = false;
    this->is_turn_hero = false;
    this->is_boss_attack = true;
    this->key = sf::Keyboard::Unknown;
  }
}

void BaseFight::hero_is_dead()
{
  std::cout << "hero_is_dead" << std::endl;
  if (this->hero->get_health() <= 0)
  {
    this->is_hero_dead = true;
    this->hero->set_ani_name(AnimationNames::DEATH);
  }
}

void BaseFight::boss_crit_attack_control()
{
  int temp_crit_chance{1 + std::rand() % 10};
  this->boss->set_crit_chance(temp_crit_chance);
  if (this->boss->get_crit_chance() >= 7)
  {
    this->boss_double_damage();
  }
}

void BaseFight::boss_double_damage()
{
  int temp_damage{this->boss->get_damage()};
  temp_damage *= 2;
  this->boss->set_damage(temp_damage);
}

void BaseFight::boss_split_damage()
{
  int temp_damage{this->boss->get_damage()};
  temp_damage /= 2;
  this->boss->set_damage(temp_damage);
}

void BaseFight::boss_is_dead()
{
  if (this->boss->get_health() <= 0)
  {
    this->is_boss_dead = true;
    this->boss->set_ani_name(AnimationNames::DEATH);
  }
}
bool BaseFight::get_is_fight_over()
{
  return this->is_fight_over;
}
