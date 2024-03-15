//
// Created by Assa on 05.03.2024.
//

#ifndef UNTITLED7_MATRIX_H
#define UNTITLED7_MATRIX_H
typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;
typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);//размещает в динамической памяти матрицу размером nRows на nCols

matrix *getMemArrayOfMatrices(int nMatrices,int nRows, int nCols);//размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols

void freeMemMatrix(matrix *m);//освобождает память, выделенную под хранение матрицы

void freeMemMatrices(matrix *ms, int nMatrices);//освобождает память, выделенную под хранение массива ms из nMatrices матриц

#endif //UNTITLED7_MATRIX_H
