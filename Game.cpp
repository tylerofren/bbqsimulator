#include "Game.h"

using namespace std;


Game::Game()
{
    initializeGame();
    initializeWindow();
    initializeFonts();
    initializeText();
}


Game::initializeGame()
{

}

Game::initializeWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(500, 500), "Game");
}

Game::initializeFonts()
{
    if(!font.loadFromFile("include/xxxxxxx.ttf"))
    {
        cout << "Failed to load font!" << end;
    }
}

Game::initializeText()
{
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
}

Game::initializeGame()
{
    /* level1 = new Level(map, player, etc)
        levels = new Level[5]
        levels[0] = level1



    */

}


Game::startGame()
{

}