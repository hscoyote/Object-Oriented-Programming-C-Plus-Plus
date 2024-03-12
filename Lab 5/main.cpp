#include <iostream>
#include "RPG.h"

using namespace std;

int main()
{
    RPG p1 = RPG("Wiz", 70, 41, 15, "mage");
    RPG p2 = RPG("Rogue", 40, 20, 30, "thief");

    //p1 stats
    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p1.getHealth(), p1.getStrength(), p1.getDefense());

    //p2 stats
    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p2.getHealth(), p2.getStrength(), p2.getDefense());

    p1.updateHealth(0);
    cout << p1.getHealth() << endl;

    p2.updateHealth(0);
    cout << p2.getHealth() << endl;

    p1.isAlive();
    p2.isAlive();
    
    return 0;
};