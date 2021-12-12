
#include <iostream>
#include <stdio.h>
//#include <string.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <typeinfo>
#include<math.h>
using namespace std;

void clear();
struct StatBlock;
void createOrcs(int numberOfOrcs, StatBlock* PorkerStatBlock, int difficulty);
string weaponName(int playerWeapon);
int weapondamage(int playerWeapon);
string armorName(int playerArmor);
bool armorDefence(int playerArmor);
void physicalAttack(int weaponType, StatBlock& Character);
void lootingCorpses(StatBlock& Character, StatBlock* orcCorpses, int numberOfOrcs);
void forest(StatBlock& Player);
void printStats(StatBlock Player);
bool upgradeWeapon(StatBlock& Player);
bool upgradeArmor(StatBlock& Player);
bool upgradeMeditate(StatBlock& Player);



void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

struct StatBlock {
    string name;
    int HP;
    int MP;
    int weapon;
    int armor;
    int money;
    int experience;
    int MaxHP;
    int MaxMP;
}Characters;

void printStats(StatBlock Player) {
    cout << "------------------------------\n";
    cout << "---your name: " << Player.name << "\n";
    cout << "---your HP: " << Player.HP << "\n";
    cout << "---your MP: " << Player.MP << "\n";
    cout << "---your Weapon: " << weaponName(Player.weapon) << "\n";
    cout << "---your Armor: " << armorName(Player.armor) << "\n";
    cout << "---your money: " << Player.money << "\n";
    cout << "---your experience: " << Player.experience << "\n";
    cout << "------------------------------\n";
}

int cinInt(int x) {
    cin.clear();
    cin.ignore(256, '\n');
    cin >> x;
    //clear();
    while (cin.fail()) {
        cout << "Use numbers.\n\n" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> x;
        //clear();
        if (cin.fail()) {
            cout << "Use a number...\n\n" << std::endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> x;
            //clear();
            if (cin.fail()) {
                cout << "Try a number!\n\n" << std::endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> x;
                //clear();
                if (cin.fail()) {
                    cout << "...press 1, 2 or 3\n" << std::endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> x;
                    //clear();
                    if (cin.fail()) {
                        cout << "What is the meaning of life? \nIs it:\nA - a 9mm apirin?\nB - Justin Beaver? Or \nC - Jesus Christ? \n";
                        cin.clear();
                        cin.ignore(256, '\n');
                        string c;
                        cin >> c;
                        //clear();
                        if (c == "a" || c == "A" || c == "b" || c == "B" || c == "c" || c == "C") {
                            cout << "Wrong...";
                            system("pause");
                            clear();
                            cout << "1, 2 or 3\n\n" << std::endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> x;
                            //clear();
                        }
                        else {
                            cout << "Correct, they would all shorten your lifespan. You get to keep playing!\n";
                            system("pause");
                            //clear();
                            cout << "1, 2 or 3\n\n" << std::endl;
                            cin.clear();
                            cin.ignore(256, '\n');
                            cin >> x;
                            //clear();
                        }
                    }
                }
            }
        }
    }
    return x;
}


bool upgradeWeapon(StatBlock& Player) {
    if (Player.money >= 5+ Player.weapon) {
        cout << "It costs " << 5+ Player.weapon << " gold to upgrade. Are you sure you want to do that?\n";
        string c;
        cin >> c;
        if (c[0] == 'y' || c[0] == 'Y') {
            Player.weapon = Player.weapon + 1;
            Player.money = Player.money - 5- Player.weapon;
            cout << "You have upgraded your weapon! \n";
            Player.HP = Player.MaxHP;
            Player.MP = Player.MaxMP;
            Sleep(5000);
            return true;
        }
        else { return false; }
    }
    else {
        cout << "You dont have enough gold for that!\n It costs " << 5 + Player.weapon << " gold to upgrade.\n";
        Sleep(5000);
        return false;
    }
}

