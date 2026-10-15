cmake_minimum_required(VERSION 3.20)
project(cpp_2_files LANGUAGES CXX)

add_executable(cpp_2_files src/main.cpp)
add_executable(files_text_streams examples/text-streams.cpp)
add_executable(files_notes_practice examples/notes-practice.cpp)

foreach(target IN ITEMS cpp_2_files files_text_streams files_notes_practice)
    target_compile_features(${target} PRIVATE cxx_std_20)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
endforeach()
