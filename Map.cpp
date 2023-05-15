#include "Map.h"


Map::Map()
{
   rows = 5;
   cols = 5;
   LevelOne = 
    {   
        {0,1,0,0,0},
        {0,1,0,0,0},
        {0,1,7,0,0},
        {0,1,0,0,0},
        {0,1,0,0,0}
    }; 
    setUpInitialState();
}

void Map::setUpInitialState()
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            //Adds water to window if tile is 0
            if(LevelOne[r][c] == 0)
            {
                WaterSpr.setPosition(50.f*c,50.f*r);
                window.draw(WaterSpr);
            }
            
            //Adds ground to window if tile is 1
            else if(LevelOne[r][c] == 1)
            {
                GroundSpr.setPosition(50.f*c,50.f*r);
                window.draw(GroundSpr);
            }

            //Adds ground to window if tile is 7
            else if(LevelOne[r][c] == 7)
            {
                SpawnSpr.setPosition(50.f*c,50.f*r);
                window.draw(SpawnSpr);
            }
            
        }
    }
}