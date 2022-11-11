#include "HOTA/Animation.hpp"
#include <iostream>

Animation::Animation(std::string type, std::string ani, std::string ani_name, size_t size, bool is_repeat)
{
  this->init_var(type, ani, ani_name, size, is_repeat);
  this->init_texture();
  this->init_sprite();
  this->init_clock();
}

Animation::~Animation()
{
  for (auto &i : *this->sprite)
  {
    delete i;
  }
  for (auto &i : *this->texture)
  {
    delete i;
  }

  delete this->texture;
  delete this->sprite;
  delete this->clock;
}
// Public
void Animation::update(bool is_repeat = true)
{
  if (is_repeat)
  {
    if (this->clock->getElapsedTime().asSeconds() > 0.1f)
    {
      if (this->que == this->size - 1)
      {
        this->que = 0;
        is_repeat = false;
      }
      else
      {
        this->que++;
      }
      this->clock->restart();
    }
  }
  else
  {
  }
}

void Animation::update_once()
{
  this->que = 0;
  if (this->clock->getElapsedTime().asSeconds() > 0.1f)
  {
    this->que++;
    this->clock->restart();
  }
}

void Animation::render(sf::RenderTarget &target)
{
  target.draw(*this->sprite->at(this->que));
}

std::vector<sf::Sprite *> *Animation::get_sprite()
{
  return this->sprite;
}

// Private
void Animation::init_var(std::string &type, std::string &ani, std::string &ani_name, size_t &size, bool &is_repeat)
{
  this->path = type + "/" + ani + "/" + ani_name;
  this->clock = nullptr;
  this->size = size;
  this->que = 0;
}

void Animation::init_texture()
{
  this->texture = new std::vector<sf::Texture *>;
  for (size_t i = 0; i < this->size; i++)
  {
    auto tx = new sf::Texture();
    this->texture->push_back(tx);
    if (!this->texture->at(i)->loadFromFile(this->path + std::to_string(i + 1) + ".png"))
    {
      std::cout << "ERROR:Background::INIT_TEXTURE_VEC::Could not load the texture" << i + 1 << std::endl;
    }
  }
}
void Animation::init_sprite()
{
  this->sprite = new std::vector<sf::Sprite *>;
  for (size_t i = 0; i < this->size; i++)
  {
    auto sp = new sf::Sprite(*this->texture->at(i));
    sp->setScale(3.f, 3.f);
    sp->setPosition(-10, 256 * 3 - (this->texture->at(i)->getSize().y * 3) - 30);
    this->sprite->push_back(sp);
  }
}
void Animation::init_clock()
{
  this->clock = new sf::Clock();
}