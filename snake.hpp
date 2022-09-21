#pragma once
//
//  snake.hpp
//  snake
//
//  Created by F on 15/09/2022.
//
#include <vector>
#include <map>
#include <iostream>





#ifndef snake_hpp
#define snake_hpp



#include <stdio.h>

#endif /* snake_hpp */

struct Vector2D
{
    Vector2D(int startX, int startY)
    {
        x = startX;
        y = startY;
    }
    
    Vector2D()
    {
        x = 0;
        y = 0;
    }
    
    int x = 0;
    int y = 0;
};


class Snake;

const int PLACEWIDTH = 50;
const int PLACEHIGHT = 50;
class WunszTablica
{
public:
   
    WunszTablica();
    std::vector<std::vector<int> > wunszTab;
    
    void mainLoop();
    
    Snake *snakepointer;
    
    

//    jest to vector vectorów w celu pozniejszej mozliwosci przypisania wartosci nagrody do miejsca w jakim znajdzie sie wunsz
//    void WunszSize
    Vector2D Apple();
    
    void Show();
    
    
    
};

