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
    void rotateTile(int, int, std::vector<std::vector<int>>);
    void rotateTileCorner(int, int, std::vector<std::vector<int>>);
    ofstream errorFile;
public: 
    // ----- Constructors -----
    Map();
    Map(std::vector<std::vector<int>>);
    // ----- Arrays -----
    GameTile* tiles[10][10];
};

#endif