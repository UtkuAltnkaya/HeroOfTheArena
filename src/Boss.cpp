#include "HOTA/Boss.hpp"
#include <iostream>
// Delegation
Boss::Boss() : Boss{"", 0, 0, 0, 0, 0.0f}
{
}

Boss::Boss(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal)
    : AnimationCreator{pathVal}, ani_name{"idle"}, health(healthVal), damage(damageVal), mana(manaVal), defense(damageVal), crit_chance(critChanceVal)
{
}

Boss::~Boss()
{
}

void Boss::update()
{
  this->animation->update(this->is_ani_over);
  this->move_boss();
  this->atk_boss();
  this->select_animation(this->ani_name);
}

void Boss::render(sf::RenderTarget &target)
{
  this->animation->render(target);
}

void Boss::move_boss()
{
  if (this->ani_name == "run")
  {
    this->move(sf::Keyboard::D);
  }
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

void Boss::move(sf::Keyboard::Key key)
{
  // sf::Sprite *sp = this->animation->get_sprite()->at(0);
  // sf::Vector2f pos = sp->getPosition();
  /*if (pos.x < (1548 - 505))
  {
      if (key == sf::Keyboard::D)
      {
          sp->setPosition(pos.x + 5, pos.y);
      }
  }
  if (pos.x != -355)
  {
      if (key == sf::Keyboard::A)
      {
          sp->setPosition(pos.x - 5, pos.y);
      }
  }
  if (key == sf::Keyboard::Space)
  {
      if (this->ani_name == "jump_up" && pos.y > 250.f)
      {
          sp->setPosition(pos.x, pos.y - 4);
      }
      else if (pos.y <= 343)
      {
          this->ani_name = "jump_down";
          sp->setPosition(pos.x, pos.y + 4);
      }
      else
      {
          this->ani_name = "idle";
      }
  }
  */
  this->set_all_animation_position(this->animation->get_sprite()->at(0)->getPosition());
}
