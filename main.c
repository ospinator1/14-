#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = vector_create(1);
    vector_add(&v,5);
    vector_add(&v,2);
    vector_add(&v,3);
    pushBack(&v, 10);
    popBack(&v);
    return 0;
}