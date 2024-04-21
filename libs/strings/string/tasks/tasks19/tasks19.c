#include "../../string_.h"
#include <stdbool.h>
#include <assert.h>


#define MAX_STRING_SIZE 100

#include <ctype.h>


#define MAX_WORD_SIZE 20
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
BagOfWords _bag;
BagOfWords _bag2;
#define Letters 97

bool lettersBelongString(char *string, WordDescriptor word) {
    bool include[26] = {0};
    char *begin = string;
    char *end = getEndOfString(string);
    while (begin != end) {
        if (isalpha(*begin))
            include[*begin - Letters] = true;
        begin++;
    }
    while (word.begin != word.end) {
        if (!include[*word.begin - Letters])
            return false;
        word.begin++;
    }
    return true;
}

void test_lettersBelongString1() {
    char s[] = "";
    WordDescriptor word;
    getWord("", &word);
    assert(!lettersBelongString(s, word));
}

void test_lettersBelongString2() {
    char s[] = "alan wake";
    WordDescriptor word;
    getWord("ala", &word);
    assert(lettersBelongString(s, word));
}

void test_lettersBelongString3() {
    char s[] = "abc fkan";
    WordDescriptor word;
    getWord("word", &word);
    assert(!lettersBelongString(s, word));
}

void test_lettersBelongString4() {
    char s[] = "abc fkan";
    WordDescriptor word;
    getWord("", &word);
    assert(!lettersBelongString(s, word));
}

void test_lettersBelongString() {
    test_lettersBelongString1();
    test_lettersBelongString2();
    test_lettersBelongString3();
    test_lettersBelongString4();
}