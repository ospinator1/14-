
#include "libs/data_structures/matrix//matrix.h"
#include <stdio.h>

int main () {
        matrix *m1 = getMemArrayOfMatrices(1,3,3);
        matrix *m2= getMemArrayOfMatrices(1,3,3);
        inputMatrix(m1);
        position pos= getMaxValuePos(*m1);
        printf("%d ", pos.rowIndex );
    printf("%d ",pos.colIndex);

    return 0;
}