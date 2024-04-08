#include "libs/strings/string/string_.h"
#include <windows.h>
#include <assert.h>

void test_findLength1(){
    char str[] = "Hello";
    char ptr = findLength(str);
    assert(ptr==5);
}
void test_findLength2() {
    char str[] = "";
    char ptr = findLength(str);
    assert(ptr == 0);
}
void test_findLength3() {
    char str[] = "1111111111111111111111111222222222222222333333333333334444444444444445555";
    char ptr= findLength(str);
    assert(ptr!=50);
}
void test_findLength(){
    test_findLength1();
    test_findLength2();
    test_findLength3();
}

void test_strlen1(){
    char s[]="\0";
    char ptr= strlen_(s);
    assert(ptr==0);
}
void test_strlen2(){
    char s[10] = "Hell\t";
    char ptr= strlen_(s);
    assert(ptr==5);
}
void test_strlen(){
    test_strlen1();
    test_strlen2();
}
char* find(char *begin);

        void test_find(){
    char s[]="Hello\0";
    char *res=find(s);
    assert(res=='H');
    assert(res==s[1]);
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    test_findLength();
    test_strlen();
}
