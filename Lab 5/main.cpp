#include <iostream>
#include "RPG.h"

using namespace std;

void displayStats(RPG player1, RPG player2) {
    cout << player1.getName() << " Health: " << player1.getHealth() << endl;
    cout << player2.getName() << " Health: " << player2.getHealth() << endl;
}

void displayEnd(RPG player1, RPG player2){
    if (player1.isAlive() == true){
        cout << player1.getName() << " won! " << endl;
    } else {
        cout << player2.getName() << " won! " << endl;
    }
    
}

void gameLoop(RPG * player1, RPG * player2) {
    while(player1->isAlive()&&player2->isAlive()) {
        displayStats((*player1), (*player2));
        cout << player1->getName() << "'s turn!" << endl;
        (*player1).useSkill(player2);
        printf("---------------------------------------\n");

        displayStats((*player1), (*player2));
        cout << player2->getName() << "'s turn!" << endl;
        (*player2).useSkill(player1);
        printf("---------------------------------------\n");
    }
}

int main()
{
    RPG p1 = RPG("Wiz", 70, 45, 5, "mage");
    RPG p2 = RPG();

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;
    // RPG p1 = RPG("Wiz", 70, 41, 15, "mage");
    // RPG p2 = RPG("Rogue", 40, 20, 30, "thief");

    // //p1 stats
    // printf("%s Current Stats\n", p1.getName().c_str());
    // printf("Health: %i\t Strength: %i\t Defense: %i\n", p1.getHealth(), p1.getStrength(), p1.getDefense());

    // //p2 stats
    // printf("%s Current Stats\n", p2.getName().c_str());
    // printf("Health: %i\t Strength: %i\t Defense: %i\n", p2.getHealth(), p2.getStrength(), p2.getDefense());

    // p1.updateHealth(0);
    // cout << p1.getHealth() << endl;

    // p2.updateHealth(0);
    // cout << p2.getHealth() << endl;

    // p1.isAlive();
    // p2.isAlive();
    
    // return 0;

};
