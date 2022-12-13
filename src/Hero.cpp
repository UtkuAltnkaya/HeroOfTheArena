#include "HOTA/Hero.hpp"
#include <iostream>
// Delegation
Hero::Hero() : Hero{"", 0, 0, 0, 0, 0.0f}
{
}

Hero::Hero(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal)
    : Physics{pathVal}, ani_name{"idle"}, health(healthVal), damage(damageVal), mana(manaVal), defense(damageVal), crit_chance(critChanceVal)
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
  // if (this->ani_name == "jump_projectile")
  // {
  //   this->projectile_jump(sf::Keyboard::D, this->ani_name);
  // }
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
  if (this->ani_name == "jump_up" || this->ani_name == "jump_down" || this->ani_name == "1_atk" || this->ani_name == "2_atk" || this->ani_name == "sp_atk" || this->ani_name == "defend")
  {
    return;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // TODO
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      // TODO
    }
    this->ani_name = "run";
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
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
      if (this->ani_name == "jump_up" || this->ani_name == "jump_down" || this->ani_name == "1_atk" || this->ani_name == "2_atk" || this->ani_name == "sp_atk" || this->ani_name == "defend")
      {
        return;
      }
      this->ani_name = "idle";
    }
  }
}
