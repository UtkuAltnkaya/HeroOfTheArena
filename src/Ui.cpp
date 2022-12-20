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

void Ui::init_health(const int &number)
{
  int heart_number{number / 400}, remainder{heart_number % 3}, size{(heart_number - remainder) / 3};
  sf::Vector2f position{150.f, 45.f};
  this->init_heart(size, 115.5f, sf::IntRect{0, 0, 33, 11}, position);
  this->init_heart(remainder, 38.5f, sf::IntRect{0, 44, 11, 11}, position);
}

void Ui::init_heart(const int &size, const float &multiplier, const sf::IntRect &rect, sf::Vector2f &position)
{
  for (int i{0}; i < size; i++)
  {
    this->health_bar.push_back(new UiHeart{position, rect});
    position.x += multiplier;
  }
}

void Ui::reduce_health(const int &atk_power)
{
  size_t size{static_cast<size_t>(atk_power * 0.005)};
  for (size_t i{0}; i < size; i++)
  {
    for (int j{(int)this->health_bar.size() - 1}; j >= 0; j--)
    {
      if (!this->health_bar.at(j)->get_is_heart_over())
      {
        this->health_bar.at(j)->decrease_heart();
        break;
      }
    }
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
