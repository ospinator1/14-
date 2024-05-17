#include "libs/data_structures/matrix/matrix.h"
#include <malloc.h>
#include <assert.h>

int cmp(const void *a, const void *b) {
    return *(unsigned int *) a - *(unsigned int *) b;
}

int get_median_in_area(matrix *m, const int i, const int j, const int filter) {
    int border = filter * 2 + 1;
    int *temp = (int *) malloc((border * border) * sizeof(int));
    int size = 0;
    for (int row_i = i - filter; row_i <= i + filter; ++row_i)
        for (int col_j = 0; col_j <= j + filter; ++col_j)
            if (row_i != i || col_j != j) {
                temp[size] = m->values[row_i][col_j];
                size++;
            }
    qsort(temp, size, sizeof(int), cmp);
    int result = (temp[size / 2 - 1] + temp[size / 2]) / 2;
    free(temp);
    return result;

}

void median_filter(matrix m,int n,int filter) {
    filter /= 2;
    for (int i = filter; i < n - filter; i++)
        for (int j = filter; j < n - filter; j++)
            m.values[i][j] = get_median_in_area(&m, i, j, filter);
}

void test() {
    int n = 3;
    int filter = 3;
    matrix m = createMatrixFromArray((int[]) {10, 20, 30,
                                              25, 35, 45,
                                              15, 25, 35}, n, n);
    median_filter(m,n,filter);
    matrix check = createMatrixFromArray((int[]) {10, 20, 30,
                                                  25, 25, 45,
                                                  15, 25, 35}, n, n);
    assert(n == 3);
    assert(filter == 3);
    assert(areTwoMatricesEqual(&m, &check));

}

int main() {
    test();
}