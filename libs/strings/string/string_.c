//
// Created by Assa on 07.04.2024.
//
#include <stdio.h>
#include <ctype.h>
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