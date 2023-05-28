#include "Game.h"

#include <iostream>

using namespace std;


Game::Game()
{
    menuIsOpened = true;
    resetLevels();
    lostScreenIsOpened = false;
    winScreenIsOpened = false;
    sausagesPerfectlyCooked = false;
    levelSelectIsOpened = false;
    
    initializeWindow();

    initializePlayer();

    initializeSausages();
    
    initializeLevels();
    
    initializeText();
    
    initializeMaps();

    initializePlayerOutline();

    initializeBackground();
}




void Game::initializeWindow()
{
    window.create(sf::VideoMode(500, 500), "Game");
}

void Game::initializeText()
{
    if(!roundFont.loadFromFile("assets/Pangolin-Regular.ttf"))
    {
        errorFile.open("errors.txt");
        errorFile << "failed to load image" << endl;
        errorFile.close();
    }
    if(!seriousFont.loadFromFile("assets/PfennigBold.ttf"))
    {
        errorFile.open("errors.txt");
        errorFile << "failed to load image" << endl;
        errorFile.close();
    }
    // ------------ Menu -------------
    gameTitle.setFont(roundFont);
    gameTitle.setCharacterSize(45);
    gameTitle.setLetterSpacing(4.0);
    gameTitle.setFillColor(sf::Color::White);
    gameTitle.setString(" Philip's\nCookout");
    gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2, gameTitle.getLocalBounds().height / 2);
    gameTitle.setPosition(250, 210);
    gameTitle.setOutlineThickness(4.0);

    pressAnyButton.setFont(seriousFont);
    pressAnyButton.setCharacterSize(20);
    pressAnyButton.setFillColor(sf::Color::White);
    pressAnyButton.setString("~ Press Any Button ~");
    pressAnyButton.setOrigin(pressAnyButton.getLocalBounds().width / 2, pressAnyButton.getLocalBounds().height / 2);
    pressAnyButton.setPosition(250, 375);
    pressAnyButton.setOutlineThickness(3.5);

    // ----------------- Level Select --------------
    levelSelect.setFont(seriousFont);
    levelSelect.setCharacterSize(40);
    levelSelect.setFillColor(sf::Color::Black);
    levelSelect.setString("Select Level");
    levelSelect.setLetterSpacing(4.0);
    levelSelect.setOrigin(levelSelect.getLocalBounds().width / 2, levelSelect.getLocalBounds().height / 2);
    levelSelect.setPosition(250, 100);
    levelSelect.setOutlineColor(sf::Color::White);
    levelSelect.setOutlineThickness(3.5);

    levelNumbers.setFont(roundFont);
    levelNumbers.setCharacterSize(40);
    levelNumbers.setFillColor(sf::Color::Black);
    levelNumbers.setString("1\t2\t3\t4\t5\n6\t7\t8\t9\t10");
    levelNumbers.setOrigin(levelNumbers.getLocalBounds().width / 2, levelNumbers.getLocalBounds().height / 2);
    levelNumbers.setPosition(250, 300);
    levelNumbers.setOutlineColor(sf::Color::White);
    levelNumbers.setOutlineThickness(3.5);

    // ---------------- Lost Screen -------------
    lostScreen.setFont(roundFont);
    lostScreen.setCharacterSize(75);
    lostScreen.setFillColor(sf::Color::White);
    lostScreen.setString("Lost");
    lostScreen.setOrigin(lostScreen.getLocalBounds().width / 2, lostScreen.getLocalBounds().height / 2);
    lostScreen.setPosition(250, 80);
    lostScreen.setLetterSpacing(3.0f);
    lostScreen.setOutlineThickness(4.0);

    lostScreen2.setFont(roundFont);
    lostScreen2.setCharacterSize(92);
    lostScreen2.setFillColor(sf::Color::Black);
    lostScreen2.setString("asdfsfadf");
    lostScreen2.setOrigin(lostScreen2.getLocalBounds().width / 2, lostScreen2.getLocalBounds().height / 2);
    lostScreen2.setPosition(250, 190);
    lostScreen2.setLetterSpacing(2.0);


    // -------------- Win Screen -------------
    winScreen.setFont(roundFont);
    winScreen.setCharacterSize(80);
    winScreen.setFillColor(sf::Color::Black);
    winScreen.setString("Win");
    winScreen.setOrigin(lostScreen2.getLocalBounds().width / 2, lostScreen2.getLocalBounds().height / 2);
    winScreen.setPosition(250, 80);
}

