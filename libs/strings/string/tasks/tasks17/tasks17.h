//
// Created by Assa on 20.04.2024.
//

#ifndef UNTITLED7_TASKS17_H
#define UNTITLED7_TASKS17_H
#include "../../string_.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>
#include <string.h>

#define MAX_STRING_SIZE 100

#include <stdlib.h>

#define MAX_WORD_SIZE 20
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
char _stringBuffer[MAX_STRING_SIZE + 1];
BagOfWords _bag;
BagOfWords _bag2;


bool isPalindromeWord(WordDescriptor *word) {
    char* end=word->end;
    char* begin=word->begin;
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return false;
        begin++;
        end--;
    }
    return true;
}
void removePalindromeWord(char *s){
    char* begin=_stringBuffer;
    char* end= copy(s,s+ strlen_(s),_stringBuffer);
    char* rec_ptr=s;
    WordDescriptor word;
    while(getWord(begin,&word)){
        if(!isPalindromeWord(&word)) {
            rec_ptr = copy(word.begin, word.end, rec_ptr);
            if (word.end != end)
                *rec_ptr++ = ' ';
        }
        begin = word.end + 1;
    }

    *rec_ptr = '\0';

    free_string(_stringBuffer);
}
void test_removePalindromeWord1() {
    char s[] = "";
    removePalindromeWord(s);
    ASSERT_STRING("", s);
}
void test_removePalindromeWord2() {
    char s[] = "As pee sir, I see Pisa!";
    removePalindromeWord(s);
    ASSERT_STRING("As pee sir, see Pisa!", s);
}
void test_removePalindromeWord3(){
    char s[] = "radar spotted the tank";
    removePalindromeWord(s);
    ASSERT_STRING("spotted the tank", s);
}
void  test_removePalindromeWord4(){
    char s[] = "civic redder refer";
    removePalindromeWord(s);
    ASSERT_STRING("", s);
}

void test_removePalindromeWord(){
    test_removePalindromeWord1();
    test_removePalindromeWord2();
    test_removePalindromeWord3();
    test_removePalindromeWord4();
}
#endif //UNTITLED7_TASKS17_H
