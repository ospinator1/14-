#include "../../string_.h"
#include <windows.h>
#include <stdio.h>
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

char *getEndOfString(char *s){
    char size= findLength(s);
    return &s[size-1];
}
void removeNonLetters(char *s){
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}


void assertString(const char *expected, char *got,char const *fileName, char const *funcName,int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters1(){
    char s[]="1234 ";
    removeNonLetters(s);
    ASSERT_STRING("1234",s);
}
void test_removeNonLetters2(){
    char s[]=" ";
    removeNonLetters(s);
    ASSERT_STRING("",s);

}
void test_removeNonLetters3(){
    char s[]="244w\t";
    removeNonLetters(s);
    ASSERT_STRING("244w",s);
}
void test_removeNonLetters(){
    test_removeNonLetters1();
    test_removeNonLetters2();
    test_removeNonLetters3();
}
