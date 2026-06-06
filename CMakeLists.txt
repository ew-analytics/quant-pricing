cmake_minimum_required(VERSION 3.20)
project(quant-pricing CXX)
set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(GTest REQUIRED)

add_executable(bs_pricer src/bs_pricer.cpp)
target_include_directories(bs_pricer PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR})

enable_testing()
add_executable(bs_tests tests/bs_tests.cpp)
target_link_libraries(bs_tests GTest::gtest_main)
add_test(NAME bs_tests COMMAND bs_tests)
