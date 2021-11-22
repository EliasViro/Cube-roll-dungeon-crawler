#include "dungeonlevel.hpp"



// Outside DungeonLevel class helper functions 

// Define the boundary of the rooms
std::vector<Direction> DirsAvailable(std::pair<int, int> room, int sidelength) {
      std::vector<Direction> dirs;
      if (room.first < sidelength - 1){
        dirs.push_back(Right);
      }
      if (room.first > 0){
         dirs.push_back(Left);
      }
      if (room.second < sidelength - 1){
         dirs.push_back(Down);
      }
      if (room.second > 0){
         dirs.push_back(Up);
      }
      return dirs;
    }

// find the index of the room in the direction of the current room
std::pair<int, int> RoomInDirection(std::pair<int, int> room, Direction direction) {
      if (direction == Up){
        return std::make_pair(room.first, room.second - 1);
      } else if (direction == Down){
        return std::make_pair(room.first, room.second + 1);
      } else if (direction == Left){
        return std::make_pair(room.first - 1, room.second);
      } else return std::make_pair(room.first + 1, room.second);
    }

// find the opposite direction
Direction Opposite(Direction direction) {
    if (direction == Up) return Down;
    else if (direction == Down) return Up;
    else if (direction == Left) return Right;
    else return Left;
}

// return the room type and orientation of a room based on its exits
std::pair<RoomType, DoorOrientation> RoomOrient(std::vector<Direction> exits){

    if (exits.size() == 3) {
        if (find(exits.begin(), exits.end(), Up) == exits.end()) return std::make_pair(_3DoorRoom, South);
        if (find(exits.begin(), exits.end(), Down) == exits.end()) return std::make_pair(_3DoorRoom, North);
        if (find(exits.begin(), exits.end(), Left) == exits.end()) return std::make_pair(_3DoorRoom, East);
        if (find(exits.begin(), exits.end(), Right) == exits.end()) return std::make_pair(_3DoorRoom, West);
    }
    if (exits.size() == 2){
        if (find(exits.begin(), exits.end(), Left) != exits.end() && find(exits.begin(), exits.end(), Right) != exits.end()) 
            return std::make_pair(_2DoorRoomOpposite, Horizontal);
        if (find(exits.begin(), exits.end(), Up) != exits.end() && find(exits.begin(), exits.end(), Down) != exits.end()) 
            return std::make_pair(_2DoorRoomOpposite, Vertical);
        
        if (find(exits.begin(), exits.end(), Up) != exits.end() && find(exits.begin(), exits.end(), Right) != exits.end()) 
            return std::make_pair(_2DoorRoomCorner, NorthEast);
        if (find(exits.begin(), exits.end(), Up) != exits.end() && find(exits.begin(), exits.end(), Left) != exits.end()) 
            return std::make_pair(_2DoorRoomCorner, NorthWest);
        
        if (find(exits.begin(), exits.end(), Down) != exits.end() && find(exits.begin(), exits.end(), Right) != exits.end()) 
            return std::make_pair(_2DoorRoomCorner, SouthEast);
        if (find(exits.begin(), exits.end(), Down) != exits.end() && find(exits.begin(), exits.end(), Left) != exits.end()) 
            return std::make_pair(_2DoorRoomCorner, SouthWest);
    }
    if (exits.size() == 1){
        if (exits[0] == Up) return std::make_pair(_1DoorRoom, North);
        if (exits[0] == Down) return std::make_pair(_1DoorRoom, South);
        if (exits[0] == Left) return std::make_pair(_1DoorRoom, West);
        if (exits[0] == Right) return std::make_pair(_1DoorRoom, East);
    }
    return std::make_pair(_4DoorRoom, Omni);
};

// DFS recursion
void Visit(std::pair<int, int>& room, int sidelength,
    std::vector<std::pair<int,int>> roomsVisited,
    std::vector<std::vector<std::pair<RoomType, DoorOrientation>>>& orient,
    std::vector<std::vector<std::vector<Direction>>> exits,
    std::vector<std::vector<std::vector<std::pair<int,int>>>> neighbors,
    std::vector<std::vector<DungeonRoom*>> rooms) {
    auto rng = std::default_random_engine {};
        roomsVisited.push_back(room);
        std::vector<Direction> dirs = DirsAvailable(room, sidelength);
        std::shuffle(std::begin(dirs), std::end(dirs), rng);
        for (auto direction : dirs) {
            std::pair<int,int> neighbor = RoomInDirection(room, direction);
            if (find(roomsVisited.begin(), roomsVisited.end(), neighbor) != roomsVisited.end()){
                exits[room.second][room.first].push_back(direction);
                exits[neighbor.second][neighbor.first].push_back(Opposite(direction));
                neighbors[room.second][room.first].push_back(neighbor);
                neighbors[neighbor.second][neighbor.first].push_back(room);
                Visit(neighbor, sidelength, roomsVisited, orient, exits, neighbors, rooms);
            }
        }
    }

