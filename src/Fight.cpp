#include "HOTA/Fight.hpp"

Fight::Fight(Hero *hero, Boss *boss) : hero{hero}, boss{boss}
{
    this->hero->set_position(this->hero->initial_positions);
}

Fight::~Fight()
{
}