void Game::initializeBackground()
{
    if(!backgroundTexture.loadFromFile("assets/cookout.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load cookout" << endl;
        errorFile.close();
    }
    background.setTexture(backgroundTexture);

    if(!levelSelectBackgroundTexture.loadFromFile("assets/levelSelectBackground.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load background" << endl;
        errorFile.close();
    }
    levelSelectBackground.setTexture(levelSelectBackgroundTexture);
    levelSelectBackground.setTextureRect(sf::IntRect(225, 100, 500, 500));
}


void Game::initializeLevels()
{
    levels.resize(10, std::vector<std::vector<int>>(10, std::vector<int>(10)));
    /*
        0 - WATER0S
        1 - GROUND
        2 - GRILL
        3 - SAUSAGE
        4 - PLAYER
        -----------
        7 - WATER1S
        8 - WATER2S
        9 - WATER2SC
        10 - WATER3S
    */
    levels[0] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 7, 7, 0, 0, 0, 0},
        {0, 7, 7, 9, 1, 1, 9, 7, 7, 0},
        {7, 1, 1, 1, 1, 1, 1, 1, 1, 7},
        {7, 1, 1, 1, 2, 2, 1, 1, 1, 7},
        {7, 1, 1, 1, 2, 2, 1, 1, 1, 7},
        {7, 1, 1, 1, 1, 1, 1, 1, 1, 7},
        {7, 1, 1, 1, 1, 1, 1, 1, 1, 7},
        {0, 7, 7, 7, 7, 7, 7, 7, 7, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    levels[1] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 7, 7, 7, 0, 0, 0},
        {0, 0, 0, 7, 1, 1, 1, 7, 0, 0},
        {0, 0, 7, 9, 1, 1, 1, 9, 0, 0},
        {0, 7, 2, 2, 1, 1, 1, 2, 9, 0},
        {0, 7, 2, 2, 9, 7, 9, 2, 2, 7},
        {0, 0, 7, 7, 0, 0, 0, 7, 7, 0},
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


void Game::initializeMaps() // Make this a for loop once 10 level arrays are made
{
    maps[0] = new Map(levels[0]);
    maps[1] = new Map(levels[1]);
}


void Game::initializePlayerOutline()
{
    if(!playerOutlineTexture.loadFromFile("assets/playerOutline.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "failed to load image" << endl;
        errorFile.close();
    }
    playerOutline.setTexture(playerOutlineTexture);
    playerOutline.setPosition(0, 0);
    playerOutline.setOrigin(25, 75);
}


bool Game::sausageIntersects()
{
    return (sausage->getSprite().getGlobalBounds().intersects(sausage2->getSprite().getGlobalBounds()));
}

bool Game::forkIntersects()
{
    return (player->getSprite().getGlobalBounds().intersects(sausage->getSprite().getGlobalBounds())) || (player->getSprite().getGlobalBounds().intersects(sausage2->getSprite().getGlobalBounds()));
}



void Game::updateSausages()
{
    if(!maps[currentMap]->tiles[sausage->getRows().x][sausage->getColumns().x]->getSausagePassable() && !maps[currentMap]->tiles[sausage->getRows().y][sausage->getColumns().y]->getSausagePassable())
    {
        lostScreenIsOpened = true;
    }   
    // Sausage
    if(maps[currentMap]->tiles[sausage->getRows().x][sausage->getColumns().x]->getIsGrill())
    {
            if(sausage->getIsFacingUp()) sausage->cook(2);
            else sausage->cook(0);
    }
    if(maps[currentMap]->tiles[sausage->getRows().y][sausage->getColumns().y]->getIsGrill())
    {
            if(sausage->getIsFacingUp()) sausage->cook(3);
            else sausage->cook(1);
    }   
}

void Game::updateSausages2()
{
    if(!maps[currentMap]->tiles[sausage2->getRows().x][sausage2->getColumns().x]->getSausagePassable() && !maps[currentMap]->tiles[sausage2->getRows().y][sausage2->getColumns().y]->getSausagePassable())
    {
        lostScreenIsOpened = true;
    }
    // Sausage 2
    if(maps[currentMap]->tiles[sausage2->getRows().y][sausage2->getColumns().y]->getIsGrill())
    {
            if(sausage2->getIsFacingUp()) sausage2->cook(2);
            else sausage2->cook(0);
    }
    if(maps[currentMap]->tiles[sausage2->getRows().x][sausage2->getColumns().x]->getIsGrill())
    {
            if(sausage2->getIsFacingUp()) sausage2->cook(3);
            else sausage2->cook(1);
    }
}

void Game::winLossConditions()
{
    for(int i = 0; i < 4; i++)
    {
        if(sausage->getCookState(i) == Overcooked || sausage2->getCookState(i) == Overcooked)
        {
            lostScreenIsOpened = true;
        }
    }


    sausagesPerfectlyCooked = true;
    for(int i = 0; i < 4; i++)
    {
        if(!sausage->getCookState(i) == Cooked || !sausage2->getCookState(i) == Cooked)
        {
            sausagesPerfectlyCooked = false;
        }
    }

    if(sausagesPerfectlyCooked && player->getPosition().x == playerOutline.getPosition().x && player->getPosition().y == playerOutline.getPosition().y && player->getSprite().getRotation() == playerOutline.getRotation())
    {
        winScreenIsOpened = true;
    }


}

void Game::resetLevels()
{
    for(int i = 0; i < 10; i++)
    {
        levelIsOpened[i] = false;
    }
}

void Game::resetCurrentLevel() // Must change this function as levels are changed
{
    sausage->reset();
    sausage2->reset();
    lostScreenIsOpened = false;
    winScreenIsOpened = false;
    sausagesPerfectlyCooked = false;
    if(currentMap == 0)
    {
        player->setPosition(sf::Vector2f(225, 125));
        player->setRotation(1);
        sausage->setPosition(sf::Vector2f(125, 275));
        sausage2->setPosition(sf::Vector2f(375, 275));
    }
    else if(currentMap == 1)
    {
        player->setPosition(sf::Vector2f(275, 275));
        player->setRotation(3);
        sausage->setPosition(sf::Vector2f(225, 225));
        sausage2->setPosition(sf::Vector2f(325, 275));
    }
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
            if(ev.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            
            if(menuIsOpened)
            {
                levelSelectIsOpened = true;
                menuIsOpened = false;
            }
            else if(levelSelectIsOpened)
            {
                switch(ev.key.code)
                {
                    // --------------------- Level 1 ----------------------
                    case sf::Keyboard::Num1:
                    currentMap = 0;
                    resetLevels();
                    levelIsOpened[0] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(225, 125));
                    player->setRotation(1);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(225, 125));
                    playerOutline.setRotation(90);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(125, 275));
                    sausage->setHorizontal(false);
                    sausage2->setPosition(sf::Vector2f(375, 275));
                    sausage2->setHorizontal(true);
                    break;

                    // --------------------- Level 2 ----------------------
                    case sf::Keyboard::Num2:
                    currentMap = 1;
                    resetLevels();
                    levelIsOpened[1] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(275, 275));
                    player->setRotation(3);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(275, 275));
                    playerOutline.setRotation(270);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(225, 225));
                    sausage->setHorizontal(true);
                    sausage2->setPosition(sf::Vector2f(325, 275));
                    sausage2->setHorizontal(false);
                    break;
                }
            }
            else
            {
                switch(ev.key.code)
                {
                    case sf::Keyboard::M: // M returns to the menu
                    menuIsOpened = true;
                    resetLevels();
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    levelSelectIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    break;

                    case sf::Keyboard::L: // L returns to level select
                    menuIsOpened = false;
                    resetLevels();
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    levelSelectIsOpened = true;
                    sausagesPerfectlyCooked = false;
                    break;

                    case sf::Keyboard::R: // R restets the level
                    resetCurrentLevel();
                    break;
             
                    // ----------Player controls------------------------
                    case sf::Keyboard::W:              
                    if(!player->isHorizontal() && maps[currentMap]->tiles[player->getRow() - 1][player->getColumn()]->getPassable())
                    {
                        player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y - 50));
                        if(player->getRows().x == sausage->getRows().y && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                            updateSausages();
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                                updateSausages2();
                            }
                        }
                        else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                            updateSausages2();
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                updateSausages();
                            }
                        }
                    }
                    else if(player->isHorizontal())
                    {
                        if(player->getRotation() == 3)
                        {
                            player->setRotation(0);

                            if(player->getRows().x == sausage->getRows().y && (player->getColumns().x - 1 == sausage->getColumns().x || player->getColumns().x - 1 == sausage->getColumns().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                updateSausages();
                                if(sausageIntersects())
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                                    updateSausages2();
                                }
                                
                                if(forkIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                                    updateSausages2();
                                }
                            }
                            else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x - 1 == sausage2->getColumns().x || player->getColumns().x - 1 == sausage2->getColumns().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                    updateSausages();
                                }
                                if(forkIntersects())
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                                    updateSausages();
                                } 
                            }
                            else if(player->getRows().x == sausage->getRows().y && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                                    updateSausages2();
                                }
                            }
                            else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                                    updateSausages();
                                }
                            }
                            
                        }
                        else
                        {
                            player->setRotation(0);
                            if(player->getRows().x == sausage->getRows().y && (player->getColumns().x + 1 == sausage->getColumns().x || player->getColumns().x + 1 == sausage->getColumns().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                                    updateSausages2();
                                }
                                if(forkIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                    updateSausages2();
                                }
                            }
                            else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x + 1 == sausage2->getColumns().x || player->getColumns().x + 1 == sausage2->getColumns().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                    updateSausages();
                                }
                                if(forkIntersects())
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                    updateSausages();
                                } 
                            }
                            else if(player->getRows().x == sausage->getRows().y && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                    updateSausages2();
                                }
                            }
                            else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                    updateSausages();
                                }
                            }
                        }
                        
                    }
                    winLossConditions();
                    break;

                    case sf::Keyboard::A:               
                    if(player->isHorizontal() && maps[currentMap]->tiles[player->getRow()][player->getColumn() - 1]->getPassable())
                    {
                        player->setPosition(sf::Vector2f(player->getPosition().x - 50, player->getPosition().y));
                        
                        if(player->getColumns().x == sausage->getColumns().y && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            updateSausages();
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                updateSausages2();
                            }
                        }
                        else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            updateSausages2();
                            if(sausageIntersects())
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                updateSausages();
                            } 
                        }
                    }
                    else if(!player->isHorizontal())
                    {
                        if(player->getRotation() == 0)
                        {
                            player->setRotation(3);

                            if(player->getColumns().x == sausage->getColumns().y && (player->getRows().x - 1 == sausage->getRows().x || player->getRows().x - 1 == sausage->getRows().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                updateSausages();
                                if(sausageIntersects())
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                    updateSausages2();
                                } 
                                if(forkIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                    updateSausages2();
                                }
                            }
                            else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x - 1 == sausage2->getRows().x || player->getRows().x - 1 == sausage2->getRows().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                updateSausages2();
                                if(sausageIntersects())
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                    updateSausages();
                                } 
                                if(forkIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                    updateSausages();
                                }
                            }

                            else if(player->getColumns().x == sausage->getColumns().y && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                    updateSausages2();
                                }
                            }
                            else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                    updateSausages();
                                }
                            }
                        }
                        else
                        {
                            player->setRotation(3);

                            if(player->getColumns().x == sausage->getColumns().y && (player->getRows().x + 1 == sausage->getRows().x || player->getRows().x + 1 == sausage->getRows().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                    updateSausages2();
                                }
                                if(forkIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                                    updateSausages2();
                                }
                            }
                            else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x + 1 == sausage2->getRows().x || player->getRows().x + 1 == sausage2->getRows().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                    updateSausages();
                                }
                                if(forkIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                    updateSausages();
                                }
                            }
                            else if(player->getColumns().x == sausage->getColumns().y && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                updateSausages();
                                if(sausageIntersects())
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                                    updateSausages2();
                                } 
                            }
                            else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                    updateSausages();
                                }
                            }
                        }
                        
                        
                        
                    }
                    winLossConditions();
                    break;

                    case sf::Keyboard::S:               
                    if(!player->isHorizontal() && maps[currentMap]->tiles[player->getRow() + 1][player->getColumn()]->getPassable())
                    {
                        player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y + 50));
                        if(player->getRows().y == sausage->getRows().x && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                            updateSausages();
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                updateSausages2();
                            }
                        }
                        else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            updateSausages2();
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                updateSausages();
                            }
                        }
                    }
                    else if(player->isHorizontal()) 
                    {
                        if(player->getRotation() == 1)
                        {
                            player->setRotation(2);

                            if(player->getRows().y == sausage->getRows().x && (player->getColumns().x + 1 == sausage->getColumns().y || player->getColumns().x + 1 == sausage->getColumns().x))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                    updateSausages2();
                                }
                                if(forkIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                    updateSausages2();
                                }
                            }
                            else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x + 1 == sausage2->getColumns().y || player->getColumns().x + 1 == sausage2->getColumns().x))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                    updateSausages();
                                }
                                if(forkIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                    updateSausages();
                                }
                            }
                            else if(player->getRows().y == sausage->getRows().x && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                    updateSausages2();
                                }
                            }
                            else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                                    updateSausages();
                                }
                            }
                        }
                        else
                        {
                            player->setRotation(2);
                            if(player->getRows().y == sausage->getRows().x && (player->getColumns().x - 1 == sausage->getColumns().y || player->getColumns().x - 1 == sausage->getColumns().x))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                    updateSausages2();
                                }
                                if(forkIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                                    updateSausages2();
                                }
                            }
                            else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x - 1 == sausage2->getColumns().y || player->getColumns().x - 1 == sausage2->getColumns().x))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                updateSausages2();
                                if(sausageIntersects())
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                    updateSausages();
                                } 
                                if(forkIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                                    updateSausages();
                                }
                            }
                            else if(player->getRows().y == sausage->getRows().x && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                                    updateSausages();
                                }
                            }
                            else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                                    updateSausages();
                                }
                            }
                        }
                        
                    }
                    winLossConditions();
                    break;

                    case sf::Keyboard::D:    
                    if(player->isHorizontal() && maps[currentMap]->tiles[player->getRow()][player->getColumn() + 1]->getPassable())
                    {
                        player->setPosition(sf::Vector2f(player->getPosition().x + 50, player->getPosition().y));
                        if(player->getColumns().y == sausage->getColumns().x && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                            updateSausages();
                            if(sausageIntersects())
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                                updateSausages2();
                            } 
                        }
                        else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                            updateSausages2();
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                                updateSausages();
                            }
                        }
                    }
                    else if(!player->isHorizontal())
                    {  
                        if(player->getRotation() == 2)
                        {
                            player->setRotation(1);

                            if(player->getColumns().y == sausage->getColumns().x && (player->getRows().x + 1 == sausage->getRows().x || player->getRows().x + 1 == sausage->getRows().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y)); 
                                    updateSausages2();
                                }
                                if(forkIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50)); 
                                    updateSausages2();
                                }
                            }
                            else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x + 1 == sausage2->getRows().x || player->getRows().x + 1 == sausage2->getRows().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));  
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y)); 
                                    updateSausages();
                                }
                                if(forkIntersects())
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                    updateSausages();
                                } 

                            }
                            else if(player->getColumns().y == sausage->getColumns().x && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50)); 
                                    updateSausages2();
                                }

                            }
                            else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50)); 
                                    updateSausages();
                                }

                            }
                        }
                        else
                        {
                            player->setRotation(1);

                            if(player->getColumns().y == sausage->getColumns().x && (player->getRows().x - 1 == sausage->getRows().x || player->getRows().x - 1 == sausage->getRows().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                                    updateSausages2();
                                } 
                                if(forkIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                    updateSausages2();
                                }

                            }
                            else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x - 1 == sausage2->getRows().x || player->getRows().x - 1 == sausage2->getRows().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                                updateSausages2();   
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y)); 
                                    updateSausages();
                                }
                                if(forkIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                    updateSausages();
                                }

                            }
                            else if(player->getColumns().y == sausage->getColumns().x && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                updateSausages();
                                if(sausageIntersects()) 
                                {
                                    sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50)); 
                                    updateSausages2();
                                }

                            }
                            else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                                updateSausages2();
                                if(sausageIntersects()) 
                                {
                                    sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                                    updateSausages(); 
                                }

                            }
                        }
                    }
                    winLossConditions();
                    break;
                }
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
        window.draw(background);
        window.draw(gameTitle);
        window.draw(pressAnyButton);
    }

    if(levelSelectIsOpened)
    {
        window.draw(levelSelectBackground);
        window.draw(levelSelect);
        window.draw(levelNumbers);
    }
    
    if(levelIsOpened[0])
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

        /*
        errorFile.open("errors.txt");
        errorFile << sausage->getSprite().getOrigin().x << sausage->getSprite().getOrigin().y << sausage->getSprite().getRotation() << endl;
        errorFile.close();
        */
    }
    
    if(levelIsOpened[1])
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[1]->tiles[i][j]->getSprite());
            }
        }
        window.draw(player->getSprite());
        window.draw(sausage->getSprite());
        window.draw(sausage2->getSprite());        
    }
    
    

    if(sausagesPerfectlyCooked)
    {
        window.draw(playerOutline);
    }

    if(lostScreenIsOpened)
    {
        window.draw(lostScreen);
        window.draw(lostScreen2);
    }
    
    if(winScreenIsOpened)
    {
        window.draw(winScreen);
    }

    window.display();
}