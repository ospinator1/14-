
#include "libs/data_structures/matrix//matrix.h"
#include <stdio.h>

int main () {
        matrix *m1 = getMemArrayOfMatrices(1,3,3);
        matrix *m2= getMemArrayOfMatrices(1,3,3);
        inputMatrix(m1);
        printf("%d", isSymmetricMatrix(m1));


    return 0;
}