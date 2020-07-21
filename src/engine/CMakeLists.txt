file(GLOB HEADER_LIST
        CONFIGURE_DEPENDS
        "${chess_SOURCE_DIR}/include/chess/engine/*.hpp")

file(GLOB SOURCE_LIST
        CONFIGURE_DEPENDS
        "${chess_SOURCE_DIR}/src/engine/*.cpp")

add_library(_chess_engine_target ${SOURCE_LIST} ${HEADER_LIST})
target_compile_features(_chess_engine_target PUBLIC cxx_std_20)
target_include_directories(_chess_engine_target PUBLIC "${chess_SOURCE_DIR}/include")
target_link_libraries(_chess_engine_target PUBLIC _chess_backend_target mio)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(_chess_engine_target PUBLIC stdc++fs)
endif()
