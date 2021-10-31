


//A basic ally that moves one tile towards the nearest enemy every turn.
//If it can't proceed towards its target due to having a wall or a pit 
//between it and the target, it will move to a direction that will have
//the shortest route to its target. Spirits will die when there are no
//enemies in a room. The spirit will also switch to the nearest target if
//its current target is further than another enemy.
//Action pattern: Attack(2)