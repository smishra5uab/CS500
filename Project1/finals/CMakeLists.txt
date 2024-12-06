cmake_minimum_required(VERSION 3.14)

#Change "projectName" to whatever you want
set(this hammingcode)

#defines the project, and the language we are using
project(${this} CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# Include Eigen library
include_directories( /usr/local/include/)

#allows us to include the google test framework
add_subdirectory(googletest)

#Change foo.h and huh.h to the headers in your project
#Do not delete "Headers" this is the name of a variable
set(Headers
    hamming.h
)

#Change foo.cpp and huh.cpp to the headers in your project
#Do not delete "Sources" this is the name of a variable
#Make sure to not include a main function in any of these files
set(Sources
    hamming.cpp
)

#creates a library from the source code we provided in "Sources" and "Headers"
add_library(${this} SHARED ${Sources} ${Headers})

#Sets the name of the testing executable we are creating
#you can rename "testingExample" to whatever you want
set(test hamming_test)

#Change test.cpp to the name of your testing file
#your testing file should not include a main file
set(testSources
    hamming_test.cpp
)

#creates the testing executable, and links it to our project and
#the google test framework
add_executable(${test} ${testSources})
target_link_libraries(${test} PUBLIC
    gtest_main #when testing, gtest provides the main function
    ${this}
)

#allows us to use ctest
add_test(
    NAME ${test}
    COMMAND ${test}
)
