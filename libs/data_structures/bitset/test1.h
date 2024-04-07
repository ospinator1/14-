//
// Created by Assa on 18.02.2024.
//

#ifndef UNTITLED7_TEST1_H
#define UNTITLED7_TEST1_H



#include <assert.h>
#include "libs/data_structures/bitset/bitset.h"
void test_bitset_creat1(){
    bitset a = bitset_create(31);
}
void test_bitset_create2(){
    bitset b = bitset_create(31);
}
void test_bitset_create(){
    test_bitset_creat1();
    test_bitset_create2();
}

void test_bitset_in1(){
    bitset set1= bitset_create_from_array((uint32_t[]){1,2,3,4,5},5,6);
    assert(bitset_in(set1,5));
}
void test_bitset_in2(){
    bitset set1= bitset_create_from_array((uint32_t[]){1,2,3,4,5},5,6);
    assert(bitset_in(set1,4));
}
void test_bitset_in(){
    test_bitset_in1();
    test_bitset_in2();
}
void test_bitset_is_equal1(){
    bitset set1= bitset_create_from_array((uint32_t[]){1,2,3,4,5},5,6);
    bitset set2= bitset_create_from_array((uint32_t[]){1,2,3,4,5},5,6);
    assert(bitset_is_equal(set1,set2));
}
void test_bitset_is_equal2(){
    bitset set1= bitset_create_from_array((uint32_t[]){1,2,3,4,5},5,6);
    bitset set2= bitset_create_from_array((uint32_t[]){1,2,3,4,5},5,6);
    assert(bitset_is_equal(set1,set2));
}
void test_bitset_is_equal3(){
    bitset set1= bitset_create_from_array((uint32_t[]){1,2,3,4,6},5,6);
    bitset set2= bitset_create_from_array((uint32_t[]){1,2,3,4,6},5,6);
    assert(bitset_is_equal(set1,set2));
}
void test_bitset_is_equal4(){
    bitset set1= bitset_create_from_array((uint32_t[]){1,2,3,4},4,6);
    bitset set2= bitset_create_from_array((uint32_t[]){1,2,3,4},4,6);
    assert(bitset_is_equal(set1,set2));
}
void test_bitset_is_equal(){
    test_bitset_is_equal1();
    test_bitset_is_equal2();
    test_bitset_is_equal3();
    test_bitset_is_equal4();
}

