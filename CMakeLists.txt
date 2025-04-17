cmake_minimum_required(VERSION 3.10)
project(Laba_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(main
    src/main.cpp
)

add_executable(mutable_array_test
    tests/test_mutablearraysequence.cpp
)

add_executable(immutable_array_test
    tests/test_immutablearraysequence.cpp
)
add_executable(list_test
    tests/test_listsequence.cpp
)
