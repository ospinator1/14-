//
// Created by Assa on 07.04.2024.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../../strings/string/string_.h"
#define MAX_STRING_SIZE 100
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)


int strlen_(const char *begin ){
    char *end=begin;
    while (*end!='\0')
        end++;
    return end-begin;
}
char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin!='\0' && isspace(*begin)){
        begin++;
    }
    return begin;
}
char *findSpace(char *begin){
    while (*begin!='\0' && !isspace(*begin)) {
        begin++;
    }
    return begin;
}
char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while(rbegin>=rend && isspace(*rbegin))
        rbegin--;
    return rbegin;
}
char *findSpaceReverse(char *rbegin, const char *rend) {
    while(rbegin>=rend && !isspace(*rbegin))
        rbegin--;
    return rbegin;
}
char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    int size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);
    *(beginDestination + size) = '\0';
    return beginDestination + size;
}
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    *beginDestination = '\0';

    return beginDestination;
}
int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}
int isLetter(int x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*(rbeginSource - 1))) {
            *beginDestination = *(rbeginSource - 1);
            beginDestination++;
        }
        rbeginSource--;
    }
    beginDestination[*(rbeginSource - 1)] = '\0';
    return beginDestination;
}

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


bool getWordReverse(char *rbegin, char *rend,struct WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend) + 1;
    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend) + 1;

    return true;
}
char *getEndOfString(char *s) {
    return s + strlen(s);
}
bool getWordWithoutSpace(char* begin_search, WordDescriptor * word) {
    word->begin = findNonSpace(begin_search);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin) - 1;

    return true;
}

bool isWordsEqual(const WordDescriptor word1, const WordDescriptor  word2) {
    char* begin1 = word1.begin;
    char* begin2 = word2.begin;

    while (begin1 < word1.end && begin2 < word2.end) {
        if (*begin1 != *begin2)
            return false;

        begin1++;
        begin2++;
    }

    if (word1.end - begin1 > 0 || word2.end - begin2 > 0)
        return false;

    return true;
}

void free_string(char* string) {
    char* ptr = string;
    while (*ptr) {
        *ptr = '\0';
        ptr++;
    }
}
void free_bag(BagOfWords * bag) {
    for (size_t i = 0; i < bag->size; i++) {
        bag->words[i].begin = NULL;
        bag->words[i].end = NULL;
    }

    bag->size = 0;
}
void wordDescriptorToString(WordDescriptor word, char* dest) {
    if (word.begin == NULL && word.end == NULL)
        return;

    while (word.begin <= word.end) {
        *dest = *word.begin;
        word.begin++;
        dest++;
    }

    *dest = '\0';
}
int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}
