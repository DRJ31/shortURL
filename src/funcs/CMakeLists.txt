aux_source_directory(. FUNC_SRC_DIR)

add_library(funcs ${FUNC_SRC_DIR})

target_link_libraries(funcs drogon)