#ifndef ANIMATION_CREATOR_HPP
#define ANIMATION_CREATOR_HPP

#include <string>
#include "HOTA/Animation.hpp"

class AnimationCreator
{

private:
  Animation *idle_animation;
  Animation *atk_one_animation;
  Animation *atk_two_animation;
  Animation *run_animation;
  Animation *run_left_animation;
  Animation *atk_sp_animation;
  Animation *defend_animation;
  Animation *jump_up_animation;
  Animation *jump_down_animation;
  Animation *jump_up_left_animation;
  Animation *jump_down_left_animation;

  void set_animation_position(Animation *animation, sf::Vector2f &last_postion);
  void calculate_inital_position();

protected:
  std::string path;
  Animation *animation;

  size_t idle_num;
  size_t atk_one_num;
  size_t atk_two_num;
  size_t atk_sp_num;
  size_t run_num;
  size_t roll_num;
  size_t jump_num;
  size_t defend_num;
  size_t death_num;
  size_t take_dmg_num;
  size_t jump_up_num;
  size_t jump_down_num;

  int character_width;
  int character_height;

  int window_width;
  int window_height;

  sf::Vector2f initial_positions;

  void init_animations();
  void select_animation(std::string animation_name);
  void set_all_animation_position(sf::Vector2f last_postion);

public:
  AnimationCreator();
  AnimationCreator(std::string path);
  ~AnimationCreator();
};

#endif