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


void complement_string(char *s1, char *s2, size_t n) {
    char *beginSearch = s2;
    while (getWordWithoutSpace(beginSearch, _bag.words[_bag.size]))
        beginSearch = _bag.words[_bag.size].end + 1;
    _bag.size++;
    char *rec_ptr = getEndOfString(s1);
    *rec_ptr++ = ' ';
    for (int i = _bag.size - n; i < _bag.size; ++i) {
        rec_ptr = copy(_bag.words[i].begin, _bag.words[i].end + 1, rec_ptr);
        if (i != _bag.size - 1)
            *rec_ptr++ = ' ';
    }
    *rec_ptr = '\0';
    free_bag(&_bag);

}

#endif //UNTITLED7_TASKS18_H
