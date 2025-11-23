/*
    Disclaimer: This is pseudocode based on real code

    Developed by: VEENSTRA SOARES, Vasco Miguel

*/
#include <iostream>
#include "Player.h"

Player player1 {};
Player player2 {};

int main() {

    std::cout << player1.GetPlayerId() << "\n";
    std::cout << player2.GetPlayerId() << "\n";

    return 0;
}