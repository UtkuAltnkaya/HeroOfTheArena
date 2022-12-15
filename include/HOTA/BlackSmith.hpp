#ifndef BLACK_SMITH_HPP
#define BLACK_SMITH_HPP

#include "HOTA/Npc.hpp"

class BlackSmith : public Npc
{
private:
  void init_var();
  void init_ani_stats();

public:
  BlackSmith();
  ~BlackSmith();
};

#endif