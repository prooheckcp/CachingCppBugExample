/*
    Disclaimer: This is pseudocode based on real code

    Developed by: VEENSTRA SOARES, Vasco Miguel

*/
#include <iostream>
#include "Player.h"

Player player1 {};
Player player2 {};

int main() {
    std::cout << player1.GetPlayerHealth().GetHealth() << "\n";
    player1.Damage(10, player2);
    std::cout << player1.GetPlayerHealth().GetHealth() << "\n";

    return 0;
}