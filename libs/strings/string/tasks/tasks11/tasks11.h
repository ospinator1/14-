//
// Created by Assa on 19.04.2024.
//

#ifndef UNTITLED7_TASKS11_H
#define UNTITLED7_TASKS11_H

#include <stdbool.h>
#include "../../string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа

} WordDescriptor;

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

bool isLettersInWord(WordDescriptor word, char letters) {
    char *start = word.begin;
    while (start != word.begin) {
        if (*start == letters)
            return true;
        start++;
    }
    return false;
}

int get_word_before_first_word_a(char *s, WordDescriptor *word) {
    char *beginSearch = s;
    WordDescriptor word1;
    if (!getWord(beginSearch, &word1)) {
        return EMPTY_STRING;
    }
    beginSearch = word1.end + 1;
    if (isLettersInWord(word1, 'a') || isLettersInWord(word1, 'A')) {
        return FIRST_WORD_WITH_A;
    }
    WordDescriptor word2;
    while (getWord(beginSearch, &word2)) {
        if (isLettersInWord(word2, 'a') || isLettersInWord(word2, 'A')) {
            *word = word1;
            return WORD_FOUND;
        }

        word1 = word2;
        beginSearch = word2.end + 1;

    }
    return NOT_FOUND_A_WORD_WITH_A;
}



#endif //UNTITLED7_TASKS11_H
