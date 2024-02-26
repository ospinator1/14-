
#include "libs/data_structures/vector/vector.h"

#include <stdio.h> // For UINT32_MAX
#include <stdint.h>
#include <windows.h>
#define nullptr NULL
void test_pushBack_emptyVector() {
    vector v = vector_create(1);
    pushBack(&v, 1);
    assert(v.size == 1);
    assert(v.capacity >= 1);

}

void test_pushBack_fullVector() {
    vector v = vector_create(1);
    pushBack(&v, 1);
    pushBack(&v, 2);
    assert(v.size == 2);
    assert(v.capacity >= 2);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();

}
void test_popBack_emptyVector() {
    vector v = vector_create(1);
    pushBack(&v, 2);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}
void test_popBack_FullVector() {
    vector v = vector_create(3);
    pushBack(&v, 10);
    pushBack(&v, 421);
    pushBack(&v, 41);
   printf("%d", vector_front(&v));

}
void test_at_vector_not_empty_vector() {
    vector v = vector_create(1);
    pushBack(&v, 5);
    assert(isFull(&v));

    int* element = atVector(&v, 0);

    assert(*element == 5);
}

void test_atVector_requestToLastElement() {
    int array[] = {1, 2, 3, 4, 5};
    vector v = {array, 5, 5};

    int *last_element = atVector(&v, v.size - 1);
    assert(*last_element == 5);
}

void test_back_oneElementInVector() {
    vector v = vector_create(2);
    pushBack(&v, 5);
    pushBack(&v, 6);
    assert(isFull(&v));

    int* element = back(&v);

    assert(*element == 6);
}

void test_front_oneElementInVector() {
    vector v = vector_create(2);
    pushBack(&v, 5);
    pushBack(&v, 6);
    assert(isFull(&v));

    int* element = vector_front(&v);

    assert(*element == 5);
}
int main() {



    return 0;
}