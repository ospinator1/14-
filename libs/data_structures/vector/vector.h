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

// возвращает структуру-дескриптор вектор из n значений
vector vector_create(size_t capacity);

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору
void deleteVector(vector *v);

// проверка на то, является ли вектор пустым
bool isEmpty(vector *v);

// проверки на то, является ли вектор полным
bool isFull(vector *v);

// возвращает i-ый элемент вектора v//
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора v
void pushBack(vector *v, int x);
// удаляет последний элемент из вектора
void popBack(vector *v);

int* vector_front(vector* v);
int* back(vector *v);
int* atVector(vector *v, size_t index);
void vector_print ( vector v );
#endif