#include "HOTA/UiHeart.hpp"
#include <iostream>

UiHeart::UiHeart(const sf::Vector2f &position, const sf::IntRect &rect) : scale{sf::Vector2f{3.5f, 3.5f}}, position{position}, rect{rect}, inital_rec{rect}, is_heart_over{false}
{
  this->init_texture();
  this->init_sprite();
}

UiHeart::~UiHeart()
{
  delete this->texture;
  delete this->sprite;
}

void UiHeart::init_texture()
{
  this->texture = new sf::Texture{};
  this->texture->loadFromFile("image/ui/HealthUi.png");
}

void UiHeart::init_sprite()
{
  this->sprite = new sf::Sprite{*this->texture};
  this->sprite->setScale(this->scale);
  this->sprite->setPosition(this->position);
  this->sprite->setTextureRect(this->inital_rec);
}

void UiHeart::decrease_heart()
{
  this->rect = sf::IntRect{this->rect.left, this->rect.top + 11, this->rect.width, this->rect.height};
  this->sprite->setTextureRect(this->rect);
  if (this->rect.top == 66)
  {
    this->is_heart_over = true;
    return;
  }
}

void UiHeart::set_full_heart()
{
  this->sprite->setTextureRect(this->inital_rec);
}

const bool &UiHeart::get_is_heart_over()
{
  return this->is_heart_over;
}

void UiHeart::render(sf::RenderTarget &target)
{
  target.draw(*this->sprite);
}
