
#include "libs/data_structures/matrix//matrix.h"


int main () {
        matrix *m = getMemArrayOfMatrices(2,3,3);
        inputMatrix(m);
         swapRows(*m,2,1);
        outputMatrix(m);

    return 0;
}