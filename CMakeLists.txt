cmake_minimum_required (VERSION 3.8)

project ("DungeonCrawler")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_subdirectory ("src")

add_executable(DungeonCrawler "src/main.cpp")

target_link_libraries(DungeonCrawler sfml-audio sfml-graphics)