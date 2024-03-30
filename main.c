
#include "libs/data_structures/matrix//matrix.h"
#include <windows.h>
#include "libs/algorithms/basic_functions/basic_functions.h"
#include <assert.h>




void test_sortRowsMaxAndMinElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9


            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    4, 5, 6,
                    1, 2, 3


            },
            3, 3
    );
    int minRow = getMinElementRow(m1);
    int maxRow = getMaxElementRow(m1);
    swapRows(&m1, minRow, maxRow);
    assert(areTwoMatricesEqual(&m1, &m2));
}

void test_sortRowsByMinElement() {
    int a = {1, 2, 3, 4, 5};
    assert(getMax(&a, 5));
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3


            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1


            },
            3, 3
    );
    sortRowsByMinElement(m1);
    assert(areTwoMatricesEqual(&m1, &m2));
}


void test_sortColsByMinElement() {
    int a = {1, 2, 3, 4, 5};
    assert(getMin(&a, 5));
    matrix m1 = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 1,
                                               2, 5, 1, 8, 1, 7,
                                               1, 1, 4, 1, 8, 3}, 3, 6);

    matrix m2 = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 1,
                                               2, 5, 1, 8, 1, 7,
                                               1, 1, 4, 1, 8, 3}, 3, 6);

    sortColsByMinElement(m1);

    assert(areTwoMatricesEqual(&m1, &m2));
}


void test_getSquareOfMatrixIfSymmetric() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               2, 5, 6,
                                               3, 6, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {14, 30, 42,
                                               30, 65, 90,
                                               42, 90, 126}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    assert(areTwoMatricesEqual(&m1, &m2));

}
void test_getSum(){
    int a[5] = {1, 2, 3, 4, 5};
    int result = getSum((int *) &a, 5);
    assert(result == 15);
}
void test_isUnique(){
    int a[5] = {1, 2, 3, 4, 5};
    int result1 = isUnique(a, 5);
    assert(result1 == 1);
}
int test_transposeIfMatrixHasNotEqualSumOfRows() {
    SetConsoleOutputCP(CP_UTF8);
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               0, 1, 1,
                                               3, 6, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 0, 3,
                                               2, 1, 6,
                                               3, 1, 9}, 3, 3);



    transposeIfMatrixHasNotEqualSumOfRows(m1);
    assert(areTwoMatricesEqual(&m1, &m2));
}



void test_isMutuallyInverseMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {2, 0, 1,
                                               1, 5, -4,
                                               -1, 1, 0}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {-4, 0, 3,
                                               2, 1, 6,
                                               3, 1, 9}, 3, 3);

    assert(!isMutuallyInverseMatrices(m1, m2));
}

void test_max2(){
    int a = 3;
    int b = 5;
    int result = max2(a, b);
    assert(result == 5);
}
void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m1 = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                               1, 3, 6, 3,
                                               3, 2, 1, 2}, 3, 4);



    int result1 = findSumOfMaxesOfPseudoDiagonal(m1);
    assert(result1 = 20);
}


void test_position(){
    position posit = {3, 2};
    int result = value_is_in_the_area(posit, 3, 3);
    assert(result == 1);
}
void test_getMinInArea() {
    matrix m1 = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                               3, 11, 8, 9,
                                               4, 1, 12, 2}, 3, 4);



    int result1 = getMinInArea(m1);
    assert(result1 == 2);
}

void test_getDistance(){
    int a[5] = {1, 1, 1, 1, 1};
    float result = getDistance(a, 5);
    assert(result = 2.23606797749979);
}

void test_sortByDistances() {

    matrix m1 = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                               3, 11, 8, 9,
                                               4, 1, 12, 2}, 3, 4);

    matrix m2 = createMatrixFromArray((int[]) {3, 11, 8, 9,
                                               10, 7, 5, 6,
                                               3, 11, 8, 9
    }, 3, 4);

    sortByDistances(m1);
    assert(areTwoMatricesEqual(&m1, &m2));
}

void test_countNUnique(){
    int a[5] = {1, 2, 3, 1, 1};
    float result = (a, 5);
    assert(result == 5);
}

void test_countEqClassesByRowsSum() {
    matrix m1 = createMatrixFromArray((int[]) {7, 1,
                                               2, 7,
                                               5, 4,
                                               4, 3,
                                               1, 6,
                                               8, 0
    }, 6, 2);


    int result1 = countEqClassesByRowsSum(m1);
    assert(result1 == 3);
}

void test_getNSpecialElement() {
    matrix m1 = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                               2, 3, 6, 7,
                                               12, 2, 1, 2
    }, 3, 4);


    int result = getNSpecialElement(m1);

    assert(result == 2);
}


