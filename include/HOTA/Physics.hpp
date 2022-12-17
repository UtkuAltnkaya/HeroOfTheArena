#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "HOTA/AnimationCreator.hpp"
// #include "HOTA/Hero.hpp"
// #include "HOTA/Boss.hpp"

class Physics : public AnimationCreator
{
private:
  sf::Vector2f position;

  float velocity_x;
  float velocity_y;
  float gravity;

  int character_actual_width;
  int character_actual_height;

  float top_point;
  bool is_reach_to_top_point;

  void move_left();
  void move_right();
  void jump_up(std::string &jump_ani_name);
  void jump_down(std::string &jump_ani_name);

protected:
  void init_position();
  void projectile_jump(const sf::Keyboard::Key &Key, std::string &jump_ani_name);
  void jump(std::string &jump_ani_name);
  void move_left_right(const sf::Keyboard::Key &Key);

public:
  Physics(std::string path, int character_actual_width, int character_actual_height);
  ~Physics();
  bool is_collide(const Physics *obj);
  void set_position(const sf::Vector2f new_position);
};

#endif