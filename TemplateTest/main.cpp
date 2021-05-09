#include "EntityList.h"
#include "Armor.h"
#include "Weapon.h"
#include "System.h"

int main(){

    Armor *item6 = new Armor("Netherite Chestplate", "Does 2 Damage to any enemy within 2 blocks when struck", 100, 1, 500, HEAVY);
    item6->longPrint();

    EntityList<Item *> armorList = EntityList<Item *>();
    armorList.addEntity(item6);

    Weapon *item7 = new Weapon("Diamond Sword", "Takes 10 lifepoints with every landed swing", 20, 2, 1000, SLASHING, 1);
    armorList.addEntity(item7);


    armorList.printList();
    Spell *item8 = new Spell("Hi", 1, "descripyion", 1, 1, 1);
    System* system = System::getInstance();
    system->addEntity<Item*>(ITEM, item6);
    system->addEntity<Item*>(ITEM, item7);
    system->addEntity<Spell*>(SPELL, item8);
    system->importEntityLists();
    system->StartMenu();

}