void test_position1(){
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9
    }, 3, 3);
    position result = getLeftMin(m1);

    assert(result.rowIndex == 0 && result.colIndex == 0);
}
void test_swapPenultimateRow() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9
    }, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               1, 4, 7,
                                               7, 8, 9
    }, 3, 3);

    swapPenultimateRow(m1);
    assert(areTwoMatricesEqual(&m1, &m2));
}

void test_isNonDescendingSorted(){
    int a[5] = {1, 2, 3, 4, 5};
    int result = isNonDescendingSorted(a, 5);
    assert(result == 1);
}
void test_hasAllNonDescendingRows(){
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9
    }, 3, 3);



    int result1 = hasAllNonDescendingRows(m1);
    assert(result1 == 1);
}
void test_countNonDescendingRowsMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9
    }, 3, 3);

    int result2 = countNonDescendingRowsMatrices(&m1, 1);
    assert(result2 == 1);
}

void test_getMaxValue(){
    int a[5] = {1, 2, 3, 4, 5};
    int result = getMaxValue(a);
    assert(result == 5);
}
void test_printMatrixWithMaxZeroRows() {
    matrix m1 = createMatrixFromArray((int[]) {1, 0, 1,
                                               4, 5, 6,
                                               7, 0, 9
    }, 3, 3);


    int result1 = countZeroRows(m1);
    assert(result1 == 2);

}



void test_printMatrixWithMinNorm() {
    matrix m1 = createMatrixFromArray((int[]) {1, 0, 1,
                                               4, 5, 6,
                                               7, 0, 9
    }, 3, 3);

    int result1 = getMaxValueMatrix(m1);
    assert(result1 == 9);
}



void test_getNSpecialElement2() {
    matrix m1 = createMatrixFromArray((int[]) {2, 3, 5, 5, 4,
                                               6, 2, 3, 8, 12,
                                               12, 12, 2, 1, 2
    }, 3, 5);

    int result = getNSpecialElement2(m1);
    assert(result == 4);

}

void test_getScalarProduct(){
    int a[3] = {1, 2, 3};
    int b[3] = {1, 2, 3};
    int result = getScalarProduct(a, b, 3);
    assert(result == 14);
}
void test_getVectorLength(){

    int a[3] = {1, 2, 3};
    double result1 = getVectorLength(a, 3);
    assert(result1 == 3.7416573867739413);
}
void test_getCosine(){
    int a[3] = {1, 2, 3};
    int b[3] = {1, 2, 3};
    double result2 = getCosine(a, b, 3);
    assert(result2 == 1);
}
void test_getVectorIndexWithMaxAngle(){
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               1, 4, 7,
                                               2, 3, 4
    }, 3, 3);
    int b[3] = {1, 2, 3};
    int result3 = getVectorIndexWithMaxAngle(m2, b);
    assert(result3 == 1);
}

void test_getScalarProductRowAndCol(){
    matrix m1 = createMatrixFromArray((int[]) {2, 3, 5, 5, 4,
                                               6, 2, 3, 8, 12,
                                               12, 12, 2, 1, 2
    }, 3, 3);

    int result= getScalarProductRowAndCol(m1,1,2);
    assert(result==97);
}
void test_getSpecialScalarProduct(){
    matrix m1 = createMatrixFromArray((int[]) {2, 3, 5, 5, 4,
                                               6, 2, 3, 8, 12,
                                               12, 12, 2, 1, 2
    }, 3, 3);

    int result1= getSpecialScalarProduct(m1);
    assert(result1=35);
}
void test() {
    void test_sortRowsMaxAndMinElement();
    void test_sortRowsByMinElement();
    void test_sortColsByMinElement();
    void test_getSquareOfMatrixIfSymmetric();
    void test_getSum();
    void test_isUnique();
    void test_transposeIfMatrixHasNotEqualSumOfRows1();
    void test_isMutuallyInverseMatrices();
    void test_max2();
    void test_findSumOfMaxesOfPseudoDiagonal();
    void test_position();
    void test_getMinInArea();
    void test_getDistance();
    void test_sortByDistances();
    void test_countNUnique();
    void test_countEqClassesByRowsSum();
    void test_getNSpecialElement();
    void test_position1();
    void test_swapPenultimateRow();
    void test_isNonDescendingSorted();
    void test_hasAllNonDescendingRows();
    void test_countNonDescendingRowsMatrices();
    void test_getMaxValue();
    void test_printMatrixWithMaxZeroRows();
    void test_printMatrixWithMinNorm();
    void test_getNSpecialElement2();
    void test_getScalarProduct();
    void test_getVectorLength();
    void test_getCosine();
    void test_getVectorIndexWithMaxAngle();
    void test_getScalarProductRowAndCol();
    void test_getSpecialScalarProduct();
}
int main() {
    test();
}
