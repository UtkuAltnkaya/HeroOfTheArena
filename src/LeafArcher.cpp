#include "HOTA/LeafArcher.hpp"
#include <iostream>

LeafArcher::LeafArcher() : Hero{"image", 5000, 200, 500, 250, 0.1f}
{
  this->init_var();
}

LeafArcher::~LeafArcher()
{
}

void LeafArcher::init_var()
{
  this->init_ani_stats();
  this->init_ani();
  this->init_stats();
}

void LeafArcher::init_ani_stats()
{

  this->set_path(this->get_path() + "/Leaf Archer");
  this->set_atk_one_num(10);
  this->set_atk_two_num(15);
  this->set_atk_sp_num(17);
  this->set_death_num(19);
  this->set_defend_num(19);
  this->set_idle_num(9);
  this->set_jump_num(22);
  this->set_roll_num(8);
  this->set_run_num(10);
  this->set_take_dmg_num(6);
}

void LeafArcher::init_stats()
{
  this->set_health(this->get_health() - 1800);
  this->set_damage(this->get_damage() + 100);
  this->set_mana(this->get_mana() + 200);
  this->set_defense(this->get_defense() - 50);
  this->set_crit_chance(this->get_crit_chance() + 0.25);
}

void LeafArcher::init_ani()
{
  auto ani_path = this->get_path();
  this->set_hero_ani(std::pair<std::string, Animation *>("idle", new Animation(ani_path, "idle", "idle_", 9)));
  this->set_hero_ani(std::pair<std::string, Animation *>("run", new Animation(ani_path, "run", "run_", 10)));
  this->set_hero_ani(std::pair<std::string, Animation *>("roll", new Animation(ani_path, "roll", "roll_", 8)));
  this->set_hero_ani(std::pair<std::string, Animation *>("roll_left", new Animation(ani_path, "roll", "roll_", 8)));
  // this->set_hero_ani(std::pair<std::string, Animation *>("run_left", new Animation(ani_path, "run_left", "run_", 10)));
}

void LeafArcher::skill()
{
  // TODO
}

void LeafArcher::upgrade()
{
  // TODO
}

void LeafArcher::update()
{
  for (auto i : this->get_hero_ani())
  {
    auto name = this->get_ani_name(5); // todo delete index
    if (i.first == name)
    {
      this->get_hero_ani()[name]->update();
    }
  }
  // this->get_hero_ani()["idle"]->update();
}

void LeafArcher::render(sf::RenderTarget &target)
{

  for (auto i : this->get_hero_ani())
  {
    auto name = this->get_ani_name(5); // todo delete index
    if (i.first == name)
    {
      this->get_hero_ani()[name]->render(target);
    }
  }
}
