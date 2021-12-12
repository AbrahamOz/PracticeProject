
#include "PracticeProject.h"


void clear();

struct StatBlock;



int main() {
    //{"name", currentHP, currentMP, weapon, armor, gold, exp, maxHP, maxMP}
    //{"placeholder", 24, 3, 0, 0, 2, 0, 24, 3}

    StatBlock Player = {"placeholder", 1, 3, 0, 0, 5, 0, 24, 3}; 
    StatBlock* pPlayer = &Player;

    cout << "What is your name, adventurer? \n";
    cin >> Player.name;
    Sleep(500);
    clear();


    camp(*pPlayer);

    return 0;
}



