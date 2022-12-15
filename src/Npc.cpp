// #include "HOTA/Npc.hpp"

// NPC::NPC() : type{"image/"}, char_name{"BlackSmith"}, path{type + char_name}, animation{nullptr}
// {
//     this->init_animation();
// }

// NPC::~NPC()
// {
//     delete this->greeting_animation;
//     delete this->idle_animation;
//     delete this->work_one_animation;
//     delete this->work_two_animation;
// }

// void NPC::init_animation()
// {
//     this->greeting_animation = new Animation{this->path, "greeting", "greeting_0", 4, true};
//     this->animation = this->idle_animation = new Animation{this->path, "idle", "idle_0", 4, true};
//     this->work_one_animation = new Animation{this->path, "work_01", "work_01_0", 5, true};
//     this->work_two_animation = new Animation{this->path, "work_02", "work_02_0", 6, false};
// }

// void NPC::init_position()
// {
//     auto ani = this->*animation->get_sprite();
//     this->position = ani->at(0)->getPosition();
// }

// void NPC::set_position(Animation *animation, sf::Vector2f last_position)
// {
//     for (auto &&i : *animation->get_sprite())
//     {
//         i->setPosition(last_position);
//     }
// }

// void NPC::set_all_position()
// {
//     this->set_position(this->greeting_animation, sf::Vector2f(100, -200));
// }