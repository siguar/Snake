//
//  main.cpp
//  snake
//
//  Created by F on 19/09/2022.
//

#include "snake.hpp"
#include "sly.h"
#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main ()
{
    srand(time(nullptr));
    
    
    WunszTablica plansza;
    
    
    plansza.mainLoop();
    
    
    return (0);
};
