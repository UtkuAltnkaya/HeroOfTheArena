#include "HOTA/UiHeartAndMana.hpp"

UiHeartAndMana::UiHeartAndMana(const sf::Vector2f &position, const sf::IntRect &rect, const sf::Vector2f &scale, const std::string &png_name)
    : png_name{png_name}, scale{scale}, position{position}, rect{rect}, inital_rec{rect}, is_over{false}, is_full{true}
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
{ // Initialize all textures
  this->texture = new sf::Texture{};
  this->texture->loadFromFile("image/ui/" + png_name + ".png");
}

void UiHeartAndMana::init_sprite()
{ // Initialize all sprites
  this->sprite = new sf::Sprite{*this->texture};
  this->sprite->setScale(this->scale);
  this->sprite->setPosition(this->position);
  this->sprite->setTextureRect(this->inital_rec);
}

void UiHeartAndMana::increase()
{ // Increase heart and mana
  this->rect = sf::IntRect{this->rect.left, this->rect.top - 11, this->rect.width, this->rect.height};
  this->sprite->setTextureRect(this->rect);
  this->is_over = false;
  if (this->rect.top == 0)
  {
    this->is_full = true;
  }
}

void UiHeartAndMana::decrease()
{ // Decrease heart and mana
  this->rect = sf::IntRect{this->rect.left, this->rect.top + 11, this->rect.width, this->rect.height};
  this->sprite->setTextureRect(this->rect);
  this->is_full = false;
  if (this->rect.top == 66)
  {
    this->is_over = true;
  }
}
void UiHeartAndMana::rotate()
{ // Rotate heart for the boss
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

const bool &UiHeartAndMana::get_is_full()
{
  return this->is_full;
}

void UiHeartAndMana::render(sf::RenderTarget &target)
{
  target.draw(*this->sprite);
}
