cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)

project(SerialisationTests)

add_executable(TestsPlayer testsPlayer.cpp)

add_subdirectory(USerialisation)

target_link_libraries(TestsPlayer USerialisation)
