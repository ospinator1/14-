
#include "libs/data_structures/matrix//matrix.h"
#include <malloc.h>
#include <windows.h>
#include "libs/algorithms/basic_functions/basic_functions.h"
#include <assert.h>

void sortColsByMinElement(matrix m) {
    selectionSortColsMatrixByColCriteria(&m, getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    printf("Resultant Matrix is:\n");

    int result[m1.nRows][m2.nCols];
    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < m2.nRows; ++k) {
                result[i][j] += m1.values[i][k] * m2.values[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(&m) == 1) {
        mulMatrices(*m, *m);
    } else
        outputMatrix(&m);

}

long long getSum(int *a, int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

bool isUnique(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return 0;

    return 1;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int *sum = (int *) (malloc(sizeof(int) * m.nRows));

    for (int i = 0; i < m.nRows; i++)
        sum[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sum, m.nRows)) {
        transposeSquareMatrix(&m);
    } else
        outputMatrix(&m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix result_mul = mulMatrices(m1, m2);
    matrix result_mul1 = mulMatrices(m2, m1);
    bool E = isEMatrix(&result_mul1) && isEMatrix(&result_mul);

    return E;

}

void findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int j = 0;
    int sum[100];
    for (int offset = -m.nCols + 1; offset < m.nCols; ++offset) {
        int sum1 = 0;
        for (int i = 0; i < m.nRows - abs(offset); ++i) {
            if (offset <= 0) {
                sum1 += m.values[i][i - offset];
            } else {
                sum1 += m.values[i + offset][i];
            }
            sum[j] = sum1;
            j++;
        }
        printf("%d\n", sum1);
    }
}
bool value_is_in_the_area(position posit,int i,int j){
    position new={i-posit.rowIndex,j-posit.colIndex};
    return (new.rowIndex<=new.colIndex) ;
}
int getMinInArea(matrix m) {
position max= getMaxValuePos(m);
int min=INT_MAX;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (value_is_in_the_area(max,i,j)&&m.values[i][j]<min) {
                min=m.values[i][j];
            }

        }
    }
   return min;
}

int getNSpecialElement(matrix m) {
    int k = 0;
    int sum = 0;
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            sum += m.values[i][j];
        }
        for (int z = 0; z < m.nRows; z++) {
            if (m.values[z][j] > sum - m.values[z][j])
                k++;
        }
        sum = 0;
    }

    printf("%d\n", k);
    getchar();
    return 0;
}

int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] == 0) {
                count++;
            }
    printf("%d", count);
    getchar();
    return 0;
}

int getNSpecialElement2(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 1; j < m.nCols - 1; ++j) {
            for (int k = 0; k < i; ++k) {
                bool flag = m.values[i][k] > m.values[i][j];
                if (flag == 1)
                    count++;
            }
        }
    }
    printf("%d", count);
}

int NormaMatrix(matrix m) {
    int count=0;
    for (int i = 0; i < m.nRows; ++i){
        for (int j = 0; j < m.nCols; ++j)
            count++;
}
    return count;
}

int Sum_Dioganal(matrix m){
    int* max= (int*) malloc(sizeof (int)* (m.nRows+m.nCols-1));
    for (int i = 0; i < m.nRows+m.nCols-1; ++i) {
        max[i] = 0;
    }
        for (int j = 0; j < m.nRows; ++j) {
            for (int k = 0; k < m.nCols; ++k) {
                if(j!=k){
                    max[j-k + m.nCols - 1] = max2(max[j-k + m.nCols - 1],m.values[j][k]);
            }
        }
    }
        int sum=0;
    for (int i = 0; i < m.nRows+m.nCols-1; ++i) {
        sum+=max[i];

    }
    return sum;
}
int cmp_long_long(const void *pa, const void *pb){
    return *(long long *)pa - *(long long *)pb;
}
int countNUnique(long long *a, int n){

    qsort(a,n, sizeof(long long),cmp_long_long);
    int count_of_unique = n == 0 ? 1 : 0 ;
    int i=0;

    while(i<n){
        int left=0;
        int right=n-1;
        while(left<=right){
        int middle=left+(right-left)/2;
            if (a[middle] == a[i]) {
                i = middle;
                left = middle + 1;
            }
            else if (a[middle] > a[i])
                right = middle- 1;
            else
                left = middle + 1;
        }

        i++;
        count_of_unique++;
    }
    return count_of_unique;
}
int countEqClassesByRowsSum(matrix m) {
    long long *sum = (int *) malloc(sizeof(long long) * m.nRows);
    for (size_t i = 0; i < m.nRows; ++i)
        sum[i] = getSum(m.values[i], m.nCols);
        int count = countNUnique(sum, m.nRows);
        return count;

}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    matrix m1 = createMatrixFromArray(
            (int[]) {
                7,1,
                2,7,
                5,4,
                4,3,
                1,6,
                8,0


            },
            6, 2
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    6, 1, 4,
                    7, 8, 9


            },
            3, 3
    );
    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 2, 5, 5,
                    6, 1, 3, 8,
                    7, 8, 9, 10,
                    6, 4, 1, 4

            },
            4, 4
    );
    printf("%d", countEqClassesByRowsSum(m1));
}
