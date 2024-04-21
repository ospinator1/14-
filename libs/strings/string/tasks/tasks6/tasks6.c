#include "../../string_.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)



int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    return strcmp(w1.begin, w2.begin);
}

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

void test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered() {
    test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered1();
    test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered2();
    test_isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered3();
}