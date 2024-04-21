#include "../../string_.h"
#include <assert.h>

#define MAX_STRING_SIZE 100


#define MAX_WORD_SIZE 20
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
BagOfWords _bag;
BagOfWords _bag2;
char _stringBuffer[MAX_STRING_SIZE + 1];

void getWordExceptLast(char* source, char* dest) {
    char *beginSearch = source;
    while (getWordWithoutSpace(beginSearch, &_bag.words[_bag.size])) {
        beginSearch = _bag.words[_bag.size].end + 1;
        _bag.size++;

    }
    if (_bag.size == 0) {
        free_bag(&_bag);
        return;
    }
    WordDescriptor last_word = _bag.words[_bag.size - 1];
    char *rec_ptr = dest;
    for (size_t i = 0; i < _bag.size - 1; i++) {
        if (!isWordsEqual(_bag.words[i], last_word)) {
            rec_ptr = copy(_bag.words[i].begin, _bag.words[i].end + 1, rec_ptr);
            if (i != _bag.size - 2)
                *rec_ptr++ = ' ';
        }
    }
    *rec_ptr='\0';
    free_bag(&_bag);
}
void test_getWordExceptLast1(){
    char source[]="";
    char dest[100]="";
    getWordExceptLast(source,dest);
    ASSERT_STRING("",dest);
}
void test_getWordExceptLast2(){
    char source[]="word";
    char dest[100]="";
    getWordExceptLast(source,dest);
    ASSERT_STRING("",dest);
}

void test_getWordExceptLast3(){
    char source[]="Cherry Lady Cherry";
    char dest[100]="";
    getWordExceptLast(source,dest);
    ASSERT_STRING("Lady",dest);
}
void test_getWordExceptLast(){
    test_getWordExceptLast1();
    test_getWordExceptLast2();
    test_getWordExceptLast3();
}