#define MAX_N_WORDS_IN_STRING 100

#include <stdio.h>
#include "../../string_.h"
char _stringBuffer[MAX_STRING_SIZE + 1];


void printWord(WordDescriptor word){
    char *endBuffer=copy(word.begin,word.end,_stringBuffer);
    *endBuffer='\0';
    printf("%s",_stringBuffer);
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