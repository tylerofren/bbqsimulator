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
    void initializeTiles(std::vector<std::vector<int>>); 
    ofstream errorFile;
    void rotateTile(int, int, std::vector<std::vector<int>>);
    void rotateTileCorner(int, int, std::vector<std::vector<int>>);

public: 
    Map();

    Map(std::vector<std::vector<int>>);
    GameTile* tiles[10][10];




        
};

















#endif