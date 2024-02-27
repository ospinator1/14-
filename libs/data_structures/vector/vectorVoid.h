//
// Created by Assa on 27.02.2024.
//
#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H
#include <limits.h>
typedef struct vectorVoid {
void *data; // указатель на нулевой элемент вектора
size_t size; // размер вектора
size_t capacity; // вместимость вектора
size_t baseTypeSize; // размер базового типа:

} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);
void reserveV(vectorVoid *v, size_t newCapacity);
void shrinkToFitV(vectorVoid *v);
void clearV(vectorVoid *v);
void deleteVectorV(vectorVoid *v);

#endif
