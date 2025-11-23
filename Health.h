//
// Created by Vasco Miguel Veenstra Soares on 20/11/2025.
//

#ifndef CACHINGCPPBUGEXAMPLE_HEALTH_H
#define CACHINGCPPBUGEXAMPLE_HEALTH_H


#define ATTACKERS_COUNTER_MAX 3

class Health {
private:
    int AttackersList[ATTACKERS_COUNTER_MAX];
    int CurrentHealth;
    int MaxHealth;
public:
    Health();
    void SetHealth(int);
    int GetHealth();
    int GetMaxHealth();
};


#endif //CACHINGCPPBUGEXAMPLE_HEALTH_H
