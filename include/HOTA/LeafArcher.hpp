#ifndef LEAF_ARCHER_HPP
#define LEAF_ARCHER_HPP

#include "HOTA/Hero.hpp"
#include <string>

class LeafArcher : public Hero
{
private:
  void init_var();
  void init_ani_stats();
  void init_stats();

public:
  LeafArcher();
  ~LeafArcher();
  void skill();
  void upgrade();
};

#endif