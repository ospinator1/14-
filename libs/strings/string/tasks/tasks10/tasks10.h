

#ifndef UNTITLED7_TASKS10_H
#define UNTITLED7_TASKS10_H

#include "../../string_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void reverseWords(char *str) {
    char buffer[100];
    int i, j, k;
    for (i = 0; str[i] != '\0'; i++) {
        buffer[i] = str[i];
    }
    buffer[i] = '\0';

    i = i - 1;
    k = 0;
    while (i >= 0) {
        while (i >= 0 && buffer[i] != ' ') {
            i--;
        }
        j = i + 1;
        while (buffer[j] != '\0' && buffer[j] != ' ') {
            str[k++] = buffer[j++];
        }
        if (i >= 0) {
            str[k++] = ' ';
        }

        i--;
    }
    str[k] = '\0';
}
void test_reverseWords1(){
    char s[]="";
    char result[]="";
    reverseWords(s);
    ASSERT_STRING(result,s);
}
void test_reverseWords2(){
    char s[]="a b c d";
    reverseWords(s);
    ASSERT_STRING("d c b a",s);
}
void test_reverseWords3() {
    char s[] = "herald of darkness";
    reverseWords(s);
    ASSERT_STRING("darkness of herald", s);
}
void test_10(){
    test_reverseWords1();
    test_reverseWords2();
    test_reverseWords3();
}
#endif //UNTITLED7_TASKS10_H
