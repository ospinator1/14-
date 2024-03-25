
#include "libs/data_structures/matrix//matrix.h"


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

int main() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3,5,2,4,3,3,
                    2,5,1,8,2,7,
                    6,1,4,4,8,3


            },
            3, 6
    );
    sortColsByMinElement(m);
    outputMatrix(&m);
    return 0;
}