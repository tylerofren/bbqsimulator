#include "Game.h"

Game::Game()
{
    menuIsOpened = true;
    lostScreenIsOpened = false;
    winScreenIsOpened = false;
    levelSelectIsOpened = false;
    overcookedScreenIsOpened = false;
    sausagesPerfectlyCooked = false;

    resetLevels();

    initializeWindow();

    initializePlayer();

    initializeSausages();
    
    initializeLevels();
    
    initializeText();
    
    initializeMaps();

    initializePlayerOutline();

    initializeBackground();

    initializeSounds();

    initializeStars();

    initializeMusic();
}

// ----- Initialization -----

void Game::initializeWindow()
{
    window.create(sf::VideoMode(500, 500), "BBQ Simulator");
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
    gameTitle.setString("\tBBQ\nSimulator");
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

    copyrightDisclaimer.setFont(seriousFont);
    copyrightDisclaimer.setCharacterSize(20);
    copyrightDisclaimer.setFillColor(sf::Color::White);
    copyrightDisclaimer.setString(L"© 2018 - 2023 RoastWorks");
    copyrightDisclaimer.setOrigin(copyrightDisclaimer.getLocalBounds().width / 2, copyrightDisclaimer.getLocalBounds().height / 2);
    copyrightDisclaimer.setPosition(250, 475);
    copyrightDisclaimer.setOutlineThickness(3.5);

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
    lostScreen.setPosition(220, 100);
    lostScreen.setLetterSpacing(4.5);
    lostScreen.setOutlineThickness(4.0);

    lostScreen2.setFont(roundFont);
    lostScreen2.setCharacterSize(32);
    lostScreen2.setFillColor(sf::Color::White);
    lostScreen2.setString("R to Restart\n  Z to Undo\n L to Leave");
    lostScreen2.setOrigin(lostScreen2.getLocalBounds().width / 2, lostScreen2.getLocalBounds().height / 2);
    lostScreen2.setPosition(220, 275);
    lostScreen2.setLineSpacing(1.5);
    lostScreen2.setLetterSpacing(4.0);
    lostScreen2.setOutlineThickness(3.0);

    // ---------------- Overcooked -------------
    overcookedScreen.setFont(roundFont);
    overcookedScreen.setCharacterSize(50);
    overcookedScreen.setFillColor(sf::Color::White);
    overcookedScreen.setString("Overcooked");
    overcookedScreen.setOrigin(overcookedScreen.getLocalBounds().width / 2, overcookedScreen.getLocalBounds().height / 2);
    overcookedScreen.setPosition(200, 100);
    overcookedScreen.setLetterSpacing(4.5);
    overcookedScreen.setOutlineThickness(3.0);

    // -------------- Win Screen -------------
    winScreen.setFont(roundFont);
    winScreen.setCharacterSize(50);
    winScreen.setFillColor(sf::Color::White);
    winScreen.setString("Level Complete!");
    winScreen.setOrigin(winScreen.getLocalBounds().width / 2, winScreen.getLocalBounds().height / 2);
    winScreen.setPosition(200, 80);
    winScreen.setLetterSpacing(3.0);
    winScreen.setOutlineThickness(3.0);

    winScreen2.setFont(roundFont);
    winScreen2.setCharacterSize(25);
    winScreen2.setFillColor(sf::Color::White);
    winScreen2.setString("L to Return to Level Select");
    winScreen2.setOrigin(winScreen2.getLocalBounds().width / 2, winScreen2.getLocalBounds().height / 2);
    winScreen2.setPosition(200, 250);
    winScreen2.setLetterSpacing(3.0);
    winScreen2.setOutlineThickness(2.0);
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
        5 - WATER3S
        6 - WATER4S
    */
    levels[0] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 7, 7, 0, 0, 0, 0},
        {0, 0, 0, 9, 1, 1, 9, 0, 0, 0},
        {0, 0, 7, 1, 1, 1, 1, 7, 0, 0},
        {0, 0, 7, 1, 2, 2, 1, 7, 0, 0},
        {0, 0, 7, 1, 2, 2, 1, 7, 0, 0},
        {0, 0, 7, 1, 1, 1, 1, 7, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
    levels[2] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 7, 7, 7, 0, 0, 7, 0, 0},
        {0, 7, 2, 2, 2, 9, 9, 1, 7, 0},
        {0, 7, 2, 2, 2, 1, 1, 1, 7, 0},
        {0, 7, 2, 2, 2, 1, 1, 1, 7, 0},
        {0, 7, 2, 2, 2, 9, 9, 1, 7, 0},
        {0, 0, 7, 7, 7, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    levels[3] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 7, 0, 0},
        {0, 0, 9, 1, 1, 1, 1, 1, 7, 0},
        {0, 7, 1, 1, 9, 8, 9, 1, 7, 0},
        {0, 7, 1, 9, 9, 2, 8, 1, 7, 0},
        {0, 7, 1, 8, 2, 9, 9, 1, 7, 0},
        {0, 7, 1, 9, 8, 9, 1, 1, 7, 0},
        {0, 7, 1, 1, 1, 1, 1, 9, 0, 0},
        {0, 0, 7, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    levels[4] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 7, 1, 1, 1, 1, 7, 0, 0},
        {0, 0, 7, 1, 1, 1, 2, 7, 0, 0},
        {0, 0, 7, 2, 1, 1, 1, 7, 0, 0},
        {0, 0, 7, 1, 1, 1, 1, 7, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    levels[5] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 7, 1, 1, 1, 2, 9, 0, 0},
        {0, 0, 7, 1, 1, 1, 2, 2, 7, 0},
        {0, 0, 7, 1, 1, 1, 9, 7, 0, 0},
        {0, 0, 7, 1, 2, 2, 7, 0, 0, 0},
        {0, 0, 0, 9, 2, 2, 7, 0, 0, 0},
        {0, 0, 0, 0, 7, 7, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    levels[6] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 7, 1, 1, 2, 1, 7, 0, 0},
        {0, 0, 0, 5, 1, 6, 1, 7, 0, 0},
        {0, 0, 7, 1, 2, 1, 1, 7, 0, 0},
        {0, 0, 7, 1, 1, 1, 9, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    levels[7] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 7, 7, 7, 7, 7, 7, 0, 0},
        {0, 7, 1, 1, 1, 1, 1, 1, 7, 0},
        {0, 7, 1, 1, 2, 2, 5, 1, 7, 0},
        {0, 0, 7, 9, 2, 2, 8, 1, 7, 0},
        {0, 0, 0, 0, 7, 7, 0, 7, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    levels[8] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 7, 0, 0},
        {0, 0, 7, 1, 1, 1, 1, 1, 7, 0},
        {0, 0, 7, 1, 2, 1, 1, 2, 7, 0},
        {0, 0, 7, 1, 2, 1, 1, 2, 7, 0},
        {0, 0, 7, 1, 1, 1, 1, 1, 7, 0},
        {0, 0, 0, 7, 7, 7, 7, 7, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    levels[9] =  
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 7, 2, 1, 1, 2, 7, 0, 0},
        {0, 0, 7, 2, 1, 1, 1, 7, 0, 0},
        {0, 0, 0, 5, 1, 1, 1, 7, 0, 0},
        {0, 0, 7, 1, 1, 9, 7, 0, 0, 0},
        {0, 0, 0, 7, 7, 0, 0, 0, 0, 0},
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
    for(int i = 0; i < 10; i++)
    {
        maps[i] = new Map(levels[i]);
    }
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

