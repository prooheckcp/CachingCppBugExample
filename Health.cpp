//
// Created by Vasco Miguel Veenstra Soares on 24/11/2025.
//

#include "Health.h"
#include <algorithm>

const int DEFAULT_HEALTH = 100;

Health::Health():
    AttackersList {0, 0 ,0},
    CurrentHealth(DEFAULT_HEALTH),
    MaxHealth(DEFAULT_HEALTH)
{};

void Health::SetHealth(int newAmount){
    if (newAmount == this->GetHealth())
        return;

    // Updates our health
    this->CurrentHealth = std::clamp(newAmount, 0, this->GetMaxHealth());
}

int Health::GetHealth() {
    return this->CurrentHealth;
}

int Health::GetMaxHealth() {
    return this->MaxHealth;
}