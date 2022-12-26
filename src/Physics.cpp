#include "HOTA/Physics.hpp"
#include <iostream>

Physics::Physics(const std::string &path, const int &character_actual_width, const int &character_actual_height)
    : AnimationCreator{path},
      velocity_x{5.f}, velocity_y{7.5f}, gravity{10.f},
      character_actual_width{character_actual_width}, character_actual_height{character_actual_height},
      top_point{250.f}, is_reach_to_top_point{false}
{
}

Physics::~Physics()
{
}

void Physics::init_position()
{
  this->position = this->initial_positions;
}

void Physics::projectile_jump(const sf::Keyboard::Key &Key, AnimationNames &jump_ani_name)
{
  this->velocity_x = 4.f;
  this->jump(jump_ani_name);
  this->move_left_right(Key);
  this->velocity_x = 5.f;
}

void Physics::move_left_right(const sf::Keyboard::Key &Key, float velocity_x)
{
  this->velocity_x = velocity_x;
  if (Key == sf::Keyboard::D) // Right
  {
    return this->move_right();
  }
  if (Key == sf::Keyboard::A) // Left
  {
    return this->move_left();
  }
}

void Physics::move_right() // Move right
{
  if (this->position.x < this->window_width - this->character_width * 0.5 - this->character_actual_width)
  {
    this->set_position(sf::Vector2f{this->position.x + this->velocity_x, this->position.y});
  }
}

void Physics::move_left() // Move left
{
  if (this->position.x > (this->character_width * 0.5 - this->character_actual_width) * -1)
  {
    this->set_position(sf::Vector2f{this->position.x - this->velocity_x, this->position.y});
  }
}

void Physics::jump(AnimationNames &jump_ani_name)
{
  this->jump_up(jump_ani_name);
  this->jump_down(jump_ani_name);
}

void Physics::jump_up(AnimationNames &jump_ani_name)
{
  if (this->is_reach_to_top_point)
  {
    return;
  }
  this->velocity_y -= 0.2;
  if (this->position.y < this->top_point) // reach top point
  {
    this->is_reach_to_top_point = true;
    if (jump_ani_name == AnimationNames::JUMP_PROJECTILE_UP)
    {
      jump_ani_name = AnimationNames::JUMP_PROJECTILE_DOWN;
    }
    else if (jump_ani_name == AnimationNames::JUMP_PROJECTILE_UP_LEFT)
    {
      jump_ani_name = AnimationNames::JUMP_PROJECTILE_DOWN_LEFT;
    }
    else
    {
      jump_ani_name = AnimationNames::JUMP_DOWN;
    }
  }
  this->set_position(sf::Vector2f{this->position.x, this->position.y - this->velocity_y});
}

void Physics::jump_down(AnimationNames &jump_ani_name)
{
  if (!this->is_reach_to_top_point)
  {
    return;
  }
  this->velocity_y += 0.2;
  if (this->position.y > this->initial_positions.y - 10) // came back to ground
  {
    this->is_reach_to_top_point = false;
    jump_ani_name = AnimationNames::IDLE;
    this->velocity_y = 7.5f;
  }
  this->set_position(sf::Vector2f{this->position.x, this->position.y + this->velocity_y});
}

void Physics::set_position(const sf::Vector2f &new_position) // Set all animation position to new position
{
  this->position = new_position;
  this->set_all_animation_position(this->position);
}

bool Physics::is_collide(const Physics *obj) // Check boss and player is collide
{
  float char_start_pos{this->position.x + (this->character_width + this->character_actual_width) * 0.5f}; // Character start postion
  float char_end_pos{this->position.x + (this->character_width - this->character_actual_width) * 0.5f};   // Character end position
  float obj_start_pos{obj->position.x + (obj->character_width - obj->character_actual_width) * 0.5f};     // Obj start position
  float obj_end_pos{obj->position.x + (obj->character_width + obj->character_actual_width) * 0.5f + 20};  // Obj end position,20 is used for equalize start and end position
  if (char_start_pos > obj_start_pos && char_end_pos < obj_end_pos)
  {
    return true;
  }
  return false;
}

const float &Physics::get_position_x()
{
  return this->position.x;
}