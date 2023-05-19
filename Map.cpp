#include "Map.h"

Map::Map()
{

}

Map::Map(std::vector<std::vector<int>> array, int x, int y, int r)
{
    initializeTiles(array);
    player = new Player(50.f * x, 50.f * y, r);
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
                tiles[i][j] = new GameTile("assets/GroundPlaceholder.png", 50.f * j, 50.f * i);
            }
            else if(array[i][j] == 2)
            {
                tiles[i][j] = new GameTile("assets/grill.png", 50.f * j, 50.f * i);
            }
            else if(array[i][j] == 5)
            {
                tiles[i][j] = new GameTile("assets/SpawnPlaceholder.png", 50.f * j, 50.f * i);
            }
            
            
            else 
            {
                tiles[i][j] = new GameTile("assets/water.png", 50.f * j, 50.f * i);
            }

            
        }

   }

}

Player* Map::getPlayer()
{
    return player;
}