
#include "libs/data_structures/matrix//matrix.h"
#include <malloc.h>
#include <stdio.h>
#define N 3
int getMin(int *a,int n){
    int min=a[0];
    for (int i = 0; i < n; ++i) {

        if(a[i]<min)
            a[i]=min;
        }
        return min;
    }
void sortColsByMinElement(matrix m){
    selectionSortColsMatrixByColCriteria(&m, getMin);
}

struct matrix mulMatrices(matrix m1, matrix m2){
    printf("Resultant Matrix is:\n");

    int result[m1.nRows][m2.nCols];
    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            result[i][j]=0;
            for (int k = 0; k < m2.nRows; ++k) {
                result[i][j]+=m1.values[i][k]*m2.values[k][j];
            }
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}

void getSquareOfMatrixIfSymmetric(matrix m) {
            if (isSymmetricMatrix(&m) == 1) {
                mulMatrices(m, m);
            } else
                outputMatrix(&m);

}
long long getSum(int *a,int n){
    int i, sum = 0;
    for (i=0; i < n; i++)
        sum += a[i];
    return sum;
}
bool isUnique(int *a, int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return 0;

    return 1;
}
void transposeIfMatrixHasNotEqualSumOfRows(matrix m){
    int *sum= (int *)(malloc(sizeof(int) * m.nRows));

    for (int i = 0; i < m.nRows; i++)
        sum[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sum, m.nRows)) {
        transposeSquareMatrix(&m);
    } else
        outputMatrix(&m);
}
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix result_mul = mulMatrices(m1, m2);
    matrix result_mul1= mulMatrices(m2,m1);
    bool E= isEMatrix(&result_mul1) && isEMatrix(&result_mul) ;

    return E;

}
int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1,0,
                    0,1,


            },
            2, 2
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1,0,
                    0,1,



            },
            2, 2
    );

    printf("%d", isMutuallyInverseMatrices(m1,m2));
    return 0;
}
