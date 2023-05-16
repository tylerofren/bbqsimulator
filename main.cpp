#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>






using namespace std;




int main()
{
    
    

    

    
    



    
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color(255, 255, 255));
        
        

        
        window.display();

    }

    





    return 0;
}