#include "HOTA/Boss.hpp"
#include <iostream>
// Delegation
Boss::Boss() : Boss{"", 0, 0, 0, 0, 0.0f}
{
}

Boss::Boss(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal)
    : Physics{pathVal, 300, 300}, ani_name{"idle"}, health(healthVal),
      damage(damageVal), mana(manaVal), defense(damageVal), crit_chance(critChanceVal), is_fight_start{false}, is_ani_over{false}
{
}

Boss::~Boss()
{
}

void Boss::init_all_animations()
{
  this->init_game_animations();
  this->init_fight_animations();
  this->set_and_calculate_position();
}

void Boss::init_game_animations()
{
  this->insert_new_animation("idle", "idle_", this->idle_num, true);
  this->insert_new_animation("run", "run_", this->run_num, true);
  this->insert_new_animation("run_left", "run_", this->run_num, true);
  // this->insert_new_animation("jump_up", "jump_up_", this->jump_up_num, false);
}

void Boss::init_fight_animations()
{
  this->insert_new_animation("1_atk", "atk_", this->atk_one_num, false);
  this->insert_new_animation("defend", "defend_", this->defend_num, false);
  this->insert_new_animation("take_hit", "take_hit_", this->take_dmg_num, false);
  this->insert_new_animation("death", "death_", this->death_num, false);
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
  if (this->ani_name == "1_atk" || this->ani_name == "take_hit")
  {
    if (this->is_ani_over)
    {
      this->ani_name = "idle";
    }
  }
}

void Boss::poll_events(sf::Event &event)
{
  if (this->ani_name == "1_atk")
  {
    return;
  }
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

void Boss::fight_start()
{
  this->is_fight_start = true;
  this->is_ani_over = false;
  this->init_fight_animations();
}

bool Boss::get_is_ani_over()
{
  return this->is_ani_over;
}

void Boss::set_is_ani_over(const bool &is_ani_over)
{
  this->is_ani_over = is_ani_over;
}

void Boss::set_ani_name(const std::string &ani_name)
{
  this->ani_name = ani_name;
}
