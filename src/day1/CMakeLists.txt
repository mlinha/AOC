add_library(day1 OBJECT)
target_sources(day1 PRIVATE ${CMAKE_CURRENT_LIST_DIR}/day1.cpp)

add_library(day1_headers INTERFACE)
target_sources(day1_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/day1.h)

target_link_libraries(day1 PUBLIC day1_headers)