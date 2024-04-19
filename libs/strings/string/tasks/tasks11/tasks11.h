//
// Created by Assa on 19.04.2024.
//

#ifndef UNTITLED7_TASKS11_H
#define UNTITLED7_TASKS11_H

#include <stdbool.h>
#include "../../string_.h"
#include <assert.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
#define MAX_WORD_SIZE 20
typedef enum word_before_first_word_with_a_return_code {
    EMPTY_STRING,
    NOT_FOUND_A_WORD_WITH_A,
    FIRST_WORD_WITH_A,
    WORD_FOUND
} word_before_first_word_with_a_return_code;


bool isLettersInWord(WordDescriptor word, char letters) {
    char* start = word.begin;

    while (start != word.end) {
        if (*start == letters)
            return true;

        start++;
    }

    return false;
}


word_before_first_word_with_a_return_code getWordBeforeFirstWordWithA(char* s, WordDescriptor * word) {
    char* begin_search = s;
    WordDescriptor word1;
    if (!getWord(begin_search, &word1)) {
        return EMPTY_STRING;
    }
    begin_search = word1.end + 1;
    if (isLettersInWord(word1, 'a') || isLettersInWord(word1, 'A')) {
        return FIRST_WORD_WITH_A;
    }
    WordDescriptor word2;
    while (getWord(begin_search, &word2)) {
        if (isLettersInWord(word2, 'a') || isLettersInWord(word2, 'A')) {
            *word = word1;
            return WORD_FOUND;
        }
        word1 = word2;
        begin_search = word2.end + 1;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}


void test_11_all_test_get_before_first_word_with_a() {
    WordDescriptor word;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word)== EMPTY_STRING);
    char s2[] = "ABC";
    assert(getWordBeforeFirstWordWithA(s2, &word)== FIRST_WORD_WITH_A);
    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &word)== WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(word.begin, word.end, got);
    got[word.end - word.begin] = '\0';
    ASSERT_STRING("BC", got);
    char s4[] = "B Q WE YR OW IUWR";
    assert(getWordBeforeFirstWordWithA(s4, &word) ==NOT_FOUND_A_WORD_WITH_A);
}




#endif //UNTITLED7_TASKS11_H
