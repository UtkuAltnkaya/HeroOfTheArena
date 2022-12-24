#include "HOTA/Boss.hpp"
#include <iostream>
// Delegation
Boss::Boss() : Boss{"", 0, 0, 0, 0, 0}
{
}

Boss::Boss(std::string pathVal, int healthVal, int damageVal, int manaVal, int defenseVal, int critChanceVal)
    : Physics{pathVal, 300, 300}, ui{nullptr},
      ani_name{AnimationNames::IDLE}, health(healthVal),
      damage(damageVal), mana(manaVal), defense_chance(damageVal), crit_chance(critChanceVal), is_fight_start{false}, is_ani_over{false}
{
}

Boss::~Boss()
{
  delete this->ui;
}

void Boss::init_all_animations()
{
  this->init_game_animations();
  this->init_fight_animations();
  this->set_and_calculate_position();
}

void Boss::init_game_animations()
{
  this->insert_new_animation(AnimationNames::IDLE, "idle", "idle_", this->idle_num, true);
  this->insert_new_animation(AnimationNames::RUN, "run", "run_", this->run_num, true);
  this->insert_new_animation(AnimationNames::RUN_LEFT, "run_left", "run_", this->run_num, true);
}

void Boss::load_fight_multi_thread(const AnimationNames num, std::string type, std::string file, int num_of_png, bool is_repeated)
{
  this->insert_new_animation(num, type, file, num_of_png, is_repeated);
}
void Boss::init_fight_animations()
{
  std::thread t1(&Boss::load_fight_multi_thread, this, AnimationNames::ONE_ATK, "1_atk", "atk_", this->atk_one_num, false);
  std::thread t2(&Boss::load_fight_multi_thread, this, AnimationNames::DEFEND, "defend", "defend_", this->defend_num, false);
  std::thread t3(&Boss::load_fight_multi_thread, this, AnimationNames::DEATH, "death", "death_", this->death_num, false);
  std::thread t4(&Boss::load_fight_multi_thread, this, AnimationNames::TAKE_HIT, "take_hit", "take_hit_", this->take_dmg_num, false);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

void Boss::update()
{
  this->animation->update(this->is_ani_over);
  this->atk_boss();
  this->select_animation(this->ani_name);
}

void Boss::render(sf::RenderTarget &target)
{
  this->animation->render(target);
  if (this->ui)
  {
    this->ui->render(target);
  }
}

void Boss::atk_boss()
{
  if (this->ani_name == AnimationNames::ONE_ATK || this->ani_name == AnimationNames::TAKE_HIT)
  {
    if (this->is_ani_over)
    {
      this->ani_name = AnimationNames::IDLE;
    }
  }
}

void Boss::poll_events(sf::Event &event)
{
  if (this->ani_name == AnimationNames::ONE_ATK)
  {
    return;
  }
};

void Boss::poll_events_loop(sf::Event &event)
{
  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
    {
      if (this->ani_name == AnimationNames::ONE_ATK)
      {
        return;
      }
      this->ani_name = AnimationNames::IDLE;
    }
  }
}

void Boss::fight_start()
{
  this->is_fight_start = true;
  this->is_ani_over = false;
  this->init_fight_animations();
  this->ani_name = AnimationNames::IDLE;

  this->ui = new Ui{};
  this->ui->init_character_photo(this->path, "demon_slime", sf::Vector2f{this->window_width - 140.f, 40.f});
  this->ui->init_health_or_mana_bar(this->health, 400, "HealthUI", sf::Vector2f{this->window_width - 625.f, 45.f});
  this->ui->rotate_health();
}

void Boss::decrease_heath(const int &number)
{
  this->ui->reduce_health(number, false);
}

bool Boss::get_is_ani_over()
{
  return this->is_ani_over;
}

const int &Boss::get_damage()
{
  return this->damage;
}

int Boss::get_health()
{
  return this->health;
}

int Boss::get_defense_chance()
{
  return this->defense_chance;
}

int Boss::get_crit_chance()
{
  return this->crit_chance;
}

const size_t &Boss::get_que()
{
  return this->animation->get_que();
}

void Boss::set_is_ani_over(const bool &is_ani_over)
{
  this->is_ani_over = is_ani_over;
}

void Boss::set_ani_name(const AnimationNames &ani_name)
{
  this->ani_name = ani_name;
}

void Boss::set_damage(const int &damage)
{
  this->damage = damage;
}

void Boss::set_health(const int &health)
{
  this->health = health;
}

void Boss::set_defense_chance(const int &defense_chance)
{
  this->defense_chance = defense_chance;
}

void Boss::set_crit_chance(const int &crit_chance)
{
  this->crit_chance = crit_chance;
}

void Boss::set_is_ani_stop(const bool &is_ani_stop)
{
  this->animation->set_is_stop(is_ani_stop);
}
