#include "dungeonlevel.hpp"

//Represents a level of the dungeon.
//A level consists of nine rooms connected by doors on a 3 x 3 grid.

int lev = DungeonLevel::getLevel();
int startRow = (std::rand() % lev) ; // Generate rand number between 1 to level side length
int startCol = (std::rand() % lev) ; // Generate rand number between 1 to level side length

std::pair<int,int> startPos(startCol, startRow); // (col, row) due to graphics reason


DungeonLevel::DungeonLevel(int level, unsigned int depth) : level_(level), depth_(depth){}; 

// Define the boundary of the rooms
std::vector<Direction> DungeonLevel::dirsAvailable(std::pair<int, int> room) {
      std::vector<Direction> dirs;
      if (room.first < lev - 1){
        dirs.push_back(Right);
      }
      if (room.first > 0){
         dirs.push_back(Left);
      }
      if (room.second < lev - 1){
         dirs.push_back(Down);
      }
      if (room.second > 0){
         dirs.push_back(Up);
      }
      return dirs;
    }

// find the index of the room in the direction of the current room
std::pair<int, int> DungeonLevel::roomInDirection(std::pair<int, int> room, Direction direction) {
      if (direction == Up){
        return std::make_pair(room.first, room.second - 1);
      } else if (direction == Down){
        return std::make_pair(room.first, room.second + 1);
      } else if (direction == Left){
        return std::make_pair(room.first - 1, room.second);
      } else return std::make_pair(room.first + 1, room.second);
    }
// find the opposite direction
Direction DungeonLevel::opposite(Direction direction){
    if (direction == Up) return Down;
    if (direction == Down) return Up;
    if (direction == Left) return Right;
    if (direction == Right) return Left;
};

// return the room type and orientation of a room based on its exits
std::pair<RoomType, DoorOrientation> roomOrient(std::vector<Direction> exits){

    if (exits.size() == 3) {
        if (find(exits.begin(), exits.end(), Up) == exits.end()) return std::pair<3DoorRoom, South>;
        if (find(exits.begin(), exits.end(), Down) == exits.end()) return std::pair<3DoorRoom, North>;
        if (find(exits.begin(), exits.end(), Left) == exits.end()) return std::pair<3DoorRoom, East>;
        if (find(exits.begin(), exits.end(), Right) == exits.end()) return std::pair<3DoorRoom, West>;
    }
    if (exits.size() == 2){
        if (find(exits.begin(), exits.end(), Left) != exits.end() && find(exits.begin(), exits.end(), Right) != exits.end()) 
            return std::pair<2DoorRoom, Horizontal>;
        if (find(exits.begin(), exits.end(), Up) != exits.end() && find(exits.begin(), exits.end(), Down) != exits.end()) 
            return std::pair<2DoorRoom, Vertical>;
        
        if (find(exits.begin(), exits.end(), Up) != exits.end() && find(exits.begin(), exits.end(), Right) != exits.end()) 
            return std::pair<2DoorRoom, NorthEast>;
        if (find(exits.begin(), exits.end(), Up) != exits.end() && find(exits.begin(), exits.end(), Left) != exits.end()) 
            return std::pair<2DoorRoom, NorthWest>;
        
        if (find(exits.begin(), exits.end(), Down) != exits.end() && find(exits.begin(), exits.end(), Right) != exits.end()) 
            return std::pair<2DoorRoom, SouthEast>;
        if (find(exits.begin(), exits.end(), Down) != exits.end() && find(exits.begin(), exits.end(), Left) != exits.end()) 
            return std::pair<2DoorRoom, SouthWest>;
    }
    if (exits.size() == 1){
        if (exits[0] == Up) return std::pair<1DoorRoom, North>;
        if (exits[0] == Down) return std::pair<1DoorRoom, South>;
        if (exits[0] == Left) return std::pair<1DoorRoom, West>;
        if (exits[0] == Right) return std::pair<1DoorRoom, East>;
    }
    return std::pair<4DoorRoom, Omni>;
};

// Depth first search maze generator
void DungeonLevel::generateRooms(){
    std::vector<std::pair<int,int>> roomsVisited; // vector to store
    int s = level_ // side length of the level
    int n = level_ * level_; // total rooms of the level
    
    std::vector<std::vector<std::pair<RoomType, DoorOrientation>>> orient(lev, std::vector<std::pair<RoomType, DoorOrientation>> (lev)); // information of roomtype and orientation for the rooms
    
    //vector<vector<int>> vec( n , vector<int> (m));
    std::vector<std::vector<std::vector<Direction>>> exits(lev, std::vector<std::vector<Direction>> (lev)); // information on which doors the room has after maze generation

    std::vector<std::vector<std::vector<std::pair<int,int>>>> neighbors(lev, std::vector<std::vector<std::pair<int,int>> (lev)); // information on the neighbors of each room after maze generation
    
    std::vector<std::vector<DungeonRoom>> rooms(lev, std::vector<DungeonRoom> (lev)); // rooms generated after maze generation

    auto rng = std::default_random_engine {};
    
    // DFS recursion
    void visit(std::pair<int, int> room){
      roomsVisited.push_back(room);
      std::vector<Direction> dirs = DungeonLevel::dirsAvailable(room);
      std::shuffle(std::begin(dirs), std::end(dirs), rng);
      for (direction : dirs){
        std::pair<int,int> neighbor = DungeonLevel::roomInDirection(room, direction);
        if (find(roomsVisited.begin(), roomsVisited.end(), neighbor) != roomsVisited.end()){
           exits[room.second][room.first].push_back(direction);
           exits[neighbor.second][neighbor.first].push_back(DungeonLevel::opposite(direction));
           neighbors[room.second][room.first].push_back(neighbor);
           neighbors[neighbor.second][neighbor.first].push_back(room);
           visit(neighbor);
        }
      }
    }
    
    visit(startPos);
    
    // Calculate room orientations
    for (int row = 0; row < lev; row++){
        for (int col = 0; col < lev; col++){
            auto orientation = Dungeon::roomOrient(exits[col][row]);
            orient[col][row] = orientation; 
        }
    }
    

    // Initialize rooms in the level and add information of neighbors for each room
    for (int row = 0; row < lev; row++){
        for (int col = 0; col < lev; col++){
            std::pair<int,int> indexinlevel(col,row);
            RoomType roomtype = orient[col][row].first;
            DoorOrientation doororientation = orient[col][row].second;
            bool isStart = col == startPos.first && row == startPos.second;           
            DungeonRoom room(indexinlevel, depth_, roomtype, doororientation, 0, nullptr, isStart);
            rooms[col][name] = room; // add the room
        }
    }
    
    // Set the neighbors of each room
    for (int row = 0; row < lev; row++){
        for (int col = 0; col < lev; col++){
            for (index : neighbors[col][name]){
                rooms[col][row].addNeighbor(rooms[index.second][index.first]);
            }
        }
    }
    
    rooms_ = rooms; // set the rooms
}

