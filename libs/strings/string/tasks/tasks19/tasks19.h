//
// Created by Assa on 21.04.2024.
//

#ifndef UNTITLED7_TASKS19_H
#define UNTITLED7_TASKS19_H
#include "../../string_.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>
#include <string.h>

#define MAX_STRING_SIZE 100
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 20
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
BagOfWords _bag;
BagOfWords _bag2;
#define Letters 97
bool letters_belong_string(char* string, WordDescriptor  word){
    bool include[26]={0};
    char* begin=string;
    char* end= getEndOfString(string);
    while (begin!=end){
        if(isalpha(*begin))
            include[*begin-Letters]=true;
        begin++;
    }
    while (word.begin!=word.end){
        if(!include[*word.begin-Letters])
            return false;
        word.begin++;
    }
    return true;
}
#endif //UNTITLED7_TASKS19_H