void Game::initializeSounds()
{
    if(!wooshBuffer.loadFromFile("assets/woosh.wav"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load woosh sound" << endl;
        errorFile.close();
    }
    woosh.setBuffer(wooshBuffer);

    if(!stepsBuffer.loadFromFile("assets/steps.wav"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load steps sound" << endl;
        errorFile.close();
    }
    steps.setBuffer(stepsBuffer);
}

void Game::initializeStars()
{
    double p = 3.14*4;
    double x = 140.0;
    double y = 265.0;
    double width = 10.0; // r

    for(int i = 0; i < 10; i++)
    {
        levelsComplete[i] = false;
        stars[i] = new sf::ConvexShape(5);
        // { (rcos(π/5k),rsin(π/5k)) ∣ k = 0,...,4 }
        stars[i]->setPoint(0, sf::Vector2f(width*cos(p/5)+x,width*sin(p/5)+y));
        stars[i]->setPoint(1, sf::Vector2f(width*cos(p/5*2)+x, width*sin(p/5*2)+y));
        stars[i]->setPoint(2, sf::Vector2f(width*cos(p/5*3)+x, width*sin(p/5*3)+y));
        stars[i]->setPoint(3, sf::Vector2f(width*cos(p/5*4)+x, width*sin(p/5*4)+y));
        stars[i]->setPoint(4, sf::Vector2f(width*cos(p/5*5)+x, width*sin(p/5*5)+y));
        stars[i]->setFillColor(sf::Color::Yellow);
        x += 59;
        // Next row
        if(i == 4)
        {
            x = 147.0;
            y += 50;
        }
        // Number 10 is wider than other numbers
        if(i == 8)
        {
            x += 14;
        }
    }
}

void Game::initializeMusic()
{
    if(!song.openFromFile("assets/song.wav"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load song sound" << endl;
        errorFile.close();
    }
    song.setLoop(true);
}

// -------------------------

bool Game::sausageIntersects()
{
    return (sausage->getSprite().getGlobalBounds().intersects(sausage2->getSprite().getGlobalBounds()));
}

bool Game::forkIntersects()
{   
    if(sausage->getDrowned())
    {
        return false;
    }
    return (player->getSprite().getGlobalBounds().intersects(sausage->getSprite().getGlobalBounds())) || (player->getSprite().getGlobalBounds().intersects(sausage2->getSprite().getGlobalBounds()));
}

void Game::updateSausages()
{  
    // Sausage
    if(maps[currentMap]->tiles[sausage->getRows().x][sausage->getColumns().x]->getIsGrill())
    {
            if(sausage->getIsFacingUp()) 
            {
                if(sausage->isHorizontal())
                {
                    sausage->cook(3);
                }
                else
                {
                    sausage->cook(2);
                }
                
            }
            else
            {
                if(sausage->isHorizontal())
                {
                    sausage->cook(1);
                }
                else
                {
                    sausage->cook(0);
                }
            }
    }
    if(maps[currentMap]->tiles[sausage->getRows().y][sausage->getColumns().y]->getIsGrill())
    {
            if(sausage->getIsFacingUp())
            {
                if(sausage->isHorizontal())
                {
                    sausage->cook(2);
                }
                else
                {
                    sausage->cook(3);
                }
            } 
            else
            {
                if(sausage->isHorizontal())
                {
                    sausage->cook(0);
                }
                else
                {
                    sausage->cook(1);
                }
            }
    }   
    
}

void Game::updateSausages2()
{
    // Sausage 2
    if(maps[currentMap]->tiles[sausage2->getRows().x][sausage2->getColumns().x]->getIsGrill())
    {
            if(sausage2->getIsFacingUp()) 
            {
                if(sausage2->isHorizontal())
                {
                    sausage2->cook(3);
                }
                else
                {
                    sausage2->cook(2);
                }
                
            }
            else
            {
                if(sausage2->isHorizontal())
                {
                    sausage2->cook(1);
                }
                else
                {
                    sausage2->cook(0);
                }
            }
    }
    if(maps[currentMap]->tiles[sausage2->getRows().y][sausage2->getColumns().y]->getIsGrill())
    {
            if(sausage2->getIsFacingUp())
            {
                if(sausage2->isHorizontal())
                {
                    sausage2->cook(2);
                }
                else
                {
                    sausage2->cook(3);
                }
            } 
            else
            {
                if(sausage2->isHorizontal())
                {
                    sausage2->cook(0);
                }
                else
                {
                    sausage2->cook(1);
                }
            }
    }
}

void Game::winLossConditions()
{
    //Two Sausage Maps
    if(currentMap != 3 && currentMap != 6 && currentMap != 9)
    {
        if((!maps[currentMap]->tiles[sausage->getRows().x][sausage->getColumns().x]->getSausagePassable() && !maps[currentMap]->tiles[sausage->getRows().y][sausage->getColumns().y]->getSausagePassable()))
        {
            sausage->drownSausage(true);
            lostScreenIsOpened = true;
        }
        if((!maps[currentMap]->tiles[sausage2->getRows().x][sausage2->getColumns().x]->getSausagePassable() && !maps[currentMap]->tiles[sausage2->getRows().y][sausage2->getColumns().y]->getSausagePassable()))
        {
            sausage2->drownSausage(true);
            lostScreenIsOpened = true;
        }

        if(!sausage->getDrowned() && !sausage2->getDrowned())
        {
            lostScreenIsOpened = false;
        }   

        overcookedScreenIsOpened = false;
        for(int i = 0; i < 4; i++)
        {
            if((sausage->getCookState(i) == Overcooked || sausage2->getCookState(i) == Overcooked) && !lostScreenIsOpened)
            {
                overcookedScreenIsOpened = true;
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

        if(sausagesPerfectlyCooked && player->getPosition().x == playerOutline.getPosition().x && player->getPosition().y == playerOutline.getPosition().y && player->getSprite().getRotation() == playerOutline.getRotation() && !overcookedScreenIsOpened && !lostScreenIsOpened)
        {
            levelsComplete[currentMap] = true;
            winScreenIsOpened = true;

        }
    }
    //One Sausage Maps
    else
    {
        if(!maps[currentMap]->tiles[sausage->getRows().x][sausage->getColumns().x]->getSausagePassable() && !maps[currentMap]->tiles[sausage->getRows().y][sausage->getColumns().y]->getSausagePassable() && !overcookedScreenIsOpened)
        {
            sausage->drownSausage(true);
            lostScreenIsOpened = true;
            
        }
        else
        {
            lostScreenIsOpened = false;
        }   

        overcookedScreenIsOpened = false;
        for(int i = 0; i < 4; i++)
        {
            if(sausage->getCookState(i) == Overcooked && !lostScreenIsOpened)
            {
                overcookedScreenIsOpened = true;
            }
        }

        sausagesPerfectlyCooked = true;
        for(int i = 0; i < 4; i++)
        {
            if(!sausage->getCookState(i) == Cooked)
            {
                sausagesPerfectlyCooked = false;
            }
        }

        if(sausagesPerfectlyCooked && player->getPosition().x == playerOutline.getPosition().x && player->getPosition().y == playerOutline.getPosition().y && player->getSprite().getRotation() == playerOutline.getRotation() && !overcookedScreenIsOpened && !lostScreenIsOpened)
        {
            levelsComplete[currentMap] = true;
            winScreenIsOpened = true;
        }
    }
}

void Game::resetLevels()
{
    for(int i = 0; i < 10; i++)
    {
        levelIsOpened[i] = false;
    }
}

void Game::resetCurrentLevel() 
{
    sausage->reset();
    sausage2->reset();
    lostScreenIsOpened = false;
    winScreenIsOpened = false;
    sausagesPerfectlyCooked = false;
    overcookedScreenIsOpened = false;
    //Level 1 reset
    if(currentMap == 0)
    {
        player->setPosition(sf::Vector2f(225, 125));
        player->setRotation(1);
        sausage->setPosition(sf::Vector2f(175, 275));
        sausage2->setPosition(sf::Vector2f(325, 275));
    }
    //Level 2 reset
    else if(currentMap == 1)
    {
        player->setPosition(sf::Vector2f(275, 275));
        player->setRotation(3);
        sausage->setPosition(sf::Vector2f(225, 225));
        sausage2->setPosition(sf::Vector2f(325, 275));
    }
    //Level 3 reset
    else if(currentMap == 2)
    {
        player->setPosition(sf::Vector2f(375, 275));
        player->setRotation(2);
        sausage->setPosition(sf::Vector2f(275, 275));
        sausage2->setPosition(sf::Vector2f(325, 275));
    }
    //Level 4 reset
    else if(currentMap == 3)
    {
        player->setPosition(sf::Vector2f(125, 325));
        player->setRotation(2);
        sausage->setPosition(sf::Vector2f(225, 125));
        sausage2->setPosition(sf::Vector2f(600, 600));
    }
    //Level 5 reset
    else if(currentMap == 4)
    {
        player->setPosition(sf::Vector2f(175, 225));
        player->setRotation(0);
        sausage->setPosition(sf::Vector2f(225, 325));
        sausage2->setPosition(sf::Vector2f(275, 225));
    }
    //Level 6 reset
    else if(currentMap == 5)
    {
        player->setPosition(sf::Vector2f(225, 275));
        player->setRotation(3);
        sausage->setPosition(sf::Vector2f(175, 225));
        sausage2->setPosition(sf::Vector2f(225, 225));
    }
    //Level 7 reset
    else if(currentMap == 6)
    {
        player->setPosition(sf::Vector2f(325, 275));
        player->setRotation(3);
        sausage->setPosition(sf::Vector2f(175, 325));
        sausage2->setPosition(sf::Vector2f(600, 600));
    }
    //Level 8 reset
    else if(currentMap == 7)
    {
        player->setPosition(sf::Vector2f(125, 225));
        player->setRotation(1);
        sausage->setPosition(sf::Vector2f(175, 325));
        sausage2->setPosition(sf::Vector2f(225, 225));
    }
    //Level 9 reset
    else if(currentMap == 8)
    {
        player->setPosition(sf::Vector2f(175, 275));
        player->setRotation(0);
        sausage->setPosition(sf::Vector2f(275, 275));
        sausage2->setPosition(sf::Vector2f(325, 275));
    }
    //Level 10 reset
    else if(currentMap == 9)
    {
        player->setPosition(sf::Vector2f(275, 275));
        player->setRotation(0);
        sausage->setPosition(sf::Vector2f(225, 225));
        sausage2->setPosition(sf::Vector2f(600, 600));
    }
}

// ----- Undo -----

void Game::resetGameStates()
{
    while(!gameStates.empty())
    {
        gameStates.pop_back();
    }

    GameState* gameState = new GameState(player->getPosition(), sausage->getPosition(), sausage2->getPosition(), player->getRotation(), sausage->getCookStates(), sausage2->getCookStates(), false, false);
    gameStates.push_back(gameState);
}

void Game::addGameState()
{
    GameState* gameState = new GameState(player->getPosition(), sausage->getPosition(), sausage2->getPosition(), player->getRotation(), sausage->getCookStates(), sausage2->getCookStates(), sausage->getDrowned(), sausage2->getDrowned()); 
    gameStates.push_back(gameState);
}

void Game::undo()
{
    if(gameStates.size() > 1)
    {
        player->setPosition(gameStates[gameStates.size() - 2]->getPlayerPosition());
        player->setRotation(gameStates[gameStates.size() - 2]->getPlayerRotation()); 
        sausage->setCookStates(gameStates[gameStates.size() - 2]->getCookStates());
        sausage2->setCookStates(gameStates[gameStates.size() - 2]->getCookStates2()); 
        sausage->drownSausage(gameStates[gameStates.size() - 2]->getSausageDrowned());
        sausage2->drownSausage(gameStates[gameStates.size() - 2]->getSausage2Drowned());
        sausage->setPosition(gameStates[gameStates.size() - 2]->getSausagePosition());
        sausage2->setPosition(gameStates[gameStates.size() - 2]->getSausage2Position());
 
        gameStates.pop_back();
    }    
}

// ----- Accessors -----

const bool Game::running() const
{
    return window.isOpen();
}

// ----- Public Functions -----

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
                    overcookedScreenIsOpened = false; 
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(225, 125));
                    player->setRotation(1);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(225, 125));
                    playerOutline.setRotation(90);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(175, 275));
                    sausage->setHorizontal(false);
                    sausage2->setPosition(sf::Vector2f(325, 275));
                    sausage2->setHorizontal(false);
                    resetGameStates();
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
                    overcookedScreenIsOpened = false;
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
                    resetGameStates();
                    break;

                    // --------------------- Level 3 ----------------------
                    case sf::Keyboard::Num3:
                    currentMap = 2;
                    resetLevels();
                    levelIsOpened[2] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    overcookedScreenIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(375, 275));
                    player->setRotation(2);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(375, 275));
                    playerOutline.setRotation(180);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(275, 275));
                    sausage->setHorizontal(false);
                    sausage2->setPosition(sf::Vector2f(325, 275));
                    sausage2->setHorizontal(false);
                    resetGameStates();
                    break;

                    // --------------------- Level 4 ----------------------
                    case sf::Keyboard::Num4:
                    currentMap = 3;
                    resetLevels();
                    levelIsOpened[3] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    overcookedScreenIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(125, 325));
                    player->setRotation(2);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(125, 325));
                    playerOutline.setRotation(180);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(225, 125));
                    sausage->setHorizontal(true);
                    sausage2->setPosition(sf::Vector2f(600, 600));
                    sausage2->setHorizontal(true);
                    resetGameStates();
                    break;

                    // --------------------- Level 5 ----------------------
                    case sf::Keyboard::Num5:
                    currentMap = 4;
                    resetLevels();
                    levelIsOpened[4] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    overcookedScreenIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(175, 225));
                    player->setRotation(0);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(175, 225));
                    playerOutline.setRotation(0);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(225, 325));
                    sausage->setHorizontal(false);
                    sausage2->setPosition(sf::Vector2f(275, 225));
                    sausage2->setHorizontal(false);
                    resetGameStates();
                    break;

                    // --------------------- Level 6 ----------------------
                    case sf::Keyboard::Num6:
                    currentMap = 5;
                    resetLevels();
                    levelIsOpened[5] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    overcookedScreenIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(225, 275));
                    player->setRotation(3);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(225, 275));
                    playerOutline.setRotation(270);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(175, 225));
                    sausage->setHorizontal(false);
                    sausage2->setPosition(sf::Vector2f(225, 225));
                    sausage2->setHorizontal(true);
                    resetGameStates();
                    break;

                    // --------------------- Level 7 ----------------------
                    case sf::Keyboard::Num7:
                    currentMap = 6;
                    resetLevels();
                    levelIsOpened[6] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    overcookedScreenIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(325, 275));
                    player->setRotation(3);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(325, 275));
                    playerOutline.setRotation(270);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(175, 325));
                    sausage->setHorizontal(false);
                    sausage2->setPosition(sf::Vector2f(600, 600));
                    sausage2->setHorizontal(true);
                    resetGameStates();
                    break;

                    // --------------------- Level 8 ----------------------
                    case sf::Keyboard::Num8:
                    currentMap = 7;
                    resetLevels();
                    levelIsOpened[7] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    overcookedScreenIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(125, 225));
                    player->setRotation(1);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(125, 225));
                    playerOutline.setRotation(90);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(175, 325));
                    sausage->setHorizontal(false);
                    sausage2->setPosition(sf::Vector2f(225, 225));
                    sausage2->setHorizontal(true);
                    resetGameStates();
                    break;

                    // --------------------- Level 9 ----------------------
                    case sf::Keyboard::Num9:
                    currentMap = 8;
                    resetLevels();
                    levelIsOpened[8] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    overcookedScreenIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(175, 275));
                    player->setRotation(0);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(175, 275));
                    playerOutline.setRotation(0);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(275, 275));
                    sausage->setHorizontal(false);
                    sausage2->setPosition(sf::Vector2f(325, 275));
                    sausage2->setHorizontal(false);
                    resetGameStates();
                    break;

                    // --------------------- Level 10 ----------------------
                    case sf::Keyboard::Num0:
                    currentMap = 9;
                    resetLevels();
                    levelIsOpened[9] = true;
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    levelSelectIsOpened = false;
                    overcookedScreenIsOpened = false;
                    sausage->reset();
                    sausage2->reset();
                    // Starting Player Position
                    player->setPosition(sf::Vector2f(275, 275));
                    player->setRotation(0);
                    // Player outline position
                    playerOutline.setPosition(sf::Vector2f(275, 275));
                    playerOutline.setRotation(0);
                    // Starting Sausage Positions
                    sausage->setPosition(sf::Vector2f(225, 225));
                    sausage->setHorizontal(false);
                    sausage2->setPosition(sf::Vector2f(600, 600));
                    sausage2->setHorizontal(false);
                    resetGameStates();
                    break;
                }
            }
            else if(!winScreenIsOpened) // During gameplay
            {
                switch(ev.key.code)
                {
                    case sf::Keyboard::M: // M returns to the menu
                    menuIsOpened = true;
                    resetLevels();
                    resetGameStates();
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    levelSelectIsOpened = false;
                    sausagesPerfectlyCooked = false;
                    overcookedScreenIsOpened = false;
                    break;

                    case sf::Keyboard::L: // L returns to level select
                    menuIsOpened = false;
                    resetLevels();
                    resetGameStates();
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    levelSelectIsOpened = true;
                    sausagesPerfectlyCooked = false;
                    overcookedScreenIsOpened = false;
                    break;

                    case sf::Keyboard::R: // R resets the level
                    resetCurrentLevel();
                    resetGameStates();
                    break;

                    case sf::Keyboard::Z:
                    undo();
                    winLossConditions();
                    break;
             
                    // ----------Player controls------------------------
                    // this sucks but i just want to finish it
                    case sf::Keyboard::W:              
                    if(!player->isHorizontal() && maps[currentMap]->tiles[player->getRow() - 1][player->getColumn()]->getPassable())
                    {
                        player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y - 50));
                        steps.play();
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
                            woosh.play();
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
                            woosh.play();
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
                    addGameState();
                    break;

                    case sf::Keyboard::A:               
                    if(player->isHorizontal() && maps[currentMap]->tiles[player->getRow()][player->getColumn() - 1]->getPassable())
                    {
                        player->setPosition(sf::Vector2f(player->getPosition().x - 50, player->getPosition().y));
                        steps.play();
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
                            woosh.play();
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
                            woosh.play();
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
                    addGameState();
                    break;

                    case sf::Keyboard::S:               
                    if(!player->isHorizontal() && maps[currentMap]->tiles[player->getRow() + 1][player->getColumn()]->getPassable())
                    {
                        player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y + 50));
                        steps.play();
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
                            woosh.play();
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
                            woosh.play();
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
                    addGameState();
                    break;

                    case sf::Keyboard::D:    
                    if(player->isHorizontal() && maps[currentMap]->tiles[player->getRow()][player->getColumn() + 1]->getPassable())
                    {
                        player->setPosition(sf::Vector2f(player->getPosition().x + 50, player->getPosition().y));
                        steps.play();
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
                            woosh.play();
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
                            woosh.play();
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
                    addGameState();
                    break;
                }
            }
            else // Win screen is opened
            {
                if(ev.key.code == sf::Keyboard::L)
                {
                    resetLevels();
                    menuIsOpened = false;
                    lostScreenIsOpened = false;
                    winScreenIsOpened = false;
                    levelSelectIsOpened = true;
                    sausagesPerfectlyCooked = false;
                    overcookedScreenIsOpened = false;
                }
            }
        }
    }
}

