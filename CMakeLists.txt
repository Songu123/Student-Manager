cmake_minimum_required(VERSION 3.26)
project(Student_Manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Student_Manager main.cpp
        SinhVien.cpp
        SinhVien.h
        Functions.cpp
        Functions.h
        File.cpp
        File.h
)
