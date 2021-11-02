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