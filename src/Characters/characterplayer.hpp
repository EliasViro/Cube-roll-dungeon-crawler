


//The character that represents the player on the game board.
//Moving will roll the player inventory along with the cube.
//After moving attempts to use the item on the top inventory tile
//of the player cube.

//Cube[0] == UP
//Cube[1] == N
//Cube[2] == E
//Cube[3] == W
//Cube[4] == S
//Cube[5] == BOTTOM

/*
Before each movement:
TempCube = Cube

Movement up:
Cube[0] = TempCube[4]
Cube[1] = TempCube[0]
Cube[2] = TempCube[2]
Cube[3] = TempCube[3]
Cube[4] = TempCube[5]
Cube[5] = TempCube[1]

Movement down:
Cube[0] = TempCube[1]
Cube[1] = TempCube[5]
Cube[2] = TempCube[2]
Cube[3] = TempCube[3]
Cube[4] = TempCube[0]
Cube[5] = TempCube[4]

Movement right:
Cube[0] = TempCube[2]
Cube[1] = TempCube[1]
Cube[2] = TempCube[0]
Cube[3] = TempCube[5]
Cube[4] = TempCube[4]
Cube[5] = TempCube[3]

Movement left:
Cube[0] = TempCube[3]
Cube[1] = TempCube[4]
Cube[2] = TempCube[5]
Cube[3] = TempCube[0]
Cube[4] = TempCube[1]
Cube[5] = TempCube[2]
*/