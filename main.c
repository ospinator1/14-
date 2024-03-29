
#include "libs/data_structures/matrix//matrix.h"
#include <malloc.h>
#include <windows.h>
#include "libs/algorithms/basic_functions/basic_functions.h"
#include <assert.h>
#include <math.h>

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

void swapRows1(matrix m, int row1, int row2) {
    for (int j = 0; j < m.nCols; j++) {
        swap(&m.values[row1][j], &m.values[row2][j]);
    }
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    matrix m1= createMatrixFromArray(
            (int[]) {
                1,2,3,
              4,5,6,
              7,8,9


    },
    3, 3
    );

    matrix m2= createMatrixFromArray(
            (int[]) {
                    7,8,9,
                    4,5,6,
                    1,2,3


            },
            3, 3
    );
    int minRow = getMinElementRow(m1);
    int maxRow = getMaxElementRow(m1);
    swapRows(&m1,minRow,maxRow);
    assert(areTwoMatricesEqual(&m1,&m2));

}