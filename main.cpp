#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>



using namespace std;


const int rows = 5;
const int cols = 5;

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Game");

    

    //Sets Water Texture #0
    sf::Texture WaterTexture;
    if(!WaterTexture.loadFromFile("include\\WaterPlaceholder.png"))
    {
        cout << "failed to load image" << endl;
        exit(1);
    }
    sf::Sprite WaterSpr;
    WaterSpr.setTexture(WaterTexture);

    
    //Sets Ground Texture #1
    sf::Texture GroundTexture;
    if(!GroundTexture.loadFromFile("include\\GroundPlaceholder.png"))
    {
        cout << "failed to load image" << endl;
        exit(1);
    }
    sf::Sprite GroundSpr;
    GroundSpr.setTexture(GroundTexture);
    

    //Sets Spawn Texture #7
    sf::Texture SpawnTexture;
    if(!SpawnTexture.loadFromFile("include\\SpawnPlaceholder.png"))
    {
        cout << "failed to load image" << endl;
        exit(1);
    }
    sf::Sprite SpawnSpr;
    SpawnSpr.setTexture(SpawnTexture);
    



    
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color(255, 255, 255));
        
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

        int MapArray[5][5] = 
        {   
            {0,1,0,0,0},
            {0,1,0,0,0},
            {0,1,7,0,0},
            {0,1,0,0,0},
            {0,1,0,0,0}
        };


        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c <cols; c++)
            {
                //Adds water to window if tile is 0
                if(MapArray[r][c]==0)
                {
                    WaterSpr.setPosition(50.f*c,50.f*r);
                    window.draw(WaterSpr);
                }
                
                //Adds ground to window if tile is 1
                else if(MapArray[r][c]==1)
                {
                    GroundSpr.setPosition(50.f*c,50.f*r);
                    window.draw(GroundSpr);
                }

                //Adds ground to window if tile is 7
                else if(MapArray[r][c]==7)
                {
                    SpawnSpr.setPosition(50.f*c,50.f*r);
                    window.draw(SpawnSpr);
                }
                
            }
        }
        window.display();

    }

    





    return 0;
}