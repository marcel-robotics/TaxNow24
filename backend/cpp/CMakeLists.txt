cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

set(PROJECT_NAME TaxNow24)

project(${PROJECT_NAME})

find_package(PkgConfig REQUIRED)
pkg_check_modules(ASIO REQUIRED IMPORTED_TARGET asio)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        taxnow24/statecontroller.cpp
        taxnow24/statecontroller.h
        main.cpp
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE /usr/local/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${ASIO_INCLUDE_DIRS})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)


# Tests
set(PROJECT_NAME_TESTS ${PROJECT_NAME}_Tests)

set(SOURCE_FILES_TESTS
        taxnow24/statecontroller.cpp
        taxnow24/statecontroller.h
        tests/test_statecontroller.cpp
)

add_executable(${PROJECT_NAME_TESTS} ${SOURCE_FILES_TESTS})

target_include_directories(${PROJECT_NAME_TESTS} PRIVATE /usr/local/include)
target_include_directories(${PROJECT_NAME_TESTS} PRIVATE ${ASIO_INCLUDE_DIRS})

target_compile_definitions(${PROJECT_NAME_TESTS} PRIVATE TEST_BUILD)

target_compile_features(${PROJECT_NAME_TESTS} PRIVATE cxx_std_11)

enable_testing()
add_test(NAME ${PROJECT_NAME_TESTS} COMMAND ${PROJECT_NAME_TESTS})