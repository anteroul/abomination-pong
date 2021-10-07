//
// Created by valiant on 8.10.2021.
//

#ifndef SIGMAENGINE_GAMEMANAGER_H
#define SIGMAENGINE_GAMEMANAGER_H

#include "cmath"

class GameManager {
public:
    static bool SetDirection();
    static float CalcAngle(float y1, float y2, int height);
};


#endif //SIGMAENGINE_GAMEMANAGER_H
