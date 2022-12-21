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

void Ui::init_health(const int &number, sf::Vector2f &&position)
{
  int heart_number{number / 400}, remainder{heart_number % 3}, size{(heart_number - remainder) / 3};
  this->init_heart(size, 115.5f, sf::IntRect{0, 0, 33, 11}, position);
  this->init_heart(remainder, 38.5f, sf::IntRect{0, 44, 11, 11}, position);
}

// void Ui::init_mana_bar(const int &number, sf::Vector2f &&position)
// {
//   int mana_number{number / 100}, remainder{mana_number % 2}, size{(mana_number - remainder) / 2};

//   this->init_mana(mana_number, 66.f, sf::IntRect{23, 24, 23, 23}, position);
// }

void Ui::init_heart(const int &size, const float &multiplier, const sf::IntRect &rect, sf::Vector2f &position)
{
  for (int i{0}; i < size; i++)
  {
    this->health_bar.push_back(new UiHeart{position, rect});
    position.x += multiplier;
  }
}

// void Ui::init_mana(const int &size, const float &multiplier, const sf::IntRect &rect, sf::Vector2f &position)
// {
// }

void Ui::reduce_health(const int &atk_power, const bool &is_hero)
{
  size_t size{static_cast<size_t>(atk_power * 0.005)};
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
    if (!this->health_bar.at(i)->get_is_heart_over())
    {
      this->health_bar.at(i)->decrease_heart();
      return;
    }
  }
}

void Ui::reduce_boss_health()
{
  size_t size{this->health_bar.size()};
  for (size_t i{0}; i < size; i++)
  {
    if (!this->health_bar.at(i)->get_is_heart_over())
    {
      this->health_bar.at(i)->decrease_heart();
      return;
    }
  }
}

void Ui::rotate_health()
{
  for (auto &&i : this->health_bar)
  {
    i->rotate_heart();
  }
}

void Ui::render(sf::RenderTarget &target)
{
  target.draw(*this->character_photo.sprite);
  for (auto &&i : this->health_bar)
  {
    i->render(target);
  }
}
