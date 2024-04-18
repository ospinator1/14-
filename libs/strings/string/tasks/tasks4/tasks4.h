
#ifndef UNTITLED7_TASKS4_H
#define UNTITLED7_TASKS4_H

#include "../../string_.h"
#include <windows.h>
#include <stdio.h>


#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)




void replaceEachNumberWithSpaces(char *s) {
    char *buffer = _stringBuffer;
    char *endString = getEndOfString(s);
    char *endOfBuffer = copy(s, endString, buffer);
    *endOfBuffer = '\0';
    while (*buffer != '\0') {
        if (!isdigit(*buffer)) {
            *s = *buffer;
            s++;
        } else {
            int nSpaces = *buffer - '0';
            for (int i = 0; i < nSpaces; i++) {
                *s = ' ';
                s++;
            }
        }
        buffer++;
    }
    *s = '\0';
}


void test_replaceEachNumberWithSpaces_nonWords() {
    char s[] = "";
    replaceEachNumberWithSpaces(s);
    ASSERT_STRING("", s);
}
void test_replaceEachNumberWithSpaces_nonDigits() {
    char s[] = "abc bcd";
    replaceEachNumberWithSpaces(s);
    ASSERT_STRING("abc bcd", s);
}
void test_replaceEachNumberWithSpaces_withDigits() {
    char s[] = "a0b2";
    replaceEachNumberWithSpaces(s);
    ASSERT_STRING("ab  ", s);
}
void test_replaceEachNumberWithSpaces() {
    test_replaceEachNumberWithSpaces_nonWords();
    test_replaceEachNumberWithSpaces_nonDigits();
    test_replaceEachNumberWithSpaces_withDigits();
}

#endif
