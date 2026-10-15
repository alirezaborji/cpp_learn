cmake_minimum_required(VERSION 3.20)
project(cpp_1_exceptions LANGUAGES CXX)

add_library(cpp_1_exceptions_lib STATIC src/exceptions.cpp)
target_include_directories(cpp_1_exceptions_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(cpp_1_exceptions_lib PUBLIC cxx_std_20)
set_target_properties(cpp_1_exceptions_lib PROPERTIES CXX_EXTENSIONS OFF)

add_executable(cpp_1_exceptions src/main.cpp)
target_link_libraries(cpp_1_exceptions PRIVATE cpp_1_exceptions_lib)
set_target_properties(cpp_1_exceptions PROPERTIES CXX_EXTENSIONS OFF)

add_executable(exceptions_basic examples/basic-throw.cpp)
target_compile_features(exceptions_basic PRIVATE cxx_std_20)
set_target_properties(exceptions_basic PROPERTIES CXX_EXTENSIONS OFF)
