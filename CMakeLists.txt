cmake_minimum_required(VERSION 3.13)
project(code C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(code
        csvReader.c
        main.c
        htmlGenerator.c structDataBase.c structDataBase.h structPerson.c structPerson.h structNodeTrie.c structNodeTrie.h htmlGenerator.h menu.c menu.h)
