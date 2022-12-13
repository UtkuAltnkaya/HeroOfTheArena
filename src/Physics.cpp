#include "HOTA/Physics.hpp"
#include <iostream>

Physics::Physics(std::string path) : AnimationCreator{path}, velocity_x{5.f}, gravity{10.f}, character_actual_width{100}
{
}

Physics::~Physics()
{
}

void Physics::init_position()
{
  sf::Sprite *animation = this->animation->get_sprite()->at(0);
  this->position = animation->getPosition();
}

void Physics::projectile_jump(sf::Keyboard::Key Key, std::string &jump_ani_name)
{

  this->jump(jump_ani_name);
  this->move_left_right(Key);
}

void Physics::move_left_right(sf::Keyboard::Key Key)
{
  if (Key == sf::Keyboard::D) // Right
  {
    return this->move_right();
  }

  if (Key == sf::Keyboard::A) // Left
  {
    return this->move_left();
  }
}

void Physics::move_right()
{
  if (this->position.x < this->window_width - this->character_width * 0.5 - this->character_actual_width)
  {
    this->set_position(sf::Vector2f{this->position.x + this->velocity_x, this->position.y});
  }
}

void Physics::move_left()
{
  if (this->position.x > (this->character_width * 0.5 - this->character_actual_width) * -1)
  {
    this->set_position(sf::Vector2f{this->position.x - this->velocity_x, this->position.y});
  }
}

void Physics::jump(std::string &jump_ani_name)
{
  if (jump_ani_name == "jump_up" && this->position.y > 250.f)
  {
    return this->set_position(sf::Vector2f{this->position.x, this->position.y - this->velocity_x});
  }
  else if (this->position.y <= this->initial_positions.y)
  {
    jump_ani_name = "jump_down";
    return this->set_position(sf::Vector2f{this->position.x, this->position.y + this->velocity_x});
  }
  jump_ani_name = "idle";
}

void Physics::set_position(sf::Vector2f new_position)
{
  this->position = new_position;
  this->set_all_animation_position(this->position);
}