bool upgradeArmor(StatBlock& Player) {
    if (Player.money >= 5+ Player.armor) {
        cout << "It costs " << 5+ Player.armor << " gold to upgrade. Are you sure you want to do that?\n";
        string c;
        cin >> c;
        if (c[0] == 'y' || c[0] == 'Y') {
            Player.armor = Player.armor + 1;
            Player.money = Player.money - 5 - Player.armor;
            cout << "You have upgraded your armor! \n";
            Player.HP = Player.MaxHP;
            Player.MP = Player.MaxMP;
            Sleep(5000);
            return true;
        }
        else { return false; }
    }
    else {
        cout << "You dont have enough gold for that!\n It costs " << 5 + Player.armor << " gold to upgrade.\n";
        Sleep(5000);
        return false;
    }
}

bool upgradeMeditate(StatBlock& Player) {
    if (Player.money >= 5+ Player.MaxMP) {
        cout << "It costs " << 5+ Player.MaxMP << " gold to Meditate. Are you sure you want to do that?\n";
        string c;
        cin >> c;
        if (c[0] == 'y' || c[0] == 'Y') {
            Player.MaxMP = Player.MaxMP + 3;
            Player.money = Player.money - 5- Player.MaxMP;
            cout << "You have condensed your Mana! \n";
            Player.HP = Player.MaxHP;
            Player.MP = Player.MaxMP;
            Sleep(5000);
            return true;
        }
        else { return false; }
    }
    else {
        cout << "You dont have enough gold for that!\n It costs " << 5 + Player.MaxMP << " gold to Meditate.\n";
        Sleep(5000);
        return false;
    }
}

void createOrcs(int numberOfOrcs, StatBlock *PorkerStatBlock, int difficulty) {

    

    for (int i = 0; i < numberOfOrcs; i++) {



        srand(time(0));
        int HPOfOrcs = rand() % 4* difficulty + 6;
        int weaponOfOrcs = rand() % 2* difficulty + 0;
        int armorOfOrcs = rand() % 2*difficulty + 0;
        int moneyOfOrcs = rand() % 2 * difficulty + 1 * difficulty;
        if (difficulty == 0) { moneyOfOrcs = 1; }
        int expOfOrcs = rand() % 2 * difficulty + 1 * difficulty;

        PorkerStatBlock[i] = { "Orc" + to_string(i + 1), HPOfOrcs, 3, weaponOfOrcs, armorOfOrcs,moneyOfOrcs,expOfOrcs,HPOfOrcs,3 };

        cout << "------------------------------\n";
        //cout << "---Orc ref: " << &PorkerStatBlock[i] << "\n";
        cout << "---Orc name: " << PorkerStatBlock[i].name << "\n";
        cout << "---Orc HP: " << PorkerStatBlock[i].HP << "\n";
        cout << "---your MP: " << PorkerStatBlock[i].MP << "\n";
        cout << "---Orc Weapon: " << weaponName(PorkerStatBlock[i].weapon) << "\n";
        cout << "---Orc Armor: " << armorName(PorkerStatBlock[i].armor) << "\n";
        cout << "------------------------------\n\n\n\n";
        system("pause");
        cout << "\n\n\n\n";
        Sleep(200);
    }
}

string weaponName(int playerWeapon) {
    //returns name of weapon

    //1 broken sword
    //2 Sword
    //3 Longsword
    //4 Battlehammer
    //5 Leviathan Axe
    //6 Mjölnir
    //7 Mothers Slipper 

    //Any added weapon in the weaponarray[] will add +d2 damage to the newly added weapon
    string waeponarray[] = { "broken sword 1d4","Sword 1d6","Longsword 1d8","Battlehammer 1d10","Leviathan Axe 1d12","Mjolnir 1d14","Mothers Slipper 1d16","1d18","1d20","1d22","1d24","1d26","1d28","1d30","1d32","1d34","1d36","1d38","1d40 -last weapon" };

    
    return waeponarray[playerWeapon];
}

