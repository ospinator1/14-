//
// Created by Assa on 18.04.2024.
//

#ifndef UNTITLED7_TASKS8_H
#define UNTITLED7_TASKS8_H
#define MAX_N_WORDS_IN_STRING 100

#include <stdio.h>
#include "../../string_.h"
#include <stdbool.h>
bool isPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return false;
        begin++;
        end--;
    }
    return true;
}
int countPalindromes(char *string){
    char *endSearch= getEndOfString(string);
    char *beginSearch= findNonSpace(string);
    int count=0;
    char *commaPos=find(beginSearch,endSearch,',');
    bool isLastComma=*commaPos=='\0' && endSearch!=beginSearch;
    while(*commaPos!='\0' || isLastComma){
        beginSearch= findNonSpace(beginSearch);
        count+= isPalindrome(beginSearch,commaPos);
        beginSearch=commaPos+1;
        if(isLastComma)
            break;
        commaPos= find(beginSearch,endSearch,',');
        isLastComma=*commaPos=='\0';
    }
    return count;
}
#endif //UNTITLED7_TASKS8_H
