#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Map.cpp"

#ifndef LEVEL_H
#define LEVEL_H

class Level
{
private:

bool endGame;




public:

Level(Map map);

void run();
void update();
void render();

bool getEndGame();

};


















#endif