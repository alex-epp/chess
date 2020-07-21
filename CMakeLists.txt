cmake_minimum_required (VERSION 3.15)


project(chess VERSION 0.1
        DESCRIPTION "C++ chess engine"
        LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

include(FetchContent)
set(FETCHCONTENT_QUIET off)

FetchContent_Declare(
        mio
        GIT_REPOSITORY https://github.com/mandreyel/mio
)
if(NOT mio_POPULATED)
    FetchContent_MakeAvailable(mio)
endif()

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.11.3
)
if(NOT Catch2_POPULATED)
    FetchContent_Populate(Catch2)
    add_subdirectory("${catch2_SOURCE_DIR}" "${catch2_BINARY_DIR}")
endif()

add_subdirectory("src")
add_subdirectory("demos")
add_subdirectory("tests")


