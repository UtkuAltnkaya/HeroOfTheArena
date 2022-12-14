#include "HOTA/Animation.hpp"
#include <iostream>

// Constructor that initializes variables texture, sprite and clock.

Animation::Animation(const std::string &type, const std::string &ani, const std::string &ani_name, const size_t &size, const bool &is_repeat)
{
  this->init_var(type, ani, ani_name, size, is_repeat);
  this->init_texture();
  this->init_sprite();
  this->init_clock();
}

// copy constructor
Animation::Animation(Animation &source)
{
  this->path = source.path;
  this->init_var(source.size, source.is_repeat);
  this->init_texture();
  this->init_sprite();
  this->init_clock();
}
// Destructor deallocates memory after sprites and textures being used.
Animation::~Animation()
{
  for (auto &i : *this->texture)
  {
    delete i;
  }
  for (auto &i : *this->sprite)
  {
    delete i;
  }
  delete this->texture;
  delete this->sprite;
  delete this->clock;
}

// Private
void Animation::init_var(const std::string &type, const std::string &ani, const std::string &ani_name, const size_t &size, const bool &is_repeat)
{
  this->path = type + "/" + ani + "/" + ani_name;
  this->clock = nullptr;
  this->size = size;
  this->que = 0;
  this->is_repeat = is_repeat;
  this->is_stop = false;
}

void Animation::init_var(size_t &size, bool &is_repeat)
{
  this->clock = nullptr;
  this->size = size;
  this->que = 0;
  this->is_repeat = is_repeat;
}

void Animation::init_texture() // first we initialize textures and after this texture method sprite will be created.
{
  this->texture = new std::vector<sf::Texture *>;
  for (size_t i = 0; i < this->size; i++)
  {
    auto tx = new sf::Texture();
    this->texture->push_back(tx);
    if (!this->texture->at(i)->loadFromFile(this->path + std::to_string(i + 1) + ".png"))
    {
      std::cout << "ERROR:Animation::INIT_TEXTURE_VEC::Could not load the texture" << i + 1 << std::endl;
    }
  }
}

void Animation::init_sprite() // sprite is created by using textures. (pushed back to a sprite vector that is in animation class)
{
  this->sprite = new std::vector<sf::Sprite *>;
  for (size_t i = 0; i < this->size; i++)
  {
    auto sp = new sf::Sprite(*this->texture->at(i));
    sp->setScale(3.f, 3.f);
    this->sprite->push_back(sp);
  }
}
void Animation::init_clock()
{
  this->clock = new sf::Clock();
}

// Public
void Animation::render(sf::RenderTarget &target) // target is window here that comes from game.
{
  target.draw(*this->sprite->at(this->que)); // window draws the sprite that is derived from texture (draws the png on the screen) according to que.
}

void Animation::render_background(sf::RenderTarget &target)
{
  for (auto &&i : *this->sprite)
  {
    target.draw(*i);
  }
}

void Animation::update(bool &is_ani_over)
{
  if (this->clock->getElapsedTime().asSeconds() > 0.1f) // This clock avoids the animation to run fast. It makes the animation slower in this example it is 0.1 if it was 1 it would be very slow.
  {
    if (this->que >= this->size - 1) // if animation is over then the condition enters this if statement.
    {
      this->que = 0;  // Set que to 0 and start the animation again.
      if (!is_repeat) // If is not repeated, assign the is_ani_over to true and end the animation
      {
        is_ani_over = true;
      }
    }
    else // if animation is not over we have to change the frame by increasing que by one. (one frame increase which is 1 png)
    {
      if (!this->is_stop)
      {
        this->que++;
      }
    }
    this->clock->restart(); // sfml function
  }
}

std::vector<sf::Sprite *> *Animation::get_sprite()
{
  return this->sprite;
}

void Animation::set_is_stop(const bool &is_stop)
{
  this->is_stop = is_stop;
}

const bool &Animation::get_is_stop()
{
  return this->is_stop;
}

const size_t &Animation::get_que()
{
  return this->que;
}