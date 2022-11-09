#include "HOTA/CharacterMenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

CharMenu::CharMenu(std::string type, std::string version)
{
  this->open = true;
  this->init_var(type, version);
}
CharMenu::~CharMenu()
{

  for (auto i : this->texture)
  {
    delete i;
  }
  for (auto i : this->sprite)
  {
    delete i;
  }
  delete clock;
}

// Public
void CharMenu::render(sf::RenderTarget &target)
{
  this->Animated(target);
  sf::Texture border;
  border.loadFromFile("bin/image/MenuCard/Cards.png");
  sf::Sprite borderDraw(border, sf::IntRect(125, 281, 92, 130));
  borderDraw.setScale(3.f, 2.f);
  for (int i = 0; i < charSize; i++)
  {
    if (i < 3)
    {
      borderDraw.setPosition(i * 300 + 320, 50);
      target.draw(borderDraw);
    }
    else
    {
      borderDraw.setPosition((i - 3) * 300 + 320, 350);
      target.draw(borderDraw);
    }
    target.draw(*this->sprite.at(i));
  }
}

// Private

void CharMenu::init_texture_vec(int i)
{
  auto tx = new sf::Texture();
  this->texture.push_back(tx);
  if (!this->texture.at(i)->loadFromFile(this->path + "_1.png"))
  {
    std::cout << "ERROR:CharMenu::INIT_TEXTURE_VEC::Could not load the texture" << std::endl;
  }
}

void CharMenu::init_sprite_vec(int i)
{

  auto sp = new sf::Sprite(*this->texture.at(i), sf::IntRect(0, 0, 288, 128));
  if (i < 3)
  {
    sp->setPosition(sf::Vector2f(i * 300 + 80, -90));
  }
  else
  {
    sp->setPosition(sf::Vector2f((i - 3) * 300 + 80, 210));
  }

  this->sprite.push_back(sp);
  this->sprite.at(i)->setScale(2.5f, 2.5f);
}

void CharMenu::init_var(std::string &type, std::string &version)
{
  for (int i = 0; i < charSize; i++)
  {
    this->path = type + "/" + version + "/" + chars[i] + "/" + "idle/idle";
    this->init_texture_vec(i);
    this->init_sprite_vec(i);
    this->init_clock();
  }
}

void CharMenu::MoveRight()
{
  if (this->selectedItem + 1 < Max_Items)
  {
    this->texture.at(this->animate)->loadFromFile("bin/image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem += 1;
    this->animate = this->selectedItem;
  }
  else
  {
    this->texture.at(Max_Items - 1)->loadFromFile("bin/image/" + chars[Max_Items - 1] + "/idle/idle_1.png");
    this->animate = 0;
    this->selectedItem = 0;
  }
}

void CharMenu::MoveLeft()
{
  if (this->selectedItem - 1 >= 0)
  {
    this->texture.at(this->animate)->loadFromFile("bin/image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem -= 1;
    this->animate = this->selectedItem;
  }
  else
  {
    this->texture.at(0)->loadFromFile("bin/image/" + chars[0] + "/idle/idle_1.png");
    this->animate = Max_Items - 1;
    this->selectedItem = Max_Items - 1;
  }
}

void CharMenu::MoveUp()
{
  if (this->selectedItem - 3 >= 0)
  {
    this->texture.at(this->animate)->loadFromFile("bin/image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem -= 3;
    this->animate = this->selectedItem;
  }
  else
  {
    this->texture.at(this->selectedItem)->loadFromFile("bin/image/" + chars[this->selectedItem] + "/idle/idle_1.png");
    this->animate = this->selectedItem + 3;
    this->selectedItem = this->animate;
  }
}

void CharMenu::MoveDown()
{
  if (this->selectedItem + 3 < Max_Items)
  {
    this->texture.at(this->animate)->loadFromFile("bin/image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem += 3;
    this->animate = this->selectedItem;
  }
  else
  {
    this->texture.at(this->selectedItem)->loadFromFile("bin/image/" + chars[this->selectedItem] + "/idle/idle_1.png");
    this->animate = this->selectedItem - 3;
    this->selectedItem = this->animate;
  }
}

void CharMenu::Update()
{

  if (this->clock->getElapsedTime().asSeconds() > 0.1f)
  {

    if (this->que >= characterAtkNums[this->animate])
    {
      this->que = 1;
    }
    else
    {
      this->que++;
    }

    clock->restart();
  }
}

void CharMenu::Animated(sf::RenderTarget &target)
{

  target.draw(*this->sprite.at(this->animate));

  if (que <= this->characterAtkNums[this->animate])
  {
    this->texture.at(this->animate)->loadFromFile("bin/image/" + chars[this->animate] + "/1_atk/atk_" + std::to_string(this->que) + ".png");
  }
}

void CharMenu::MoveLeftRight(sf::Event &event, Hero *&hero)
{
  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
    {
      MoveRight();
    }
    else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
    {
      MoveLeft();
    }
    else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
    {
      MoveUp();
    }
    else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
    {
      MoveDown();
    }
    else if (event.key.code == sf::Keyboard::Escape)
    {
      this->open = false;
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      this->open = false;
      // index = this->animate;
      hero = new LeafArcher();
    }
  }
}

void CharMenu::init_clock()
{
  clock = new sf::Clock();
}

bool CharMenu::get_open()
{
  return this->open;
}

void CharMenu::set_open(bool open)
{
  this->open = open;
}