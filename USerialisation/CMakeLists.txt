cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)

project(USerialisation)

add_library(USerialisation STATIC
        src/Serializer.cpp
)

target_include_directories(USerialisation PUBLIC include)
