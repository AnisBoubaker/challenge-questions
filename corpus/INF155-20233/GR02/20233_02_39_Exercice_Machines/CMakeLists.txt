cmake_minimum_required(VERSION 3.26)
project(Exercice_Machines C)

set(CMAKE_C_STANDARD 11)

add_executable(Exercice_Machines main.c
        t_date.h
        t_date.c
        t_machine.c
        t_machine.h)
