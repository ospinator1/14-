#include "libs/strings/string/string_.h"
#include <windows.h>
#include <assert.h>

void test_findLength1() {
    char str[] = "Hello";
    assert(findLength(str) == 5);
}

void test_findLength2() {
    char str[] = "";
    assert(findLength(str) == 0);
}

void test_findLength3() {
    char str[] = "1111111111111111111111111222222222222222333333333333334444444444444445555";
    assert(findLength(str) != 50);
}

void test_findLength() {
    test_findLength1();
    test_findLength2();
    test_findLength3();
}

void test_strlen1() {
    char s[] = "\0";
    assert(strlen_(s) == 0);
}

void test_strlen2() {
    char s[10] = "Hell\t";
    assert(strlen_(s) == 5);
}

void test_strlen() {
    test_strlen1();
    test_strlen2();
}


void test_find() {
    char s[] = "hello";
    assert(find(&s[0], &s[9], 'h') == &s[0]);
    assert(find(&s[0], &s[9], '0') == &s[9]);
    assert(find(&s[0], &s[9], 'e') == &s[1]);
}


void test_findNonSpace() {
    char s[] = " 12345";
    char s1[] = "12 34";
    assert(findNonSpace(s) == &s[1]);
    assert(*findNonSpace(s) == '1');
}

void test_findSpace() {
    char s[] = "123456789";
    char s1[] = "\t12344";
    char s2[] = "12 34";
    assert(*findSpace(s) == '\0');
    assert(*findSpace(s1) == '\t');
    assert(*findSpace(s2) == ' ');
}


void test_findNonSpaceReverse() {
    char *str = " 1234567890";;
    char *str1 = "123 123\t";
    char *str2 = "\t\t\t";
    assert(*findNonSpaceReverse(&str[10], &str[0]) == '0');
    assert(*findNonSpaceReverse(&str1[7], &str1[0]) == '3');
    assert(*findNonSpaceReverse(&str2[2], &str2[0]) == '\0');
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while(rbegin>=rend && !isspace(*rbegin))
        rbegin--;
    return rbegin;
}

void test_findSpaceReverse() {
    char *str = "1234567890";;
    char *str1 = "ABCDE";
    char *str2 = "AB DE";
    assert(*findSpaceReverse(&str[10], &str[0]) == '\0');
    assert(findSpaceReverse(&str1[5],&str1[0])==&str1[-1]);
    assert(findSpaceReverse(&str2[10], &str2[0]) == &str2[2]);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    test_findLength();
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
}
