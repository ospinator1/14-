
#ifndef UNTITLED7_MATRIX_С
#define UNTITLED7_MATRIX_С

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
# include "../../algorithms/basic_functions/basic_functions.h"

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


#endif