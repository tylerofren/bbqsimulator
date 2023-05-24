#include "Game.h"

#include <iostream>

using namespace std;


Game::Game()
{
    menuIsOpened = true;
    levelOneIsOpened = false;
    lostScreenIsOpened = false;
    
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

    // Lost screen
    lostScreen.setFont(font);
    lostScreen.setCharacterSize(75);
    lostScreen.setFillColor(sf::Color::White);
    lostScreen.setString("Lost");
    lostScreen.setOrigin(lostScreen.getLocalBounds().width / 2, lostScreen.getLocalBounds().height / 2);
    lostScreen.setPosition(250, 80);

    lostScreen2.setFont(font);
    lostScreen2.setCharacterSize(80);
    lostScreen2.setFillColor(sf::Color::Black);
    lostScreen2.setString("Lost");
    lostScreen2.setOrigin(lostScreen2.getLocalBounds().width / 2, lostScreen2.getLocalBounds().height / 2);
    lostScreen2.setPosition(250, 80);
}


void Game::initializeLevels()
{
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
    levelOne =  
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
    if(!maps[currentMap]->tiles[sausage2->getRows().x][sausage2->getColumns().x]->getSausagePassable() && !maps[currentMap]->tiles[sausage2->getRows().y][sausage2->getColumns().y]->getSausagePassable())
    {
        lostScreenIsOpened = true;
    }
    
    // Sausage
    if(maps[currentMap]->tiles[sausage->getRows().x][sausage->getColumns().x]->getIsGrill())
    {
        if(!sausage->getIsCookedOnCurrentGrill())
        {
            if(sausage->getIsFacingUp()) sausage->cook(2);
            else sausage->cook(0);
            sausage->setCookedOnCurrentGrill(true);
        }
    }
    else
    {
        sausage->setCookedOnCurrentGrill(false);
    }
    if(maps[currentMap]->tiles[sausage->getRows().y][sausage->getColumns().y]->getIsGrill())
    {
        if(!sausage->getIsCookedOnCurrentGrill())
        {
            if(sausage->getIsFacingUp()) sausage->cook(3);
            else sausage->cook(1);
            sausage->setCookedOnCurrentGrill(true);
        }
    }
    else
    {
        sausage->setCookedOnCurrentGrill(false);
    }
    // Sausage 2
    if(maps[currentMap]->tiles[sausage2->getRows().y][sausage2->getColumns().y]->getIsGrill())
    {
        if(!sausage2->getIsCookedOnCurrentGrill())
        {
            if(sausage2->getIsFacingUp()) sausage2->cook(2);
            else sausage2->cook(0);
            sausage2->setCookedOnCurrentGrill(true);
        }
    }
    else
    {
        sausage2->setCookedOnCurrentGrill(false);
    }
    if(maps[currentMap]->tiles[sausage2->getRows().x][sausage2->getColumns().x]->getIsGrill())
    {
        if(!sausage2->getIsCookedOnCurrentGrill())
        {
            if(sausage2->getIsFacingUp()) sausage2->cook(3);
            else sausage2->cook(1);
            sausage2->setCookedOnCurrentGrill(true);
        }
    }
    else
    {
        sausage2->setCookedOnCurrentGrill(false);
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
            switch(ev.key.code)
            {
                case sf::Keyboard::Escape: // Escape closes the program
                window.close();
                break;

                case sf::Keyboard::M: // M returns to the menu
                menuIsOpened = true;
                levelOneIsOpened = false;
                lostScreenIsOpened = false;
                break;

                case sf::Keyboard::Num1: // Select lvl 1
                menuIsOpened = false;
                levelOneIsOpened = true;
                lostScreenIsOpened = false;
                currentMap = 0;

                sausage->reset();
                sausage2->reset();

                // ----------- Level 1 Starting Player Positions --------------
                // Position: row/col * 50 + 25
                // Rotations: 0 = North
                // 1 = East 
                // 2 = South 
                // 3 = West
                player->setPosition(sf::Vector2f(225, 125));
                player->setRotation(1);

                // --------- Level 1 Starting Sausage Positions --------------
                sausage->setPosition(sf::Vector2f(125, 275));
                sausage->setHorizontal(false);

                sausage2->setPosition(sf::Vector2f(375, 275));
                sausage2->setHorizontal(true);
                break;

                
                // ----------Player controls------------------------
                case sf::Keyboard::W:               
                if(!player->isHorizontal() && maps[currentMap]->tiles[player->getRow() - 1][player->getColumn()]->getPassable())
                {
                    player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y - 50));
                    if(player->getRows().x == sausage->getRows().y && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                    {
                        sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                        if(sausageIntersects()) sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                    }
                    else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                    {
                        sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                        if(sausageIntersects()) sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
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
                            if(sausageIntersects())
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                            }
                            
                            if(forkIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                            }
                        }
                        else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x - 1 == sausage2->getColumns().x || player->getColumns().x - 1 == sausage2->getColumns().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                            }
                            if(forkIntersects())
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                            } 
                        }
                        else if(player->getRows().x == sausage->getRows().y && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                            }
                        }
                        else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                            }
                        }
                        
                    }
                    else
                    {
                        player->setRotation(0);
                        if(player->getRows().x == sausage->getRows().y && (player->getColumns().x + 1 == sausage->getColumns().x || player->getColumns().x + 1 == sausage->getColumns().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                            }
                            if(forkIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            }
                        }
                        else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x + 1 == sausage2->getColumns().x || player->getColumns().x + 1 == sausage2->getColumns().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                            }
                            if(forkIntersects())
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            } 
                        }
                        else if(player->getRows().x == sausage->getRows().y && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            }
                        }
                        else if(player->getRows().x == sausage2->getRows().y && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            }
                        }
                    }
                    
                }
                updateSausages();
                break;

                case sf::Keyboard::A:
                if(player->isHorizontal() && maps[currentMap]->tiles[player->getRow()][player->getColumn() - 1]->getPassable())
                {
                    player->setPosition(sf::Vector2f(player->getPosition().x - 50, player->getPosition().y));
                    if(player->getColumns().x == sausage->getColumns().y && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                    {
                        sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                        if(sausageIntersects()) 
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                        }
                    }
                    else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                    {
                        sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                        if(sausageIntersects())
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
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
                            if(sausageIntersects())
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            } 
                            if(forkIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            }
                        }
                        else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x - 1 == sausage2->getRows().x || player->getRows().x - 1 == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            if(sausageIntersects())
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            } 
                            if(forkIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                            }
                        }

                        else if(player->getColumns().x == sausage->getColumns().y && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            }
                        }
                        else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                            }
                        }
                    }
                    else
                    {
                        player->setRotation(3);

                        if(player->getColumns().x == sausage->getColumns().y && (player->getRows().x + 1 == sausage->getRows().x || player->getRows().x + 1 == sausage->getRows().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            }
                            if(forkIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                            }
                        }
                        else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x + 1 == sausage2->getRows().x || player->getRows().x + 1 == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            }
                            if(forkIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                            }
                        }
                        else if(player->getColumns().x == sausage->getColumns().y && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                            if(sausageIntersects())
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                            } 
                        }
                        else if(player->getColumns().x == sausage2->getColumns().y && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                            }
                        }
                    }
                    
                    
                    
                }
                updateSausages();
                break;

                case sf::Keyboard::S:
                if(!player->isHorizontal() && maps[currentMap]->tiles[player->getRow() + 1][player->getColumn()]->getPassable())
                {
                    player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y + 50));
                    if(player->getRows().y == sausage->getRows().x && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                    {
                        sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                        if(sausageIntersects()) 
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                        }
                    }
                    else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                    {
                        sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                        if(sausageIntersects()) 
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
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
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            }
                            if(forkIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            }
                        }
                        else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x + 1 == sausage2->getColumns().y || player->getColumns().x + 1 == sausage2->getColumns().x))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                            }
                            if(forkIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            }
                        }
                        else if(player->getRows().y == sausage->getRows().x && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            }
                        }
                        else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x - 50, sausage2->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x - 50, sausage->getPosition().y));
                            }
                        }
                    }
                    else
                    {
                        player->setRotation(2);
                        if(player->getRows().y == sausage->getRows().x && (player->getColumns().x - 1 == sausage->getColumns().y || player->getColumns().x - 1 == sausage->getColumns().x))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            }
                            if(forkIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                            }
                        }
                        else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x - 1 == sausage2->getColumns().y || player->getColumns().x - 1 == sausage2->getColumns().x))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            if(sausageIntersects())
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                            } 
                            if(forkIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                            }
                        }
                        else if(player->getRows().y == sausage->getRows().x && (player->getColumns().x == sausage->getColumns().x || player->getColumns().x == sausage->getColumns().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                            }
                        }
                        else if(player->getRows().y == sausage2->getRows().x && (player->getColumns().x == sausage2->getColumns().x || player->getColumns().x == sausage2->getColumns().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                            }
                        }
                    }
                    
                }
                updateSausages();
                break;

                case sf::Keyboard::D:
                if(player->isHorizontal() && maps[currentMap]->tiles[player->getRow()][player->getColumn() + 1]->getPassable())
                {
                    player->setPosition(sf::Vector2f(player->getPosition().x + 50, player->getPosition().y));
                    if(player->getColumns().y == sausage->getColumns().x && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                    {
                        sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                        if(sausageIntersects())
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                        } 
                    }
                    else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                    {
                        sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                        if(sausageIntersects()) 
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
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
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y)); 
                            }
                            if(forkIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50)); 
                            }
                        }
                        else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x + 1 == sausage2->getRows().x || player->getRows().x + 1 == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));  
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y)); 
                            }
                            if(forkIntersects())
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                            } 

                        }
                        else if(player->getColumns().y == sausage->getColumns().x && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50)); 
                            }

                        }
                        else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y - 50));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y - 50)); 
                            }

                        }
                    }
                    else
                    {
                        player->setRotation(1);

                        if(player->getColumns().y == sausage->getColumns().x && (player->getRows().x - 1 == sausage->getRows().x || player->getRows().x - 1 == sausage->getRows().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));
                            } 
                            if(forkIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            }

                        }
                        else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x - 1 == sausage2->getRows().x || player->getRows().x - 1 == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x + 50, sausage2->getPosition().y));   
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x + 50, sausage->getPosition().y)); 
                            }
                            if(forkIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                            }

                        }
                        else if(player->getColumns().y == sausage->getColumns().x && (player->getRows().x == sausage->getRows().x || player->getRows().x == sausage->getRows().y))
                        {
                            sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50));
                            if(sausageIntersects()) 
                            {
                                sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50)); 
                            }

                        }
                        else if(player->getColumns().y == sausage2->getColumns().x && (player->getRows().x == sausage2->getRows().x || player->getRows().x == sausage2->getRows().y))
                        {
                            sausage2->setPosition(sf::Vector2f(sausage2->getPosition().x, sausage2->getPosition().y + 50));
                            if(sausageIntersects()) 
                            {
                                sausage->setPosition(sf::Vector2f(sausage->getPosition().x, sausage->getPosition().y + 50)); 
                            }

                        }
                    }
                }
                updateSausages();
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

        
        
        

        /*
        errorFile.open("errors.txt");
        errorFile << boolalpha << sausage->getIsCookedOnCurrentGrill()  << endl;
        errorFile.close();
        */
        
       
        
        
        
    }

    if(lostScreenIsOpened)
    {
        window.draw(lostScreen2);
        window.draw(lostScreen);
    }
    
    

   



    


    window.display();
}