


//A level exit tile, represented by 'E' in room files.
//Passable but inactive when there are enemies in the same room as 
//the player. Unpassable when a character is standing on it.
//Becomes active when there are no enemies in the same room.
//If the player character steps on an active level exit tile outside combat, 
//A new level will be generated, the player will be moved onto it and the
//previous level will be deleted.