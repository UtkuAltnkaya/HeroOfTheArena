#include "HOTA/Hero.hpp"
#include <iostream>
// Delegation
Hero::Hero() : Hero{"", 0, 0, 0, 0, 0, 0, 0}
{
}

Hero::Hero(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, int critChanceVal, int actualWidth, int actualHeight)
    : Physics{pathVal, actualWidth, actualHeight},
      ui{new Ui{}},
      health(healthVal), damage(damageVal), mana(manaVal), defense_chance(defenseVal), crit_chance(critChanceVal),
      is_fight_start{false}, is_ani_over{false}, ani_name{AnimationNames::IDLE}

{
  this->init_var();
}

Hero::~Hero()
{
  delete this->ui;
}

void Hero::init_var()
{
  this->character_width = 864;
  this->character_height = 384;
  this->initial_positions.x = -200;
}

void Hero::init_all_animations()
{
  this->init_game_animations();
  this->set_and_calculate_position();
}

void Hero::init_game_animations()
{
  this->insert_new_animation(AnimationNames::IDLE, "idle", "idle_", this->idle_num, true);
  this->insert_new_animation(AnimationNames::RUN, "run", "run_", this->run_num, true);
  this->insert_new_animation(AnimationNames::RUN_LEFT, "run_left", "run_", this->run_num, true);
  this->insert_new_animation(AnimationNames::JUMP_UP, "jump_up", "jump_up_", this->jump_up_num, false);
  this->insert_new_animation(AnimationNames::JUMP_DOWN, "jump_down", "jump_down_", this->jump_down_num, false);
  this->insert_new_animation(AnimationNames::JUMP_UP_LEFT, "jump_up_left", "jump_up_", this->jump_up_num, false);
  this->insert_new_animation(AnimationNames::JUMP_DOWN_LEFT, "jump_down_left", "jump_down_", this->jump_down_num, false);
}
void Hero::load_fight_multi_thread(AnimationNames num, std::string type, std::string file, int num_of_png, bool is_repeated)
{
  this->insert_new_animation(num, type, file, num_of_png, is_repeated);
}
void Hero::init_fight_animations()
{
  std::thread t1(&Hero::load_fight_multi_thread, this, AnimationNames::ONE_ATK, "1_atk", "atk_", this->atk_one_num, false);
  std::thread t2(&Hero::load_fight_multi_thread, this, AnimationNames::TWO_ATK, "2_atk", "atk_", this->atk_two_num, false);
  std::thread t3(&Hero::load_fight_multi_thread, this, AnimationNames::SP_ATK, "sp_atk", "sp_atk_", this->atk_sp_num, false);
  std::thread t4(&Hero::load_fight_multi_thread, this, AnimationNames::DEFEND, "defend", "defend_", this->defend_num, false);
  std::thread t5(&Hero::load_fight_multi_thread, this, AnimationNames::DEATH, "death", "death_", this->death_num, false);
  std::thread t6(&Hero::load_fight_multi_thread, this, AnimationNames::TAKE_HIT, "take_hit", "take_hit_", this->take_dmg_num, true);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
}

void Hero::update()
{
  this->animation->update(this->is_ani_over);
  if (this->is_fight_start)
  {
    this->atk_character();
  }
  else
  {
    this->move_character();
  }
  this->select_animation(this->ani_name);
}

void Hero::render(sf::RenderTarget &target)
{
  this->animation->render(target);
  this->ui->render(target);
}

void Hero::move_character()
{
  if (this->ani_name == AnimationNames::RUN)
  {
    return this->move_left_right(sf::Keyboard::D);
  }
  if (this->ani_name == AnimationNames::RUN_LEFT)
  {
    return this->move_left_right(sf::Keyboard::A);
  }
  if (this->ani_name == AnimationNames::JUMP_UP || this->ani_name == AnimationNames::JUMP_DOWN)
  {
    return this->jump(this->ani_name);
  }
  if (this->ani_name == AnimationNames::JUMP_PROJECTILE_UP || this->ani_name == AnimationNames::JUMP_PROJECTILE_DOWN)
  {
    return this->projectile_jump(sf::Keyboard::D, this->ani_name);
  }
  if (this->ani_name == AnimationNames::JUMP_PROJECTILE_UP_LEFT || this->ani_name == AnimationNames::JUMP_PROJECTILE_DOWN_LEFT)
  {
    return this->projectile_jump(sf::Keyboard::A, this->ani_name);
  }
}

