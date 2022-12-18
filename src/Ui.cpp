#include "HOTA/Ui.hpp"
#include <iostream>
Ui::Ui(const std::string &folder, const std::string &png)
    : folder{folder}, png{png},
      character_photo{new TextureAndSprite}, health_bar{new std::vector<TextureAndSpriteAndRectangle *>}
{
}

Ui::~Ui()
{
  delete this->character_photo->texture;
  delete this->character_photo->sprite;
  delete this->character_photo;

  for (auto &&i : *this->health_bar)
  {
    delete i->texture;
    delete i->sprite;
  }
  delete this->health_bar;
}

sf::Texture *Ui::init_texture(const std::string &path)
{
  sf::Texture *texture = new sf::Texture{};
  texture->loadFromFile(path);
  return texture;
}

sf::Sprite *Ui::init_sprite(const sf::Texture *texture, const sf::Vector2f &scale, const sf::Vector2f &position)
{
  sf::Sprite *sprite = new sf::Sprite{*texture};
  sprite->setScale(scale);
  sprite->setPosition(position);
  return sprite;
}

void Ui::init_character_photo(const std::string &folder, const std::string &png)
{
  this->character_photo->texture = this->init_texture(folder + "/" + png + ".png");
  this->character_photo->sprite = this->init_sprite(this->character_photo->texture, sf::Vector2f{1.5f, 1.5f}, sf::Vector2f{40.f, 40.f});
}

void Ui::init_health(const int &number)
{
  int heart_number{number / 400}, remainder{heart_number % 3}, size{(heart_number - remainder) / 3};
  sf::Vector2f scale{3.5f, 3.5f}, position{150.f, 45.f};
  this->init_heart(size, scale, position, (3 * 11 * 3.5f));
  this->init_heart(remainder, scale, position, (11 * 3.5f));
}

void Ui::init_heart(const int &size, const sf::Vector2f &scale, sf::Vector2f &position, const float &multiplier)
{
  for (int i{0}; i < size; i++)
  {
    TextureAndSpriteAndRectangle *item{new TextureAndSpriteAndRectangle};
    item->texture = this->init_texture("image/ui/HealthUI.png");
    item->sprite = this->init_sprite(item->texture, scale, position);
    position.x += multiplier;
    item->rectangle = sf::IntRect(0, 0, multiplier / 3.5f, 11);
    item->sprite->setTextureRect(item->rectangle);
    this->health_bar->push_back(item);
  }
}

void Ui::update()
{
}
void Ui::render(sf::RenderTarget &target)
{
  target.draw(*this->character_photo->sprite);
  for (auto &&i : *this->health_bar)
  {
    target.draw(*i->sprite);
  }
}
