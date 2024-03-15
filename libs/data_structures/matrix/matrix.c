
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
void freeMemMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; ++i) {
        freeMemMatrix(ms+i);
    }
#endif