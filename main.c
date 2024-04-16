#include "libs/strings/string/string_.h"
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "libs/algorithms/basic_functions/basic_functions.h"

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

void Reversit(char s[]) {
    int i = 0;
    for (i = 0; s[i]; i++);
    for (int j = 0; j < i / 2; j++)
        swap(&s[j], &s[i - 1 - j]);
}

bool getWordReverse(char *rbegin, char *rend, struct WordDescriptor *word) {
    char *begin;
    *rbegin = *begin;
    char *end;
    rend = end;
    if (*word->begin == '\0')
        return 0;
    word->end = copyIfReverse(word->begin, word->end, word, isLetter);
    return 1;
}

void test_digitToStartWithSaveWithoutDigit() {
    char s[] = "bc";
    char result[20];
    printf("%d", getWordReverse(s + 10, s, result));

}

bool isPalindrome(char *str) {
    char begin = 0, end = strlen_(str) - 1;

    // traversing from both the ends
    while (begin < end)

        // not palindrome
        if (str[begin++] != str[end--])
            return false;

    // palindrome
    return true;
}

int getWord(char *beginSearch, struct WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

char *OuputStringReplacingADigitWithASpace(char *src) {
    char buffer[100];

    char *dst = buffer;

    while (*src) {
        if ('0' <= *src && *src <= '9') {
            int count = *src - '0';
            while (count-- > 0) {
                *dst++ = ' ';
            }
        } else {
            *dst++ = *src;
        }
        src++;
    }

    *dst = '\0';

    printf("Modified string: '%s'\n", buffer); // Выводим результат
    return 0;
}

int main() {
    char s[] = "aba1cdb";

    printf("%s", OuputStringReplacingADigitWithASpace(s));
}

