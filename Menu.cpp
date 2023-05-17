#include "Menu.h"

Menu::Menu()
{
    // Initialize font
    if(!font.loadFromFile("include/PfennigBold.ttf"))
    {
        cout << "Failed to load font..." << endl;
    }

    // Initialize text
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);

    // Select a level
    text.setString("Pick a level from 1 - 10 !!!!!!!!!!");
    text.setPosition(250, 250);
}