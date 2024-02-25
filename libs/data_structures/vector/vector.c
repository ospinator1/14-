# ifndef INC_ORDERED_ARRAY_SET_H
# define INC_ORDERED_ARRAY_SET_H
#include <malloc.h>
# include <stdint.h>
# include <assert.h>
# include <memory.h>
# include <stdio.h>
# include <stdbool.h>
#include <stddef.h> // For size_t
#include <stdlib.h> // For malloc, free, realloc, and exit
#include <stdio.h>
# include "../../algorithms/array/array.h"
typedef struct vector {
    int *data; // указатель на элементы вектора
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
    free((void *) v->data);
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
    v->data = (int*)realloc(v->data, sizeof(int)*v->size);
}
void deleteVector(vector *v){
    free(&v);
}
bool isEmpty(vector *v){
    return (v->size==0);
}
void vector_add(vector *v, int element) {
    for (size_t i = 0; i < v->size; i++) {
        if (v->data[i] == element) {
            return;
        }
    }
    if (v->size < v->capacity) {
        v->data[v->size++] = element;
    }
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

void vector_print ( vector v ){
    for(int i=0;i<v.size;i++){
        printf("%d\n",v.data[i]);
    }
}
#endif