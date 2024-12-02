cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(Game_of_Life_project VERSION 0.2.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(lib)

target_include_directories(game_of_life PUBLIC .) 

add_subdirectory(tests)

add_executable(GL_main main.cpp) 

target_link_libraries(GL_main game_of_life)