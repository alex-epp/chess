file(GLOB SOURCE_LIST
        CONFIGURE_DEPENDS
        "*.cpp"
        "*.hpp")

add_executable(_chess_engine_demo_target ${SOURCE_LIST})
target_link_libraries(_chess_engine_demo_target PRIVATE _chess_engine_target)
