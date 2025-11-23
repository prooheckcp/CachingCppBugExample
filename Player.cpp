//
// Created by Vasco Miguel Veenstra Soares on 24/11/2025.
//

#include "Player.h"

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

Health Player::GetPlayerHealth() {
    return this->HealthClass;
}

void Player::Damage(int amount) {
    Health healthReference = this->GetPlayerHealth();

    int currentHealth = healthReference.GetHealth();

    healthReference.SetHealth(currentHealth - amount);
}

void Player::Damage(int amount, Player source) {

}