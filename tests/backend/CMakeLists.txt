file(GLOB SOURCE_LIST
        CONFIGURE_DEPENDS
        "*.cpp"
        "*.hpp")

add_executable(_chess_backend_tests_target ${SOURCE_LIST})
target_link_libraries(_chess_backend_tests_target PRIVATE _chess_backend_target Catch2)
