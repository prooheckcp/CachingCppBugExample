/*
    Disclaimer: This is pseudocode based on real code

    Developed by: VEENSTRA SOARES, Vasco Miguel

*/
#include <iostream>
#include "Player.h"

Player player1 {};
Player player2 {};

int main() {

    player1.Damage(10);

    std::cout << player1.GetPlayerHealth().GetHealth() << "\n";
    std::cout << player2.GetPlayerHealth().GetHealth() << "\n";

    return 0;
}