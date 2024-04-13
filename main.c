#include "libs/strings/string/string_.h"
#include <windows.h>
#include <assert.h>
#include <stdio.h>
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

int getEndOfString(char *s){}
void removeNonLetters(char *s){}

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
    char s[]="24\t4w";
    removeNonLetters(s);
    ASSERT_STRING("244w",s);
}
int main(){

}