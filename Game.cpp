#include "Game.h"

#include <iostream>

using namespace std;


Game::Game()
{
    initializeWindow();
    initializeText();
}




void Game::initializeWindow()
{
    window.create(sf::VideoMode(500, 500), "Game");
}

void Game::initializeText()
{
    if(!font.loadFromFile("assets/PfennigBold.ttf"))
    {
        cout << "Failed to load font..." << endl;
    }
    // Initialize text
    // Game Title
    gameTitle.setFont(font);
    gameTitle.setCharacterSize(30);
    gameTitle.setFillColor(sf::Color::White);
    gameTitle.setString("Game");
    gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2, gameTitle.getLocalBounds().height / 2);
    gameTitle.setPosition(250, 100);

    // Level select
    levels.setFont(font);
    levels.setCharacterSize(20);
    levels.setFillColor(sf::Color::White);
    levels.setString("Pick a level from 1 - 10 !!!!!!!!!");
    levels.setOrigin(levels.getLocalBounds().width / 2, levels.getLocalBounds().height / 2);
    levels.setPosition(250, 250);
}





// Accessors

const bool Game::running() const
{
    return window.isOpen();
}


// Public functions

void Game::pollEvents()
{
    while(window.pollEvent(ev))
    {
        if(ev.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Game::update()
{
    pollEvents();
}

void Game::render()
{
    window.clear();

    window.draw(gameTitle);
    window.draw(levels);


    window.display();
}