#include "Game.h"

#include <iostream>

using namespace std;


Game::Game()
{
    menuIsOpened = true;
    levelOneIsOpened = false;
    
    initializeWindow();

    initializePlayer();

    initializeSausages();
    
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
    /*
        0 - WATER
        1 - GROUND
        2 - GRILL
        3 - SAUSAGE
        4 - PLAYER
        5 - SPAWN
    */
    levelOne =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 2, 2, 1, 0, 0, 0},
        {0, 0, 0, 1, 2, 2, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

}

void Game::initializePlayer()
{
    player = new Player(0, 0, 0);
}

void Game::initializeSausages()
{
    sausage = new Sausage(0, 0, false);
    sausage2 = new Sausage(0, 0, false);
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

/*

Fix bug: game crashes when W,A,S,D pressed in main menu



*/

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

                case sf::Keyboard::Num1: // Select lvl 1
                menuIsOpened = false;
                levelOneIsOpened = true;
                currentMap = 0;

                // ----------- Level 1 Starting Player Positions --------------
                // Position: row/col * 50 + 25
                // Rotations: 0 = North
                // 1 = East 
                // 2 = South 
                // 3 = West
                player->setPosition(sf::Vector2f(225, 125));
                player->setRotation(1);

                // --------- Level 1 Starting Sausage Positions --------------
                sausage->setPosition(sf::Vector2f(325, 425));
                sausage->setHorizontal(false);

                sausage2->setPosition(sf::Vector2f(125, 225));
                sausage2->setHorizontal(true);
                break;

                // ----------Player controls------------------------
                case sf::Keyboard::W:
                if(!player->isHorizontal() && maps[currentMap]->tiles[player->getRow() - 1][player->getColumn()]->getPassable())
                {
                    player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y - 50));
                }
                else if(player->isHorizontal())
                {
                    player->setRotation(0);
                }
                break;

                case sf::Keyboard::A:
                if(player->isHorizontal() && maps[currentMap]->tiles[player->getRow()][player->getColumn() - 1]->getPassable())
                {
                    player->setPosition(sf::Vector2f(player->getPosition().x - 50, player->getPosition().y));
                }
                else if(!player->isHorizontal())
                {
                    player->setRotation(3);
                }
                break;

                case sf::Keyboard::S:
                if(!player->isHorizontal() && maps[currentMap]->tiles[player->getRow() + 1][player->getColumn()]->getPassable())
                {
                    player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y + 50));
                }
                else if(player->isHorizontal())
                {
                    player->setRotation(2);
                }
                break;

                case sf::Keyboard::D:
                if(player->isHorizontal() && maps[currentMap]->tiles[player->getRow()][player->getColumn() + 1]->getPassable())
                {
                    player->setPosition(sf::Vector2f(player->getPosition().x + 50, player->getPosition().y));
                }
                else if(!player->isHorizontal())
                {
                    player->setRotation(1);
                }
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
        window.draw(player->getSprite());
        window.draw(sausage->getSprite());
        window.draw(sausage2->getSprite());
        
    }
    
    

   



    


    window.display();
}