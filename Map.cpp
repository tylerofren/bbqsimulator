#include "Map.h"

Map::Map()
{

}

Map::Map(std::vector<std::vector<int>> array)
{
    initializeTiles(array);
}


// Creates a vector of GameTiles using the array
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
                tiles[i][j] = new GameTile("assets/GrassV3.png", 50.f * j, 50.f * i, true, true, false);
            }
            else if(array[i][j] == 2)
            {
                tiles[i][j] = new GameTile("assets/grill.png", 50.f * j, 50.f * i, false, true, true);
            }
            else if(array[i][j] == 5)
            {
                tiles[i][j] = new GameTile("assets/SpawnPlaceholder.png", 50.f * j, 50.f * i, true, true, false);
            }

            else if(array[i][j] == 7)
            {
                tiles[i][j] = new GameTile("assets/Water1S.png", 50.f * j, 50.f * i, false, false, false);
                rotateTile(i, j, array);
            }

            else if(array[i][j] == 9)
            {
                tiles[i][j] = new GameTile("assets/Water2SC.png", 50.f * j, 50.f * i, false, false, false);
                rotateTileCorner(i, j, array);
            }
            
            
            else 
            {
                tiles[i][j] = new GameTile("assets/Water0S.png", 50.f * j, 50.f * i, false, false, false);
            }

            
        }

   }

}

void Map::rotateTile(int i, int j, std::vector<std::vector<int>> array)
{

    if(array[i][j + 1] == 1 || array[i][j + 1] == 2)
    {
        tiles[i][j]->getSprite().rotate(180);
        tiles[i][j]->getSprite().move(sf::Vector2f(50, 50));
    }
    else if(array[i + 1][j] == 1 || array[i + 1][j] == 2)
    {
        tiles[i][j]->getSprite().rotate(270);
        tiles[i][j]->getSprite().move(sf::Vector2f(0, 50));
    }
    else if(array[i - 1][j] == 1 || array[i - 1][j] == 2)
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