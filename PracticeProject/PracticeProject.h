#pragma once
#include "Functions.h"

void camp(StatBlock& Player) {

    while (true) {
        int x = 0;
        
        bool campFireChoice = false;
        //introduction, what would you like to do? these are your choices

        while (campFireChoice==false) {
            clear();
            printStats(Player);
            cout << "The campfire gives of a calming crackling sound\n";
            cout << "1. Upgrade weapon and rest.\n";
            cout << "2. Upgrade Armor and rest.\n";
            cout << "3. Meditate and rest.\n";
            cout << "4. Rest for tonight and prepair for another adventure at dawn.\n";
            x = cinInt(x);
            switch (x)
            {
            case 1:
                cout << "Upgrade weapon" << "\n";
                //Try upgrade weapon
                campFireChoice = upgradeWeapon(Player);
                break;
            case 2: 	cout << "Upgrade armor" << endl;
                //Try upgrade armor
                campFireChoice = upgradeArmor(Player);
                break;
            case 3: 	cout << "Meditate" << endl;
                //Try meditate
                campFireChoice = upgradeMeditate(Player);
                break;
            case 4: 	cout << "Resting" << endl;
                //Resting
                campFireChoice = true;
                Player.HP = Player.MaxHP;
                Player.MP = Player.MaxMP;
                break;
            case 9: 	cout << "Secret option. Quitting game" << endl;
                return;
                break;
            default: 	cout << "Was " << x << " in the list of options that i so graciously gave you? How difficult could pressing 1, 2, 3 or 4 be?\n";
                campFireChoice = false;
                cout << "Or is your head tired and you want to quit?\n";
                string c;
                cin >> c;
                if (c[0] == 'y' || c[0] == 'Y') {
                    return;
                }
            }
        }
        clear();
        printStats(Player);
        //choose your destination
        cout << "Choose difficulty. \n";
        cout << "1. Forest easy. \n";
        cout << "2. Forest medium. \n";
        cout << "3. Forest hard. \n";

        

        x = cinInt(x);

        bool enteredInstance = false;

        switch (x)
        {
        case 0:
            cout << "Entering Forest 0, very easy mode" << "\n";
            enteredInstance = true;
            forest(Player, x);
            break;
        case 1:
            cout << "Entering Forest 1" << "\n";
            enteredInstance = true;
            forest(Player, x);
            break;
        case 2: 	cout << "Entering Forest 2" << endl;
            enteredInstance = true;
            forest(Player, x);
            break;
        case 3: 	cout << "Entering Forest 3" << endl;
            enteredInstance = true;
            forest(Player, x);
            break;
        case 9: 	cout << "Secret option. Quitting game" << endl;
            return;
            break;
         default: 	cout <<"Was "<< x <<" in the list of options that i so graciously gave you? How difficult could pressing 1, 2 or 3 be?\n";
            enteredInstance = false;
            cout << "Or is your little head tired and you want to quit?\n";
            string c;
            cin >> c;
            if (c[0] == 'y' || c[0] == 'Y') {
                return;
            }
        }
        //forest. max 2 orcs
        // exp muliplier 1x
        // money muliplier 1x
        // 
        //cave. max 5 orcs
        // exp muliplier 2x
        // money muliplier 2x
        // 
        //orc camp. max 10 orcs
        // exp muliplier 4x
        // money muliplier 4x
        // 
        //orc demon castle. face the demon lord
        //win the game.

        if (enteredInstance) {
            cout << "You make your way back to camp. \n\n";


        }
       
    }
}

