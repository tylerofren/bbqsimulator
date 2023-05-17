#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Game.cpp"






using namespace std;




int main()
{
    Game game;

    

    

    




    
    while(game.running())
    {
        game.update();

        game.render();
    }

    





    return 0;
}