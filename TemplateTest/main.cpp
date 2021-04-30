#include "TestItem.h"
#include "EntityList.h"
#include "DifferentItem.h"

int main(){
    TestItem item1 = TestItem("Star Wars", 1);
    TestItem item2 = TestItem("Star Trek", 2);
    TestItem item3 = TestItem("Infinity War", 3);

    EntityList<TestItem> movieList = EntityList<TestItem>();
    movieList.addEntity(item1);
    movieList.addEntity(item2);
    movieList.addEntity(item3);

    movieList.printList();

    DifferentItem item4 = DifferentItem("Cat", 45);
    DifferentItem item5 = DifferentItem("Dog", 98);

    EntityList<DifferentItem> animalList = EntityList<DifferentItem>();
    animalList.addEntity(item4);
    animalList.addEntity(item5);

    animalList.printList();

}