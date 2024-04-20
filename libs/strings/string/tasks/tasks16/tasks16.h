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


WordDescriptor find_preceding_word(char* s1, char* s2){
    char *beginSearch1=s1;
    char *beginSearch2=s2;
    while(getWordWithoutSpace(beginSearch1,_bag.words[_bag.size])){
        beginSearch1=_bag.words[_bag.size].end;
        _bag.size++;
    }
    while(getWordWithoutSpace(beginSearch1,_bag.words[_bag.size])){
        beginSearch1=_bag.words[_bag.size].end;
        _bag.size++;
    }
    bool stop=false;
    WordDescriptor w;
    WordDescriptor preceding_word={.begin=NULL,.end=NULL};
    for (size_t i = 1; i < _bag.size; i++) {
        w = _bag.words[i];
        for (int j = 0; j < _bag2.size; ++j)
            if (isWordsEqual(w, _bag2.words[j])) {
                stop = true;
                break;
            }
        if (stop) {
            preceding_word = _bag.words[i - 1];
        }
    }
    free_bag(&_bag);
    free_bag(&_bag2);
    return preceding_word;
}
#endif //UNTITLED7_TASKS16_H
