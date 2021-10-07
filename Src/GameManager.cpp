//
// Created by valiant on 8.10.2021.
//

#include "GameManager.h"

const float MAX_ANGLE = 3.142 / 5.0; // 72 degrees

bool GameManager::SetDirection() {
    int randomValue = rand() % 10 + 1;

    if (randomValue <= 5)
        return false;
    else
        return true;
}

float GameManager::CalcAngle(float y1, float y2, int height) {
    float rely = y1 + height / 2 - y2;
    rely /= height / 2.0;   // Normalise
    return rely * MAX_ANGLE;
}
