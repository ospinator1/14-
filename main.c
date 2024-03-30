
#include "libs/data_structures/matrix//matrix.h"
#include <malloc.h>
#include <windows.h>
#include "libs/algorithms/basic_functions/basic_functions.h"
#include <assert.h>
#include <math.h>
#include "libs/algorithms/array/array.h"
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
    int a={1,2,3,4,5};
    assert(getMin(&a,5));
    matrix m1 = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 1,
                                               2, 5, 1, 8, 1, 7,
                                               1, 1, 4, 1, 8, 3}, 3, 6);

    matrix m2 = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 1,
                                               2, 5, 1, 8, 1, 7,
                                               1, 1, 4, 1, 8, 3}, 3, 6);

    sortColsByMinElement(m1);

    assert(areTwoMatricesEqual(&m1, &m2));
}

matrix mulMatrices(matrix m1, matrix m2) {
    printf("Resultant Matrix is:\n");

    int result[m1.nRows][m2.nCols];
    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < m2.nRows; ++k) {
                result[i][j] += m1.values[i][k] * m2.values[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
void getSquareOfMatrixIfSymmetric(matrix *m){
    if(isSymmetricMatrix(m)==1)
        mulMatrices(*m,*m);
    else
        outputMatrix(&m);
}
void test_getSquareOfMatrixIfSymmetric(){
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 5, 6,
                                              3, 6, 9}, 3, 3);

    matrix m2= createMatrixFromArray((int[]) {14, 30, 42,
                                              30, 65, 90,
                                              42, 90, 126}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    assert(areTwoMatricesEqual(&m1, &m2));

}

bool isUnique(int *a,int n) {
    for (int i = 0; i < n; ++i) {
            if (a[i] == a[i+1]) {
                return false;

        }

    }
    return true;
}
int getSum(int *a,int n){
    int sum=0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}
void transposeIfMatrixHasNotEqualSumOfRows(matrix m){
    int *sum=(int *)(malloc(sizeof(int)*m.nRows));
    for (int i = 0; i < m.nRows; ++i)
        sum[i]= getSum(m.values[i],m.nCols);
    if(isUnique(sum,m.nRows)){
        transposeSquareMatrix(&m);
    }else
        outputMatrix(&m);
}
int test_transposeIfMatrixHasNotEqualSumOfRows(){
    SetConsoleOutputCP(CP_UTF8);
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               0, 1, 1,
                                               3, 6, 9}, 3, 3);

    matrix m2= createMatrixFromArray((int[]) {1, 0, 3,
                                              2, 1, 6,
                                              3, 1, 9}, 3, 3);
    int a[5]={1,2,3,4,5};
    int result= getSum(&a,5);
    assert(result==15);
    int result1= isUnique(a,5);
    assert(result1==1);

    transposeIfMatrixHasNotEqualSumOfRows(m1);
    assert(areTwoMatricesEqual(&m1,&m2));
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2){
    matrix result1= mulMatrices(m1,m2);
    matrix result2= mulMatrices(m2,m1);
    bool E=isEMatrix(&result1)&& isEMatrix(&result2);
    return E;
}
void test_isMutuallyInverseMatrices(){
    matrix m1 = createMatrixFromArray((int[]) {2, 0, 1,
                                               1, 5, -4,
                                               -1, 1, 0}, 3, 3);

    matrix m2= createMatrixFromArray((int[]) {-4, 0, 3,
                                              2, 1, 6,
                                              3, 1, 9}, 3, 3);

    assert(!isMutuallyInverseMatrices(m1,m2));
}
int max2(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
long long findSumOfMaxesOfPseudoDiagonal(matrix m){
    int* max_value=(int*) malloc(sizeof(int)*(m.nRows+m.nCols-1));
    for(int i=0;i<m.nRows+m.nCols-1;i++){
        max_value[i]=0;
    }
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
             if(i!=j){
                 max_value[i-j+m.nCols-1]=max(max_value[i-j+m.nCols-1],m.values[i][j]);
             }
        }
    }
    long long sum=0;
    for (int i = 0; i < m.nRows+m.nCols-1; ++i) {
        sum += max_value[i];

    }
    return sum;
}
void test_findSumOfMaxesOfPseudoDiagonal(){
    matrix m1 = createMatrixFromArray((int[]) {3,2,5,4,
                                               1, 3,6,3,
                                               3,2,1,2}, 3, 4);


    int a=3;
    int b=5;
    int result= max2(a,b);
    assert(result==5);
    int result1= findSumOfMaxesOfPseudoDiagonal(m1);
    assert(result1=20);
}
bool value_is_in_the_area(position posit,int i,int j){
    position new={i-posit.rowIndex,j-posit.rowIndex};
    return (new.rowIndex<=new.colIndex);
}
int getMinInArea(matrix m){
    position max= getMaxValuePos(m);
    int min=INT_MAX;

    for (int i = 0; i <= max.rowIndex; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (value_is_in_the_area(max,i,j) && m.values[i][j] < min) {
                min = m.values[i][j];
            }
        }
    }

    return min;
}
void test_getMinInArea(){
    matrix m1 = createMatrixFromArray((int[]) {10,7,5,6,
                                               3,11,8,9,
                                               4,1,12,2}, 3, 4);


    position posit={3,2};
    int result= value_is_in_the_area(posit,3,3);
    assert(result==1);
    int result1= getMinInArea(m1);
    assert(result1==2);
}
int main(){

    matrix m1 = createMatrixFromArray((int[]) {10,7,5,6,
                                                 3,11,8,9,
                                                 4,1,12,2}, 3, 4);

    matrix m2= createMatrixFromArray((int[]) {-4, 0, 3,
                                                     2, 1, 6,
                                                     3, 1, 9}, 3, 3);
    position posit={3,2};
    int result= value_is_in_the_area(posit,3,3);
    assert(result==1);
    int result1= getMinInArea(m1);
    assert(result1==2);
}
