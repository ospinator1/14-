//
// Created by Assa on 18.05.2024.
//

#ifndef UNTITLED7_TASKS5_H
#define UNTITLED7_TASKS5_H

#include <assert.h>
#include "../data_structures/matrix/matrix.h"
int CountSubmatricesСontaining1(matrix *m) {
    matrix nums = getMemMatrix(m->nRows, m->nCols);
    int value = 0;
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            if (m->values[i][j] == 0) {
                value = 0;
            } else {
                if (j > 0) {
                    value = nums.values[i][j - 1] + 1;
                } else {
                    value = 1;
                }
            }
            nums.values[i][j] = value;
        }
    }
    int count = 0;
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            int minWidth = nums.values[i][j];
            for (int k = i; k < m->nRows; ++k) {
                if (minWidth > nums.values[k][j]){
                    minWidth = nums.values[k][j];
                }
                count += minWidth;
            }
        }
    }
    return count;
}
void test(){
    int n = 3;
    int m = 3;
    int test[3][3] = {{1,0,1},{1,1,0},{1,1,0}};
    matrix matrix1 = createMatrixFromArray(*test, n, m);
    int res = CountSubmatricesСontaining1(&matrix1);
    assert(res == 13);
}

int main() {
    test();
}
#endif //UNTITLED7_TASKS5_H
