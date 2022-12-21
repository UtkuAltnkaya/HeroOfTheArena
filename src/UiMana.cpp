#include "HOTA/UiMana.hpp"

UiMana::UiMana(const sf::Vector2f &position, const sf::IntRect &rect) : scale{sf::Vector2f{5.5f, 5.5f}}, position{position}, rect{rect}, inital_rec{rect}
{
  this->init_texture();
  this->init_sprite();
}

UiMana::~UiMana()
{
}

void UiMana::init_texture()
{
  this->texture = new sf::Texture{};
  this->texture->loadFromFile("image/ui/Heart&ManaUi.png");
}

void UiMana::init_sprite()
{
  this->sprite = new sf::Sprite{*this->texture};
  this->sprite->setScale(this->scale);
  this->sprite->setPosition(this->position);
  this->sprite->setTextureRect(this->inital_rec);
}

void UiMana::render(sf::RenderTarget &target)
{
  target.draw(*this->sprite);
}