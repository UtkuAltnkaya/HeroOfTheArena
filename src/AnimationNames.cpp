#include "HOTA/AnimationNames.hpp"
#include <iostream>
#define DEBUG 1

#if DEBUG
std::ostream &operator<<(std::ostream &os, const AnimationNames ani_name)
{
  const char *items[] = {
      "IDLE",
      "RUN",
      "RUN_LEFT",
      "JUMP_UP",
      "JUMP_DOWN",
      "JUMP_UP_LEFT",
      "JUMP_DOWN_LEFT",
      "JUMP_PROJECTILE_UP",
      "JUMP_PROJECTILE_DOWN",
      "JUMP_PROJECTILE_UP_LEFT",
      "JUMP_PROJECTILE_DOWN_LEFT",
      "ONE_ATK",
      "TWO_ATK",
      "SP_ATK",
      "DEFEND",
      "DEATH",
      "TAKE_HIT",
      "GREETING",
      "WORK_ONE",
      "WORK_TWO",
  };
  return os << items[static_cast<int>(ani_name)];
}
#else
std::ostream &operator<<(std::ostream &os, const AnimationNames ani_name)
{
  return os;
}
#endif