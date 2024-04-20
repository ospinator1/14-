
#ifndef UNTITLED7_TASKS9_H
#define UNTITLED7_TASKS9_H
#include <stdio.h>
#include <stdbool.h>
#include "../../string_.h"
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}
void combiningTwoStrings(char *s, char *s1, char *s2) {
    char *beginCopy = s;
    bool isW1Found = true, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    WordDescriptor word1, word2;
    while (isW1Found || isW2Found) {
        isW1Found = getWord(beginSearch1, &word1);
        isW2Found= getWord(beginSearch2,&word2);
        if(isW1Found){
            beginCopy= copy(word1.begin,word1.end,beginCopy);
            *beginCopy++=' ';
            beginSearch1=word1.end;
        }
        if(isW2Found){
            beginCopy= copy(word2.begin,word2.end,beginCopy);
            *beginCopy++=' ';
            beginSearch2=word2.end;
        }
    }
    *(beginCopy-1)='\0';
}
void test_combiningTwoStrings1(){
    char s1[]="a b c";
    char s2[]="d e f";
    char s[15];
    combiningTwoStrings(s,s1,s2);
    ASSERT_STRING("a d b e c f",s);
}
void test_combiningTwoStrings2(){
    char s1[]="a b c q z";
    char s2[]="d e f";
    char s[15];
    combiningTwoStrings(s,s1,s2);
    ASSERT_STRING("a d b e c f q z",s);
}
void test_combiningTwoStrings(){
    test_combiningTwoStrings1();
    test_combiningTwoStrings2();
}
#endif //UNTITLED7_TASKS9_H
