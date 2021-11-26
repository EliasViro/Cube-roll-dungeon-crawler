# Meeting Notes
In this file, you are required to take notes for your weekly meetings. 
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any


# Meeting dd.mm.2021 HH::MM

**Participants**: 
1. Member 1
2. Member 2
3. Member 3
4. Member 4 

## Summary of works
1. Member 1 
   
   Implementing the class XX. Tested the class XX. 
   Results are in `tests/<class-xx-tests>`. Resolved the identified problems.

2. Member 2

   Same as above

3. ...

## Challenges

1. The integration of UI with the monsters requires an abstract interface.
2. ...

## Actions
1. Member 1 is going to look into defining an abstract interface for monsters 
   to enable easy UI integration.
2. Member 2 is going to work with Member 1 to use abstract interface in derived 
   monster classes.
3. Member 2 is going to test the interface.
4. Member 3 is going to use ...

> Please reflect these action decisions in your git commit messages so that 
> your group members and advisor can follow the progress.

## Project status 
Short summary of current project status. 

### TODOs
1. Member 1: Write an action.
2. ...





# Meeting 30.10.2021 10::00

**Participants**: 
1. Elias
2. Atte
3. Binh
4. Selin

## Summary of works
1. Elias: Finished the project plan and the game engine related diagrams, concept art and class structure.

2. Atte: Studied SFML integration into the project and created a diagram of class relationships on the graphics side.

3. Binh: Read through the project plan.

4. Selin: Read through the project plan.

## Challenges

None at this point.

## Actions
1. Elias: Implement the character class and item base class, as well as the player cube character and start working on the player inventory and the main Game function.
2. Atte: Research and tests with graphics and sound libraries, creating the necessary project files and folders (such as SoundStorage and GraphicsStorage)
3. Binh: Implement a working dungeon generation algorithm that can create a single level randomly using the placeholder files in the RoomStorage folder. Note that it needs to have the capacity to randomly select a room file from there, even though currently each folder for different types of rooms only has one room file.
4. Selin: Start working on implementing the base classes for items, enemies and their "middleman" subclasses such as MeleeWeapon and Potion.

## Project status 
The project is absolutely barebones, however the plan has been finished.

### TODOs
Project file structure and basically everything mentioned in the ##Actions.



# Meeting 5.11.2021 17::10

**Participants**: 
1. Elias
2. Atte
3. Binh
4. Selin

## Summary of works
1. Elias: Implementing the file structure and some base classes, configured SFML.

2. Atte: Got SFML working and configured.

3. Binh: Took care of important matters.

4. Selin: Started working on MeleeWeapon class and studied some of the main base classes.

## Challenges

-Configuring SFML.
-Warnings not showing in the editor, and the code not having a compile button.

## Actions
1. Elias: Continue working on the WIP classes and fix errors with currently implemented classes.
2. Atte: Get Cmake working and implement a way to open a simple graphics window.
3. Binh: Start working on planning the implementation for the dungeon generation algorithm and read through the DungeonRoom class to get an understanding of what it does.
4. Selin: Continue working on various Item type classes.

## Project status 
Some of the main base classes are mostly implemented, but will need more work.

### TODOs
-More classes
-Getting the project to compile
-Getting errors to show, and fixing those errors
-Figuring out some class relationships
-Getting a simple graphics window to show
-Running tests on implemented classes



# Meeting 12.11.2021 17::10

**Participants**: 
1. Elias
2. Binh
3. Selin

## Summary of works
1. Elias: Implemented some Item classes, finished Character and Player classes, fixed tons of errors, created sprites for the game.

2. Atte: Worked on SFML and other graphics related stuff.

3. Binh: Implemented the basis for the DungeonLevel class.

4. Selin: Implemented the basis for some Item classes.

## Challenges

-Errors in DungeonRoom class
-Lack of time to program
-Errors in DungeonLevel class
-Git hiccups

## Actions
1. Elias: Start implementing the game engine, help Binh to refactor the DungeonLevel class, create more graphics, find sound effects.
2. Atte: Get a graphics window showing properly, implement a main menu with interactive buttons.
3. Binh: Refactor the DungeonLevel class to generate DungeonRoom objects.
4. Selin: Continue working on various Item type classes.

## Project status 
Process has been swift and most classes have been implemented, except the main game engine.

### TODOs
-Pathfinding for enemies
-Refactoring DungeonLevel
-Fixing errors in DungeonLevel & DungeonRoom.
-Implementing a working game window, accepting input and creating the game engine.




# Meeting 19.11.2021 14::00

**Participants**: 
1. Elias
2. Atte
3. Binh
4. Selin

## Summary of works
1. Elias: Created textures for the game, converted game sounds to the correct file format (OGG), added a bunch of enemy classes, debugged lots of errors and implemented a
couple of helpful functions for the main game loop.

2. Atte: Configured CMake and the debugger, created a functioning main menu screen and laid the groundwork for main game loop.

3. Binh: Fixed compilation errors related to the DungeonLevel class, added a few more rooms for testing purposes.

4. Selin: Started the work on enemy pathfinding algorithms.

## Challenges

-Problems with getting the debugger to work
-Compilation errors
-Finding appropriate game music

## Actions
1. Elias: Support role, debugging and testing some classes, implementing final missing textures, adding helper functions for the main game loop.
2. Atte: Work on the main game loop.
3. Binh: Fix the bugs in the DungeonLevel class (such as always creating 4DoorRooms)
4. Selin: Continue working on enemy pathfinding

## Project status 
Compilation errors have been fixed for now and the work on the main game loop is proceeding well. Debugger is working and the main menu interactions also work.

### TODOs
-Pathfinding fixes for enemies
-Fixing bugs in DungeonLevel
-Working on the main game loop and getting the game into a playable state



# Meeting 26.11.2021 15::00

**Participants**: 
1. Elias
2. Atte
3. Binh
4. Selin

## Summary of works
1. Elias: Created more textures for the game, debugged lots of errors and segfaults, implemented the core structure of the main game loop, playtested the game.

2. Atte: Implemented game graphics printing functions and interactive buttons and other menus.

3. Binh: Fixed bugs in the DungeonLevel class

4. Selin: Implemented enemy pathfinding

## Challenges

-Lots of segmentation faults that weren't very obvious to track down
-Tracking down bugs with item usage and cooldowns
-Refactoring loading the sprites from disk and optimizing the process of creating them

## Actions
1. Elias: Debugging and testing some classes, implementing more textures, programming the main game loop
2. Atte: Work on graphics printing functions and helping with debugging.
3. Binh: Fixed bugs in the DungeonLevel class
4. Selin: Implemented enemy pathfinding

## Project status 
The game is missing sound effects and music, and the main game loop doesn't have weapon item usage yet. Interactive inventory hasn't been done yet, but all other functionalities of the UI
have been added.

### TODOs
-Adding sound effects
-Fixing bugs
-Playtesting
-Implementing the weapon usage and interactive inventory.