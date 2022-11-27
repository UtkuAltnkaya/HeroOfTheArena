#include "HOTA/MainMenu.hpp"

MainMenu::MainMenu(float width, float height)
{
  std::string menuText[3] = {"Play", "Options", "Quit"};
  this->titleFont.loadFromFile("bin/Fonts/PixExtrusion.ttf");
    title.setFont(titleFont);
    title.setCharacterSize(80);
    title.setColor(sf::Color::Blue);
    title.setString("HERO OF THE ARENA");
    title.setPosition(sf::Vector2f((width - 800) / 2,  50));

  this->open = true;

  
  if (!font.loadFromFile("bin/Fonts/PixelHigh.ttf"))
  {
    // handle error
  }
  for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
  {
    menu[i].setFont(font);
    menu[i].setCharacterSize(40);
    menu[i].setColor(sf::Color::White);
    menu[i].setString(menuText[i]);
    menu[i].setPosition(sf::Vector2f((width - menu[i].getString().getSize() * 10) / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * i + 250));
  }
  menu[0].setColor(sf::Color::Red);
  this->init_char_menu();
}

MainMenu::~MainMenu()
{
  delete this->char_menu;
}

void MainMenu::render(sf::RenderWindow &window)
{
  if (this->open)
  {
    window.draw(title);

    for (int i{0}; i < MAX_NUMBER_OF_ITEMS; i++)
    {
      window.draw(menu[i]);
    }
  }
  else if (this->char_menu->get_open())
  {
    this->char_menu->render(window);
  }
}

void MainMenu::MoveUp()
{

  if (this->selectedItemIndex - 1 >= 0)
  {
    menu[this->selectedItemIndex].setColor(sf::Color::White);
    this->selectedItemIndex--;
    menu[this->selectedItemIndex].setColor(sf::Color::Red);
  }
  else
  {
    menu[this->selectedItemIndex].setColor(sf::Color::White);
    this->selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
    menu[this->selectedItemIndex].setColor(sf::Color::Red);
  }
}

void MainMenu::MoveDown()
{
  if (this->selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
  {
    menu[this->selectedItemIndex].setColor(sf::Color::White);
    this->selectedItemIndex++;
    menu[this->selectedItemIndex].setColor(sf::Color::Red);
  }
  else
  {
    menu[this->selectedItemIndex].setColor(sf::Color::White);
    this->selectedItemIndex = 0;
    menu[this->selectedItemIndex].setColor(sf::Color::Red);
  }
}

void MainMenu::MenuUpDown(sf::Event &event, Hero *&hero)
{
  if (this->open)
  {
    if (event.type == sf::Event::KeyReleased)
    {
      if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
      {
        MoveUp();
      }
      else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
      {
        MoveDown();
      }
      else if (event.key.code == sf::Keyboard::Enter && this->selectedItemIndex == 0)
      {
        this->open = false;
      }
      else 
      {
        //todo
      }
    }
  }
  else if (this->char_menu->get_open())
  {

    this->char_menu->MoveLeftRight(event, hero);
  }
}

// bool MainMenu::GetOpen()
// {
//   return this->open;
// }

// void MainMenu::SetOpen(bool changeOpen)
// {
//   this->open = changeOpen;
// }

void MainMenu::init_char_menu()
{
  this->char_menu = new CharMenu("bin", "image");
}

void MainMenu::update()
{
  if (this->open)
  {
    //
  }
  else if (this->char_menu->get_open())
  {
    /* code */
    this->char_menu->Update();
  }
}