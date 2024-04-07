//
// Created by Assa on 06.04.2024.
//

#ifndef UNTITLED7_ДИСКРЕТКА_H
#define UNTITLED7_ДИСКРЕТКА_H
#include <stdbool.h>
void combinations_of_A_and_B(const int *A, const int *B, int *C, int KA, int KB, int *KC);
void intersection_of_sets_A_and_B(const int *A, const int *B, int *C, int KA, int KB, int *KC);
void intersection_of_sets_A_and_B(const int *A, const int *B, int *C, int KA, int KB, int *KC);
void symmetric_difference_between_sets_A_and_B(const int *A, int KA, const int *B, int KB, int
*C, int *KC);
bool is_included(int *A, int KA, int *B, int KB);
bool is_strict_includes(const int *A, int KA, const int *B, int KB);
void union_set_ordered(const int *A, int KA, int *B, int KB, int *C, int *KC);
void intersection_of_sets_ordered_A_and_B(const int *A, int KA, int *B, int KB, int *C, int
*KC);
void difference_ordered(const int *A, int KA, const int *B, int KB, int *C, int *KC);
void symmetric_difference_between_sets_ordered_A_and_B(const int a[], const int b[], int *c,
                                                       int size_a, int size_b, int *size_c);
bool is_included_ordered(const int *A, const int *B, int KA, int KB);
bool is_strict_includes_ordered(const int *A,int KA,const int *B,int KB);
#endif //UNTITLED7_ДИСКРЕТКА_H
