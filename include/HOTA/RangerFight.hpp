#ifndef RANGER_FIGHT
#define RANGER_FIGHT

#include "HOTA/LeafArcher.hpp"
#include "HOTA/BaseFight.hpp"

class RangerFight : public BaseFight
{
private:
  LeafArcher *hero;
  Boss *boss;

public:
  RangerFight(LeafArcher *hero, Boss *boss);
  ~RangerFight();
  void poll_events() override;
};

#endif // RANGER_FIGHT
