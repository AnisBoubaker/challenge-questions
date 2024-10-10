cmake_minimum_required(VERSION 3.26)
project(Tabs2D C)

set(CMAKE_C_STANDARD 11)


# Toujours s'assurer que tous les fichiers sont là
add_executable(Tabs2D main.c
        temperatures.c
        temperatures.h
        test/module_test.c
        test/module_test.h)
