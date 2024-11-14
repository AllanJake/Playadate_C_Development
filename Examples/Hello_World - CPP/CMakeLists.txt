cmake_minimum_required(VERSION 3.19)
project("HelloWorldExampleCPP")

# C++ 20 and up is required in order to include the playdate headers
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_XCODE_GENERATE_SCHEME TRUE)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/submodules/playdate-cpp)

add_playdate_application(HelloWorldExample)

# Add its sources
target_sources(HelloWorldExample PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/main.h)
target_sources(HelloWorldExample PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)