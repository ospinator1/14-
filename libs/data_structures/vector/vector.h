//
// Created by Assa on 18.02.2024.
//



# ifndef INC_ORDERED_ARRAY_SET_H
# define INC_ORDERED_ARRAY_SET_H

# include <stdint.h>
# include <assert.h>
# include <memory.h>
# include <stdio.h>
# include <stdbool.h>
# include "../../algorithms/array/array.h"
typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;
vector vector_create(size_t capacity);
void reserve(vector *v, size_t newCapacity);
void clear(vector *v);
bool isEmpty(vector *v);
int vector_add(vector *v, int element);
bool isFull(vector *v);
int getVectorValue(vector *v, size_t i);
vector vector_create_from_array(const int* a, size_t size);
void pushBack(vector *v, int x);
void popBack(vector *v);
vector vector_array(int* a, int size);
int* vector_front(vector* v);
int* back(vector *v);
int* atVector(vector *v, size_t index);
void vector_print ( vector v );
#endif