void Game::update() // why?
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
        window.draw(copyrightDisclaimer);
    }

    if(levelSelectIsOpened)
    {
        window.draw(levelSelectBackground);
        window.draw(levelSelect);
        window.draw(levelNumbers);
        for(int i = 0; i < 10; i++)
        {
            if(levelsComplete[i])
            {
                window.draw(*stars[i]);
            }
        }
        if(!songIsPlaying)
        {
            song.play();
            songIsPlaying = true;
        }
    }
    else
    {
        song.stop();
        songIsPlaying = false;
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
        window.draw(sausage->getSprite());
        window.draw(sausage2->getSprite());
        window.draw(player->getSprite());
        
        /*
        errorFile.open("errors.txt");
        errorFile << 
        "Sausage 1:\nCook States:\n" << sausage->getCookStates()[0] << sausage->getCookStates()[1] <<
        sausage->getCookStates()[2] << sausage->getCookStates()[3] <<  "\nRows: " << sausage->getRows().x << sausage->getRows().y
        << "\nColumns:" << sausage->getColumns().x << sausage->getColumns().y <<

        "\n\nSausage2:\nCook States:\n" << sausage2->getCookStates()[0] << sausage2->getCookStates()[1] <<
        sausage2->getCookStates()[2] << sausage2->getCookStates()[3] <<  "\nRows: " << sausage2->getRows().x << sausage2->getRows().y
        << "\nColumns:" << sausage2->getColumns().x << sausage2->getColumns().y
        <<endl;
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
        window.draw(sausage->getSprite());
        window.draw(sausage2->getSprite()); 
        window.draw(player->getSprite());  
    }

    if(levelIsOpened[2])
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[2]->tiles[i][j]->getSprite());
            }
        }
        window.draw(sausage->getSprite());
        window.draw(sausage2->getSprite());   
        window.draw(player->getSprite());
    }

    if(levelIsOpened[3])
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[3]->tiles[i][j]->getSprite());
            }
        }
        window.draw(sausage->getSprite()); 
        window.draw(player->getSprite());    
    }

    if(levelIsOpened[4])
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[4]->tiles[i][j]->getSprite());
            }
        }
        window.draw(sausage->getSprite());
        window.draw(sausage2->getSprite());  
        window.draw(player->getSprite());       
    }

    if(levelIsOpened[5])
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[5]->tiles[i][j]->getSprite());
            }
        }
        window.draw(sausage->getSprite());
        window.draw(sausage2->getSprite()); 
        window.draw(player->getSprite());       
    }

    if(levelIsOpened[6])
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[6]->tiles[i][j]->getSprite());
            }
        }
        window.draw(sausage->getSprite()); 
        window.draw(player->getSprite());       
    }

    if(levelIsOpened[7])
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[7]->tiles[i][j]->getSprite());
            }
        }
        window.draw(sausage->getSprite());
        window.draw(sausage2->getSprite());
        window.draw(player->getSprite());        
    }
    
    if(levelIsOpened[8])
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[8]->tiles[i][j]->getSprite());
            }
        }
        window.draw(sausage->getSprite());
        window.draw(sausage2->getSprite());  
        window.draw(player->getSprite());           
    }

    if(levelIsOpened[9])
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                window.draw(maps[9]->tiles[i][j]->getSprite());
            }
        }
        window.draw(sausage->getSprite()); 
        window.draw(player->getSprite());      
    }
    
    if(sausagesPerfectlyCooked && !lostScreenIsOpened && !overcookedScreenIsOpened)
    {
        window.draw(playerOutline);
    }

    if(lostScreenIsOpened && !overcookedScreenIsOpened)
    {
        window.draw(lostScreen);
        window.draw(lostScreen2);
    }

    if(overcookedScreenIsOpened && !lostScreenIsOpened)
    {
        window.draw(overcookedScreen);
        window.draw(lostScreen2);
    }
    
    if(winScreenIsOpened)
    {
        window.draw(winScreen);
        window.draw(winScreen2);
    }

    window.display();
}