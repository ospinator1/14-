


#include "libs/data_structures/matrix//matrix.h"


int main(void) {
    matrix *A = c_create_matrix(3, 3);
    print_matrix(&A);
    c_fill_matrix((matrix *) &A);
    print_matrix(A);

    return 0;
}
