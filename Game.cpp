#include "Game.h"

#include <iostream>

using namespace std;


Game::Game()
{
    initializeGame();
    initializeWindow();
    initializeFonts();
    initializeText();
}


/*void Game::initializeGame()
{

}*/

void Game::initializeWindow()
{
    window.create(sf::VideoMode(500, 500), "Game");
}

void Game::initializeFonts()
{
    if(!font.loadFromFile("include/xxxxxxx.ttf"))
    {
        cout << "Failed to load font!" << endl;
    }
}

void Game::initializeText()
{
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
}

void Game::initializeGame()
{
    /* level1 = new Level(map, player, etc)
        levels = new Level[5]
        levels[0] = level1



    */

}


void Game::startGame()
{

}


// Accessors

const bool Game::running() const
{
    return window.isOpen();
}
const bool Game::getEndGame() const
{
    return endGame;
}

// Public functions

void Game::pollEvents()
{
    while(window.pollEvent(ev))
    {
        switch(ev.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(ev.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
        }
    }
}

void Game::update()
{
    pollEvents();
    if(!endGame)
    {
        // Events 
    }


    // End game condition : Level finished etc
}

void Game::render()
{
    window.clear();
    // render stuff, draw game objects

    window.display();
}