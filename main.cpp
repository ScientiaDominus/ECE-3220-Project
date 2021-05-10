#include "EntityList.h"
#include "Armor.h"
#include "Weapon.h"
#include "System.h"

int main(){
    System* system = System::getInstance();
    system->importEntityLists();
    system->StartMenu();
}