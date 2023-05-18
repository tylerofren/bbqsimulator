#include "Game.h"

#include <iostream>

using namespace std;


Game::Game()
{
    menuIsOpened = true;
    levelOneIsOpened = false;
    
    initializeWindow();
    
    initializeLevels();
    
    initializeText();
    
    initializeMaps();





}




void Game::initializeWindow()
{
    window.create(sf::VideoMode(500, 500), "Game");
}

void Game::initializeText()
{
    if(!font.loadFromFile("assets/PfennigBold.ttf"))
    {
        errorFile.open("errors.txt");
        errorFile << "failed to load image" << endl;
        errorFile.close();
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
    levelSelect.setFont(font);
    levelSelect.setCharacterSize(20);
    levelSelect.setFillColor(sf::Color::White);
    levelSelect.setString("Pick a level from 1 - 10 !!!!!!!!!");
    levelSelect.setOrigin(levelSelect.getLocalBounds().width / 2, levelSelect.getLocalBounds().height / 2);
    levelSelect.setPosition(250, 250);
}

void Game::initializeLevels()
{
    levelOne =  
    {
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0}
    };

}



void Game::initializeMaps()
{
    maps[0] = new Map(levelOne);
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
        else if(ev.type == sf::Event::KeyReleased)
        {
            switch(ev.key.code)
            {
                case sf::Keyboard::Escape: // Escape closes the program
                window.close();
                break;

                case sf::Keyboard::M: // M returns to the menu
                menuIsOpened = true;
                levelOneIsOpened = false;
                break;

                case sf::Keyboard::Num1:
                menuIsOpened = false;
                levelOneIsOpened = true;
                break;

                
            }
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



    if(menuIsOpened)
    {
        window.draw(gameTitle);
        window.draw(levelSelect);
    }
    
    if(levelOneIsOpened)
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[0]->tiles[i][j]->getSprite());
            }
        }
        
    }
    
    

   



    


    window.display();
}