// Depth first search maze generator
std::vector<std::vector<DungeonRoom*>> GenerateRooms(int sidelength, std::pair<int,int> startPos) {
    std::vector<std::pair<int,int>> roomsVisited; // vector to store
    int s = sidelength; // side length of the level
    int n = sidelength * sidelength; // total rooms of the sidelength
    
    std::vector<std::vector<std::pair<RoomType, DoorOrientation>>> orient(sidelength, std::vector<std::pair<RoomType, DoorOrientation>> (sidelength)); // information of roomtype and orientation for the rooms
    
    std::vector<std::vector<std::vector<Direction>>> exits(sidelength, std::vector<std::vector<Direction>> (sidelength)); // information on which doors the room has after maze generation

    std::vector<std::vector<std::vector<std::pair<int,int>>>> neighbors(sidelength, std::vector<std::vector<std::pair<int,int>>> (sidelength)); // information on the neighbors of each room after maze generation
    
    std::vector<std::vector<DungeonRoom*>> rooms(sidelength, std::vector<DungeonRoom*> (sidelength)); // rooms generated after maze generation

    Visit(startPos, sidelength, roomsVisited, orient, exits, neighbors, rooms);
    
    // Calculate room orientations
    std::vector<std::pair<RoomType, DoorOrientation>> tempvector;  
    for (int row = 0; row < sidelength; row++){
        for (int col = 0; col < sidelength; col++){
            tempvector.push_back(RoomOrient(exits[col][row])); 
        }
        orient.push_back(tempvector);
        tempvector.clear();
    }
    

    // Initialize rooms in the level and add information of neighbors for each room
    std::vector<DungeonRoom*> tempvector2;
    for (int row = 0; row < sidelength; row++){
        for (int col = 0; col < sidelength; col++){
            auto indexinlevel = std::make_pair(col,row);
            RoomType roomtype = orient[col][row].first;
            DoorOrientation doororientation = orient[col][row].second;
            bool isStart = (col == startPos.first && row == startPos.second);           
            auto room = new DungeonRoom(indexinlevel, roomtype, doororientation, nullptr, isStart);
            tempvector2.push_back(room);
        }
        rooms.push_back(tempvector2);
        tempvector2.clear();
    }
    
    // Set the neighbors of each room
    for (int row = 0; row < sidelength; row++) {
        for (int col = 0; col < sidelength; col++) {
            //Add North neighbor
            if (row == 0) {
                rooms[col][row]->AddNeighbor(nullptr);
            }
            else if (row == sidelength - 1) {
                rooms[col][row]->AddNeighbor(rooms[col][row - 1]);
            }
            else {
                rooms[col][row]->AddNeighbor(rooms[col][row - 1]);
            }
            //Add East neighbor
            if (col == 0) {
                rooms[col][row]->AddNeighbor(rooms[col + 1][row]);
            }
            else if (col == sidelength - 1) {
                rooms[col][row]->AddNeighbor(nullptr);
            }
            else {
                rooms[col][row]->AddNeighbor(rooms[col + 1][row]);
            }
            //Add West neighbor
            if (col == 0) {
                rooms[col][row]->AddNeighbor(nullptr);
            }
            else if (col == sidelength - 1) {
                rooms[col][row]->AddNeighbor(rooms[col + 1][row]);
            }
            else {
                rooms[col][row]->AddNeighbor(rooms[col + 1][row]);
            }
            //Add South neighbor
            if (row == 0) {
                rooms[col][row]->AddNeighbor(rooms[col][row + 1]);
            }
            else if (row == sidelength - 1) {
                rooms[col][row]->AddNeighbor(nullptr);
            }
            else {
                rooms[col][row]->AddNeighbor(rooms[col][row + 1]);
            }
        }
    }
    
    return rooms; // set the rooms
}



//Represents a level of the dungeon.
//A level consists of nine rooms connected by doors on a 3 x 3 grid.

DungeonLevel::DungeonLevel(int sidelength) : sidelength_(sidelength) {
    int startRow = (std::rand() % sidelength) ; // Generate rand number between 1 to level side length
    int startCol = (std::rand() % sidelength) ; // Generate rand number between 1 to level side length
    std::pair<int,int> startPos = std::make_pair(startCol, startRow); // (col, row) due to graphics reason
    startPos_ = startPos; // Starting room
    rooms_ = GenerateRooms(sidelength, startPos); // Generated rooms
} 

int DungeonLevel::GetSideLength() const { return sidelength_; }

std::pair<int,int> DungeonLevel::GetStartPos() const {
  return startPos_;
}

std::vector<std::vector<DungeonRoom*>> DungeonLevel::GetRooms() const {
  return rooms_;
}
