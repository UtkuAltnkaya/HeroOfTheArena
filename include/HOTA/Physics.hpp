#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "HOTA/AnimationCreator.hpp"

class Physics : public AnimationCreator
{
private:
  sf::Vector2f position;

  float velocity_x;
  float velocity_y;
  float gravity;

  int character_actual_width;
  int character_actual_height;

  void move_left();
  void move_right();

protected:
  void init_position();
  void projectile_jump(sf::Keyboard::Key Key, std::string &jump_ani_name);
  void jump(std::string &jump_ani_name);
  void move_left_right(sf::Keyboard::Key Key);
  void set_position(sf::Vector2f new_position);

public:
  Physics(std::string path);
  ~Physics();
};

#endif