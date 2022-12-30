#include "HOTA/CharacterMenu.hpp"
#include <SFML/Graphics.hpp>
#include "HOTA/FireKnight.hpp"
#include "HOTA/Wind.hpp"
#include "HOTA/Water.hpp"
#include "HOTA/BladeKeeper.hpp"
#include "HOTA/GroundMonk.hpp"
#include "HOTA/FrostGuardian.hpp"
#include "HOTA/DemonSlime.hpp"
#include "HOTA/BlackSmith.hpp"

CharMenu::CharMenu(std::string type, std::string version)
{
  this->open = true;
  this->init_var(type, version);
}

CharMenu::~CharMenu() // heap teki bellekleri teslim ediyoruz
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

void CharMenu::render(sf::RenderTarget &target)
{
  this->Animated(target); // animasyonu cagiriyoruz

  sf::Texture border; // cerceveyi olustuyoruz
  border.loadFromFile("image/MenuCard/Cards.png");
  sf::Sprite borderDraw(border, sf::IntRect(125, 281, 92, 130)); // cerceve sonu

  borderDraw.setScale(3.f, 2.f); // cerceveyi cizdiriyoruz
  for (int i = 0; i < charSize; i++)
  {
    if (i < 3) // karakterleri cizdiyoruz ve cerceve konumunu duzeltiyoruz
    {
      borderDraw.setPosition(i * 300 + 320, 50);
      target.draw(borderDraw);
    }
    else // indexe uyarli cerceve konumu
    {
      borderDraw.setPosition((i - 3) * 300 + 320, 350);
      target.draw(borderDraw);
    }
    target.draw(*this->sprite.at(i));
  }
}

void CharMenu::init_texture_vec(int i) // karakterleri filedan okuyoruz
{
  auto tx = new sf::Texture();
  this->texture.push_back(tx);
  if (!this->texture.at(i)->loadFromFile(this->path + "_1.png"))
  {
    // std::cout << "ERROR:CharMenu::INIT_TEXTURE_VEC::Could not load the texture" << std::endl;
  }
}

void CharMenu::init_sprite_vec(int i) // We are creating characters and their positions for the menu
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

void CharMenu::init_var(std::string &type, std::string &version) // Initialising variables
{
  for (int i = 0; i < charSize; i++)
  {
    this->path = type + "" + version + "/" + chars[i] + "/" + "idle/idle"; // Initialising paths
    this->init_texture_vec(i);
    this->init_sprite_vec(i);
    this->init_clock();
  }
  this->init_characters_vector();
}

void CharMenu::init_clock()
{
  clock = new sf::Clock(); // sfml clock object for the animations
}

void CharMenu::init_characters_vector() // Store func addresses in vector
{
  this->characters.push_back([]() -> Hero *
                             { return new BladeKeeper{}; });
  this->characters.push_back([]() -> Hero *
                             { return new FireKnight{}; });
  this->characters.push_back([]() -> Hero *
                             { return new GroundMonk{}; });
  this->characters.push_back([]() -> Hero *
                             { return new LeafArcher{}; });
  this->characters.push_back([]() -> Hero *
                             { return new Water{}; });
  this->characters.push_back([]() -> Hero *
                             { return new Wind{}; });
}

bool CharMenu::get_open() // getter for open
{
  return this->open;
}

void CharMenu::set_open(bool open) // setter for open
{
  this->open = open;
}

// start of the menu move functions
void CharMenu::MoveRight()
{
  if (this->selectedItem + 1 < Max_Items) // changing selected elements indexes
  {
    this->texture.at(this->animate)->loadFromFile("image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem += 1;
    this->animate = this->selectedItem;
  }
  else // no space for right go beginning
  {
    this->texture.at(Max_Items - 1)->loadFromFile("image/" + chars[Max_Items - 1] + "/idle/idle_1.png");
    this->animate = 0;
    this->selectedItem = 0;
  }
}

void CharMenu::MoveLeft()
{
  if (this->selectedItem - 1 >= 0)
  {
    this->texture.at(this->animate)->loadFromFile("image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem -= 1;
    this->animate = this->selectedItem;
  }
  else // no space left for to go left and turn to the beginning
  {
    this->texture.at(0)->loadFromFile("image/" + chars[0] + "/idle/idle_1.png");
    this->animate = Max_Items - 1;
    this->selectedItem = Max_Items - 1;
  }
}

void CharMenu::MoveUp()
{
  if (this->selectedItem - 3 >= 0)
  {
    this->texture.at(this->animate)->loadFromFile("image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem -= 3;
    this->animate = this->selectedItem;
  }
  else // if there is not enough space to go 3 index up then go the next 3
  {
    this->texture.at(this->selectedItem)->loadFromFile("image/" + chars[this->selectedItem] + "/idle/idle_1.png");
    this->animate = this->selectedItem + 3;
    this->selectedItem = this->animate;
  }
}

void CharMenu::MoveDown()
{
  if (this->selectedItem + 3 < Max_Items) // Conditions for down
  {
    this->texture.at(this->animate)->loadFromFile("image/" + chars[this->animate] + "/idle/idle_1.png");
    this->selectedItem += 3;
    this->animate = this->selectedItem;
  }
  else // not enough space for down 3 then go up 3
  {
    this->texture.at(this->selectedItem)->loadFromFile("image/" + chars[this->selectedItem] + "/idle/idle_1.png");
    this->animate = this->selectedItem - 3;
    this->selectedItem = this->animate;
  }
}
// end of move functions

void CharMenu::selectedHero(Hero *&hero, Boss *&boss, Npc *&npc) // the function that creates selected hero
{
  hero = this->characters[this->selectedItem]();
  boss = new DemonSlime();
}

void CharMenu::MoveLeftRight(sf::Event &event, Hero *&hero, Boss *&boss, Npc *&npc, bool &menuOpen) // character menu key control function
{

  if (event.type == sf::Event::KeyReleased)
  {
    this->stop = false;
    if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
    {
      this->que = 1;
      MoveRight(); // call the move right
    }
    else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
    {
      this->que = 1;
      MoveLeft(); // call the move left
    }
    else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
    {
      this->que = 1;
      MoveUp(); // call move up
    }
    else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
    {
      this->que = 1;
      MoveDown(); // call move down
    }
    else if (event.key.code == sf::Keyboard::Escape)
    {
      menuOpen = true;
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      this->open = false;
      this->selectedHero(hero, boss, npc); // selecting character
    }
  }
}

void CharMenu::Update() // Updating animations
{
  if (this->clock->getElapsedTime().asSeconds() > 0.1f && !stop)
  {
    if (this->que >= characterAtkNums[this->animate])
    {
      this->que = 1;
      this->stop = true;
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
  target.draw(*this->sprite.at(this->animate));              // selected index character animate and draw
  if (que <= this->characterAtkNums[this->animate] && !stop) // there are some characters that have lots of png than other to error handling we use if condition here
  {
    is_leaf_archer();
  }
  else
  {
    this->que = 1;
    this->texture.at(this->animate)->loadFromFile("image/" + chars[this->animate] + "/idle/idle_" + std::to_string(this->que) + ".png");
  }
}

void CharMenu::is_leaf_archer()
{
  if (this->animate != 3)
  {
    this->texture.at(this->animate)->loadFromFile("image/" + chars[this->animate] + "/1_atk/atk_" + std::to_string(this->que) + ".png");
  }
  else
  {
    this->texture.at(this->animate)->loadFromFile("image/" + chars[this->animate] + "/defend/defend_" + std::to_string(this->que) + ".png");
  }
}