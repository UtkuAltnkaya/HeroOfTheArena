#ifndef ANIMATION_NAMES_HPP
#define ANIMATION_NAMES_HPP
#include <iostream>

enum class AnimationNames
{
  IDLE,
  RUN,
  RUN_LEFT,
  JUMP_UP,
  JUMP_DOWN,
  JUMP_UP_LEFT,
  JUMP_DOWN_LEFT,
  JUMP_PROJECTILE_UP,
  JUMP_PROJECTILE_DOWN,
  JUMP_PROJECTILE_UP_LEFT,
  JUMP_PROJECTILE_DOWN_LEFT,
  ONE_ATK,
  TWO_ATK,
  SP_ATK,
  DEFEND,
  DEATH,
  TAKE_HIT,
  GREETING,
  WORK_ONE,
  WORK_TWO,
  ARROW,
  ARROW_ONE,
  ARROW_TWO,
  ARROW_THREE,
  NONE,
};

#define DEBUG 1
#if DEBUG
std::ostream &operator<<(std::ostream &os, const AnimationNames ani_name);
#else
std::ostream &operator<<(std::ostream &os, const AnimationNames ani_name);
#endif

#endif
