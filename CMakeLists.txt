#файл для сборки, по сути cmake
cmake_minimum_required(VERSION 3.14)
project(homeworkOpenMp)

set(CMAKE_CXX_STANDARD 17)

add_executable(homeworkOpenMp main.cpp Task2.h Task1.h Task3.h Task5.h Task4.h Task6.h Task7.h Task8.h Task9.h Task10.h Task11.h Task12.h Task13_1.h)
#add_executable(${PROJECT_NAME} ${SRC_LIST})

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(homeworkOpenMp PUBLIC OpenMP::OpenMP_CXX)
endif()

#set(CMAKE_C_COMPILER "/usr/local/opt/llvm/bin/clang++")
#set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang")

