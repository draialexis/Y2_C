cmake_minimum_required(VERSION 3.17)

project(Y2_C)

set(CMAKE_C_STANDARD 11)

include_directories(TP_1 TP_2)

add_executable(
#        TP_1
#        TP_1/main.c
#        TP_1/tp1ex1.h
#        TP_1/tp1ex2.h
#        TP_1/tp1ex3.h
#        TP_1/tp1ex5.h
#        TP_1/tp1ex6.h
#        TP_1/tp1ex7.h
#        TP_1/tp1ex8.h
#        TP_1/tp1ex9.h
#        TP_1/tp1ex10.h
#        TP_1/tp1ex11.h
#        TP_1/tp1ex12.h
#        TP_1/tp1ex13.h

        TP_2
        TP_2/main.c
        TP_2/toolbox.h
        TP_2/tp2ex1.h
        TP_2/tp2ex2.h
        TP_2/tp2ex3.h
        TP_2/tp2ex4.h
        TP_2/tp2ex5.h
#        TP_2/tp2ex6.h
#        TP_2/tp2ex7.h
#        TP_2/tp2ex8.h
#        TP_2/tp2ex9.h
)
