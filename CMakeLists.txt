cmake_minimum_required(VERSION 3.5)

project(ShortURL)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(src SRC_DIR)

include_directories(${JSONCPP_INCLUDE_DIRS})

add_subdirectory(libs/drogon)
add_subdirectory(src/funcs)
add_subdirectory(src/controller)
find_package(GTest)
if (GTest_FOUND)
    enable_testing()
    add_subdirectory(src/tests)
endif(GTest_FOUND)

file(COPY static etc DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SRC_DIR})
target_link_libraries(${PROJECT_NAME} drogon funcs controller)

