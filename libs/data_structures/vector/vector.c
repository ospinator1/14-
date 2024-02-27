# ifndef INC_ORDERED_ARRAY_SET_H
# define INC_ORDERED_ARRAY_SET_H
-
#include <stdio.h> // For UINT32_MAX
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
# include "../../algorithms/array/array.h"

typedef struct vector {
    int* data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector vector_create(size_t capacity) {
    if (capacity< UINT32_MAX)
        return (vector) {
                malloc(sizeof(int) * capacity),
                0,
                capacity
        };
    fprintf(stderr, "bad alloc");
    exit(1);
}

void clear(vector *v){
    free( v->data);
}

void reserve(vector *v, size_t new_capacity) {
    if (new_capacity == 0) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
        return;
    }

    if (new_capacity < v->size) {
        v->size = new_capacity;
    }
    int *new_data = (int*)realloc(v->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->data = new_data;
    v->capacity = new_capacity;
}

void shrinkToFit(vector *v){
    v->capacity = v->size;
}

void deleteVector(vector *v){
    free(&v);
}

bool isEmpty(vector *v){
    return (v->size==0);
}

bool isFull(vector *v){
    return v->size==v->capacity;
}

int getVectorValue(vector *v, size_t i){
    return linearSearch_(v,v->size,v->data[i]);
}


void pushBack(vector *v, int x) {
    if (v->size == v->capacity) {
        reserve(v, 2 * v->capacity);
    }
    v->data[v->size++] = x;
}
void popBack(vector *v) {
    if (v->size > 0) {
        v->size--;
    }else
        fprintf(stderr, "bad alloc");
    exit(1);
}


int* vector_front(vector* v) {
    if (v == nullptr || v->size == 0) {
        return nullptr;
    }
    return &(v->data[0]);
}

int* back(vector *v) {
    if (v == NULL || v->size == 0) {
        return NULL;
    }
    return &(v->data[v->size-1]);
}

int* atVector (vector *v, size_t index){
    if(index<v->size) {
        return &(v->data[index]);
    } else
        fprintf(stderr, "IndexError: a[%d] is not exists\n", index);
    exit(1);
}

#endif