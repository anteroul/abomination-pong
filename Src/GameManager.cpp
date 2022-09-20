//
// Created by valiant on 8.10.2021.
//

#include "GameManager.h"

const float MAX_ANGLE = 3.142 / 5.0; // 72 degrees

bool GameManager::SetDirection() {
    int randomValue = rand() % 10 + 1;

    return randomValue > 5;
}