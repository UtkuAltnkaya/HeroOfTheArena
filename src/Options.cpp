#include "HOTA/Options.hpp"

Options::Options(sf::Font &font)
{
    init_var(font); // Init font
}

Options::~Options()
{
}

void Options::init_var(sf::Font &font)
{ // Initialize SFX text and the sound bar
    this->is_open = true;
    this->selected_index = 1;
    // init boxes
    this->boxes.setSize(sf::Vector2f(15, 25));
    this->boxes.setOutlineColor(sf::Color::Black);
    this->boxes.setOutlineThickness(3.5);
    // init text
    this->sfx.setFont(font);
    this->sfx.setCharacterSize(50);
    this->sfx.setColor(sf::Color::Black);
    this->sfx.setString("SFX");
}

void Options::move_right()
{
    if (this->selected_index < 19) // Upper limit for music up
    {
        this->selected_index++;
        return;
    }
}

void Options::move_left()
{
    if (this->selected_index > 0) // Lower limit for music down
    {
        this->selected_index--;
        return;
    }
}

void Options::move_left_right(sf::Event &event, Music *&music, bool &menu_open)
{ // Arranging music volume with changing the static variable of Music class
    if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
    {
        this->move_right();
        music->set_volume(this->selected_index * 5.0);
    }
    else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
    {
        this->move_left();
        music->set_volume(this->selected_index * 5.0);
    }
    else if (event.key.code == sf::Keyboard::Escape)
    {
        this->is_open = false;
        menu_open = true;
    }
}

void Options::render(sf::RenderWindow &window)
{ // Draw the options part
    this->sfx.setPosition(sf::Vector2f(460, 256 * 3 / 2 - 20));
    window.draw(this->sfx);
    for (int i{0}; i < 20; i++)
    {
        if (i <= this->selected_index)
        {
            this->boxes.setFillColor(sf::Color::Red);
        }
        else
        {
            this->boxes.setFillColor(sf::Color::Transparent);
        }
        this->boxes.setPosition(sf::Vector2f(512 + i * 20 + 100, 256 * 3 / 2));
        window.draw(this->boxes);
    }
}

bool Options::get_is_open()
{
    return this->is_open;
}

void Options::set_is_open(bool is_open)
{
    this->is_open = is_open;
}
