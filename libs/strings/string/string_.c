//
// Created by Assa on 07.04.2024.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
char findLength(char str[50]) {
    char length = printf("%s\n",str);
    return length - 1;
}
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