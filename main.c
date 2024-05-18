
#include <assert.h>
#include "libs/strings/string/string_.h"
#include <malloc.h>
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
char *MinStrlen(char *pattern) {
    int length = strlen_(pattern);
    int num[length + 1];
    for (int i = 0; i < sizeof(num) / sizeof(int); ++i) {
        num[i] = 1;
    }
    int currentNumber = 2;
    int lastIIndex = 0;
    for (int i = 0; i < length; ++i) {
        if (pattern[i] == 'I') {
            num[i + 1] = currentNumber++;
            lastIIndex = i + 1;
        } else {
            for (int j = i; j >= lastIIndex; j--) {
                num[j + 1] = num[j];
            }
            num[lastIIndex] = currentNumber++;
        }
    }
    char *res = (char *) malloc(sizeof(char) * (length + 2));
    for (int i = 0; i < sizeof(num) / sizeof(int); ++i) {
        res[i] = num[i] + '0';
    }
    res[length + 1] = '\0';
    return res;
}


void test() {
   char pattern1[]="IIIDIDDD";
   char pattern2[]="DDD";
    char *result1=MinStrlen(pattern1);
    char *result2=MinStrlen(pattern2);
    ASSERT_STRING("123549876",result1);
    ASSERT_STRING("4321",result2);
}

int main() {
    test();
}