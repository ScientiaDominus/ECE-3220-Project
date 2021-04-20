#include "System.h"

void System::addItem(const Item &item)
{
    try
    {
        std::vector<Item>::iterator iter;
        for(iter=itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if(iter->ID_() == item.ID_())
            {
                throw std::string("Exception: This item already exists in the vector");
            }
        }
        itemVector.emplace_back(item);
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;
    }
}
void System::addSpell(const Spell &spell)
{
    try
    {
        std::vector<Spell>::iterator iter;
        for(iter=spellVector.begin(); iter != spellVector.end(); iter++)
        {
            if(iter->get_spellID() == spell.get_spellID())
            {
                throw std::string("Exception: This spell already exists in the vector");
            }
        }
        itemVector.emplace_back(spell);
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;
    }
}
void System::addCharacter(const Character &character)
{
    try
    {
        std::vector<Character>::iterator iter;
        for(iter=characterVector.begin(); iter != characterVector.end(); iter++)
        {
            if(iter->get_character_id() == character.get_character_id())
            {
                throw std::string("Exception: This character already exists in the vector");
            }
        }
        itemVector.emplace_back(character);
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Character* System::getCharacter(std::string name)
{
    try
    {
        std::vector<Character>::iterator iter;

        for(iter = characterVector.begin(); iter != characterVector.end(); iter++)
        {
            if(iter->get_character_name() == name)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Character not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Item* System::getItem(std::string name)
{
    try
    {
        std::vector<Item>::iterator iter;

        for(iter = itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if(iter->Name_() == name)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Item not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Spell* System::getSpell(std::string name)
{
    try
    {
        std::vector<Spell>::iterator iter;

        for(iter = spellVector.begin(); iter != spellVector.end(); iter++)
        {
            if(iter->get_spellName() == name)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Spell not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}
Character* System::getCharacterByID(int charID)
{
    try
    {
        std::vector<Character>::iterator iter;

        for(iter = characterVector.begin(); iter != characterVector.end(); iter++)
        {
            if(iter->get_character_id() == charID)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Character not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Item* System::getItemByID(int itemID)
{
    try
    {
        std::vector<Item>::iterator iter;

        for(iter = itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if(iter->ID_() == itemID)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Item not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Spell* System::getSpellByID(int spellID)
{
    try
    {
        std::vector<Spell>::iterator iter;

        for(iter = spellVector.begin(); iter != spellVector.end(); iter++)
        {
            if(iter->get_spellID() == spellID)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Spell not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}