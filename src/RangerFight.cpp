#include <iostream>
#include "HOTA/RangerFight.hpp"

RangerFight::RangerFight(LeafArcher *hero, Boss *boss) : BaseFight{hero, boss}, hero{hero}, boss{boss}
{
}

RangerFight::~RangerFight()
{
}

void RangerFight::poll_events()
{
  if (this->is_turn_hero && !this->is_hero_dead)
  {
    this->hero_attack();
  }
  else if (!this->is_turn_hero && !this->is_boss_dead)
  {
    this->boss_attack();
  }

  if (this->is_hero_dead)
  {
    if (this->hero->get_que() == this->hero->get_death_position()) // Stop animation
    {
      this->hero->set_is_ani_stop(true);
      std::cout << "hero_dead" << std::endl;
      this->is_fight_over = true;
    }
  }

  if (this->is_boss_dead)
  {
    if (this->boss->get_que() == 20) // Stop animation
    {
      this->boss->set_is_ani_stop(true);
      std::cout << "boss_dead" << std::endl;
      this->is_fight_over = true;
    }
  }
}

void RangerFight::hero_attack()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
  {
    this->key_archer = sf::Keyboard::Q;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    this->key_archer = sf::Keyboard::W;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
  {
    this->key_archer = sf::Keyboard::E;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
  {
    this->key_archer = sf::Keyboard::R;
  }

  if (this->boss->get_ani_name() == AnimationNames::TAKE_HIT)
  {
    if (!this->boss->get_is_ani_over())
    {
      this->boss->set_is_ani_over(true);
    }
  }

  this->hero_attack_control();
  this->arrow_hit_moment();
}

void RangerFight::hero_attack_control()
{
  if (this->key_archer == sf::Keyboard::Q)
  {
    this->hero->set_ani_name(AnimationNames::ONE_ATK);
  }
  if (this->key_archer == sf::Keyboard::W)
  {
    this->hero->set_ani_name(AnimationNames::TWO_ATK);
  }
  this->key_archer = sf::Keyboard::Unknown;
}

void RangerFight::arrow_hit_moment()
{
  if (this->hero->get_hit())
  {
    this->boss_decrease_health();
    this->boss->set_ani_name(AnimationNames::TAKE_HIT);
    this->hero->set_is_ani_over(false);
    this->is_turn_hero = false;
    this->is_boss_attack = true;

    this->hero->set_hit(false);
  }
}
