#include "HOTA/Background.hpp"
#include <iostream>

Background::Background(std::string type, std::string version, std::string file_name, size_t size)
{

  this->init_var(type, version, file_name, size);
  this->init_texture_vec();
  this->init_sprite_vec();
}

Background::~Background()
{
  for (auto i : this->texture)
  {
    delete i;
  }
  for (auto i : this->sprite)
  {
    delete i;
  }
}

// Public
void Background::render(sf::RenderTarget &target)
{
  for (size_t i = 0; i < this->size; i++)
  {
    target.draw(*this->sprite.at(i));
  }
}

// Private
void Background::init_texture_vec()
{
  for (size_t i = 0; i < this->size; i++)
  {
    auto tx = new sf::Texture();
    this->texture.push_back(tx);
    if (!this->texture.at(i)->loadFromFile(this->path + std::to_string(i + 1) + ".png"))
    {
      std::cout << "ERROR:Background::INIT_TEXTURE_VEC::Could not load the texture" << i + 1 << std::endl;
    }
  }
}

void Background::init_sprite_vec()
{
  for (size_t i = 0; i < this->size; i++)
  {
    auto sp = new sf::Sprite(*this->texture.at(i));
    this->sprite.push_back(sp);
    this->sprite.at(i)->setScale(3.f, 3.f);
  }
}

void Background::init_var(std::string &type, std::string &version, std::string &file_name, size_t &size)
{
  this->path = "image/" + type + "/" + version + "/" + file_name;
  this->size = size;
}