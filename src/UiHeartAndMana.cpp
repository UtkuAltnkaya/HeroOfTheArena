#include "HOTA/UiHeartAndMana.hpp"
#include <iostream>

UiHeartAndMana::UiHeartAndMana(const sf::Vector2f &position, const sf::IntRect &rect, const sf::Vector2f &scale, const std::string &png_name)
    : png_name{png_name}, scale{scale}, position{position}, rect{rect}, inital_rec{rect}, is_over{false}
{
  this->init_texture();
  this->init_sprite();
}

UiHeartAndMana::~UiHeartAndMana()
{
  delete this->texture;
  delete this->sprite;
}

void UiHeartAndMana::init_texture()
{
  this->texture = new sf::Texture{};
  this->texture->loadFromFile("image/ui/" + png_name + ".png");
}

void UiHeartAndMana::init_sprite()
{
  this->sprite = new sf::Sprite{*this->texture};
  this->sprite->setScale(this->scale);
  this->sprite->setPosition(this->position);
  this->sprite->setTextureRect(this->inital_rec);
}

void UiHeartAndMana::decrease()
{
  this->rect = sf::IntRect{this->rect.left, this->rect.top + 11, this->rect.width, this->rect.height};
  this->sprite->setTextureRect(this->rect);
  if (this->rect.top == 66)
  {
    this->is_over = true;
    return;
  }
}
void UiHeartAndMana::rotate()
{
  this->sprite->setScale(-3.5f, 3.5f);
}

void UiHeartAndMana::set_full()
{
  this->sprite->setTextureRect(this->inital_rec);
}

const bool &UiHeartAndMana::get_is_over()
{
  return this->is_over;
}

void UiHeartAndMana::render(sf::RenderTarget &target)
{
  target.draw(*this->sprite);
}
