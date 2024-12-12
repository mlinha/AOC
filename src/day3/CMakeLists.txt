add_library(day3 OBJECT)
target_sources(day3
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/day3.cpp
        ${CMAKE_CURRENT_LIST_DIR}/recursive_parser.cpp
)

add_library(day3_headers INTERFACE)
target_sources(day3_headers
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/day3.h
        ${CMAKE_CURRENT_LIST_DIR}/recursive_parser.h
)

target_link_libraries(day3 PUBLIC day3_headers)