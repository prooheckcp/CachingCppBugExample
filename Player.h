//
// Created by Vasco Miguel Veenstra Soares on 24/11/2025.
//

#ifndef CACHINGCPPBUGEXAMPLE_PLAYER_H
#define CACHINGCPPBUGEXAMPLE_PLAYER_H

#include "Health.h"

class Player {

public:
private:
    int Level;
    int PlayerId;
    Health HealthClass;
public:
    Player(); // Constructor
    Health GetPlayerHealth();

    void Damage(int);
    void Damage(int, Player);

    int GetLevel();
    int GetPlayerId();
};


#endif //CACHINGCPPBUGEXAMPLE_PLAYER_H
