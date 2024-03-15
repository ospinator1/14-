
#ifndef UNTITLED7_MATRIX_С
#define UNTITLED7_MATRIX_С
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
# include "../../algorithms/array/array.h"
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
        int **values = (int **) malloc(sizeof(int*) * nRows);
        for (int i = 0; i < nRows; i++)
            values[i] = (int *) malloc(sizeof(int) * nCols);
        return (matrix){values, nRows, nCols};
    }
matrix *getMemArrayOfMatrices(int nMatrices,int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}
void freeMemMatrix(matrix *m){
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
void swapRows(matrix *m, int i1, int i2){
    int *t=m->values[i1];
    m->values[i1]=m->values[i2];
    m->values[i2]=t;
}
void swapColumns(matrix *m, int j1, int j2) {
    for (int i = 0; i < m->nRows; i++) {
        int t = *(&m->values[i][j1]);
        *(&m->values[i][j1]) = *(&m->values[i][j2]);
        *(&m->values[i][j2]) = t;
    }
}

#endif