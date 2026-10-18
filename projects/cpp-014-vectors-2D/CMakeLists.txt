cmake_minimum_required(VERSION 3.20)
project(cpp_014_vectors_2d LANGUAGES CXX)

add_executable(cpp_014_vectors_2d src/main.cpp)
target_compile_features(cpp_014_vectors_2d PRIVATE cxx_std_20)
set_target_properties(cpp_014_vectors_2d PROPERTIES CXX_EXTENSIONS OFF)
