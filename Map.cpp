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
    errorFile.open("errors.txt");
   for(int i = 0; i < 10; i++)
   {
        for(int j = 0; j < 10; j++)
        {
            
            if(array[i][j] == 0)
            {
                tiles[i][j] = new GameTile("assets/WaterPlaceholder.png", 50.f * j, 50.f * i);
            }
            
            else // (array[i][j] == 1)
            {
                tiles[i][j] = new GameTile("assets/GroundPlaceholder.png", 50.f * j, 50.f * i);
            }

            errorFile << array[i][j];
            
        }
        errorFile << "\n";
   }
   errorFile.close();
}