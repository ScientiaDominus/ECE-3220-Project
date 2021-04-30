#include "TestItem.h"
#include "EntityList.h"
#include "DifferentItem.h"
#include "Armor.h"

int main(){

    Armor item6 = Armor("Netherite Chestplate", "Does 2 Damage to any enemy within 2 blocks when struck", 100, 1, 500, HEAVY);
    item6.longPrint();

    EntityList<Armor> armorList = EntityList<Armor>();
    armorList.addEntity(item6);

    armorList.printList();

}