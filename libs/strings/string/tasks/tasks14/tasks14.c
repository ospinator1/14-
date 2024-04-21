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
BagOfWords _bag;
BagOfWords _bag2;
char _stringBuffer[MAX_STRING_SIZE + 1];

int compare_letters(void* s1,void* s2){
    return *(char*)s1-*(char *) s2;
}
void sortWordLetters(WordDescriptor *word){
    qsort(word->begin,word->end-word->begin, sizeof (char ), (int (*)(const void *, const void *)) compare_letters);
}
bool areIdenticalWordsInString(char* s) {
    char *beginBuffer = _stringBuffer;
    copy(s, s + strlen_(s), _stringBuffer);
    while (getWordWithoutSpace(beginBuffer, &_bag.words[_bag.size])) {
        beginBuffer = _bag.words[_bag.size].end + 2;
        _bag.size++;

    }
    free_string(_stringBuffer);
    if (_bag.size <= 1)
        return false;
    for (size_t i = 0; i < _bag.size; ++i)
        sortWordLetters(&_bag.words[i]);
    for (size_t i = 0; i < _bag.size; ++i)
        for (size_t j = 0; j < _bag.size; ++j)
            if (isWordsEqual(_bag.words[i], _bag.words[j])){
                free_bag(&_bag);
                return true;
            }
    free_bag(&_bag);
    return false;
}
void test_areIdenticalWordsInString1(){
    char s[]="";
    assert(!areIdenticalWordsInString(s));
}
void test_areIdenticalWordsInString2(){
    char s[]="Cherry Cherry Lady";
    assert(areIdenticalWordsInString(s));
}
void test_areIdenticalWordsInString3(){
    char s[]="Alan Wake";
    assert(areIdenticalWordsInString(s));
}
void test_areIdenticalWordsInString(){
    test_areIdenticalWordsInString1();
    test_areIdenticalWordsInString2();
    test_areIdenticalWordsInString3();
}