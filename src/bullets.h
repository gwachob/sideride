//
//  bullets.h
//  sideride
//
//  Created by Gabriel Wachob on 4/24/21.
//


#ifndef bullets_h
#define bullets_h

#include <list>

struct Bullet {
    int positionX;
    int positionY;
    
    double velocityX;
    double velocityY;
    
    Bullet(int positionX, int positionY, double velocityX, double velocityY): positionX(positionX), positionY(positionY), velocityX(velocityX), velocityY(velocityY){}
};
#endif /* bullets_h */
