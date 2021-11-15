#include "../src/DungeonGeneration/dungeontile.hpp"
#include <utility>
#include <iostream>
#include <string>

void Test() {
    auto joku = DungeonTile(TileType::Wall, 1, 2);
    std::cout << std::to_string(joku.GetXCoord()) << " <-- this should be 1." << std::endl;
}