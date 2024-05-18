# ifndef INC_VECTOR_H
# define INC_VECTOR_H

#include <stdio.h> // For UINT32_MAX
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
# include "../../algorithms/array/array.h"

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;


vector createVector(size_t n) {
    int *data = malloc(sizeof(int) * n);

    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {data,0,n};
}


void reserve(vector *v, size_t newCapacity) {
    int *data = (int*) realloc(v->data, newCapacity * sizeof(int));
    if (data == NULL) {
        v->data = NULL;
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->data = data;
    v->capacity = newCapacity;

    if (v->size > v->capacity) {
        v->size = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size >= v->capacity;
}

int getVectorValue(vector v, size_t i) {
    return v.data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v)) {
        size_t new_capacity;

        if (v->capacity == 0)
            new_capacity = 1;
        else
            new_capacity = v->capacity * 2;

        reserve(v, new_capacity);
    }

    v->data[v->size] = x;
    v->size++;
}


void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }
    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index > v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exist", index);
        exit(1);
    }
    return &v->data[index];
}

int* back(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "no elements");
        exit(1);
    }
    return &v->data[v->size - 1];
}

int* front(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "no elements");
        exit(1);
    }
    return &v->data[0];
}

#endif