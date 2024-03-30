
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

int getMax(int *a, int n) {
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(&m, getMax);
}

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

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    selectionSortColsMatrixByColCriteria(&m, getMin);
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

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(m) == 1)
        mulMatrices(*m, *m);
    else
        outputMatrix(&m);
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

bool isUnique(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == a[i + 1]) {
            return false;

        }

    }
    return true;
}

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int *sum = (int *) (malloc(sizeof(int) * m.nRows));
    for (int i = 0; i < m.nRows; ++i)
        sum[i] = getSum(m.values[i], m.nCols);
    if (isUnique(sum, m.nRows)) {
        transposeSquareMatrix(&m);
    } else
        outputMatrix(&m);
}

int test_transposeIfMatrixHasNotEqualSumOfRows() {
    SetConsoleOutputCP(CP_UTF8);
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               0, 1, 1,
                                               3, 6, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 0, 3,
                                               2, 1, 6,
                                               3, 1, 9}, 3, 3);
    int a[5] = {1, 2, 3, 4, 5};
    int result = getSum(&a, 5);
    assert(result == 15);
    int result1 = isUnique(a, 5);
    assert(result1 == 1);

    transposeIfMatrixHasNotEqualSumOfRows(m1);
    assert(areTwoMatricesEqual(&m1, &m2));
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix result1 = mulMatrices(m1, m2);
    matrix result2 = mulMatrices(m2, m1);
    bool E = isEMatrix(&result1) && isEMatrix(&result2);
    return E;
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

int max2(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int *max_value = (int *) malloc(sizeof(int) * (m.nRows + m.nCols - 1));
    for (int i = 0; i < m.nRows + m.nCols - 1; i++) {
        max_value[i] = 0;
    }
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (i != j) {
                max_value[i - j + m.nCols - 1] = max(max_value[i - j + m.nCols - 1], m.values[i][j]);
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i < m.nRows + m.nCols - 1; ++i) {
        sum += max_value[i];

    }
    return sum;
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m1 = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                               1, 3, 6, 3,
                                               3, 2, 1, 2}, 3, 4);


    int a = 3;
    int b = 5;
    int result = max2(a, b);
    assert(result == 5);
    int result1 = findSumOfMaxesOfPseudoDiagonal(m1);
    assert(result1 = 20);
}

bool value_is_in_the_area(position posit, int i, int j) {
    position new = {i - posit.rowIndex, j - posit.rowIndex};
    return (new.rowIndex <= new.colIndex);
}

int getMinInArea(matrix m) {
    position max = getMaxValuePos(m);
    int min = INT_MAX;

    for (int i = 0; i <= max.rowIndex; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (value_is_in_the_area(max, i, j) && m.values[i][j] < min) {
                min = m.values[i][j];
            }
        }
    }

    return min;
}

void test_getMinInArea() {
    matrix m1 = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                               3, 11, 8, 9,
                                               4, 1, 12, 2}, 3, 4);


    position posit = {3, 2};
    int result = value_is_in_the_area(posit, 3, 3);
    assert(result == 1);
    int result1 = getMinInArea(m1);
    assert(result1 == 2);
}

float getDistance(int *a, int n) {
    float d = 0;
    for (int i = 0; i < n; ++i) {
        d += sqrt(pow(a[i], 2));
    }
    return d;
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteria1(&m, getDistance);
}

void test_sortByDistances() {

    matrix m1 = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                               3, 11, 8, 9,
                                               4, 1, 12, 2}, 3, 4);

    matrix m2 = createMatrixFromArray((int[]) {3, 11, 8, 9,
                                               10, 7, 5, 6,
                                               3, 11, 8, 9
    }, 3, 4);
    int a[5] = {1, 1, 1, 1, 1};
    float result = getDistance(a, 5);
    assert(result = 2.23606797749979);
    sortByDistances(m1);
    assert(areTwoMatricesEqual(&m1, &m2));
}

int cmp_long_long(const void *pa, const void *pb) {
    return *(long long *) pa - *(long long *) pb;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int count_unique = n == 0 ? 1 : 0;
    int i = 0;
    while (i < n) {
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (a[middle] == a[i]) {
                i = middle;
                left = middle + 1;
            } else if (a[middle] > a[i])
                right = middle - 1;
            else
                left = middle + 1;
        }
        i++;
        count_unique++;
    }
    return count_unique;
}

int countEqClassesByRowsSum(matrix m) {
    long long *sum = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        sum[i] = getSum(m.values[i], m.nCols);
    int count_of_unique = countNUnique(sum, m.nRows);
    free(sum);
    return count_of_unique;
}

void test_countEqClassesByRowsSum() {
    matrix m1 = createMatrixFromArray((int[]) {7, 1,
                                               2, 7,
                                               5, 4,
                                               4, 3,
                                               1, 6,
                                               8, 0
    }, 6, 2);

    int a[5] = {1, 2, 3, 1, 1};
    float result = countNUnique(a, 5);
    assert(result == 5);
    int result1 = countEqClassesByRowsSum(m1);
    assert(result1 == 3);
}

