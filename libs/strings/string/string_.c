//
// Created by Assa on 07.04.2024.
//
#include <stdio.h>

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