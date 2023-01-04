#include <iostream>
#include "HOTA/RangerFight.hpp"

RangerFight::RangerFight(LeafArcher *hero, Boss *boss) : BaseFight{hero, boss}, hero{hero}, boss{boss}, is_hero_hit{false}
{
}

RangerFight::~RangerFight()
{
}

void RangerFight::poll_events()
{
  if (this->is_turn_hero && !this->is_hero_dead) // Hero attack condition
  {
    this->hero_attack();
  }
  else if (!this->is_turn_hero && !this->is_boss_dead) // Boss attack conditon
  {
    this->boss_attack();
  }

  if (this->is_hero_dead)
  {
    if (this->hero->get_que() == this->hero->get_death_position()) // Stop animation
    {
      this->hero->set_is_ani_stop(true);
      this->is_fight_over = true;
    }
  }

  if (this->is_boss_dead)
  {

    if (this->boss->get_que() == 20) // Stop animation
    {
      this->boss->set_is_ani_stop(true);
      this->is_fight_over = true;
    }
  }
}

void RangerFight::hero_attack()
{
  if (this->hero->get_ani_name() == AnimationNames::IDLE) // Avoid spamming key
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
      this->key_archer = sf::Keyboard::Q;
      this->hero_split_damage();
      this->key = this->key_archer;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
      if (this->hero->get_mana() >= 200)
      {
        this->key_archer = sf::Keyboard::W;
        this->key = this->key_archer;
      }
      else
      {
        std::cout << "Don't have enough mana for W" << std::endl;
        // this->key = sf::Keyboard::Unknown;
      }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
      this->key_archer = sf::Keyboard::E;
      this->key = this->key_archer;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
      if (this->hero->get_mana() >= 300)
      {
        this->hero_double_damage();
        this->key_archer = sf::Keyboard::R;
        this->key = this->key_archer;
      }
      else
      {
        std::cout << "Don't have enough mana for R" << std::endl;
        // this->key = sf::Keyboard::Unknown;
      }
    }
  }

  if (this->key_archer == sf::Keyboard::E) // Perform defend
  {
    return this->hero_perform_defense(this->key_archer);
  }

  this->hero_attack_control();
  this->arrow_hit_moment();
  this->just_before_boss_turn();
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

  if (this->key_archer == sf::Keyboard::E)
  {
    this->hero->set_ani_name(AnimationNames::DEFEND);
    return;
  }

  if (this->key_archer == sf::Keyboard::R)
  {
    this->hero->set_ani_name(AnimationNames::SP_ATK);
  }

  this->key_archer = sf::Keyboard::Unknown;
}

void RangerFight::arrow_hit_moment() // Arrow hit moment
{
  if (this->hero->get_hit()) // if arrow position collide with boss
  {
    this->boss_decrease_health();

    if (this->key == sf::Keyboard::Q)
    {
      this->hero_double_damage();
    }
    else if (this->key == sf::Keyboard::R)
    {
      this->hero_split_damage();
    }

    this->hero_decrease_mana();
    this->boss->set_ani_name(AnimationNames::TAKE_HIT);
    this->boss_is_dead(); // After decreasing boss health check whether is he dead if so, fight must end. Problem: (NOT CALLED IN LOOP)
    this->hero->set_ani_name(AnimationNames::IDLE);
    this->hero->set_is_ani_over(false);
    this->hero->set_hit(false);
    this->is_hero_hit = true; // To perform take hit animation correctly
  }
}

void RangerFight::just_before_boss_turn() // Just before the boss turn start
{
  if (this->is_hero_hit) // If arrow hit the boss
  {
    if (this->boss->get_is_ani_over()) // If take hit animation over
    {
      this->is_hero_hit = true;
      this->is_turn_hero = false;
      this->is_boss_attack = true;
      this->boss->set_is_ani_over(false);
    }
  }
}