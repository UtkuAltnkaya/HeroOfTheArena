#include "HOTA/Player.hpp"
#include <iostream>

Player::Player()
{
  this->init_var();
  this->init_animation();
}

Player::~Player()
{
  for (auto i : this->player_ani)
  {
    delete i.second;
  }
  this->player_ani.clear();
}

// Public
void Player::update(std::string &ani_name)
{
  bool is;
  for (auto i : this->player_ani)
  {
    if (i.first == ani_name)
    {
      if (i.first == "run" || i.first == "roll")
      {
        this->move("right");
      }
      else if (i.first == "run_left" || i.first == "roll_left")
      {
        this->move("left");
      }
      return i.second->update(is);
    }
  }
}

void Player::render(sf::RenderTarget &target, std::string &ani_name)
{

  for (auto i : this->player_ani)
  {
    if (i.first == ani_name)
    {
      return this->player_ani[ani_name]->render(target);
    }
  }
}

void Player::move(std::string dir)
{

  for (auto &i : this->player_ani)
  {
    for (auto &j : *i.second->get_sprite())
    {
      auto sp_pos = j->getPosition();
      if (dir == "left")
      {
        j->setPosition(sp_pos.x - 5, sp_pos.y);
      }
      else
      {
        j->setPosition(sp_pos.x + 5, sp_pos.y);
      }

      if (sp_pos.x >= (1536 - 300))
      {
        j->setPosition(-10, sp_pos.y);
      }
    }
  }
}

// Private
void Player::init_var()
{
}

void Player::init_animation()
{
  // this->player_ani.insert(std::pair<std::string, Animation *>("idle", new Animation("idle", "idle_", 9)));
  // this->player_ani.insert(std::pair<std::string, Animation *>("run", new Animation("run", "run_", 10)));
  // this->player_ani.insert(std::pair<std::string, Animation *>("roll", new Animation("roll", "roll_", 8)));
  // this->player_ani.insert(std::pair<std::string, Animation *>("roll_left", new Animation("roll", "roll_", 8)));
  // this->player_ani.insert(std::pair<std::string, Animation *>("run_left", new Animation("run_left", "run_", 10)));
}
