#include "Game.h"

#include <iostream>

using namespace std;


Game::Game()
{
    initializeGame();
    initializeWindow();



}




void Game::initializeWindow()
{
    window.create(sf::VideoMode(500, 500), "Game");
}

void Game::initializeLevel1()
{
    Level1.create(sf::VideoMode(500, 500), "Level 1");
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

                // Select Levels
                // Level 1
                if(ev.key.code == sf::Keyboard::Num1)

                    initializeLevel1();

                    while(Level1.isOpen())
                    {
                        while(Level1.pollEvent(event1))
                        {
                            switch(ev.type)
                            {
                                case sf::Event::Closed:
                                    Level1.close();
                                    break;
                                case sf::Event::KeyPressed:
                                    if(event1.key.code == sf::Keyboard::Escape)
                                        Level1.close();
                                    break;
                            }
                        }
                        Level1.clear();
                        Level1.display();
                    }
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