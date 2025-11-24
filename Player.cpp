//
// Created by Vasco Miguel Veenstra Soares on 24/11/2025.
//

#include "Player.h"
#include <iostream>

const int DEFAULT_LEVEL = 100;

int playerCount = 0;

Player::Player()
    :Level(DEFAULT_LEVEL)
{
    playerCount++;
    this->PlayerId = playerCount; // Very simple way of ensuring unique IDs
}

int Player::GetPlayerId() {
    return this->PlayerId;
}

int Player::GetLevel() {
    return this->Level;
}

Health& Player::GetPlayerHealth() {
    return this->HealthClass;
}

void Player::Damage(int amount) {
    Health& healthReference = this->GetPlayerHealth();
    int currentHealth = healthReference.GetHealth();

    healthReference.SetHealth(currentHealth - amount);
}

void Player::Damage(int amount, Player source) {
    Health& healthReference = this->GetPlayerHealth();
    int* attackersList = healthReference.GetAttackersList();

    std::cout << "Health:" << attackersList[3] << "\n";

    for (int i = ATTACKERS_COUNTER_MAX - 1; i >= 0; i--){
        attackersList[i+1] = attackersList[i]; // Intentional bug
        std::cout << "Changed: " << i+1<< "\n";
        if (i == 0)
            continue; // There is no value to override
    }

    this->Damage(amount);
    attackersList[0] = source.GetPlayerId();
}