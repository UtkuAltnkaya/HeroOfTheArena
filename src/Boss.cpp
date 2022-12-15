#include "HOTA/Boss.hpp"
#include <iostream>
// Delegation
Boss::Boss() : Boss{"", 0, 0, 0, 0, 0.0f}
{
}

Boss::Boss(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal)
    : Physics{pathVal, 150, 150}, ani_name{"idle"}, health(healthVal),
      damage(damageVal), mana(manaVal), defense(damageVal), crit_chance(critChanceVal)
{
}

Boss::~Boss()
{
}

void Boss::init_all_animations()
{
  this->init_game_animation();
  this->init_fight_animation();
  this->set_and_calculate_position();
}

void Boss::init_game_animation()
{
  this->insert_new_animation("idle", "idle_", this->idle_num, true);
  this->insert_new_animation("run", "run_", this->run_num, true);
  this->insert_new_animation("run_left", "run_", this->run_num, true);
  this->insert_new_animation("jump_up", "jump_up_", this->jump_up_num, false);
}

void Boss::init_fight_animation()
{
  this->insert_new_animation("1_atk", "atk_", this->atk_one_num, false);
  this->insert_new_animation("defend", "defend_", this->defend_num, false);
}

void Boss::update()
{
  this->animation->update(this->is_ani_over);
  this->atk_boss();
  this->select_animation(this->ani_name);
}

void Boss::render(sf::RenderTarget &target)
{
  this->animation->render(target);
}

void Boss::atk_boss()
{
  if (this->ani_name == "1_atk")
  {
    if (this->is_ani_over)
    {
      this->ani_name = "idle";
      this->is_ani_over = false;
    }
  }
}

void Boss::poll_events(sf::Event &event)
{
  if (this->ani_name == "1_atk")
  {
    return;
  }
  /*
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // TODO
  {
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
  */
};

void Boss::poll_events_loop(sf::Event &event)
{
  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
    {
      if (this->ani_name == "1_atk")
      {
        return;
      }
      this->ani_name = "idle";
    }
  }
}
