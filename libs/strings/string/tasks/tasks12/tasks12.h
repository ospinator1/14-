//
// Created by Assa on 19.04.2024.
//

#ifndef UNTITLED7_TASKS12_H
#define UNTITLED7_TASKS12_H


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
void wordDescriptorToString(WordDescriptor word, char* dest) {
    if (word.begin == NULL && word.end == NULL)
        return;

    while (word.begin <= word.end) {
        *dest = *word.begin;
        word.begin++;
        dest++;
    }

    *dest = '\0';
}
WordDescriptor findLastCommonWord(char* s1, char* s2) {
    char* begin_search_1 = s1;
    char* begin_search_2 = s2;

    while (getWordWithoutSpace(begin_search_1, &_bag.words[_bag.size])) {
        begin_search_1 = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    while (getWordWithoutSpace(begin_search_2, &_bag2.words[_bag2.size])) {
        begin_search_2 = _bag2.words[_bag2.size].end + 1;
        _bag2.size++;
    }
    WordDescriptor word = {.begin = NULL, .end = NULL};
    for (int i = (int) _bag.size - 1; i >= 0; i--)
        for (int j = 0; j < _bag2.size; j++)
            if (isWordsEqual(_bag.words[i], _bag2.words[j])) {
                word = _bag.words[i];

                free_bag(&_bag);
                free_bag(&_bag2);

                return word;
            }

    return word;
}
void test_findLastCommonWord1(){
    char s1[]="";
    char s2[]="Гвардия Петра";
    WordDescriptor word= findLastCommonWord(s1,s2);
    assert(word.begin == NULL && word.end == NULL);
}
void test_findLastCommonWord2(){
    char s1[]="Pavel's Guard";
    char s2[]="Peter's Guard";
    char dest[MAX_N_WORDS_IN_STRING]="";
    WordDescriptor word= findLastCommonWord(s1,s2);
    wordDescriptorToString(word,dest);
    ASSERT_STRING("Guard",dest);
}
void test_findLastCommonWord3(){
    char s1[]="Beauty Queen";
    char s2[]="The Queen of Dreams";
    char dest[MAX_N_WORDS_IN_STRING]="";
    WordDescriptor word= findLastCommonWord(s1,s2);
    wordDescriptorToString(word,dest);
    ASSERT_STRING("Queen",dest);
}
void test_findLastCommonWord(){
    test_findLastCommonWord1();
    test_findLastCommonWord2();
    test_findLastCommonWord3();
}
#endif //UNTITLED7_TASKS12_H
