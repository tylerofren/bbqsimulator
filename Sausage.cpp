#include "Sausage.h"

Sausage::Sausage()
{

}


Sausage::Sausage(float x, float y, bool hor)
{
    loadTextures();
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setOrigin(25, 75);
    position = sf::Vector2f(x, y);
    sprite.setPosition(position);
    
    if(hor)
    {
        sprite.setRotation(270);
        sprite.setPosition(position.x, position.y - 50);
    }
    horizontal = hor;

    partStates.resize(4, Raw);
    isFacingUp = true;
    cookedOnCurrentGrill = false;

}

// ------ Accessors ---------

sf::Sprite Sausage::getSprite()
{
    return sprite;
}

sf::Vector2f Sausage::getPosition()
{
    return sprite.getPosition();
}



sf::Vector2i Sausage::getRows() const
{
    if(!horizontal)
    {
        return sf::Vector2i((position.y - 25) / 50 - 1, (position.y - 25) / 50);
    }
    return sf::Vector2i((position.y - 25) / 50, (position.y - 25) / 50);
}

sf::Vector2i Sausage::getColumns() const
{
    if(horizontal)
    {
        return sf::Vector2i((position.x - 25) / 50, (position.x - 25) / 50 + 1);
    }
    return sf::Vector2i((position.x - 25) / 50, (position.x - 25) / 50);
}




// ------------ Cooking -------------

/*
Part states:
0 - Facing down, top
1 - Facing down, bottom
2 - Facing up, top
3 - Facing up, bottom

*/
void Sausage::cook(int part)
{
    if(partStates[part] == Raw) partStates[part] = Cooked;
    else partStates[part] = Overcooked;
    updateTexture();

}

void Sausage::reset()
{
    for(int i = 0; i < 4; i++)
    {
        partStates[i] = Raw;
    }
    updateTexture();
}

cookState Sausage::getCookState(int part)
{
    return partStates[part];
}

void Sausage::updateTexture()
{
    if(isFacingUp)
    {
        if(partStates[2] == Raw && partStates[3] == Raw) sprite.setTexture(texture);
        else if(partStates[2] == Cooked && partStates[3] == Raw) sprite.setTexture(texture1);
        else if(partStates[2] == Raw && partStates[3] == Cooked) sprite.setTexture(texture2);
        else if(partStates[2] == Cooked && partStates[3] == Cooked) sprite.setTexture(texture3);
        else if(partStates[2] == Overcooked && partStates[3] == Raw) sprite.setTexture(texture4);
        else if(partStates[2] == Overcooked && partStates[3] == Cooked) sprite.setTexture(texture5);
        else if(partStates[2] == Overcooked && partStates[3] == Overcooked) sprite.setTexture(texture6);
        else if(partStates[2] == Raw && partStates[3] == Overcooked) sprite.setTexture(texture7);
        else if(partStates[2] == Cooked && partStates[3] == Overcooked) sprite.setTexture(texture8);
    }
    else
    {
        if(partStates[0] == Raw && partStates[1] == Raw) sprite.setTexture(texture);
        else if(partStates[0] == Cooked && partStates[1] == Raw) sprite.setTexture(texture1);
        else if(partStates[0] == Raw && partStates[1] == Cooked) sprite.setTexture(texture2);
        else if(partStates[0] == Cooked && partStates[1] == Cooked) sprite.setTexture(texture3);
        else if(partStates[0] == Overcooked && partStates[1] == Raw) sprite.setTexture(texture4);
        else if(partStates[0] == Overcooked && partStates[1] == Cooked) sprite.setTexture(texture5);
        else if(partStates[0] == Overcooked && partStates[1] == Overcooked) sprite.setTexture(texture6);
        else if(partStates[0] == Raw && partStates[1] == Overcooked) sprite.setTexture(texture7);
        else if(partStates[0] == Cooked && partStates[1] == Overcooked) sprite.setTexture(texture8);
    }
}

void Sausage::loadTextures()
{
    if(!texture.loadFromFile("assets/sausage0.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
    if(!texture1.loadFromFile("assets/sausage1.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
    if(!texture2.loadFromFile("assets/sausage2.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
    if(!texture3.loadFromFile("assets/sausage3.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
    if(!texture4.loadFromFile("assets/sausage4.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
    if(!texture5.loadFromFile("assets/sausage5.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
    if(!texture6.loadFromFile("assets/sausage6.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
    if(!texture7.loadFromFile("assets/sausage7.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
    if(!texture8.loadFromFile("assets/sausage8.png"))
    {
        errorFile.open("errors.txt");
        errorFile << "Failed to load sausage image" << endl;
        errorFile.close();
    }
}

bool Sausage::getIsFacingUp()
{
    return isFacingUp;
}

void Sausage::flip()
{
    if(isFacingUp) isFacingUp = false;
    else isFacingUp = true;
    updateTexture();
}


bool Sausage::getIsCookedOnCurrentGrill()
{
    return cookedOnCurrentGrill;
}

void Sausage::setCookedOnCurrentGrill(bool cook)
{
    cookedOnCurrentGrill = cook;
}


















bool Sausage::isHorizontal()
{
    return horizontal;
}

// ------ Modifiers ------

void Sausage::setPosition(const sf::Vector2f pos)
{
    position = pos;
    sprite.setPosition(pos);
}

void Sausage::setHorizontal(bool hor)
{
    if(hor)
    {
        sprite.setRotation(90);
    }
    horizontal = hor;
}


////////////////////////////////////////////////////////