int weapondamage(int playerWeapon) {
    // takes in weapon tier and randomizes damage, returns damage.

    //0 broken sword 1d4
    //1 Sword 1d6
    //2 Longsword 1d8
    //3 Battlehammer 1d10
    //4 Leviathan Axe 1d12
    //5 Mjölnir 1d14
    //6 Mothers Slipper 1d16

    int weapon = playerWeapon * 2 - playerWeapon + 3;

    srand(time(NULL));
    int damage = rand() % weapon + 1;

    return damage;
}

string armorName(int playerArmor) {
    //returns name of armor

    //1 Rusty armor
    //2 Leather armor
    //3 Studded leather armor
    //4 Scale mail
    //5 Plate mail
    //6 Adamantite armor
    //7 Quantum apron 

    string armorarray[] = { "Rusty armor","Leather armor","Studded leather armor","Scale mail","Plate mail","Adamantite armor","Quantum apron","Diminishing Return 8","Diminishing Return 9","Diminishing Return 10 -last armor"};


    return armorarray[playerArmor];
}

bool armorDefence(int playerArmor) {
    // takes in armor tier and randomizes chance to get hit, returns true if hit.
    

    double z = -0.5 * pow(playerArmor, 2) + 10 * playerArmor;
    int x = 70 - z;
    //int x = 80 - (10 + 10 * playerArmor);
    //0,15*log(x) + 10;
    //double x = -0.5 * pow(x, 2) + 10 * x ;
    cout << "Chance that the attack will hit is " << x << "%\n";
    //cout << "Chance that the attack will land a hit is temporarily 100%\n";
    srand(time(NULL));
    int y = rand() % 100 + 1;
    //int y = rand() % 20 + 1; // temporary value, all attacks hit.

 

    //int armor = playerArmor * 2 - playerArmor + 3;

    //srand(time(NULL));
    //int defence = rand() % armor + 1;

    return (y < x) ? true : false;
}


//Takes in weaponType and the Character StatBlocks that is being attacked.
void physicalAttack(int weaponType, StatBlock& Character) {

    cout << Character.name << "s Armor: " << armorName(Character.armor) << "\n";

    if (armorDefence(Character.armor)) {
        int damage = weapondamage(weaponType);
        cout << Character.name << " is hit for " << damage << " damage!\n";
        Character.HP = Character.HP - damage;
        //Sleep(3000);
        if (Character.HP <= 0) {
            cout << Character.name << " has died-------------------------------------------------------------\n\n\n";
            system("pause");
            cout << "\n\n\n\n";
            Sleep(200);
            return;
        }
        else {
            cout << Character.name << "s remaining HP is " << Character.HP << ". \n\n\n";
            system("pause");
            cout << "\n\n\n\n";
            Sleep(200);
            return;
        }
    }
    else {
        cout << Character.name << " has blocked the attack!\n\n\n";
        system("pause");
        cout << "\n\n\n\n";
        Sleep(200);
        return;
    }
}

void lootingCorpses(StatBlock& Character, StatBlock *orcCorpses, int numberOfOrcs) {

    cout << "You search for corpses and find " << numberOfOrcs << ".\n\n";

    for (int i = 0; i < numberOfOrcs; i++) {
        cout << orcCorpses[i].name << " had  " << orcCorpses[i].money << " coins.\n";
        Character.money = Character.money + orcCorpses[i].money;
        Character.experience = Character.experience + orcCorpses[i].experience;
    }
    cout << "\nYou took whatever you could find, you have " << Character.money << " coins in your pouch.\n";
    cout << "You have " << Character.experience << " experience point.\n";
    system("pause");
    cout << "\n\n\n\n";
    Sleep(200);

}


