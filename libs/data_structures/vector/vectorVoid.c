//
// Created by Assa on 27.02.2024.
# ifndef INC_VECTOR_H
# define INC_VECTOR_H

#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
# include <stdint.h>
# include <assert.h>
# include <memory.h>
# include <stdio.h>
# include <stdbool.h>
#include "../../data_structures/vector/vectorVoid.h"



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
        deleteVectorV(&v);
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
bool isEmptyV(vectorVoid *v){
        return (v->size==0);
    }
bool isFullV(vectorVoid *v){
    return v->size==v->capacity;
}
void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index > v->size) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        char *source = (char *) v->data + index * v->baseTypeSize;
        memcpy(destination, source, v->baseTypeSize);
    }
}
void setVectorValueV(vectorVoid *v, size_t index, void *source){
    if(index>v->size){
        fprintf(stderr, "bad alloc");
        exit(1);
    } else{
        char *destination=(char *) v->data + index * v->baseTypeSize;
        memcpy(destination, source, v->baseTypeSize);
    }
    }
void popBackV(vectorVoid *v){
    if (v->size > 0) {
        v->size--;
    }else
        fprintf(stderr, "bad alloc");
    exit(1);
}
void pushBackV(vectorVoid *v, void *source){
    if (v->capacity == 0) {
        v->capacity++;
    } else if (isFullV(v)) {
        reserveV(v, v->capacity * 2);
    }
    char *destination=(char *) v->data + v->size * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
    v->size++;
}

#endif