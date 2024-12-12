add_library(day2 OBJECT)
target_sources(day2 PRIVATE ${CMAKE_CURRENT_LIST_DIR}/day2.cpp)

add_library(day2_headers INTERFACE)
target_sources(day2_headers INTERFACE ${CMAKE_CURRENT_LIST_DIR}/day2.h)

target_link_libraries(day2 PUBLIC day2_headers)