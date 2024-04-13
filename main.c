#include "libs/strings/string/string_.h"
#include <windows.h>
#include <stdio.h>
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)



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

void* removeExtraSpaces(char *s){
    if(!s)
        return NULL;
    if(!*s)
        return s;
    char  *p=s ,*wp = s;
    while(*p){
        if(isspace(*p)){
            if(wp>s)
                *wp++=*p;
            while (*p && isspace(*p))
                p++;
            if(!*p)
                break;
        }
        if(*p=='.')
            while (wp > s && isspace (*(wp - 1)))
                wp--;
        *wp++ = *p;
        p++;
    }
    while (wp > s && isspace (*(wp - 1)))
        wp--;
        *wp=0;
    return s;

}
void test_removeExtraSpaces1(){
    char s[]="1     4     4    5     k";
    removeExtraSpaces(s);
    ASSERT_STRING("1 4 4 5 k",s);
}
void test_removeExtraSpaces2(){
    char s[]="1 4 4 5 k";
    removeExtraSpaces(s);
    ASSERT_STRING("1 4 4 5 k",s);
}
void test_removeExtraSpaces3(){
    char s[]="1 2 3     5   1\0";
    removeExtraSpaces(s);
    ASSERT_STRING("1 2 3 5 1\0",s);
}
void test_removeExtraSpaces(){
    test_removeExtraSpaces1();
    test_removeExtraSpaces2();
    test_removeExtraSpaces3();
}

int main(){
    test_removeExtraSpaces();

}