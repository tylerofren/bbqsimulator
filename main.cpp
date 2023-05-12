#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>



using namespace std;


const int rows = 5;
const int cols = 5;

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "Stephens Sausage Roll");

    

    //Sets Water Texture #0
    sf::Texture WaterTexture;
    if(!WaterTexture.loadFromFile("C:\\Users\\1207318\\Desktop\\Final-Project\\include\\WaterPlaceholder.png"))
    {
        cout << "failed to load image" << endl;
        exit(1);
    }
    sf::Sprite WaterSpr;
    WaterSpr.setTexture(WaterTexture);

    
    //Sets Ground Texture #1
    sf::Texture GroundTexture;
    if(!GroundTexture.loadFromFile("C:\\Users\\1207318\\Desktop\\Final-Project\\include\\GroundPlaceholder.png"))
    {
        cout << "failed to load image" << endl;
        exit(1);
    }
    sf::Sprite GroundSpr;
    GroundSpr.setTexture(GroundTexture);
    
    



    
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
            {0,1,0,0,0},
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


                
            }
        }
        window.display();

    }

    





    return 0;
}