cmake_minimum_required(VERSION 2.8.3)
project(multi_thread_app)
FIND_PACKAGE( Boost COMPONENTS program_options thread REQUIRED )

## Compile as C++11, supported in ROS Kinetic and newer
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -lboost_system -DBOOST_SYSTEM_NO_DEPRECATED -fpermissive -std=c++11 -g -O0")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${Boost_INCLUDE_DIR} )

link_directories(${Boost_LIBRARY_DIRS})


FILE(GLOB SOURCE_FILES *.hpp *.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${Boost_LIBRARY_DIRS})


