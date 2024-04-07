#include <stdio.h>
#include "libs/strings/string/string_.h"
#include <windows.h>
#include <assert.h>



void test_findLength(){
    char str[] = "Hello";
    char ptr = findLength(str);
    printf("%d",ptr);
}
int main() {
    test_findLength();
}
