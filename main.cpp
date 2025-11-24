/*
    This is pseudocode modeled after real-world production code.
    It is intentionally simplified so it can serve as a learning
    environment for experimenting with breakpoints, stepping through
    execution, and understanding how memory corruption bugs behave.

     The main idea is to give you a controlled scenario where:
        - A seemingly harmless function call corrupts internal state
        - The bug is not immediately obvious from reading the code
        - Breakpoints and step-by-step debugging become essential tools
          to trace the exact moment where memory goes bad
        - You can observe how corrupted memory propagates and affects
          unrelated logic (in this case, player health)

    Developed by: VEENSTRA SOARES, Vasco Miguel
*/
#include <iostream>
#include "Player.h"

Player player1 {};
Player player2 {};

int main() {
    // Player 1 health before taking damage: expected 100
    std::cout << "Health Before Damage: " << player1.GetPlayerHealth().GetHealth() << "\n";
    // Apply damage to Player 1, originating from Player 2.
    // Due to a hidden memory corruption bug, this unexpectedly
    // sets Player 1's health to 0 instead of reducing it by 10.
    player1.Damage(10, player2);
    // Player 1 health after taking damage: output will be 0.
    // The goal is to debug why this occurs, using breakpoints to
    // track where state is corrupted during the Damage() call.
    std::cout << "Health After Damage:"  << player1.GetPlayerHealth().GetHealth() << "\n";

    return 0;
}