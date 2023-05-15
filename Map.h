#include <SFML/Graphics.hpp>


#ifndef MAP_H
#define MAP_H

/*
    Makes a map using an array filled with tiles
*/


class Map
{
    const int rows;
    const int cols;

    //LEVEL 1
        // 0 - WATER
        // 1 - GROUND
        // 2 - GRILL
        // 3 - SAUSAGE
        // 4 - GRILLED SAUSAGE
        // 5 - PLAYER
        // 6 - FORK
        // 7 - SPAWN
        
        // 0 0 0 0 0
        // 0 0 0 0 0
        // 0 0 0 0 0
        // 0 0 0 0 0
        // 0 0 0 0 0
    

    int LevelOne[5][5];


    void setUpInitialState();
public: 
    Map();
        
};

















#endif