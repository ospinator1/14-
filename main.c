#include <stdint.h>
#include <windows.h>
#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

void test_popBack_notEmptyVector() {
    vector v = vector_create(2);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity >= 1);
}

void test_pushBack_emptyVector() {
    vector v = vector_create(0);
    pushBack(&v, 1);
    assert(v.size == 1);
    assert(v.capacity >= 1);
    printf("test_pushBack_emptyVector OK\n");
}

void test_pushBack_fullVector() {
    vector v = vector_create(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(v.size == 2);
    assert(v.capacity >= 2);
    printf("test_pushBack_fullVector - OK\n");
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    printf("All OK\n");
}
int main() {
    test();
    vector v = vector_create(3);
    vector_add(&v, 1);
    vector_add(&v, 2);
    vector_add(&v, 7);
    pushBack(&v, 4);
    vector_print(v);

    return 0;
}