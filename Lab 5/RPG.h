#ifndef RPG_H
#define RPG_H

#include <string>

using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:
        //constructors
        RPG();
        RPG(string name, int health, int strength, int defense, string type);
        
        void setSkills(); 
        void printAction(string, RPG);
        void updateHealth(int);
        //^^ possibly add "new_health", ask about it
        void attack(RPG *);
        void useSkill(RPG *);
        //ask about asterisk

        bool isAlive() const;
        string getName() const;
        int getHealth() const;
        int getStrength() const;
        int getDefense() const; 
    private:
        string name;
        int health ;
        int strength;
        int defense;
        string typ;
        string type; // warrior, mage, thief, archer
        string skills[SKILL_SIZE];
};
#endif 

/**
 * unused functions - 
 * all private functions are in use
 * attack.(RPG) is not implemented in RPG.CPP
 * useSkill(RPG) is not implemented in RPG.CPP
 * 
*/