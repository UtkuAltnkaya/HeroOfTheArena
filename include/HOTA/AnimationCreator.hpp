#ifndef ANIMATION_CREATOR_HPP
#define ANIMATION_CREATOR_HPP

#include <string>
#include "HOTA/Animation.hpp"
#include "HOTA/AnimationNames.hpp"
#include <map>

class AnimationCreator
{

private:
  std::map<AnimationNames, Animation *> all_animations;

  bool select_jump_animation(const AnimationNames &animation_name);
  void set_animation_position(Animation *animation, const sf::Vector2f &last_postion);
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

  sf::Vector2f initial_positions;

  int character_width;
  int character_height;

  int window_width;
  int window_height;

  virtual void init_all_animations() = 0;
  void insert_new_animation(const AnimationNames &animation_name, const std::string &type, const std::string &png_name, const size_t &animation_len, const bool &is_repeat);
  void select_animation(const AnimationNames &animation_name);
  void set_and_calculate_position();
  void set_all_animation_position(const sf::Vector2f &last_postion);

public:
  AnimationCreator();
  AnimationCreator(const std::string &path);
  ~AnimationCreator();
};

#endif