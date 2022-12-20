#include "HOTA/MainMenu.hpp"

MainMenu::MainMenu(float width, float height)
{
  std::string menuText[3] = {"Play", "Options", "Quit"};
  this->titleFont.loadFromFile("Fonts/PixExtrusion.ttf");
  title.setFont(titleFont);
  title.setCharacterSize(80);

  title.setColor(sf::Color::Black);
  title.setString("HERO OF THE ARENA");
  title.setPosition(sf::Vector2f((width - 800) / 2, 50));

  this->open = true;

  if (!font.loadFromFile("Fonts/PixelHigh.ttf"))
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
  this->selectedItemIndex = 0;

  this->options = new Options(font);
  this->init_char_menu();
}

MainMenu::~MainMenu()
{
  delete this->char_menu;
  delete this->music;
  delete this->options;
}

void MainMenu::render(sf::RenderWindow &window, Hero *&hero)
{
  if (this->open)
  {
    window.draw(title);

    for (int i{0}; i < MAX_NUMBER_OF_ITEMS; i++)
    {
      window.draw(menu[i]);
    }
    return;
  }
  else if (this->options->get_is_open())
  {
    this->options->render(window);
    return;
  }
  else if (this->char_menu->get_open())
  {
    this->char_menu->render(window);
    return;
  }
  if (!hero)
    window.close();
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

void MainMenu::MenuUpDown(sf::Event &event, Hero *&hero, Boss *&boss, Npc *&npc)
{
  if (this->open)
  {
    if (event.type == sf::Event::KeyReleased)
    {
      this->move_it(event);
    }
  }
  else if (this->options->get_is_open())
  {
    this->options->move_left_right(event, this->music, this->open);
  }
  else if (this->char_menu->get_open())
  {

    this->char_menu->MoveLeftRight(event, hero, boss, npc, this->open);
  }
}

void MainMenu::move_it(sf::Event &event)
{
  if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
  {
    MoveUp();
  }
  else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
  {
    MoveDown();
  }
  else if (event.key.code == sf::Keyboard::Enter)
  {
    this->selected_option();
  }
  else
  {
    // todo
  }
}
void MainMenu::selected_option()
{
  if (this->selectedItemIndex == 0)
  {
    this->open = false;
    this->options->set_is_open(false);
  }
  else if (this->selectedItemIndex == 1)
  {
    this->open = false;
    this->options->set_is_open(true);
  }
  else if (this->selectedItemIndex == 2)
  {
    this->open = false;
    this->options->set_is_open(false);
    this->char_menu->set_open(false);
  }
}

void MainMenu::init_char_menu()
{
  this->char_menu = new CharMenu("", "image");
  this->music = new Musics("Battle Encounter.ogg");
  this->music->play();
}

void MainMenu::update()
{
  if (this->open)
  {
  }
  else if (this->char_menu->get_open())
  {

    this->char_menu->Update();
  }
}