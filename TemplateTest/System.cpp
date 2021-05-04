#include "System.h"

System::System(){
    itemList = new EntityList<Item*>();
    characterList = new EntityList<Character*>();
}

System::~System(){
    delete itemList;
}

void System::StartMenu(){
    bool continueOption = true;
    do{
    
        std::cout << "Main Menu. Pick and Option Below" << std::endl;
        std::cout << "\t1) Character\n\t2) Item\n\t3) Spell\n\t4) Exit" << std::endl;
        int response;
        std::cin >> response;
        switch (response){
             case 1:
                 changeMenuMode(CHARACTER);
                 EntityMenu<Character>(characterList);
                 break;
            case 2:
                changeMenuMode(ITEM);
                EntityMenu<Item>(itemList);
                break;
            // case 3:
            //     changeMenuMode(SPELL);
            //     EntityMenu<Item>(spellList);
            //     break;
        
            default:
                continueOption = false;
        }
    }while(continueOption == true);
}

template<typename E>
void System::EntityMenu(EntityList<E*>* list){
    std::cout << "Welcome to the " << menuModeString << " Entity Menu\nPlease select and option below" << std::endl;
    std::cout << "\t1) View/Edit Existing " << menuModeString << std::endl;
    std::cout << "\t2) Create New " << menuModeString << std::endl;
    std::cout << "\t3) Exit" << std::endl;
    int response;
    std::cin >> response;
    switch (response){
        case 1:
            std::cout << "Option 1" << std::endl;
            ViewEditMenu<E*>(list);
            break;
        case 2:
        std::cout << "Option 2" << std::endl;
            E::CreateMenu(list);
        default:
            return;
    }
}

template<typename E>
    void System::ViewEditMenu(EntityList<E>* list){
        std::cout << "Welcome to the View/Edit " << menuModeString << " Menu\nPlease select an option below" << std::endl;
        std::cout << "\t1) View List of Existing " << menuModeString << std::endl;
        std::cout << "\t2) Look up " << menuModeString << std::endl;
        std::cout << "\t3) Exit" << std::endl;
        int response;
        std::cin >> response;
        switch (response)
        {
        case 1:
            std::cout << "You've selected to view the list of all existing " << menuModeString << "!" << std::endl;
            std::cout << "Here are all the " << menuModeString << " stored in the database:" << std::endl;
            list->printList();
            break;
        case 2:
            SearchListMenu<E>(list);
        default:
            return;
            break;
        }
    }

    template<typename E>
    void System::SearchListMenu(EntityList<E>* list){
        std::cout << "You've selected to look up an existing " << menuModeString << "\nPlease Select an option below." << std::endl;
        std::cout << "\tSearch " << menuModeString << " by ID\n\t2) Search " << menuModeString << "by Name\n\t3) Exit" << std::endl;
        E entity;
        int response;
        std::cin >> response;
        int ID;
        std::string name;
        switch (response){
            case 1:
                std::cout << "Enter the ID: ";
                std::cin >> ID;
                entity = list->searchForEntityByID(ID);
                break;
            case 2:
                std::cout << "Enter the name: ";
                std::cin >> name;
                entity = list->searchForEntityByName(name);
                break;
            default:
                return;
        }

        std::cout << "View or Edit?" << std::endl;
        std::cout << "\t1)View" << std::endl;
        std::cout << "\t2)Edit" << std::endl;
        std::cout << "\t3)Return" << std::endl;
        std::cin >> response;
        switch(response){
            case 1:
                entity->longPrint();
                break;
            case 2:
                //entity->EditMenu();
                break;
            default:
                return;
        }

    }

    void System::changeMenuMode(MenuModeType menuMode){
        this->menuMode = menuMode;
        switch (this->menuMode){
            case CHARACTER:
                menuModeString = "Character";
                break;
            case ITEM:
                menuModeString = "Item";
                break;
            case SPELL:
                menuModeString = "Spell";
            default:
                menuModeString = "";
                break;
        }
    }