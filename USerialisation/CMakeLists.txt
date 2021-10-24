cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)

project(USerialisation)

add_library(USerialisation STATIC
        src/Serializer.cpp
        src/Deserializer.cpp
        src/FloatCompressor.cpp
        src/IntCompressor.cpp
        src/QuatCompressor.cpp
        src/VectCompressor.cpp
)

target_include_directories(USerialisation PUBLIC include)
