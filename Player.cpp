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
    // Basic damage application: directly subtract health
    Health& healthReference = this->GetPlayerHealth();
    int currentHealth = healthReference.GetHealth();

    // No bounds checking — intentionally simple
    healthReference.SetHealth(currentHealth - amount);
}

void Player::Damage(int amount, Player source) {
    // The overloaded Damage() stores the ID of the attacker that caused the damage
    // This introduces additional logic and more opportunity for incorrect memory access
    Health& healthReference = this->GetPlayerHealth();
    int* attackersList = healthReference.GetAttackersList();

    // this loop intentionally writes OUT OF BOUNDS. This corrupts our data
    for (int i = ATTACKERS_COUNTER_MAX - 1; i >= 0; i--){
        // Writing to attackersList[3] corrupts memory that does exist in the array
        attackersList[i+1] = attackersList[i];

        if (i == 0)
            continue; // Nothing to shift into index 0
    }

    // Now apply actual health damage
    this->Damage(amount);

    // Record the attacker at the front of the list.
    attackersList[0] = source.GetPlayerId();
}