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

matrix * getMemMatrix(int nRows, int nCols);//размещает в динамической памяти матрицу размером nRows на nCols

matrix *getMemArrayOfMatrices(int nMatrices,int nRows, int nCols);//размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols

void freeMemMatrix(matrix *m);//освобождает память, выделенную под хранение матрицы m

void freeMemMatrices(matrix *ms, int nMatrices);//освобождает память, выделенную под хранение массива ms из nMatrices матриц

void inputMatrix(matrix *m);//ввод матрицы m

void inputMatrices(matrix *ms, int nMatrices);//– ввод массива из nMatrices матриц, хранящейся по адресу ms

void outputMatrix(matrix *m); // вывод матрицы m

void outputMatrices(matrix *ms, int nMatrices);//вывод массива из nMatrices матриц, хранящейся по адресу ms

void swapRows(matrix m, int i1, int i2);//обмен строк с порядковыми номерами i1 и i2 в матрице m

void swapColumns(matrix m, int j1, int j2)// обмен колонок с порядковыми номерами j1 и j2 в матрице m.
#endif //UNTITLED7_MATRIX_H
