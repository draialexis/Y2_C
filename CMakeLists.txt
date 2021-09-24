cmake_minimum_required(VERSION 3.17)
project(Y2_C C)

set(CMAKE_C_STANDARD 99)

include_directories(TP_1)

add_executable(TP1_PA
        TP_1/main.c
        TP_1/ex1.h
        TP_1/ex2.h
        TP_1/ex3.h
        TP_1/ex5.h
        TP_1/ex6.h
        TP_1/ex7.h)