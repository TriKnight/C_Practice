# Add CMake Version
cmake_minimum_required(VERSION 3.0)
# Name of project 
project(useSophus)
# Add header file
include_directories("/usr/include/eigen3")
find_package(Sophus REQUIRED)
include_directories("/opt/local/include/pangolin")
find_package(Pangolin REQUIRED)
find_package(fmt REQUIRED)
# Add executable
add_executable(useSophus useSophus.cpp)
target_link_libraries(useSophus Sophus::Sophus)

# Add executable
include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(trajectoryError trajectoryError.cpp)
target_link_libraries(trajectoryError Sophus::Sophus ${Pangolin_LIBRARIES} ${FMT_LIBRARIES})
