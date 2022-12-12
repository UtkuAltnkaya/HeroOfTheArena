#include "HOTA/Boss.hpp"
#include <iostream>
#include "HOTA/Animation.hpp"
// Delegation
Boss::Boss() : Boss{"", 0, 0, 0, 0, 0.0f}
{
}

Boss::Boss(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, float critChanceVal)
    : AnimationCreator{pathVal}, ani_name{"idle"}, health(healthVal), damage(damageVal), mana(manaVal), defense(damageVal), crit_chance(critChanceVal)
{
}

Boss::~Boss()
{
}

void Boss::update()
{
    this->animation->update(this->is_ani_over);
    this->move_boss();
    this->atk_boss();
    this->select_animation(this->ani_name);
}

void Boss::render(sf::RenderTarget &target)
{
    this->animation->render(target);
}

void Boss::move_boss()
{
    if (this->ani_name == "run")
    {
        this->move(sf::Keyboard::D);
    }
}

void Boss::atk_boss()
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

void Boss::poll_events(sf::Event &event)
{
    if (this->ani_name == "1_atk")
    {
        return;
    }
    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // TODO
    {
        this->ani_name = "run";
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->ani_name = "run_left";
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->ani_name = "1_atk";
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->ani_name = "2_atk";
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        this->ani_name = "defend";
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        this->ani_name = "sp_atk";
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->ani_name = "jump_up";
    }
    */
};

void Boss::poll_events_loop(sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
        {
            if (this->ani_name == "1_atk")
            {
                return;
            }
            this->ani_name = "idle";
        }
    }
}

void Boss::move(sf::Keyboard::Key key)
{
    sf::Sprite *sp = this->animation->get_sprite()->at(0);
    sf::Vector2f pos = sp->getPosition();
    /*if (pos.x < (1548 - 505))
    {
        if (key == sf::Keyboard::D)
        {
            sp->setPosition(pos.x + 5, pos.y);
        }
    }
    if (pos.x != -355)
    {
        if (key == sf::Keyboard::A)
        {
            sp->setPosition(pos.x - 5, pos.y);
        }
    }
    if (key == sf::Keyboard::Space)
    {
        if (this->ani_name == "jump_up" && pos.y > 250.f)
        {
            sp->setPosition(pos.x, pos.y - 4);
        }
        else if (pos.y <= 343)
        {
            this->ani_name = "jump_down";
            sp->setPosition(pos.x, pos.y + 4);
        }
        else
        {
            this->ani_name = "idle";
        }
    }
    */
    this->set_all_animation_position(this->animation->get_sprite()->at(0)->getPosition());
}
/**
 *
std::map<std::string, Animation *> &Boss::get_Boss_ani()
{
  return this->Boss_ani;
}

std::string Boss::get_ani_name()
{
  return this->ani_name;
}

// Getters
std::string Boss::get_path()
{
  return this->path;
}

int Boss::get_health()
{
  return this->health;
}
int Boss::get_damage()
{
  return this->damage;
}
int Boss::get_mana()
{
  return this->mana;
}
int Boss::get_defense()
{
  return this->defense;
}
float Boss::get_crit_chance()
{
  return this->critChance;
}

//
int Boss::get_idle_num()
{
  return this->idleNum;
}
int Boss::get_atk_one_num()
{
  return this->atk_one_num;
}
int Boss::get_atk_two_num()
{
  return this->atk_two_num;
}
int Boss::get_atk_sp_num()
{
  return this->atk_sp_num;
}
int Boss::get_run_num()
{
  return this->run_num;
}
int Boss::get_roll_num()
{
  return this->roll_num;
}
int Boss::get_jump_num()
{
  return this->jump_num;
}
int Boss::get_defend_num()
{
  return this->defend_num;
}
int Boss::get_death_num()
{
  return this->death_num;
}
int Boss::get_take_dmg_num()
{
  return this->take_dmg_num;
}
//
void Boss::set_Boss_ani(std::pair<std::string, Animation *> pair)
{
  this->Boss_ani.insert(pair);
}

// Setters
void Boss::set_path(std::string path)
{
  this->path = path;
}

void Boss::set_health(int health)
{
  this->health = health;
}
void Boss::set_damage(int damage)
{
  this->damage = damage;
}
void Boss::set_mana(int mana)
{
  this->mana = mana;
}
void Boss::set_defense(int defense)
{
  this->defense = defense;
}
void Boss::set_crit_chance(float critChance)
{
  this->critChance = critChance;
}

//
void Boss::set_idle_num(int idleNum)
{
  this->idleNum = idleNum;
}
void Boss::set_atk_one_num(int atkOneNum)
{
  this->atk_one_num = atkOneNum;
}
void Boss::set_atk_two_num(int atkTwoNum)
{
  this->atk_two_num = atkTwoNum;
}
void Boss::set_atk_sp_num(int atkSpNum)
{
  this->atk_sp_num = atkSpNum;
}
void Boss::set_run_num(int runNum)
{
  this->run_num = runNum;
}
void Boss::set_roll_num(int rollNum)
{
  this->roll_num = rollNum;
}
void Boss::set_jump_num(int jumpNum)
{
  this->jump_num = jumpNum;
}
void Boss::set_defend_num(int defendNum)
{
  this->defend_num = death_num;
}
void Boss::set_death_num(int deathNum)
{
  this->death_num = deathNum;
}
void Boss::set_take_dmg_num(int takeDmgNum)
{
  this->take_dmg_num = takeDmgNum;
}
*/
