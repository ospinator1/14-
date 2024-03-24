
#include "libs/data_structures/matrix//matrix.h"
#include "libs/algorithms/basic_functions/basic_functions.h"
#include <stdio.h>
int getMaxElementRow1(matrix m,int firstRow) {
    int max = m.values[firstRow][0];
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
void sortRowsByMinElement(matrix m) {
    for (int i = 0; i < m.nRows - 1; ++i) {
        int row = getMaxElementRow1(m, i);
        if (i != row) {
            swapRows(&m, i, row);
        }
    }
}
int main() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7,1,2,
                    1,8,1,
                    3,2,3


            },
            3, 3
    );
    sortRowsByMinElement(m);
    outputMatrix(&m);
    return 0;
}