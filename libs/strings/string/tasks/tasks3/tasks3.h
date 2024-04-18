//
// Created by Assa on 15.04.2024.
//

#ifndef UNTITLED7_TASKS3_H
#define UNTITLED7_TASKS3_H
//
// Created by Assa on 15.04.2024.
//
#include "../../string_.h"
#include <windows.h>
#include <stdio.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 120








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
    char s[] = "a12b34c";
    digitToStartWithReverseForEveryWord(s);
    ASSERT_STRING("4321abc", s);
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
#endif //UNTITLED7_TASKS3_H