int getNSpecialElement(matrix m) {
    int count = 0;
    int sum = 0;
    for (int j = 0; j < m.nCols; ++j) {
        for (int i = 0; i < m.nRows; ++i) {
            sum += m.values[i][j];
        }
        for (int z = 0; z < m.nRows; ++z) {
            if (m.values[z][j] > sum - m.values[z][j])
                count++;
        }
        sum = 0;
    }

    return count;
}

void test_getNSpecialElement() {
    matrix m1 = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                               2, 3, 6, 7,
                                               12, 2, 1, 2
    }, 3, 4);


    int result = getNSpecialElement(m1);

    assert(result == 2);
}

position getLeftMin(matrix m) {
    return getMinValuePos(m);
}

void swapPenultimateRow(matrix m) {
    position left_min_pos = getLeftMin(m);
    int *col = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        col[i] = m.values[i][left_min_pos.colIndex];
    int pre_last_row = m.nRows - 2;
    for (int i = left_min_pos.colIndex; i <= left_min_pos.colIndex; i++)
        for (int j = 0; j < m.nRows; j++)
            m.values[pre_last_row][j] = col[j];

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
    position result = getLeftMin(m1);

    assert(result.rowIndex == 0 && result.colIndex == 0);
    swapPenultimateRow(m1);
    assert(areTwoMatricesEqual(&m1, &m2));
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] < a[i + 1])
            return 1;
    }
    return 0;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        if (isNonDescendingSorted(m.values[i], m.nCols) == 0)
            return 0;
    }
    return 1;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; ++i)
        if (hasAllNonDescendingRows(ms[i]))
            count++;
    return count;
}

void test_countNonDescendingRowsMatrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9
    }, 3, 3);


    int a[5] = {1, 2, 3, 4, 5};
    int result = isNonDescendingSorted(a, 5);
    assert(result == 1);
    int result1 = hasAllNonDescendingRows(m1);
    assert(result1 == 1);
    int result2 = countNonDescendingRowsMatrices(&m1, 1);
    assert(result2 == 1);
}

int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] == 0) {
                count++;
            }
    return count;

}

int getMaxValue(int a[]) {
    int n;
    scanf("%d", &n);
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int min = INT_MAX;
    for (int i = 0; i < nMatrix; ++i) {
        int norma = getMaxValue((int *) &ms[i]);
        min = min2(norma, min);
    }
    for (int i = 0; i < nMatrix; ++i) {
        int norma = getMaxValue((int *) &ms[i]);
        if (norma == min)
            outputMatrix(ms);
    }
}

void test_printMatrixWithMaxZeroRows() {
    matrix m1 = createMatrixFromArray((int[]) {1, 0, 1,
                                               4, 5, 6,
                                               7, 0, 9
    }, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               1, 4, 7,
                                               7, 8, 9
    }, 3, 3);
    int a[5] = {1, 2, 3, 4, 5};
    int result = getMaxValue(a);
    assert(result == 5);
    int result1 = countZeroRows(m1);
    assert(result1 == 2);

}

int getMaxValueMatrix(matrix m) {
    int max = INT_MIN;
    for (int i = 0; i < m.nRows; i++) {
        int max_row = getMax(m.values[i], m.nCols);
        max = max(max_row, max);
    }
    return max;
}

void printMatrixWithMinNorm(matrix *ms, int nMatrix) {
    int min_norm = INT_MAX;
    for (int i = 0; i < nMatrix; ++i) {
        int norma = getMaxValueMatrix(ms[i]);
        min_norm = min2(norma, min_norm);
    }
    for (int i = 0; i < nMatrix; ++i) {
        int norm = getMaxValue(&ms[i]);

        if (norm == min_norm)
            outputMatrix(ms);
    }
}

void test_printMatrixWithMinNorm() {
    matrix m1 = createMatrixFromArray((int[]) {1, 0, 1,
                                               4, 5, 6,
                                               7, 0, 9
    }, 3, 3);

    int result1 = getMaxValueMatrix(m1);
    assert(result1 == 9);
}

int getNSpecialElement2(matrix m) {
    int count;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 1; j < m.nCols - 1; ++j) {
            for (int k = 0; k < i; ++k) {
                bool flag =m.values[i][k] > m.values[i][j];
                if (flag == 1)
                    count++;
            }
        }
    }
    printf("%d", count);
}


int main() {

    matrix m1 = createMatrixFromArray((int[]) {2,3,5,5,4,
                                               6,2,3,8,12,
                                               12,12,2,1,2
    }, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               1, 4, 7,
                                               7, 8, 9
    }, 3, 3);


    int result = getNSpecialElement2(m1);
    assert(result==4);

}
