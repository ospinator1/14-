

#include <stdint.h>
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/vector/vector.h"
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

void test_push() {
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
    assert(v.size==3);
    popBack(&v);
    assert(v.size==2);
    assert(v.capacity==3);

}
void test1(){
    test_popBack_emptyVector();
    test_popBack_FullVector();
}
void test_atVector_notEmptyVector(){
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
void test_clear(){
    vector v= vector_create(2);
    pushBack(&v,3);
    clear(&v);
    assert(isEmpty(&v));
}
void test_shrink_to_fit(){
    vector v=vector_create(6);
    pushBack(&v, 10);
    pushBack(&v, 421);
    pushBack(&v, 41);
    shrinkToFit(&v);
    assert(isFull(&v));
}

void test_delete_vector(){
    vector v= vector_create(4);
    pushBack(&v, 10);
    pushBack(&v, 421);
    pushBack(&v, 41);
    deleteVector(&v);
    assert(isEmpty(&v));
}
void test_get_vector_value(){
    vector v= vector_create(4);
    pushBack(&v, 10);
    pushBack(&v, 421);
    pushBack(&v, 41);
    int x=41;
    int y=421;
    getVectorValue(&v,2);
    assert(isFull(&v));
    assert(x==y);
}
void test_vector(){
    test_push();
    test1();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    test_clear();
    test_shrink_to_fit();
    test_delete_vector();
}
void test_pushBackV_empty_vector() {
    vectorVoid v = createVectorV(0, sizeof(int));
    v.size = 0;
    assert(isEmptyV(&v));
    int x=104;
    pushBackV(&v, &x);
    assert(v.size == 1 && v.capacity == 1);
}

void test_pushBackV_full_vector() {
    vectorVoid v = createVectorV(1, sizeof(int));
    v.size = 1;
    assert(isFull(&v));
    int x = 2;
    pushBackV(&v, &x);
    assert(v.size == 2 && v.capacity == 2);
}
void test_popBackV() {
    int array[] = {1, 2, 3};
    vectorVoid v = {array, 3, 3, sizeof(int)};
    popBackV(&v);
    assert(v.size == 2);
}
void test_getVectorValueV() {
    int a[] = {5, 3, 7};
    vectorVoid v = {a, 3, 3, sizeof(float)};
    int x = 5;
    float y = 2;
    getVectorValueV(&v, 2, &x);
    assert(isFullV(&v));
    assert(x == y);
}
void test_setVectorValueV() {
    int a[] = {5, 16, 7};
    vectorVoid v = {a, 3, 3, sizeof(float)};
    int  x = 8;
    setVectorValueV(&v, 2, &x);
    assert(isFullV(&v));
}
void test_clearV(){
    vector v= vector_create(2);
    pushBack(&v,3);
    clearV(&v);
    assert(isEmpty(&v));
}
void test_shrink_to_fitV(){
    vector v=vector_create(6);
    pushBack(&v, 10);
    pushBack(&v, 421);
    pushBack(&v, 41);
    shrinkToFitV(&v);
    assert(isFull(&v));
}
void test_vector_void(){
    test_pushBackV_empty_vector();
    test_pushBackV_full_vector();
    test_getVectorValueV();
    test_setVectorValueV();
    test_clearV();
    test_shrink_to_fitV();
}
void test(){
    test_vector();
    test_vector_void();
}
int main() {

    test();
}