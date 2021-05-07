# ECE-3220-Project
This is the project used for our ECE-3220 software designs class. This project contains a program that allows the user to create and store multiple Dungeons and Dragons characters. This program also allows the user to create a database of spells and items that can then be added to a character. 

# Features
When run, the program starts a text menu that will prompt the user to pick which entity (Characters, Items, or Spells) they would like to work with. After choosing which mode the user would like, they then can create a new entity, find an existing entity by its name or ID, view the entire entity list, and edit an existing entity. The character entity includes a player name, a character name, race, level, gold, ability scores, an item inventory, and a spell inventory. The character's item and spell inventories can be added to from the database of spells and items.

The system uses a singleton design pattern in order to run the menu. The Character, Item, and Spell classses all inherit an Entity class which has the name, ID, and virtual to string functions. The Entity class and EntityList class are both templated so that they work with all three subclasses. 

# How to Compile
A makefile is provided for compiling; use the make command to compile.

# How to Run
To run use "./main". This will start the Main Menu, and the menus can be traversed by typing in the number of the option you wish to select. 

# Members
Project members are Cameron Young: cky39v, Benjamin Chilson: bjc7p3, Kevin Whetsel: kqwpkz.
