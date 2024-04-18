//
// Created by Assa on 18.04.2024.
//

#ifndef UNTITLED7_TASKS6_H
#define UNTITLED7_TASKS6_H
#include "../../string_.h"
#include <stdio.h>
#include <stdbool.h>
bool isWhetherTheWordsOfTheGivenSentenceAreLexicographicallyOrdered(char *s){
    char *beginSearch=s;
   struct WordDescriptor currentWord;
    if(!getWord(beginSearch,&currentWord))
        return true;
    struct WordDescriptor previousWord=currentWord;
    while (getWord(beginSearch,&currentWord)){
        if(areWordsEqual(currentWord,previousWord)<0)
            return false;
        beginSearch=currentWord.end;
        previousWord=currentWord;
    }
}
#endif //UNTITLED7_TASKS6_H
