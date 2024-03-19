#include "RPG.h"
#include <iostream>


RPG::RPG()
{
    name = "NPC";
    health = 100;
    strength = 10; 
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry"; 
}

RPG::RPG(string name, int health, int strength, int defense, string type)
{
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    setSkills();

}

string RPG::getName() const 
{
    return name;
}

int RPG::getHealth() const
{
    return health;
}

int RPG::getStrength() const
{
    return strength;
}

int RPG::getDefense() const
{   
    return defense;
}

/**
 * @brief sets the skills based on the RPG's role
 * 
 * 
*/
void RPG::setSkills() {
    if (type == "mage"){
        skills[0] = "fire";
        skills[1] = "thunder";
    } else if (type == "thief"){
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if(type == "archer"){
        skills[0] = "parry";
        skills[1] = "crossbow attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

/**
 * @brief Prints along the lines of NAME used SKILL on OPPONENT
 * 
 * @param skill
 * @param opponent
*/
void RPG::printAction(string skill, RPG opponent){
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

/**
 * @brief updates health into new_health
 * 
 * @param new_health
*/
void RPG::updateHealth(int new_health){
    health = new_health;
}




/**
* @brief returns whether health is greater than 0
*
* @return true
* @return false
*/
bool RPG::isAlive() const {
   bool isAlive = health > 0;
   return isAlive; 
}

//attack decreases the opponents health by (strength- opponents defense)

void RPG::attack(RPG * opponent){
    int opp_health = (*opponent).getHealth();
    int opp_def = (*opponent).getDefense();

    if (strength - opp_def > 0) {
        int new_health =opp_health - (strength - opp_def);
        (*opponent).updateHealth(new_health);
    } else {
        int new_health = opp_health - 0;
        (*opponent).updateHealth(new_health);
    }


// old code for ^^^^
//     if ((strength - (*opponent).defense) > 0 ){
//         (*opponent).health = (*opponent).health - (strength - (*opponent).defense);
//     } else {
//         (*opponent).health = (*opponent).health - 0;
//     }

//     (*opponent).updateHealth((*opponent).health);
// }

}

void RPG::useSkill(RPG * opponent){
    for(int i=0; i < SKILL_SIZE; i++){
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    //int created
    int chosen_skill_index;

    //prompts the user to choose their skill
    printf("Choose a skill to use: Enter 0 or 1\n");

    //takes the user input for chosen_skill_index
    cin >> chosen_skill_index;

    //chosen skill assigned to a string
    string chosen_skill = skills[chosen_skill_index];

    printAction(chosen_skill, *opponent);
    attack(opponent);

}

