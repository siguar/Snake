//
//  sly.cpp
//  snake
//
//  Created by F on 19/09/2022.
//

#include "sly.h"
#include "snake.hpp"

bool Snake::isFirst = true;
Vector2D Snake::startlocation = Vector2D(0, 0);
Vector2D Snake::initposition()
{
    Vector2D newposition = Vector2D(0, 0);
    newposition.x = rand()% (PLACEWIDTH - 3) + 1;
    newposition.y = rand()% (PLACEHIGHT - 3) + 1;
    
    
    return newposition;
}
Snake::Snake(WunszTablica *wunszpointer2)
{
    this->wunszpointer = wunszpointer2;
    if(isFirst)
    {
        isFirst = false;
        switch (rand()%4)
        {
            case 0:
                direction = patatay::up;
                break;
            case 1:
                direction = patatay::right;
                break;
            case 2:
                direction = patatay::down;
                break;
            case 3:
                direction = patatay::left;
                break;
                
            default:
                break;
        }
        //startlocation = initposition();
        startlocation = Vector2D(5, 5);
        direction = patatay::right;
        snakemovement.push_back(startlocation);
    }
}

Vector2D Snake::Move()
{
    Vector2D lastelement = snakemovement.back();

    for (int i = snakemovement.size() - 1; i >= 1; --i)
    {
        snakemovement[i] = snakemovement[i - 1];
    }
    switch (whatblockhead()) {
        case 1:
            reset();
            break;
        case 2:
        {
            snakemovement.push_back(lastelement);
            Vector2D appleLocation = wunszpointer->Apple();
            wunszpointer->wunszTab[appleLocation.x][appleLocation.y] = 2;
            break;
        }
        case 3:
            reset();
            break;
            
//        default:
//            break;
    }
    switch (direction)
    {
        case up:
            snakemovement[0].y += 1;
            break;
        case right:
            snakemovement[0].x += 1;
            break;
        case down:
            snakemovement[0].y -= 1;
            break;
        case left:
            snakemovement[0].x -= 1;
            break;
            
        default:
            break;
    }
    
    
    
    return lastelement;
}
void Snake::propagateSnake(std::vector<std::vector<int> > & mainTable)
{
    for (int i = 0; i < snakemovement.size(); ++i)
    {
        mainTable[snakemovement[i].x][snakemovement[i].y] = 3;
        
    }
}
int Snake::whatblockhead()
{
    switch (direction)
    {
        case up:
            return wunszpointer->wunszTab[snakemovement[0].x][snakemovement[0].y + 1];
            break;
        case right:
            return wunszpointer->wunszTab[snakemovement[0].x + 1][snakemovement[0].y];
            break;
        case down:
            return wunszpointer->wunszTab[snakemovement[0].x][snakemovement[0].y - 1];
            break;
        case left:
            return wunszpointer->wunszTab[snakemovement[0].x - 1][snakemovement[0].y];
            break;
            
        default:
            break;
    }
    
   
};
void Snake::reset()
{
    wunszpointer->wunszTab;
    for (int i = 0; i < PLACEWIDTH; ++i)
    {
        for (int j = 0; j < PLACEHIGHT; ++j)
        {
            if (wunszpointer->wunszTab[i][j] == 3)
                wunszpointer->wunszTab[i][j] = 0;
            
        }
    }
    snakemovement.clear();
    snakemovement.push_back(startlocation);
    
}
