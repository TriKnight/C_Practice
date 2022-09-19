# Add CMake Version
cmake_minimum_required(VERSION 2.8)
# Name of project 
project(helloEigen)
# Add header file
include_directories("/usr/include/eigen3")
find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
# Add executable
add_executable(eigenMatrix eigenMatrix.cpp)
add_executable(useGeometry useGeometry.cpp)
add_executable(coordinateTransform coordinateTransform.cpp)

add_executable(plotTrajectory plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})

add_executable(visualizeGeometry visualizeGeometry.cpp)
target_link_libraries(visualizeGeometry ${Pangolin_LIBRARIES})