//
// Created by Assa on 20.04.2024.
//

#ifndef UNTITLED7_TASKS13_H
#define UNTITLED7_TASKS13_H
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
char _stringBuffer[MAX_STRING_SIZE + 1];
bool areEqualWordsInString(char* s){
    char *beginBuffer=_stringBuffer;
    copy(s,s+ strlen_(s),_stringBuffer);
    while(getWordWithoutSpace(beginBuffer,&_bag.words)){
        beginBuffer=_bag[_bag.size].end+2;
        _bag.size++;

    }
    free_string(_stringBuffer);
    if(_bag.size<=1)
        return false;
    for (int i = 0; i < _bag.size; ++i) {
        for (int j = i+1; j < _bag.size; ++j) {
            if(isWordsEqual(_bag.words[i],_bag.words[j]))
                free_bag(&_bag);
            return true;
        }

    }
    free_bag(&_bag);
    return false;
}
#endif //UNTITLED7_TASKS13_H
