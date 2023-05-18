#include <SFML/Graphics.hpp>
#include <vector>
#include "gameTile.cpp"



#ifndef MAP_H
#define MAP_H

/*
    Makes a map using an array filled with GameTiles
*/


class Map
{
private:
    void initializeTiles(int[10][10]); 
        

public: 

    Map(int[10][10]);
    std::vector<std::vector<GameTile *>> tiles;


        
};

















#endif