cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(pcl_ribxz)
find_package(PCL 1.3 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
add_executable (pcl_ribxz pcl_ribxz.cpp)
target_link_libraries (pcl_ribxz ${PCL_LIBRARIES})