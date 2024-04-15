#include "libs/strings/string/string_.h"
#include <windows.h>
#include <stdio.h>
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#include <stdio.h>
#define IN 1
#define OUT 0

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
struct WordDescriptor{
    char *begin;
    char *end;
} WordDescriptor;
void digitToStartWithReverse(struct WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}
int getWord(char *beginSearch, struct WordDescriptor *word){
    word->begin= findNonSpace(beginSearch);
    if(*word->begin=='\0')
        return 0;
    word->end= findSpace(word->begin);
    return 1;
}
void digitToStartWithReverseForEveryWord(char *s){
    char *beginSearch=s;
    struct WordDescriptor word;
    while (getWord(beginSearch,&word)){
        digitToStartWithReverse(word);
        beginSearch=word.end;
}
}
void digitToStartWithSave(struct WordDescriptor word){
    char *endStringBuffer=copy(word.begin,word.end,_stringBuffer);
    char *recPosition=copyIf(_stringBuffer, endStringBuffer, word.begin,isdigit);
    copyIf(_stringBuffer,endStringBuffer,recPosition,isalpha);
}
void digitToStartWithSaveForEveryWord(char *s) {
    char *beginSearch = s;
   struct WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithSave(word);
        beginSearch = word.end;
    }
}
        int main(){



}