void test_bitset_is_subset1(){
    bitset subset= bitset_create_from_array((uint32_t[]){1,2,3},3,6);
    bitset set= bitset_create_from_array((uint32_t[]){1,2,3,4},4,6);
    assert(bitset_is_subset(subset,set));
}
void test_bitset_is_subset2(){
    bitset subset= bitset_create_from_array((uint32_t[]){1,2,4},3,6);
    bitset set= bitset_create_from_array((uint32_t[]){1,2,3,4},4,6);
    assert(bitset_is_subset(subset,set));
}
void test_bitset_is_subset(){
    test_bitset_is_subset1();
    test_bitset_is_subset2();
}
void test_bitset_union1() {
    bitset set1 = bitset_create_from_array((uint32_t[]){1, 2, 3, 4, 5}, 5, 10);
    bitset set2 = bitset_create_from_array((uint32_t[]){4, 5, 6}, 3, 10);
    bitset res_set = bitset_union(set1, set2);
    bitset set3= bitset_create_from_array((uint32_t[]){1, 2, 3, 4, 5,6}, 6, 10);
    assert(bitset_is_equal(res_set,set3));
}
void test_bitset_union2() {
    bitset set1 = bitset_create_from_array((uint32_t[]) {1, 2, 3, 5}, 4, 10);
    bitset set2 = bitset_create_from_array((uint32_t[]) {4, 5, 6}, 3, 10);
    bitset res_set = bitset_union(set1, set2);
    bitset set3 = bitset_create_from_array((uint32_t[]) {1, 2, 3, 4, 5, 6}, 6, 10);
    assert(bitset_is_equal(res_set, set3));
}
void test_bitset_union(){
    test_bitset_union1();
    test_bitset_union2();
}
void test_bitset_intersection1() {
    unsigned array1[] = {1, 2, 3, 4, 5};
    unsigned array2[] = {1, 2, 3, 6};
    bitset set1 = bitset_create_from_array(array1, 5, 31);
    bitset set2 = bitset_create_from_array(array2, 4, 31);
    bitset set3 = bitset_intersection(set1, set2);
    bitset set4= bitset_create_from_array((uint32_t[]){1,2,3},3,31);
    assert(bitset_is_equal(set3,set4));
}
void test_bitset_intersection(){
    test_bitset_intersection1();
}
void test_bitset_difference1(){
    bitset set1 = bitset_create_from_array((uint32_t[]){1,2}, 2, 31);
    bitset set2 = bitset_create_from_array((uint32_t[]){1,2,4}, 3, 31);
    bitset set3 = bitset_difference(set1, set2);
    bitset set4= bitset_create_from_array((uint32_t[]){},0,31);
    assert(bitset_is_equal(set4,set3));
}
void test_bitset_difference2(){
    bitset set1 = bitset_create_from_array((uint32_t[]){1,2,3}, 3, 31);
    bitset set2 = bitset_create_from_array((uint32_t[]){1,2,4}, 3, 31);
    bitset set3 = bitset_difference(set1, set2);
    bitset set4= bitset_create_from_array((uint32_t[]){3},1,31);
    assert(bitset_is_equal(set4,set3));
}
void test_bitset_difference(){
    test_bitset_difference1();
    test_bitset_difference2();
}
void test_bitset_symmetric_difference1(){
    bitset set1 = bitset_create_from_array((uint32_t[]){1, 2, 3,4,5}, 5, 10);
    bitset set2 = bitset_create_from_array((uint32_t[]){1, 2, 3,6}, 4, 10);
    bitset set3= bitset_symmetric_difference(set1,set2);
    bitset set4= bitset_create_from_array((uint32_t[]){4, 5, 6}, 3, 10);
    assert(bitset_is_equal(set4,set3));
}
void test_bitset_symmetric_difference(){
    test_bitset_symmetric_difference1();
}
void test_bitset_complement1() {
    bitset set = bitset_create_from_array((uint32_t[]){}, 0, 6);
    bitset res_set = bitset_complement(set);
    assert(bitset_is_equal(set,res_set));
}
void test_bitset_complement(){
    test_bitset_complement1();
}

void test_delete1() {
    unsigned int arr1[] = {1,2,3,4};
    bitset set1 = bitset_create_from_array(arr1, 4, 10);
    bitset_delete_element(&set1, 4);

    unsigned int arr2[] = {1,2,3};
    bitset set3 = bitset_create_from_array(arr2, 3, 10);
    assert(bitset_is_equal(set1, set3));
}
void test_delete(){
    test_delete1();
}
void test_insert1(){
    bitset set1 = bitset_create(31); // Assuming max_value is the highest value allowed in the set
    bitset_insert(&set1, 1);
    bitset_insert(&set1, 2);
    bitset_insert(&set1, 3);
    bitset set2= bitset_create_from_array((uint32_t[]){1,2,3},3,10);
    assert(bitset_is_equal(set1,set2));
}
void test_insert(){
    test_insert1();
}
void test_bitset_print1(){
    uint32_t array[] = {1, 2, 3, 4, 5};
    bitset set1 = bitset_create_from_array(array, 5, 10);

}
void test_bitset_print(){
    test_bitset_print1();
}

void test(){
    test_bitset_create();
    test_bitset_in();
    test_bitset_is_equal();
    test_bitset_is_subset();
    test_insert();
    test_delete();
    test_bitset_union();
    test_bitset_intersection();
    test_bitset_difference();
    test_bitset_symmetric_difference();
    test_bitset_complement();
    test_bitset_print();
}
int main() {
    test();
    return 0;
}



#endif //UNTITLED7_TEST1_H
