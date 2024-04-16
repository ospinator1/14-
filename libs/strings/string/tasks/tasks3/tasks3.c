//
// Created by Assa on 15.04.2024.
//
#include "../../string_.h"
#include <windows.h>
#include <stdio.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 120
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
char _stringBuffer[MAX_STRING_SIZE + 1];

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

int getWord(char *beginSearch, struct WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

void digitToStartWithReverse(struct WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartWithReverseForEveryWord(char *s) {
    char *beginSearch = s;
    struct WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithReverse(word);
        beginSearch = word.end;
    }
}

void digitToStartWithSave(struct WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin,
                               isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartWithSaveForEveryWord(char *s) {
    char *beginSearch = s;
    struct WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithSave(word);
        beginSearch = word.end;
    }
}

void test_digitToStartWithReverseForEveryWordWithDigit() {
    char s[] = "a12b34c56";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("654321abc", s);
}

void test_digitToStartWithReverseForEveryWordWitoutDigit() {
    char s[] = "bc";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("bc", s);
}

void test_digitToStartWithReverseForEveryWordWithoutWordsAndDigit() {
    char s[] = "";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("", s);
}

void test_digitToStartWithSave1() {
    char s[] = "bc21";
    digitToStartWithSaveForEveryWord(s);
    ASSERT_STRING("21bc", s);
}

void test_digitToStartWithSave2() {
    char s[] = "b2c1";
    digitToStartWithSaveForEveryWord(s);
    ASSERT_STRING("21bc", s);
}
void test_digitToStartWithSaveWithoutDigit() {
    char s[] = "bc";
    digitToStartWithSaveForEveryWord(s);
    ASSERT_STRING("bc", s);
}
void test_digitToStartWithSaveWithoutWord() {
    char s[] = "21";
    digitToStartWithSaveForEveryWord(s);
    ASSERT_STRING("21", s);
}
void test_digitToStartWithReverseForEveryWord() {
    test_digitToStartWithReverseForEveryWordWithDigit();
    test_digitToStartWithReverseForEveryWordWitoutDigit();
    test_digitToStartWithReverseForEveryWordWithoutWordsAndDigit();
}
void test_digitToStartWithSave(){
    test_digitToStartWithSave1();
    test_digitToStartWithSave2();
    test_digitToStartWithSaveWithoutDigit();
    test_digitToStartWithSaveWithoutWord();
}