void Hero::atk_character()
{
  if (this->ani_name == AnimationNames::ONE_ATK || this->ani_name == AnimationNames::TWO_ATK || this->ani_name == AnimationNames::SP_ATK || this->ani_name == AnimationNames::DEFEND)
  {
    if (this->is_ani_over)
    {
      this->ani_name = AnimationNames::IDLE;
    }
  }
}

void Hero::poll_events(sf::Event &event, Boss *boss)
{
  if (this->animation_guard())
  {
    return;
  }
  if (!this->is_fight_start)
  {
    this->game_events();
  }
};

void Hero::poll_events_loop(sf::Event &event)
{
  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
    {
      if (this->animation_guard())
      {
        return;
      }
      this->ani_name = AnimationNames::IDLE;
    }
  }
}

void Hero::game_events()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      this->ani_name = AnimationNames::JUMP_PROJECTILE_UP;
      return;
    }
    this->ani_name = AnimationNames::RUN;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      this->ani_name = AnimationNames::JUMP_PROJECTILE_UP_LEFT;
      return;
    }
    this->ani_name = AnimationNames::RUN_LEFT;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    this->ani_name = AnimationNames::JUMP_UP;
  }
}

const bool Hero::animation_guard()
{
  if (this->ani_name == AnimationNames::JUMP_UP || this->ani_name == AnimationNames::JUMP_DOWN)
  {
    return true;
  }
  if (this->ani_name == AnimationNames::JUMP_PROJECTILE_UP || this->ani_name == AnimationNames::JUMP_PROJECTILE_DOWN)
  {
    return true;
  }
  if (this->ani_name == AnimationNames::ONE_ATK || this->ani_name == AnimationNames::TWO_ATK || this->ani_name == AnimationNames::SP_ATK || this->ani_name == AnimationNames::DEFEND)
  {
    return true;
  }
  if (this->ani_name == AnimationNames::JUMP_PROJECTILE_UP_LEFT || this->ani_name == AnimationNames::JUMP_PROJECTILE_DOWN_LEFT)
  {
    return true;
  }
  return false;
}

void Hero::fight_start()
{
  this->is_fight_start = true;
  this->is_ani_over = false;
  this->ani_name = AnimationNames::IDLE;
  this->init_fight_animations();
  this->set_position(this->initial_positions);
}

void Hero::decrease_heath(const int &number)
{
  this->ui->reduce_health(number, true);
}

void Hero::decrease_mana(const int &number)
{
  this->ui->reduce_hero_mana(number);
}

void Hero::increase_mana()
{
  this->ui->increase_hero_mana();
}

bool Hero::get_is_ani_over()
{
  return this->is_ani_over;
}

int Hero::get_health()
{
  return this->health;
}

int Hero::get_damage()
{
  return this->damage;
}

int Hero::get_mana()
{
  return this->mana;
}

int Hero::get_crit_chance()
{
  return this->crit_chance;
}

int Hero::get_defense_chance()
{
  return this->defense_chance;
}

void Hero::set_is_ani_over(const bool &is_ani_over)
{
  this->is_ani_over = is_ani_over;
}

void Hero::set_ani_name(const AnimationNames &ani_name)
{
  this->ani_name = ani_name;
}
const AnimationNames &Hero::get_ani_name()
{
  return this->ani_name;
}

void Hero::set_health(const int &health)
{
  this->health = health;
}

void Hero::set_damage(const int &damage)
{
  this->damage = damage;
}

void Hero::set_mana(const int &mana)
{
  this->mana = mana;
}

void Hero::set_crit_chance(const int &crit_chance)
{
  this->crit_chance = crit_chance;
}

void Hero::set_defense_chance(const int &defense_chance)
{
  this->defense_chance = defense_chance;
}