//
// Created by Assa on 13.04.2024.
//

#ifndef UNTITLED7_TASKS2_H
#define UNTITLED7_TASKS2_H
//
// Created by Assa on 13.04.2024.
//
#include <windows.h>
#include <stdio.h>
#include "../../string_.h"
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)



void* removeExtraSpaces(char *s){
    if(!s)
        return NULL;
    if(!*s)
        return s;

void test_removeExtraSpaces1(){
    char s[]=" Hi       my      name is  Leon   . ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hi my name is Leon.",s);
}
void test_removeExtraSpaces2(){
    char s[]="1 4 4 5 k";
    removeExtraSpaces(s);
    ASSERT_STRING("1 4 4 5 k",s);
}
void test_removeExtraSpaces3(){
    char s[]="1 2 3     5   1\0";
    removeExtraSpaces(s);
    ASSERT_STRING("1 2 3 5 1\0",s);
}
void test_2(){
    test_removeExtraSpaces1();
    test_removeExtraSpaces2();
    test_removeExtraSpaces3();
}
#endif //UNTITLED7_TASKS2_H
