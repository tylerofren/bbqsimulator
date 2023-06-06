#include "Game.cpp"

int main()
{  
    Game game; // game

    while(game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}