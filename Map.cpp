#include "Map.h"

// ----- Constructors -----

Map::Map()
{

}

Map::Map(std::vector<std::vector<int>> array)
{
    initializeTiles(array);
}

// ----- Private Functions -----

void Map::initializeTiles(std::vector<std::vector<int>> array) 
{
    /*
        0 - WATER
        1 - GROUND
        2 - GRILL
        3 - SAUSAGE
        4 - PLAYER
        5 - SPAWN
    */
   for(int i = 0; i < 10; i++)
   {
        for(int j = 0; j < 10; j++)
        {
            
            if(array[i][j] == 1)
            {
                tiles[i][j] = new GameTile("assets/grass1.png", 50.f * j, 50.f * i, true, true, false);
            }
            else if(array[i][j] == 3)
            {
                tiles[i][j] = new GameTile("assets/grass4.png", 50.f * j, 50.f * i, true, true, false);
            }
            else if(array[i][j] == 2)
            {
                tiles[i][j] = new GameTile("assets/grill.png", 50.f * j, 50.f * i, false, true, true);
            }
            else if(array[i][j] == 5)
            {
                tiles[i][j] = new GameTile("assets/water3S.png", 50.f * j, 50.f * i, false, false, false);
                rotateTile3S(i, j, array);
            }
            else if(array[i][j] == 7)
            {
                tiles[i][j] = new GameTile("assets/water1S.png", 50.f * j, 50.f * i, false, false, false);
                rotateTile(i, j, array);
            }
            else if(array[i][j] == 9)
            {
                tiles[i][j] = new GameTile("assets/water2SC.png", 50.f * j, 50.f * i, false, false, false);
                rotateTileCorner(i, j, array);
            }           
            else if(array[i][j] == 8)
            {
                tiles[i][j] = new GameTile("assets/water2S.png", 50.f * j, 50.f * i, false, false, false);
                rotateTile(i, j, array);
            }
            else if(array[i][j] == 6)
            {
                tiles[i][j] = new GameTile("assets/water4S.png", 50.f * j, 50.f * i, false, false, false);
            }
            else 
            {
                tiles[i][j] = new GameTile("assets/water0S.png", 50.f * j, 50.f * i, false, false, false);
            }
        }
   }
}

void Map::rotateTile(int i, int j, std::vector<std::vector<int>> array) // instead of finding where the grass is, find the water :O
{
    if(array[i][j + 1] == 1 || array[i][j + 1] == 2 || array[i][j + 1] == 3)
    {
        tiles[i][j]->getSprite().rotate(180);
        tiles[i][j]->getSprite().move(sf::Vector2f(50, 50));
    }
    else if(array[i + 1][j] == 1 || array[i + 1][j] == 2 || array[i + 1][j] == 3)
    {
        tiles[i][j]->getSprite().rotate(270);
        tiles[i][j]->getSprite().move(sf::Vector2f(0, 50));
    }
    else if(array[i - 1][j] == 1 || array[i - 1][j] == 2 || array[i - 1][j] == 3)
    {
        tiles[i][j]->getSprite().rotate(90);
        tiles[i][j]->getSprite().move(sf::Vector2f(50, 0));
    }
}

void Map::rotateTileCorner(int i, int j, std::vector<std::vector<int>> array)
{
    if((array[i][j + 1] == 1 && array[i + 1][j] == 1) || (array[i][j + 1] == 2 && array[i + 1][j] == 2) || (array[i][j + 1] == 2 && array[i + 1][j] == 1) || (array[i][j + 1] == 1 && array[i + 1][j] == 2))
    {
        tiles[i][j]->getSprite().rotate(270);
        tiles[i][j]->getSprite().move(sf::Vector2f(0, 50));
    }
    else if((array[i - 1][j] == 1 && array[i][j - 1] == 1) || (array[i - 1][j] == 2 && array[i][j - 1] == 2) || (array[i - 1][j] == 2 && array[i][j - 1] == 1) || (array[i - 1][j] == 1 && array[i][j - 1] == 2))
    {
        tiles[i][j]->getSprite().rotate(90);
        tiles[i][j]->getSprite().move(sf::Vector2f(50, 0));
    }
    else if((array[i - 1][j] == 1 && array[i][j + 1] == 1) || (array[i - 1][j] == 2 && array[i][j + 1] == 2) || (array[i - 1][j] == 2 && array[i][j + 1] == 1) || (array[i - 1][j] == 1 && array[i][j + 1] == 2))
    {
        tiles[i][j]->getSprite().rotate(180);
        tiles[i][j]->getSprite().move(sf::Vector2f(50, 50));
    }
}

void Map::rotateTile3S(int i, int j, std::vector<std::vector<int>> array)
{
    if(array[i][j + 1] == 0)
    {
        tiles[i][j]->getSprite().rotate(180);
        tiles[i][j]->getSprite().move(sf::Vector2f(50, 50));
    }
    else if(array[i + 1][j] == 0 || array[i + 1][j] == 8)
    {
        tiles[i][j]->getSprite().rotate(270);
        tiles[i][j]->getSprite().move(sf::Vector2f(0, 50));
    }
    else if(array[i - 1][j] == 0)
    {
        tiles[i][j]->getSprite().rotate(90);
        tiles[i][j]->getSprite().move(sf::Vector2f(50, 0));
    }
}