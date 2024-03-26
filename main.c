
#include "libs/data_structures/matrix//matrix.h"
#include <malloc.h>

#include "libs/algorithms/basic_functions/basic_functions.h"



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

void getSquareOfMatrixIfSymmetric(matrix m) {
    if (isSymmetricMatrix(&m) == 1) {
        mulMatrices(m, m);
    } else
        outputMatrix(&m);

}

long long getSum(int *a, int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

bool isUnique(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return 0;

    return 1;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int *sum = (int *) (malloc(sizeof(int) * m.nRows));

    for (int i = 0; i < m.nRows; i++)
        sum[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sum, m.nRows)) {
        transposeSquareMatrix(&m);
    } else
        outputMatrix(&m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix result_mul = mulMatrices(m1, m2);
    matrix result_mul1 = mulMatrices(m2, m1);
    bool E = isEMatrix(&result_mul1) && isEMatrix(&result_mul);

    return E;

}

void findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int j = 0;
    int sum[100];
    for (int offset = -m.nCols + 1; offset < m.nCols; ++offset) {
        int sum1 = 0;
        for (int i = 0; i < m.nRows - abs(offset); ++i) {
            if (offset <= 0) {
                sum1 += m.values[i][i - offset];
            } else {
                sum1 += m.values[i + offset][i];
            }
            sum[j] = sum1;
            j++;
        }
        printf("%d\n", sum1);
    }
}

int getMinInArea(matrix m) {
    int min = m.values[0][0];
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (i < m.nRows / 2 && j >= i && j < m.nRows - i) {
                if (m.values[i][j] < min)
                    min = m.values[i][j];

            } else if (i >= m.nRows / 2 && j <= i && j >= m.nRows - i - 1) {
                if (m.values[i][j] < min)
                    min = m.values[i][j];
            }

        }
    }
    printf("%d\n", min);
}

int getNSpecialElement(matrix m) {
    int k = 0;
    int sum = 0;
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            sum += m.values[i][j];
        }
        for (int z = 0; z < m.nRows; z++) {
            if (m.values[z][j] > sum - m.values[z][j])
                k++;
        }
        sum = 0;
    }

    printf("%d\n", k);
    getchar();
    return 0;
}

int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2


            },
            3, 4
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9


            },
            3, 3
    );

    printf("%d", getNSpecialElement(m1));
    return 0;
}
