# Add CMake Version
cmake_minimum_required(VERSION 2.8)
# Name of project 
project(helloEigen)
# Add header file
include_directories("/usr/include/eigen3")



# Add executable
add_executable(eigenMatrix eigenMatrix.cpp)
add_executable(useGeometry useGeometry.cpp)
add_executable(coordinateTransform coordinateTransform.cpp)

# Uncomment these line of code below if using the Pangolin Library
#find_package(Pangolin REQUIRED)
#include_directories(${Pangolin_INCLUDE_DIRS})

#add_executable(plotTrajectory plotTrajectory.cpp)
#target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})

#add_executable(visualizeGeometry visualizeGeometry.cpp)
#target_link_libraries(visualizeGeometry ${Pangolin_LIBRARIES})
