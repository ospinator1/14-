
#ifndef UNTITLED7_MATRIX_С
#define UNTITLED7_MATRIX_С

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
# include "../../algorithms/basic_functions/basic_functions.h"

#include <windows.h>
#include <assert.h>
#include <math.h>
typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;
typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    free(&m);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        freeMemMatrix(ms + i);
    }
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        printf("input %d row:", i + 1);
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &m->values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        printf("input %lld matrix\n", i + 1);
        inputMatrix(ms + i);
        printf("\n");
    }
}

void outputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            printf("%d ", m->values[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms + i);
    }
}

void swapRows(matrix *m, int row1, int row2) {
    for (int j = 0; j < m->nCols; j++) {
        swap(&m->values[row1][j], &m->values[row2][j]);
    }
}

void swapColumns(matrix *m, int j1, int j2) {
    for (int i = 0; i < m->nRows; i++) {
        int t = *(&m->values[i][j1]);
        *(&m->values[i][j1]) = *(&m->values[i][j2]);
        *(&m->values[i][j2]) = t;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    float *criteria_array = (int *) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        criteria_array[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int t = criteria_array[i];
        int j = i;

        while (j > 0 && criteria_array[j - 1] > t) {
            criteria_array[j] = criteria_array[j - 1];
            swapRows(&m, j, j - 1);
            j--;
        }

        criteria_array[j] = t;
    }

}

void insertionSortRowsMatrixByRowCriteria1(matrix *m, float (*criteria)(int *, int)) {
    float result_criteria[m->nRows];

    for (int i = 0; i < m->nRows; i++)
        result_criteria[i] = criteria(m->values[i], m->nCols);

    for (int i = 1; i < m->nRows; i++) {
        float k = result_criteria[i];
        int *address_key = m->values[i];
        int j = i - 1;
        while (j >= 0 && result_criteria[j] > k) {
            result_criteria[j + 1] = result_criteria[j];
            swapRows(m, j + 1, j);

            j -= 1;
        }

        result_criteria[j + 1] = k;
        m->values[j + 1] = address_key;
    }
}

void selectionSortColsMatrixByColCriteria(matrix *m, int (*criteria)(int *, int)) {
    int res_criteria[m->nCols];

    for (size_t i = 0; i < m->nCols; i++) {
        int temp[m->nRows];
        for (size_t j = 0; j < m->nRows; j++) {
            temp[j] = m->values[j][i];
        }

        res_criteria[i] = criteria(temp, m->nRows);
    }

    int value_min_idx;
    for (int i = 0; i < m->nCols; i++) {
        value_min_idx = i;

        for (int j = i + 1; j < m->nCols; j++) {
            if (res_criteria[j] < res_criteria[value_min_idx]) {
                value_min_idx = j;
            }
        }

        swap(&res_criteria[value_min_idx], &res_criteria[i]);
        swapColumns(m, value_min_idx, i);
    }
}


bool isSquareMatrix(matrix *m) {
    return m->nRows == m->nCols;
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    if (m1->nRows != m2->nRows || m1->nCols != m2->nCols) {
        return false;
    }
    for (int i = 0; i < m1->nRows; ++i) {
        for (int j = 0; j < m2->nCols; ++j) {
            if (m1->values[i][j] != m2->values[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool isEMatrix(matrix *m) {
    if (m->nRows != m->nCols) {
        return false;
    }
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            if (i == j && m->values[i][j] != 1) {
                return false;
            } else if (i != j && m->values[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool isSymmetricMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            if (m->values[i][j] != m->values[j][i]) {
                return false;
            }
        }
    }
    return true;
}

void transposeSquareMatrix(matrix *m) {
    if (m->nRows != m->nCols) {
        fprintf(stderr, "a non-square matrix");
        exit(1);
    }
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = i + 1; j < m->nCols; ++j) {
            if (i != j) {
                swap(&m->values[i][j], &m->values[j][i]);
            }
        }
    }
}

void transposeMatrix(matrix *m) {
    int **new_value = (int **) malloc(sizeof(int *) * m->nCols);
    for (int i = 0; i < m->nCols; i++) {
        new_value[i] = (int *) malloc(sizeof(int) * m->nRows);
        for (int j = 0; j < m->nRows; j++) {
            new_value[i][j] = m->values[j][i];
        }
    }
    for (int i = 0; i < m->nRows; i++)
        m->values = new_value;
    swap(&m->nRows, &m->nCols);
}

position getMinValuePos(matrix m) {
    position position = {0, 0};
    int minimum_values = m.values[0][0];

    for (int i = 1; i < m.nRows; ++i) {
        for (int j = 1; j < m.nCols; ++j) {
            if (m.values[i][j] < minimum_values) {
                minimum_values = m.values[i][j];
                position.rowIndex = i;
                position.colIndex = j;
            }
        }

    }
    return position;
}

position getMaxValuePos(matrix m) {
    int maximum_values = m.values[0][0];
    position position = {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] > maximum_values) {
                maximum_values = m.values[i][j];
                position.rowIndex = i;
                position.colIndex = j;
            }
        }
    }
    return position;
}

matrix createMatrixFromArray(const int *a,
                             int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}


matrix createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return *ms;
}

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
    insertionSortRowsMatrixByRowCriteria(m, getMax);
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

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix result1 = mulMatrices(m1, m2);
    matrix result2 = mulMatrices(m2, m1);
    bool E = isEMatrix(&result1) && isEMatrix(&result2);
    return E;
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

int getNSpecialElement2(matrix m) {
    int count;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 1; j < m.nCols - 1; ++j) {
            for (int k = 0; k < i; ++k) {
                bool flag = m.values[i][k] > m.values[i][j];
                if (flag == 1)
                    count++;
            }
        }
    }
    return  count;
}
double getScalarProduct(int *a, int *b, int n) {
    double scalar_product = 0;
    for (int i = 0; i < n; ++i) {
        scalar_product += a[i] * b[i];
    }
    return scalar_product;
}

double getVectorLength(int *a, int n) {
    double vector_length = 0;
    for (int i = 0; i < n; i++) {
        vector_length += a[i] * a[i];
    }
    return sqrt(vector_length);
}

double getCosine(int *a, int *b, int n) {
    double length = (getVectorLength(a, n) * getVectorLength(b, n));
    assert(length != 0);
    return getScalarProduct(a, b, n) / length;
}

double absDouble(double a) {
    return a < 0 ? -a : a;
}

int getVectorIndexWithMaxAngle(matrix m, int *b) {
    int index;
    double min_cosine = 2;

    for (int i = 0; i < m.nRows; i++) {
        double abs_cosine = absDouble(getCosine(m.values[i], b, m.nCols));

        if (abs_cosine < min_cosine) {
            index = i;
            min_cosine = abs_cosine;
        }
    }

    return index;
}
long long getScalarProductRowAndCol(matrix m, int i, int j) {
    int *col = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; ++i)
        col[i] = m.values[i][j];
    long long scalar_product = getScalarProduct(m.values[i], col, m.nRows);
    return scalar_product;
}
long long getSpecialScalarProduct(matrix m){
    position max= getMaxValuePos(m);
    position min= getMinValuePos(m);
    return getScalarProductRowAndCol(m,max.rowIndex,min.colIndex);
}
#endif