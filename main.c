#include "libs/strings/string/string_.h"
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
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


bool getWordReverse(char *rbegin, char *rend, struct WordDescriptor *word) {
    char *begin;
    *rbegin = *begin;
    char *end;
    rend = end;
    if (*word->begin == '\0')
        return 0;
    word->end = copyIfReverse(word->begin, word->end, (char *) word, isLetter);
    return 1;
}

void test_digitToStartWithSaveWithoutDigit() {
    char s[] = "bc";
    char result[20];
    printf("%d", getWordReverse(s + 10, s, (struct WordDescriptor *) result));

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

void *OuputStringReplacingADigitWithASpace(char *src) {
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
    printf("Modified string: '%s'", buffer);

}
void test_OuputStringReplacingADigitWithASpace1(){
    char s[100]="B C";
    OuputStringReplacingADigitWithASpace(s);
    ASSERT_STRING("B C",s);
}
void test_OuputStringReplacingADigitWithASpace2(){
    char s[100]="1A2B1C3";
    OuputStringReplacingADigitWithASpace(s);
    ASSERT_STRING(" A  B C   ",s);
}
void test_OuputStringReplacingADigitWithASpace3(){
    char s[100]="1";
    OuputStringReplacingADigitWithASpace(s);
    ASSERT_STRING(" ",s);
}
void test_OuputStringReplacingADigitWithASpace4(){
    char s[100]="0";
    OuputStringReplacingADigitWithASpace(s);
    ASSERT_STRING("",s);
}
void test_OuputStringReplacingADigitWithASpace(){
    test_OuputStringReplacingADigitWithASpace1();
    test_OuputStringReplacingADigitWithASpace2();
    test_OuputStringReplacingADigitWithASpace3();
    test_OuputStringReplacingADigitWithASpace4();
}
int main() {
   char s[100]="B C";
    OuputStringReplacingADigitWithASpace(s);
    ASSERT_STRING("B C",s);
}

