cmake_minimum_required(VERSION 3.13)
project(code C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(code
        file_reader.c
        main.c
        test.c structures_fonctions/structDataBase.c structures_headers/structDataBase.h structures_fonctions/structPerson.c structures_headers/structPerson.h structures_fonctions/structNodeTrie.c structures_headers/structNodeTrie.h)
