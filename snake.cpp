//
//  snake.cpp
//  snake
//
//  Created by F on 15/09/2022.
//

#include "snake.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <term.h>
#include "sly.h"
//#include <>
//#include <>


WunszTablica::WunszTablica()
{
    for(int i = 0; i < PLACEWIDTH; ++i)
    {
        std::vector<int>tempvector;
        
        for (int j = 0; j < PLACEHIGHT; ++j)
        {
            if (i == /* DISABLES CODE */ (0) || i == PLACEWIDTH - 1 || j == 0 || j == PLACEHIGHT - 1)
            {
                tempvector.push_back(1);
                
            }
            else
            {
                tempvector.push_back(0);
            }
        }
        
        wunszTab.push_back(tempvector);
    }
    //Vector2D location = Apple();
    Vector2D location = Vector2D(10, 5);
    wunszTab[location.x][location.y] = 2;
    snakepointer = new Snake(this);
    Show();
    
}
void WunszTablica::mainLoop ()
{
    
    while (true)
    {
        
        Vector2D lastposition = snakepointer->Move();
        snakepointer->propagateSnake(wunszTab);
        
        wunszTab[lastposition.x][lastposition.y] = 0;
        Show();
        
    }
}

Vector2D WunszTablica::Apple()
{
 
    Vector2D vectorApples;
    vectorApples.x = rand()% (PLACEWIDTH - 3) + 1;
    vectorApples.y = rand()% (PLACEHIGHT - 3) + 1;
    
    return vectorApples;
}



void WunszTablica::Show()
{/*
    if (!cur_term)
       {
         int result;
         setupterm( NULL, STDOUT_FILENO, &result );
         if (result <= 0) return;
       }
       // const char *x = "clear";
        putp( tigetstr( (char*)"clear" ) );
   */
  
    system("clear");


    for(int i = PLACEWIDTH - 1; i >= 0; --i)
    {
        for(int j = 0; j < PLACEHIGHT; ++j)
        {
            switch (wunszTab[j][i]) {
                case 0:
                    std::cout<< " ";
                    break;
                case 1:
                    std::cout<<"+";
                    break;
                case 2:
                    std::cout<<"░";
                    break;
                case 3:
                    std::cout<<"█";
                    break;
                    
                    
                default:
                    break;
            }
            std::cout<<" ";
        }
        std::cout<< std::endl;
        
    }
    
}
