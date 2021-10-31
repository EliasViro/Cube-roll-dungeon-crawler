


//Represents a room of a level.
//A room consists of 256 tiles on a 16 x 16 grid.
//A room holds information about its type, a list of Tile objects it containts
//and has different constructors for different types of rooms depending on
//how many doors a room has The constructor will also have a 50% chance
//of mirroring the room when it is generated, and will then rotate the
//room text file until doors of the room are in appropriate locations.
//The last room of a level will get a level exit when all enemies are
//defeated.