//
// Created by Assa on 06.04.2024.
//
#include <stdio.h>
#include <stdbool.h>
void input(int *a, int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void output(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
}
void combinations_of_A_and_B(const int *A, const int *B, int *C, int KA, int KB, int *KC) {
    int index_c = 0;
    for (int i = 0; i < KA; i++) {
        C[index_c++] = A[i];
    }
    for (int i = 0; i < KA; i++) {
        int flag= 1;
        for (int j = 0; j < KB; j++) {
            if (B[i] == A[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            C[index_c++] = B[i];
        }
    }
    (*KC) = index_c;
}
void intersection_of_sets_A_and_B(const int *A, const int *B, int *C, int KA, int KB, int *KC)
{
    int index_c = 0;
    for (int i = 0; i < KA; i++) {
        for (int j = 0; j < KB; j++) {
            if (A[i] == B[j]) {
                C[index_c] = A[i];
                index_c++;
            }
        }
    }
    (*KC) = index_c;
}
void difference_between_sets_A_and_B(int *A,int *B,int *C,int KA,int KB,int *KC){
    int index_c=0;
    for (int i = 0; i < KA; i++) {
        int index = KB;
        for (int j = 0; j < KB; j++) {
            if (B[j] == A[i]) {
                index = j;
                break;
            }
        }
        if (index == KB) {
            C[index_c] = A[i];
            index_c++;
        }
    }*KC=index_c;
}
void symmetric_difference_between_sets_A_and_B(const int *A, int KA, const int *B, int KB, int
*C, int *KC) {
    int index_c = 0;
    for (int i = 0; i < KA; i++) {
        int index = KB;
        for (int j = 0; j < KB; j++) {
            if (B[j] == A[i]) {
                index = j;
                break;
            }
        }
        if (index == KB) {
            C[index_c] = A[i];
            index_c++;
        }
    }
    for (int i = 0; i < KB; i++) {
        int index = KA;
        for (int j = 0; j < KA; j++) {
            if (A[j] == B[i]) {
                index = j;
                break;
            }
        }
        if (index == KA) {
            C[index_c] = B[i];
            index_c++;
        }
    }
    (*KC) = index_c;
}
bool contains(const int *A, int KA, int element) {
    for (int i = 0; i < KA; i++) {
        if (A[i] == element) {
            return true;
        }
    }
    return false;
}
bool is_included(int *A, int KA, int *B, int KB) {
    if (KA > KB) {
        return false;
    }
    for (int i = 0; i < KA; ++i) {
        if (!contains(B, KB, A[i]))
            return false;
    }
    return true;
}

bool isEqual(const int *A, int KA,const int *B, int KB) {
    if (KA != KB)
        return false;
    for (int i = 0; i < KA; i++) {
        if (A[i] != B[i])
            return false;
    }
    return true;
}
bool is_strict_includes(const int *A, int KA, const int *B, int KB){
    return (is_included(A,KA,B,KB)&& !isEqual(A,KA,B,KB));
}
void union_set_ordered(const int *A, int KA, int *B, int KB, int *C, int *KC) {
    int i = 0;
    int j = 0;
    int index_c = 0;
    while (i < KA && j < KB) {
        if (j == KB || A[i] < B[j]) {
            C[index_c] = A[i];
            index_c++;
            i++;
        } else if (i == KA || A[i] > B[j]) {
            C[index_c] = B[j];
            index_c++;
            j++;
        } else {
            C[index_c] = A[i];
            index_c++;
            i++;
            j++;
        }
    }
    while (i < KA) {
        C[index_c] = A[i];
        index_c++;
        i++;
    }

    while (j < KB) {
        C[index_c] = B[j];
        index_c++;
        j++;
    }
    *KC = index_c;
}
void intersection_of_sets_ordered_A_and_B(const int *A, int KA, int *B, int KB, int *C, int
*KC) {
    int i = 0;
    int j = 0;
    int index_c = 0;
    while (i < KA && j < KB) {
        if (A[i] == B[j]) {
            C[index_c++] = A[i];
            i++;
            j++;
        }else if
                (A[i]>B[j])
            j++;
        else{
            i++;
        }
    }
    *KC=index_c;
}
void difference_ordered(const int *A, int KA, const int *B, int KB, int *C, int *KC) {
    int i = 0;
    int j = 0;
    int index_c = 0;
    while (i < KA && j < KB) {
        if (A[i] == B[j]) {
            i++;
            j++;
        } else if
                (A[i] > B[j])
            j++;
        else {
            C[index_c++] = A[i++];
        }
    }
    while (i < KA) {
        C[index_c++] = A[i++];
    }
    *KC = index_c;
}
void symmetric_difference_between_sets_ordered_A_and_B(const int a[], const int b[], int *c,
                                                       int size_a, int size_b, int *size_c) {
    int i = 0;

    int j = 0;
    int index_c=0;
    while (i < size_a && j < size_b) {
        if (a[i] < b[j]) {
            c[index_c++] = a[i];
            i++;
        } else if (a[i] > b[j]) {
            c[index_c++] = b[j];
            j++;
        } else {
            i++;
            j++;
        }
    }
    while (i < size_a) {
        c[index_c++] = a[i];
        i++;
    }
    while (j < size_b) {
        c[index_c++] = b[j];
        j++;
    }
    (*size_c)=index_c;
}
bool is_included_ordered(const int *A, const int *B, int KA, int KB) {
    int i = 0, j = 0;
    while (i < KA && j < KB) {
        if (A[i] < B[j]) {
            return false;
        } else if (A[i] > B[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    return i == KA;
}
bool is_equal_ordered(const int *A, int KA,const int *B, int KB) {
    if (KA!= KB) return false;
    for (int i = 0; i < KA; i++) {
        if (A[i] != B[i])
            return false;
    }
    return true;
}
bool is_strict_includes_ordered(const int *A,int KA,const int *B,int KB){
    return (is_included_ordered(A,B,KA,KB)&&!is_equal_ordered(A,KA,B,KB));
}

