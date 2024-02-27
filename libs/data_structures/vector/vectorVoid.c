//
// Created by Assa on 27.02.2024.
//
#define INC_VECTORVOID_H
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
# include <stdint.h>
# include <assert.h>
# include <memory.h>
# include <stdio.h>
# include <stdbool.h>
#include "vectorVoid.h"
typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

vectorVoid createVectorV(size_t capacity, size_t baseTypeSize){
    if (capacity< UINT32_MAX)
        return (vectorVoid) {
                malloc(baseTypeSize * capacity),
                0,
                capacity,
                baseTypeSize
        };
    fprintf(stderr, "bad alloc");
    exit(1);
}
void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity > 0) {
        int *new_data = (int *) realloc(v->data, newCapacity * sizeof(int));

        if (new_data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }

        v->data = new_data;
        v->capacity = newCapacity;
        if (newCapacity < v->size) {
            v->size = newCapacity;
        }
    } else {
        free(v);
    }
}
void shrinkToFitV(vectorVoid *v){
    v->capacity=v->size;
}
void clearV(vectorVoid *v){
        v->size=0;
}
void deleteVectorV(vectorVoid *v){
    free(&v);
}
