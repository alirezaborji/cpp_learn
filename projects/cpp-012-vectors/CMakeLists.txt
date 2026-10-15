cmake_minimum_required(VERSION 3.20)
project(cpp_012_vectors LANGUAGES CXX)

add_executable(cpp_012_vectors src/main.cpp)
target_compile_features(cpp_012_vectors PRIVATE cxx_std_20)
set_target_properties(cpp_012_vectors PROPERTIES CXX_EXTENSIONS OFF)
