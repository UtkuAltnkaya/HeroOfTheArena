#include "HOTA/BladeKeeper.hpp"
#include <iostream>

BladeKeeper::BladeKeeper() : Hero{"image", 5000, 200, 500, 250, 0.1f}
{
    this->init_var();
    std::cout << this->ani_name << std::endl;
}

BladeKeeper::~BladeKeeper()
{
}

void BladeKeeper::init_var()
{
    this->init_ani_stats();
    this->init_ani();
    this->init_stats();
}

void BladeKeeper::init_ani_stats()
{

    this->path += "/BladeKeeper";
    this->atk_one_num = 6;
    this->atk_two_num = 18;
    this->atk_sp_num = 11;
    this->death_num = 12;
    this->defend_num = 12;
    this->idle_num = 8;
    this->jump_num = 20;
    this->roll_num = 7;
    this->run_num = 8;
    this->take_dmg_num = 6;
}

void BladeKeeper::init_stats()
{
    this->health -= 1800;
    this->damage += 100;
    this->mana += 200;
    this->defense -= 50;
    this->crit_chance += 0.25;
}

void BladeKeeper::init_ani()
{
    // auto ani_path = this->get_path();
    this->hero_ani.insert(std::pair<std::string, Animation *>("idle", new Animation(this->path, "idle", "idle_", this->idle_num, true)));
    this->hero_ani.insert(std::pair<std::string, Animation *>("run", new Animation(this->path, "run", "run_", this->run_num, true)));
    this->hero_ani.insert(std::pair<std::string, Animation *>("roll", new Animation(this->path, "roll", "roll_", this->roll_num, true)));
    this->hero_ani.insert(std::pair<std::string, Animation *>("roll_left", new Animation(this->path, "roll", "roll_", this->roll_num, true)));
    this->hero_ani.insert(std::pair<std::string, Animation *>("run_left", new Animation(this->path, "run_left", "run_", this->run_num, true)));
    this->hero_ani.insert(std::pair<std::string, Animation *>("jump", new Animation(this->path, "jump_up", "jump_up_", 3, true)));
    this->hero_ani.insert(std::pair<std::string, Animation *>("1_atk", new Animation(this->path, "1_atk", "atk_", this->atk_one_num, false)));

    //  this->hero_ani.insert(std::pair<std::string, Animation *>("jump", new Animation(this->path, "jump_up", "jump_up_", this->jump_num)));
}

void BladeKeeper::skill()
{
    // TODO
}

void BladeKeeper::upgrade()
{
    // TODO
}

void BladeKeeper::update()
{
    for (auto &i : this->hero_ani)
    {
        if (i.first == this->ani_name)
        {
            this->move_character();
            this->hero_ani[this->ani_name]->update(this->is_ani_over);
            this->atk_character();
        }
    }
    // this->get_hero_ani()["idle"]->update();
}

void BladeKeeper::render(sf::RenderTarget &target)
{

    for (auto &i : this->hero_ani)
    {
        if (i.first == this->ani_name)
        {
            this->hero_ani[this->ani_name]->render(target);
        }
    }
}

void BladeKeeper::move_character()
{
    if (this->ani_name == "run")
    {
        this->move(sf::Keyboard::D);
    }
    else if (this->ani_name == "run_left")
    {
        this->move(sf::Keyboard::A);
    }
    // if (this->ani_name == "jump")
    // {
    //     this->move(sf::Keyboard::W, window);
    // }
}

void BladeKeeper::atk_character()
{
    if (this->ani_name == "1_atk")
    {
        if (this->is_ani_over)
        {
            this->ani_name = "idle";
            this->is_ani_over = false;
        }
    }
}