//
// Created by Assa on 21.04.2024.
//

#ifndef UNTITLED7_TASKS18_H
#define UNTITLED7_TASKS18_H

#include "../../string_.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>
#include <string.h>

#define MAX_STRING_SIZE 100

#include <stdlib.h>

#define MAX_WORD_SIZE 20
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
BagOfWords _bag;
BagOfWords _bag2;


void complementString(char *s1, char *s2, int  n) {
    char *beginSearch = s2;
    while (getWordWithoutSpace(beginSearch, &_bag.words[_bag.size])) {
        beginSearch = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }
    char *rec_ptr = getEndOfString(s1);
    *rec_ptr++ = ' ';
    for (size_t i = _bag.size - n; i < _bag.size; ++i) {
        rec_ptr = copy(_bag.words[i].begin, _bag.words[i].end + 1, rec_ptr);
        if (i != _bag.size - 1)
            *rec_ptr++ = ' ';
    }
    *rec_ptr = '\0';
    free_bag(&_bag);

}


void balanceString(char* s1, int n1, char* s2, int n2) {
    if (n1 < n2)
        complementString(s1, s2, n2 - n1);
    else if  (n2 < n1)
        complementString(s2, s1, n1 - n2);
}


void test_complementString1() {
    char s1[100] = "Old Gods of Asgard";
    int n1 = 4;
    char s2[100] = "Alan Wake";
    int  n2 = 2;
    balanceString(s1, n1, s2, n2);
    ASSERT_STRING("Old Gods of Asgard",s1);
    ASSERT_STRING("Alan Wake of Asgard",s2);
}
void test_complementString2() {
    char s1[100] = "Sam Lake";
    int n1 = 2;
    char s2[100] = "Alan Wake";
    int  n2 = 2;
    balanceString(s1, n1, s2, n2);
    ASSERT_STRING("Sam Lake",s1);
    ASSERT_STRING("Alan Wake",s2);
}
void  test_complementString3(){
    char s1[100]="";
    int n1=0;
    char s2[100]="Herald of Darkness";
    int n2=3;
    balanceString(s1,n1,s2,n2);
    ASSERT_STRING(" Herald of Darkness",s1);
    ASSERT_STRING("Herald of Darkness",s2);
}
void  test_complementString4(){
    char s1[100]="Herald of Darkness";
    int n1=3;
    char s2[100]="";
    int n2=0;
    balanceString(s1,n1,s2,n2);
    ASSERT_STRING("Herald of Darkness",s1);
    ASSERT_STRING(" Herald of Darkness",s2);
}
void test_complementString(){
    test_complementString1();
    test_complementString2();
    test_complementString3();
    test_complementString4();
}
#endif //UNTITLED7_TASKS18_H
