//
// Created by Assa on 16.04.2024.
//
#include "../../string_.h"
#include <windows.h>
#include <stdio.h>


#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

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
void test_OutputStringReplacingADigitWithASpace1(){
    char s[100]="B C";
    OuputStringReplacingADigitWithASpace(s);
    ASSERT_STRING("B C",s);
}
void test_OutputStringReplacingADigitWithASpace2(){
    char s[100]="1A2B1C3";
    OuputStringReplacingADigitWithASpace(s);
    ASSERT_STRING(" A  B C   ",s);
}
void test_OutputStringReplacingADigitWithASpace3(){
    char s[100]="1";
    OuputStringReplacingADigitWithASpace(s);
    ASSERT_STRING(" ",s);
}
void test_OutputStringReplacingADigitWithASpace4(){
    char s[100]="0";
    OuputStringReplacingADigitWithASpace(s);
    ASSERT_STRING("",s);
}
void test_OutputStringReplacingADigitWithASpace(){
    test_OutputStringReplacingADigitWithASpace1();
    test_OutputStringReplacingADigitWithASpace2();
    test_OutputStringReplacingADigitWithASpace3();
    test_OutputStringReplacingADigitWithASpace4();
}