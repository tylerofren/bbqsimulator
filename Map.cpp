#include "Map.h"


Map::Map(int array[10][10])
{
    initializeTiles(array);
}


// Creates a vector of GameTiles using the array
void Map::initializeTiles(int array[10][10]) 
{
    tiles.clear();
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(array[i][j] == 0)
            {
                tiles[i].push_back(new GameTile("assets/WaterPlaceholder.png", 50.f * i, 50.f * j));
            }
            
            else if(array[i][j] == 1)
            {
                tiles[i].push_back(new GameTile("assets/GroundPlaceholder.png", 50.f * i, 50.f * j));
            }
        }
    }
}



/*Sets Water Texture #0
    sf::Texture WaterTexture;
    if(!WaterTexture.loadFromFile("include\\WaterPlaceholder.png"))
    {
        cout << "failed to load image" << endl;
        exit(1);
    }
    sf::Sprite WaterSpr;
    WaterSpr.setTexture(WaterTexture);

    
    //Sets Ground Texture #1
    sf::Texture GroundTexture;
    if(!GroundTexture.loadFromFile("include\\GroundPlaceholder.png"))
    {
        cout << "failed to load image" << endl;
        exit(1);
    }
    sf::Sprite GroundSpr;
    GroundSpr.setTexture(GroundTexture);
    

    //Sets Spawn Texture #7
    sf::Texture SpawnTexture;
    if(!SpawnTexture.loadFromFile("include\\SpawnPlaceholder.png"))
    {
        cout << "failed to load image" << endl;
        exit(1);
    }
    sf::Sprite SpawnSpr;
    SpawnSpr.setTexture(SpawnTexture);
    */