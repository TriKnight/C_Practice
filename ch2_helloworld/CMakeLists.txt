# Add CmakeList version
cmake_minimum_required(VERSION 2.8)
# Name of project 
project(helloworld)
# Add executable
add_executable(helloworld helloworld.cpp)

##---- Library ---
# Add library 
add_library(hello libHelloWorld.cpp)

# Add Share library 
add_library(hello_shared SHARED libHelloWorld.cpp)

# Add excutable using lib
add_executable(useHello useHello.cpp)
target_link_libraries(useHello hello_shared)