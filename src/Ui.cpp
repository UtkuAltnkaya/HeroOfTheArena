#include "HOTA/Ui.hpp"

Ui::Ui()
{
}

Ui::~Ui()
{
  delete this->character_photo.texture;
  delete this->character_photo.sprite;
  for (auto &&i : this->health_bar)
  {
    delete i;
  }
  for (auto &&i : this->mana_bar)
  {
    delete i;
  }
}

void Ui::init_character_photo(const std::string &folder, const std::string &png, const sf::Vector2f &position)
{
  // Texture
  this->character_photo.texture = new sf::Texture{};
  this->character_photo.texture->loadFromFile(folder + "/" + png + ".png");
  // Sprite
  this->character_photo.sprite = new sf::Sprite{*this->character_photo.texture};
  this->character_photo.sprite->setScale(sf::Vector2f{1.5f, 1.5f});
  this->character_photo.sprite->setPosition(position);
}

void Ui::init_health_or_mana_bar(const int &number, const int &denominator, const std::string &type, sf::Vector2f &&position)
{
  int item_number{(number / denominator)}, remainder{item_number % 3}, size{(item_number - remainder) / 3};
  if (type == "ManaUI")
  {
    position.y = 85.f;
  }
  this->init_heart_or_mana(size, 115.5f, sf::IntRect{0, 0, 33, 11}, position, type);
  this->init_heart_or_mana(remainder, 38.5f, sf::IntRect{0, 44, 11, 11}, position, type);
}

void Ui::init_heart_or_mana(const int &size, const float &multiplier, const sf::IntRect &rect, sf::Vector2f &position, const std::string &type)
{
  for (int i{0}; i < size; i++)
  {
    if (type == "HealthUI")
    {
      this->health_bar.push_back(new UiHeartAndMana{position, rect, sf::Vector2f{3.5f, 3.5f}, type});
    }
    else
    {
      this->mana_bar.push_back(new UiHeartAndMana{position, rect, sf::Vector2f{3.5f, 3.5f}, type});
    }
    position.x += multiplier;
  }
}

void Ui::reduce_health(const int &atk_power, const bool &is_hero)
{
  size_t size{static_cast<size_t>(atk_power * 0.005f)};
  for (size_t i{0}; i < size; i++)
  {
    if (is_hero)
    {
      this->reduce_hero_health();
    }
    else
    {
      this->reduce_boss_health();
    }
  }
}

void Ui::reduce_hero_health()
{
  for (int i{static_cast<int>(this->health_bar.size()) - 1}; i >= 0; i--)
  {
    if (!this->health_bar.at(i)->get_is_over())
    {
      this->health_bar.at(i)->decrease();
      return;
    }
  }
}

void Ui::reduce_boss_health()
{
  size_t size{this->health_bar.size()};
  for (size_t i{0}; i < size; i++)
  {
    if (!this->health_bar.at(i)->get_is_over())
    {
      this->health_bar.at(i)->decrease();
      return;
    }
  }
}

void Ui::reduce_hero_mana(const int &amount)
{
  size_t size{static_cast<size_t>(amount * 0.02f)};
  for (size_t i{0}; i < size; i++)
  {
    for (int i{static_cast<int>(this->mana_bar.size()) - 1}; i >= 0; i--)
    {
      if (!this->mana_bar.at(i)->get_is_over())
      {
        this->mana_bar.at(i)->decrease();
        break;
      }
    }
  }
}

void Ui::increase_hero_mana()
{
  for (size_t i = 0; i < 2; i++)
  {
    for (int i{static_cast<int>(this->mana_bar.size()) - 1}; i >= 0; i--)
    {
      if (!this->mana_bar.at(i)->get_is_full())
      {
        this->mana_bar.at(i)->increase();
        break;
      }
    }
  }
}

void Ui::rotate_health()
{
  for (auto &&i : this->health_bar)
  {
    i->rotate();
  }
}

void Ui::render(sf::RenderTarget &target)
{
  target.draw(*this->character_photo.sprite);
  for (auto &&i : this->health_bar)
  {
    i->render(target);
  }
  for (auto &&i : this->mana_bar)
  {
    i->render(target);
  }
}