void forest(StatBlock& Player, int difficulty)
{
    
cout << "The sun is rising and it is time to hunt orcs. You stand up refreshed with weapon in hand and armor in place. \n You head towards the battlefield...\n";
Sleep(1000);
cout << "Time for blood";
Sleep(1000);
clear();
//Sleep(2000);



    //random number of orcs. max 2 in Forest.
    StatBlock* pPlayer = &Player;
    srand(time(NULL));
    int numberOfOrcs = rand() % 2* difficulty + 1;

    StatBlock* PorkerStatBlock = new StatBlock[numberOfOrcs];
    createOrcs(numberOfOrcs, PorkerStatBlock, difficulty);


    cout << "You search the forest for orcs and come across " << numberOfOrcs << " of them. You are spotted. \n PREPAIR YOURSELF!!! \n";



    // när alla Porker har attackerat ska Player attackera, loopa tills alla Porkers eller Player HP<=0
    //denna loop ska kolla Porker antal, While loopa genom Porkers, IF Porker[i].HP > 0 attackera Player, Player ska attackera Porker[i]


    int i = 0;

    while (i <= numberOfOrcs) {

        if (PorkerStatBlock[i].HP > 0 && i < numberOfOrcs) {
            cout << PorkerStatBlock[i].name << " is attacking you!\n";
            physicalAttack(PorkerStatBlock[i].weapon, *pPlayer);


            if (Player.HP <= 0) {

                cout << "You wake up in front of a campfire. \nSomeone healed all your wounds.\n";
                cout << "Your savior took half your gold and left before you woke up.\n";
                Player.money = Player.money / 2;
                cout << "---your money: " << Player.money << "\n\n\n";
                system("pause");
                cout << "\n\n\n\n";
                Sleep(200);

                //cout << "Deleting orcs now: \n";
                //cout << "Deleting PorkerStatBlock[], " << &PorkerStatBlock << "\n";
                delete[] PorkerStatBlock;
                //cout << "Delete[] success \n";
                PorkerStatBlock = NULL;
                //cout << "Setting prt PorkerStatBlock = NULL, success \n";
                clear();
                return;

            }

        }

        //attack orcs if all orcs have finished their turn
        if (i == numberOfOrcs - 1 && PorkerStatBlock[i].HP >= 1) {
            //attack Porker here. attackera PorkerStatBlock[0] om den har HP>0 annars attackera PorkerStatBlock[0+1]

            //variiabel för vilken orc som ska attackeras
            int orcToAttack = 0;

            //om orcen som ska attackeras är mindre än den sista orcen && orc HP är mindre än 0. Välj nästa orc orcToAttack++
            while (orcToAttack <= numberOfOrcs - 1 && PorkerStatBlock[orcToAttack].HP <= 0) {
                orcToAttack++;
            }
            StatBlock* pPorcer = &PorkerStatBlock[orcToAttack];
            cout << "You are facing " << PorkerStatBlock[orcToAttack].name << "!\n";
            cout << "1. Attack with " << weaponName(Player.weapon) << "!\n";
            cout << "2. Attack with " << Player.weapon << "!\n";
            cout << "3. Attack with " << Player.weapon << "!\n";
            physicalAttack(Player.weapon, *pPorcer);

            i = 0;

        }
        else if (i < numberOfOrcs && PorkerStatBlock[numberOfOrcs - 1].HP >= 1)
        {
            //if this enemy is dead and the last enemy is alive
            i++;
            //cout << "Attacking next orc, " << PorkerStatBlock[i].name << " is already dead. \n";
        }
        else
        {
            cout << "\n\n\nNo Orcs left to kill. \nLooting the corpses...\n\n\n";

            lootingCorpses(Player, PorkerStatBlock, numberOfOrcs);

            //gets out of the loop
            i = numberOfOrcs + 1;
        }


    }

    //cout << "Deleting orcs now: \n";
    //cout << "Deleting PorkerStatBlock[], " << &PorkerStatBlock << "\n";
    delete[] PorkerStatBlock;
    //cout << "Delete[] success \n";
    PorkerStatBlock = NULL;
    //cout << "Setting prt PorkerStatBlock = NULL, success \n";
    return;

}
