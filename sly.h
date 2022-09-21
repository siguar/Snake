#pragma once
//
//  sly.h
//  snake
//
//  Created by F on 19/09/2022.
//


#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "snake.hpp"

enum patatay
{
    up      = 0,
    right   = 1,
    down    = 2,
    left    = 3
};

class Snake
{
public:
    
    Vector2D initposition();
    std::vector<Vector2D> snakemovement;
    patatay direction;
    
    Snake(WunszTablica *wunszpointer);
    
    Vector2D Move();
    void propagateSnake(std::vector<std::vector<int> > & mainTable);
    int whatblockhead();
    
    WunszTablica *wunszpointer;
    void reset();
    
    
    
    
private:
    static bool isFirst;
    static Vector2D startlocation;
    
    
};


