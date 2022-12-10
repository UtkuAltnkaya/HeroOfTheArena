#include "HOTA/CharacterMenu.hpp"
#include <SFML/Graphics.hpp>
#include "HOTA/FireKnight.hpp"
#include "HOTA/Wind.hpp"
#include "HOTA/Water.hpp"
#include "HOTA/BladeKeeper.hpp"
#include "HOTA/GroundMonk.hpp"
#include <iostream>

CharMenu::CharMenu(std::string type, std::string version)
{
  this->open = true;
  this->init_var(type, version);
}
CharMenu::~CharMenu()
{ // heapteki bellekleri teslim ediyoruz

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

void CharMenu::render(sf::RenderTarget &target)
{
  // animasyonu cagiriyoruz
  this->Animated(target);
  // cerceveyi olustuyoruz
  sf::Texture border;
  border.loadFromFile("bin/image/MenuCard/Cards.png");
  sf::Sprite borderDraw(border, sf::IntRect(125, 281, 92, 130));
  // cerceve sonu

  borderDraw.setScale(3.f, 2.f); // cerceveyi cizdiriyoruz
  for (int i = 0; i < charSize; i++)
  {
    if (i < 3)
    { // karakterleri cizdiyoruz ve cerceve konumunu duzeltiyoruz
      borderDraw.setPosition(i * 300 + 320, 50);
      target.draw(borderDraw);
    }
    else
    { // indexe uyarli cerceve konumu
      borderDraw.setPosition((i - 3) * 300 + 320, 350);
      target.draw(borderDraw);
    }
    target.draw(*this->sprite.at(i));
  }
}

void CharMenu::init_texture_vec(int i)
{
  // karakterleri filedan okuyoruz
  auto tx = new sf::Texture();
  this->texture.push_back(tx);
  if (!this->texture.at(i)->loadFromFile(this->path + "_1.png"))
  {
    std::cout << "ERROR:CharMenu::INIT_TEXTURE_VEC::Could not load the texture" << std::endl;
  }
}

void CharMenu::init_sprite_vec(int i)
{
  // we are creating characters and their positions for the menu
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
// initilazing variables
void CharMenu::init_var(std::string &type, std::string &version)
{
  for (int i = 0; i < charSize; i++)
  { // initilazing paths
    this->path = type + "/" + version + "/" + chars[i] + "/" + "idle/idle";
    this->init_texture_vec(i);
    this->init_sprite_vec(i);
    this->init_clock();
  }
}

void CharMenu::init_clock()
{ // sfml clock object for the animations
  clock = new sf::Clock();
}

// getter for open
bool CharMenu::get_open()
{
  return this->open;
}

// setter for open
void CharMenu::set_open(bool open)
{
  this->open = open;
}

// start of the menu move functions
void CharMenu::MoveRight()
{
  // changing selected elemtents indexes
  if (this->selectedItem + 1 < Max_Items)
  {
    this->texture.at(this->animate)->loadFromFile("bin/image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem += 1;
    this->animate = this->selectedItem;
  }
  else
  { // no space for right go beginning
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
  { // no space left for to go left and turn to the beginning
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
  { // if there is not enough space to go 3 index up then go the next 3
    this->texture.at(this->selectedItem)->loadFromFile("bin/image/" + chars[this->selectedItem] + "/idle/idle_1.png");
    this->animate = this->selectedItem + 3;
    this->selectedItem = this->animate;
  }
}

void CharMenu::MoveDown()
{ // conditions for down
  if (this->selectedItem + 3 < Max_Items)
  {
    this->texture.at(this->animate)->loadFromFile("bin/image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem += 3;
    this->animate = this->selectedItem;
  }
  else // not enough space for down 3 then go up 3
  {
    this->texture.at(this->selectedItem)->loadFromFile("bin/image/" + chars[this->selectedItem] + "/idle/idle_1.png");
    this->animate = this->selectedItem - 3;
    this->selectedItem = this->animate;
  }
}
// end of move functions

// the function that creates selected hero
void CharMenu::selectedHero(Hero *&hero)
{
  // simple condition for selected index
  if (selectedItem == 0)
  {
    hero = new BladeKeeper();
  }
  else if (selectedItem == 1)
  {
    hero = new FireKnight();
  }
  else if (selectedItem == 2)
  {
    hero = new GroundMonk();
  }
  else if (selectedItem == 3)
  {
    hero = new LeafArcher();
  }
  else if (selectedItem == 4)
  {
    hero = new Water();
  }
  else if (selectedItem == 5)
  {
    hero = new Wind();
  }
}

// character menu key control function
void CharMenu::MoveLeftRight(sf::Event &event, Hero *&hero)
{
  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
    {
      MoveRight();
      // call the move right
    }
    else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
    {
      MoveLeft();
      // call the move left
    }
    else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
    {
      MoveUp();
      // call move up
    }
    else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
    {
      MoveDown();
      // call mov edown
    }
    else if (event.key.code == sf::Keyboard::Escape)
    {
      this->open = false;
      // change the open variable to close char menu
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      // selecting character
      this->open = false;
      this->selectedHero(hero);
    }
  }
}

void CharMenu::Update()
{

  if (this->clock->getElapsedTime().asSeconds() > 0.1f)
  {
    // updating animations
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
  // selected index character animate and draw
  target.draw(*this->sprite.at(this->animate));

  if (que <= this->characterAtkNums[this->animate])
  { // there are some characters that have lots of png than other to errong handling we use if condition here
    this->texture.at(this->animate)->loadFromFile("bin/image/" + chars[this->animate] + "/1_atk/atk_" + std::to_string(this->que) + ".png");
  }
}
