#include "../src/DungeonGeneration/dungeonroom.hpp"
#include <utility>
#include <iostream>

std::pair<int,int> joku = std::make_pair(1,1);

auto lol = DungeonRoom(joku, 1, _1DoorRoom, North, nullptr, false);

std::cout << lol.GetIndexInLevel() << " <-- this should be 1."<<std::endl;