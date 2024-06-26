#ifndef UNTITLED7_TASKS8_H
#define UNTITLED7_TASKS8_H
#include <stdlib.h>
#include "../strings//string/string_.h"
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

char* strShuffle(const char *symbols, const int *indices, int length) {
    char *res = malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; ++i) {
        char l=symbols[i];
        int r=indices[i];
        res[r]=l;
    }
    res[length]='\0';
    return res;
}

void test(){
    char s[]="abap";
    int indices[] = {0,3,2,1};
    char *res= strShuffle(s,indices,4);
    ASSERT_STRING("apab\0",res);
}

int main() {
    test();
}
#endif //UNTITLED7_TASKS8_H
