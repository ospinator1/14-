
#include "libs/data_structures/matrix//matrix.h"
#include "libs/algorithms/basic_functions/basic_functions.h"
#include <stdio.h>
int getMinElementRow(matrix m) {
    int min = m.values[0][0];
    int row = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                row = i; // Обновляем row вместе с min
            }
        }
    }
    return row; // Возвращаем после полного просмотра матрицы
}

int getMaxElementRow(matrix m) {
    int max = m.values[0][0];
    int row = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > max)
                max = m.values[i][j];
            row = i;
        }
    }
    return row;
}



int main() {

    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9

            },
            3, 3
    );
    int minRows= getMinElementRow(m);
    int maxRows= getMaxElementRow(m);
    swapRows(&m, minRows,maxRows);
    outputMatrix(&m);
    return 0;
}