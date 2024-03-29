
#include "libs/data_structures/matrix//matrix.h"
#include <malloc.h>
#include <windows.h>
#include "libs/algorithms/basic_functions/basic_functions.h"
#include <assert.h>
#include <math.h>
int getMaxElementRow(matrix m) {
    int max = m.values[0][0];
    int row = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > max) {
                max = m.values[i][j];
                row = i;
            }
        }
    }
    return row;
}

int getMinElementRow(matrix m) {
    int min = m.values[0][0];
    int row = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                row = i;
            }
        }
    }
    return row;
}

int getMax(int *a, int n){
    int max=0;
    for (int i = 0; i < n; ++i) {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

void sortRowsByMinElement(matrix m){
    insertionSortRowsMatrixByRowCriteria(&m, getMax);
}
void test_sortRowsMaxAndMinElement(){
    matrix m1= createMatrixFromArray(
            (int[]) {
                    1,2,3,
                    4,5,6,
                    7,8,9


            },
            3, 3
    );

    matrix m2= createMatrixFromArray(
            (int[]) {
                    7,8,9,
                    4,5,6,
                    1,2,3


            },
            3, 3
    );
    int minRow = getMinElementRow(m1);
    int maxRow = getMaxElementRow(m1);
    swapRows(&m1,minRow,maxRow);
    assert(areTwoMatricesEqual(&m1,&m2));
}
void test_sortRowsByMinElement(){
    int a={1,2,3,4,5};
    assert(getMax(&a,5));
    matrix m1= createMatrixFromArray(
            (int[]) {
                    7,1,2,
                    1,8,1,
                    3,2,3


            },
            3, 3
    );
    matrix m2= createMatrixFromArray(
            (int[]) {
                    3,2,3,
                    7,1,2,
                    1,8,1


            },
            3, 3
    );
    sortRowsByMinElement(m1);
    assert(areTwoMatricesEqual(&m1,&m2));
}
int getMin(int *a, int n){
    int min=a[0];
    for (int i = 1; i < n; ++i) {
        if(a[i]<min)
            min=a[i];
    }
    return min;
}
void sortColsByMinElement(matrix m){
    selectionSortColsMatrixByColCriteria(&m,getMin);
}
void test_sortColsByMinElement(){
    SetConsoleOutputCP(CP_UTF8);
    int a={1,2,3,4,5};
    assert(getMin(&a,1));
    matrix m1 = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 1,
                                               2, 5, 1, 8, 1, 7,
                                               1, 1, 4, 1, 8, 3}, 3, 6);

    matrix m2 = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 1,
                                               2, 5, 1, 8, 1, 7,
                                               1, 1, 4, 1, 8, 3}, 3, 6);

    sortColsByMinElement(m1);

    assert(areTwoMatricesEqual(&m1, &m2));
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    int a={1,2,3,4,5};
    assert(getMin(&a,1));
    matrix m1 = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 1,
                                                 2, 5, 1, 8, 1, 7,
                                                 1, 1, 4, 1, 8, 3}, 3, 6);

    matrix m2 = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 1,
                                                     2, 5, 1, 8, 1, 7,
                                                     1, 1, 4, 1, 8, 3}, 3, 6);

   sortColsByMinElement(m1);

    assert(areTwoMatricesEqual(&m1, &m2));
}