#include "HOTA/Hero.hpp"
#include <iostream>
// Delegation
Hero::Hero() : Hero{"", 0, 0, 0, 0, 0.0f, 0, 0}
{
}

Hero::Hero(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal, int actualWidth, int actualHeight)
    : Physics{pathVal, actualWidth, actualHeight}, ani_name{"idle"}, health(healthVal),
      damage(damageVal), mana(manaVal), defense(damageVal), crit_chance(critChanceVal)
{
  this->init_var();
}

Hero::~Hero()
{
}

void Hero::init_var()
{
  this->character_width = 864;
  this->character_height = 384;
  this->initial_positions.x = -10;
}

void Hero::init_all_animations()
{
  this->init_game_animations();
  this->init_fight_animations();
  this->set_and_calculate_position();
}

void Hero::init_game_animations()
{
  this->insert_new_animation("idle", "idle_", this->idle_num, true);
  this->insert_new_animation("run", "run_", this->run_num, true);
  this->insert_new_animation("run_left", "run_", this->run_num, true);
  this->insert_new_animation("jump_up", "jump_up_", this->jump_up_num, false);
  this->insert_new_animation("jump_down", "jump_down_", this->jump_down_num, false);
  this->insert_new_animation("jump_up_left", "jump_up_", this->jump_up_num, false);
  this->insert_new_animation("jump_down_left", "jump_down_", this->jump_down_num, false);
}

void Hero::init_fight_animations()
{
  this->insert_new_animation("1_atk", "atk_", this->atk_one_num, false);
  this->insert_new_animation("2_atk", "atk_", this->atk_two_num, false);
  this->insert_new_animation("sp_atk", "sp_atk_", this->atk_sp_num, false);
  this->insert_new_animation("defend", "defend_", this->defend_num, false);
}

void Hero::update()
{
  this->animation->update(this->is_ani_over);
  this->move_character();
  this->atk_character();
  this->select_animation(this->ani_name);
}

void Hero::render(sf::RenderTarget &target)
{
  this->animation->render(target);
}

void Hero::move_character()
{
  if (this->ani_name == "run")
  {
    this->move_left_right(sf::Keyboard::D);
  }
  else if (this->ani_name == "run_left")
  {
    this->move_left_right(sf::Keyboard::A);
  }
  if (this->ani_name == "jump_up" || this->ani_name == "jump_down")
  {
    this->jump(this->ani_name);
  }
  if (this->ani_name == "jump_projectile_up" || this->ani_name == "jump_projectile_down")
  {
    this->projectile_jump(sf::Keyboard::D, this->ani_name);
  }
  if (this->ani_name == "jump_projectile_up_left" || this->ani_name == "jump_projectile_down_left")
  {
    this->projectile_jump(sf::Keyboard::A, this->ani_name);
  }
}

void Hero::atk_character()
{
  if (this->ani_name == "1_atk" || this->ani_name == "2_atk" || this->ani_name == "sp_atk" || this->ani_name == "defend")
  {
    if (this->is_ani_over)
    {
      this->ani_name = "idle";
      this->is_ani_over = false;
    }
  }
}

void Hero::poll_events(sf::Event &event)
{
  if (this->ani_name == "jump_up" || this->ani_name == "jump_projectile_up" || this->ani_name == "jump_projectile_down" || this->ani_name == "jump_down" || this->ani_name == "1_atk" || this->ani_name == "2_atk" || this->ani_name == "sp_atk" || this->ani_name == "defend" || this->ani_name == "jump_projectile_up_left" || this->ani_name == "jump_projectile_down_left")
  {
    return;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      this->ani_name = "jump_projectile_up";
      return;
    }
    this->ani_name = "run";
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      this->ani_name = "jump_projectile_up_left";
      return;
    }
    this->ani_name = "run_left";
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
  {
    this->ani_name = "1_atk";
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    this->ani_name = "2_atk";
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
  {
    this->ani_name = "defend";
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
  {
    this->ani_name = "sp_atk";
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    this->ani_name = "jump_up";
  }
};

void Hero::poll_events_loop(sf::Event &event)
{
  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
    {
      if (this->ani_name == "jump_up" || this->ani_name == "jump_projectile_up" || this->ani_name == "jump_projectile_down" || this->ani_name == "jump_down" || this->ani_name == "1_atk" || this->ani_name == "2_atk" || this->ani_name == "sp_atk" || this->ani_name == "defend" || this->ani_name == "jump_projectile_up_left" || this->ani_name == "jump_projectile_down_left")
      {
        return;
      }
      this->ani_name = "idle";
    }
  }
}
