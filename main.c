#include <stdio.h>
#include "libs/strings/string/string_.h"
#include <windows.h>
#include <assert.h>


char findLength(char str[50]) {
   return strlen(str);
}
void test_findLength(){
    char str[] = "Hello";
    char ptr = findLength(str);
    assert(ptr==5);
}
void test_findLength1() {
    char str[] = "";
    char ptr = findLength(str);
    assert(ptr == 0);
}
void test_findLength2() {
    char str[] = "1111111111111111111111111222222222222222333333333333334444444444444445555";
    char ptr= findLength(str);
    assert(ptr!=50);
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    test_findLength();
    test_findLength1();
    test_findLength2();
}
