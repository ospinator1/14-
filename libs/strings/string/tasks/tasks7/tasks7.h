//
// Created by Assa on 18.04.2024.
//

#ifndef UNTITLED7_TASKS7_H
#define UNTITLED7_TASKS7_H
#define MAX_N_WORDS_IN_STRING 100

#include <stdio.h>
#include "../../string_.h"
char _stringBuffer[MAX_STRING_SIZE + 1];
typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа

} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

void printWord(WordDescriptor word){
    char *endBuffer=copy(word.begin,word.end,_stringBuffer);
    *endBuffer='\0';
    printf("%s",_stringBuffer);
}
int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}
void getBagOfWords(BagOfWords *bag, char *s){
    char *beginSearch=s;
    bag->size=0;
    WordDescriptor word;
    while(getWord(beginSearch,&word)){
        bag->words[bag->size]=word;
        bag->size++;
        beginSearch=word.end;
    }
}
void printWordReverse(char *string){
    BagOfWords w;
    getBagOfWords(&w,string);
            for (int i = w.size-1; i >=0 ; --i) {
                printWord(w.words[i]);
                printf("\n");
            }
}
void test_printWordReverse(){
    char s[]="abc bad";
    printWordReverse(s);
}

#endif //UNTITLED7_TASKS7_H
