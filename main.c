
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
void test_front() {
    int elements[] = {1, 2, 3, 4, 5};
    vector v = vector_array(elements, 5);
    int* front = vector_front(&v); // Получаем указатель на первый элемент
    if (front != nullptr) { // Проверяем, что указатель не нулевой
        printf("%d\n", *front); // Разыменовываем указатель и печатаем значение
    } else {
        printf("Vector is empty or not valid\n");
    }
}
void test_back() {
    int capacity=9;
    int elements[] = {1, 2, 3, 4, 6};
    vector v = vector_array(elements, 5);
    int *front = back(&v); // Получаем указатель на последний элемент
    printf("%d\n", *front); // Разыменовываем указатель и печатаем значение
}

int main() {
    test_back();
    return 0;
}