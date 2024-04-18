//
// Created by Assa on 18.04.2024.
//

#ifndef UNTITLED7_TASKS5_H
#define UNTITLED7_TASKS5_H
#include "../../string_.h"
#include <stdio.h>
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа

} WordDescriptor;
int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    return strcmp(w1.begin, w2.begin);
}
void replace(char *source,char *w1,char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    struct WordDescriptor word1 = {w1, w1 + w1Size};
    struct WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;
    struct WordDescriptor word_2={readPtr, readPtr + w1Size};
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        if (*readPtr == *word1.begin) {
            if (areWordsEqual(word1, word_2 )<= 0) {

                copy(word2.begin,word2.end,recPtr);
                readPtr+=w1Size;
                recPtr+=w2Size;
            }else
                *recPtr++=*readPtr++;
        }else
            *recPtr++=*readPtr++;
    }
    *recPtr='\0';
}

void test_replaceWord1ToWord2_nonWords() {
    char s[] ="";
    replace(s, "Barcelona", "Madrid");
    ASSERT_STRING("", s);
}
void test_replaceWord1ToWord2_nonWord1() {
    char s[] ="Hello America";
    replace(s, "America", "Russia");
    ASSERT_STRING("Hello Russia", s);
}

void test_replaceWord1ToWord2_withWord1() {
    char s[] ="Alan Wake";
    replace(s, "Mike", "John");
    ASSERT_STRING("Alan Wake", s);
}
void test_replaceWord1ToWord2() {
    test_replaceWord1ToWord2_nonWords();
    test_replaceWord1ToWord2_nonWord1();
    test_replaceWord1ToWord2_withWord1();
}


#endif //UNTITLED7_TASKS5_H
