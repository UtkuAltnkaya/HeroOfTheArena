#include <iostream>
#include "HOTA/RangerFight.hpp"

RangerFight::RangerFight(LeafArcher *hero, Boss *boss) : BaseFight{hero, boss}, hero{hero}, boss{boss}
{
  std::cout << "Ranger" << std::endl;

  this->hero_decrease_health();
  std::cout << this->hero->get_health() << std::endl;
}
RangerFight::~RangerFight()
{
}

void RangerFight::poll_events()
{
}