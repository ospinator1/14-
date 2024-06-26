//
// Created by Assa on 18.04.2024.
//

#ifndef UNTITLED7_TASKS6_H
#define UNTITLED7_TASKS6_H

#include "../../string_.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)


bool isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered(char *s) {
    char *beginSearch = s;
    WordDescriptor currentWord;
    if (!getWord(beginSearch, &currentWord))
        return true;
    WordDescriptor previousWord = currentWord;
    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, previousWord) < 0)
            return false;
        beginSearch = currentWord.end;
        previousWord = currentWord;
    }
    return true;
}


void test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered1() {
    char s[] = "abcd egfh";
    assert(isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered(s) == 1);
}

void test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered2() {
    char s[] = "cbc aefg";
    assert(isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered(s) == 0);
}


void test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered3() {
    char s[] = "";
    assert(isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered(s) == 1);
}

void test_6() {
    test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered1();
    test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered2();
    test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered3();
}

#endif //UNTITLED7_TASKS6_H
