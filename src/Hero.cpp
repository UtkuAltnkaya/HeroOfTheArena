#include "HOTA/Hero.hpp"
#include "HOTA/Animation.hpp"
#include <iostream>
// Delegation
Hero::Hero() : Hero{"", 0, 0, 0, 0, 0.0f}
{
}

Hero::Hero(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal)
    : path(pathVal), health(healthVal), damage(damageVal), mana(manaVal), defense(damageVal), critChance(critChanceVal)
{
  this->ani_name = "idle";
}

Hero::~Hero()
{
  for (auto &i : this->hero_ani)
  {
    delete i.second;
  }
}

void Hero::poll_events(sf::Event &event)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // TODO
  {
    this->ani_name = "run";
  }
};

//

std::map<std::string, Animation *> &Hero::get_hero_ani()
{
  return this->hero_ani;
}

std::string Hero::get_ani_name(int index)
{
  return this->ani_name;
}

// Getters
std::string Hero::get_path()
{
  return this->path;
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
int Hero::get_defense()
{
  return this->defense;
}
float Hero::get_crit_chance()
{
  return this->critChance;
}

//
int Hero::get_idle_num()
{
  return this->idleNum;
}
int Hero::get_atk_one_num()
{
  return this->atkOneNum;
}
int Hero::get_atk_two_num()
{
  return this->atkTwoNum;
}
int Hero::get_atk_sp_num()
{
  return this->atkSpNum;
}
int Hero::get_run_num()
{
  return this->runNum;
}
int Hero::get_roll_num()
{
  return this->rollNum;
}
int Hero::get_jump_num()
{
  return this->jumpNum;
}
int Hero::get_defend_num()
{
  return this->defendNum;
}
int Hero::get_death_num()
{
  return this->deathNum;
}
int Hero::get_take_dmg_num()
{
  return this->takeDmgNum;
}
//
void Hero::set_hero_ani(std::pair<std::string, Animation *> pair)
{
  this->hero_ani.insert(pair);
}

// Setters
void Hero::set_path(std::string path)
{
  this->path = path;
}

void Hero::set_health(int health)
{
  this->health = health;
}
void Hero::set_damage(int damage)
{
  this->damage = damage;
}
void Hero::set_mana(int mana)
{
  this->mana = mana;
}
void Hero::set_defense(int defense)
{
  this->defense = defense;
}
void Hero::set_crit_chance(float critChance)
{
  this->critChance = critChance;
}

//
void Hero::set_idle_num(int idleNum)
{
  this->idleNum = idleNum;
}
void Hero::set_atk_one_num(int atkOneNum)
{
  this->atkOneNum = atkOneNum;
}
void Hero::set_atk_two_num(int atkTwoNum)
{
  this->atkTwoNum = atkTwoNum;
}
void Hero::set_atk_sp_num(int atkSpNum)
{
  this->atkSpNum = atkSpNum;
}
void Hero::set_run_num(int runNum)
{
  this->runNum = runNum;
}
void Hero::set_roll_num(int rollNum)
{
  this->rollNum = rollNum;
}
void Hero::set_jump_num(int jumpNum)
{
  this->jumpNum = jumpNum;
}
void Hero::set_defend_num(int defendNum)
{
  this->defendNum = deathNum;
}
void Hero::set_death_num(int deathNum)
{
  this->deathNum = deathNum;
}
void Hero::set_take_dmg_num(int takeDmgNum)
{
  this->takeDmgNum = takeDmgNum;
}