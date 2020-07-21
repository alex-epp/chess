file(GLOB HEADER_LIST
        CONFIGURE_DEPENDS
        "${chess_SOURCE_DIR}/include/chess/backend/*.hpp")

file(GLOB SOURCE_LIST
        CONFIGURE_DEPENDS
        "${chess_SOURCE_DIR}/src/backend/*.cpp")

add_library(_chess_backend_target ${SOURCE_LIST} ${HEADER_LIST})
target_include_directories(_chess_backend_target PUBLIC "${chess_SOURCE_DIR}/include")
target_compile_features(_chess_backend_target PUBLIC cxx_std_17)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(_chess_backend_target PUBLIC -mbmi2)
endif()

find_package(Threads REQUIRED)
target_link_libraries(_chess_backend_target PUBLIC Threads::Threads)