#include "../src/DungeonGeneration/dungeontile.hpp"
#include <utility>
#include <iostream>

auto joku = DungeonTile(TileType::Wall, 1, 2);
std::cout << joku.GetXCoord() << " <-- this should be 1." << std::endl;