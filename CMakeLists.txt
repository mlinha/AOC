cmake_minimum_required(VERSION 3.27)
project(AOCSolution)

add_executable(Solution ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src/day1)
target_link_libraries(Solution PRIVATE day1)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src/day2)
target_link_libraries(Solution PRIVATE day2)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Solution DESTINATION bin)
