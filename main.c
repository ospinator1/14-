
#include "libs/strings/string/tasks/tasks1/tasks1.h"
#include "libs/strings/string/tasks/tasks2/tasks2.h"
#include "libs/strings/string/tasks/tasks3/tasks3.h"
#include "libs/strings/string/tasks/tasks4/tasks4.h"
#include "libs/strings/string/string_.h"
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

int areWordsEqual(struct WordDescriptor w1, struct WordDescriptor w2) {
    return strcmp(w1.begin, w2.begin);
}
void replace(char *source,char *w1,char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    struct WordDescriptor word1 = {w1, w1 + w1Size};
    struct WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }
    struct WordDescriptor word_2={readPtr, readPtr + w1Size};
    while (*readPtr != '\0') {
        if (*readPtr == *word1.begin) {
            if (areWordsEqual(word1, word_2) <= 0) {

                copy(word2.begin,word2.end,recPtr);
                readPtr+=w1Size;
                recPtr+=w2Size;
            }else
                *recPtr++=*readPtr++;
        }else
            *recPtr++=*readPtr++;
    }
    recPtr="\0";
}


int main() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_digitToStartWithReverseForEveryWord();
    test_digitToStartWithSave();
    test_replaceEachNumberWithSpaces();

}
