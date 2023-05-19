#include <SFML/Graphics.hpp>
#include <vector>
#include "gameTile.cpp"
#include "Player.cpp"



#ifndef MAP_H
#define MAP_H

/*
    Makes a map using an array filled with GameTiles
*/


class Map
{
private:
    void initializeTiles(std::vector<std::vector<int>>); 
    ofstream errorFile;

public: 
    Map();

    Map(std::vector<std::vector<int>>);
    GameTile* tiles[10][10];




        
};

















#endif