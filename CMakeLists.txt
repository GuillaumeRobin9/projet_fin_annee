cmake_minimum_required(VERSION 3.13)
project(code C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(code
        file_reader.c
        main.c
        test.c htmlPersonPage.c htmlIndexPage.c structDataBase.c structDataBase.h structPerson.c structPerson.h structNodeTrie.c structNodeTrie.h dataBase_reader.c dataBase_reader.h queryResFile.c menu.c menu.h)
