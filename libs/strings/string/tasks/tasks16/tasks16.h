//
// Created by Assa on 20.04.2024.
//

#ifndef UNTITLED7_TASKS16_H
#define UNTITLED7_TASKS16_H

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


WordDescriptor findPrecedingWord(char *s1, char *s2) {
    char *begin_search_1 = s1;
    char *begin_search_2 = s2;
    while (getWordWithoutSpace(begin_search_1, &_bag.words[_bag.size])) {
        begin_search_1 = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }
    while (getWordWithoutSpace(begin_search_2, &_bag2.words[_bag2.size])) {
        begin_search_2 = _bag2.words[_bag2.size].end + 1;
        _bag2.size++;
    }
    bool stop = false;
    WordDescriptor w;
    WordDescriptor preceding_w = {.begin = NULL, .end = NULL};
    for (size_t i = 1; i < _bag.size; i++) {
        w = _bag.words[i];
        for (size_t j = 0; j < _bag2.size; j++)
            if (isWordsEqual(w, _bag2.words[j])) {
                stop = true;
                break;
            }
        if (stop) {
            preceding_w = _bag.words[i - 1];
            break;
        }

    }
    free_bag(&_bag);
    free_bag(&_bag2);

    return preceding_w;
}

void test_findPrecedingWord1() {
    char s1[] = "";
    char s2[] = "";
    char dest[100] = "";
    WordDescriptor word = findPrecedingWord(s1, s2);
    wordDescriptorToString(word, dest);
    ASSERT_STRING("", dest);
}

void test_findPrecedingWord2() {
    char s1[] = "";
    char s2[] = "words";
    char dest[100] = "";
    WordDescriptor word = findPrecedingWord(s1, s2);
    wordDescriptorToString(word, dest);
    ASSERT_STRING("", dest);
}

void test_findPrecedingWord3() {
    char s1[] = "it's words";
    char s2[] = "";
    char dest[40] = "";
    WordDescriptor word = findLastCommonWord(s1, s2);
    wordDescriptorToString(word, dest);
    ASSERT_STRING("", dest);
}


void test_findPrecedingWord4() {
    char s1[] = "i love Katya";
    char s2[] = "It's love Alina";
    char dest[40] = "";
    WordDescriptor word = findPrecedingWord(s1, s2);
    wordDescriptorToString(word, dest);
    ASSERT_STRING("i", dest);
}


void test_findPrecedingWord() {
    test_findPrecedingWord1();
    test_findPrecedingWord2();
    test_findPrecedingWord3();
    test_findPrecedingWord4();
}

#endif //UNTITLED7_TASKS16_H
