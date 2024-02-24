//
// Created by Assa on 04.02.2024.
//

#ifndef UNTITLED7_UNORDERED_SET_C
#define UNTITLED7_UNORDERED_SET_C

#include <malloc.h>
# include <assert.h>
# include <stdio.h>
# include <stdbool.h>
# include "../array/array.h"

typedef struct unordered_array_set {
    int *data; // Элементы множества
    size_t size; // Количество элементов в множестве
    size_t capacity; // Максимальное количество элементов в множестве
} unordered_array_set;

// Функция для создания нового множества с заданным начальным размером
int unordered_array_set_is_able_append(unordered_array_set *set) {
assert(set->size < set->capacity);
    return 0;
}

int unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}
    void unordered_array_set_insert(unordered_array_set* set, int element) {
    if (unordered_array_set_in(set, element) != -1) {
        unordered_array_set_is_able_append(set);
        append_(set->data, (size_t *) set->size, element);
    }
}

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

static void unordered_array_set_shrink_to_fit(unordered_array_set *a){
    if (a->size != a->capacity) {
        a->data = (int*)realloc(a->data, sizeof(int)*a->size);
        a->capacity = a->size;
    }
}

unordered_array_set unordered_array_set_create_from_array(const int* a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < set.size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrink_to_fit(&set);
    return set;
}
// Функция для добавления элемента в множество, если его там еще нет
void unordered_array_set_add(unordered_array_set *set, int element) {
    for (size_t i = 0; i < set->size; i++) {
        if (set->data[i] == element) {
            return; // Элемент уже есть в множестве
        }
    }
    // Если место есть, добавляем элемент
    if (set->size < set->capacity) {
        set->data[set->size++] = element;
    }
    // Расширение множества или обработка ошибки пропущены для краткости
}

// Функция для объединения двух множеств
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    // Создаем новое множество с достаточной емкостью для хранения всех элементов
    unordered_array_set result = unordered_array_set_create(set1.size + set2.size);

    // Добавляем все элементы из первого множества
    for (size_t i = 0; i < set1.size; i++) {
        unordered_array_set_add(&result, set1.data[i]);
    }

    // Добавляем все элементы из второго множества
    for (size_t i = 0; i < set2.size; i++) {
        {
            unordered_array_set_add(&result, set2.data[i]);
        }

        return result;
    }
    return result;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++) {
        for (size_t j = 0; j < set2.size; j++) {
            if (set1.data[i] == set2.data[j])
                unordered_array_set_add(&result, set1.data[i]);
        }
    }
    return result;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size + set2.size);
    for (int i = 0; i < set1.size; i++) {
        int is_unique = 1;
        for (int j = 0; j < set2.size; j++) {
            if (set1.data[i] == set2.data[j]) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unordered_array_set_add(&result, set1.data[i]);
        }

    }
    return result;
}

unordered_array_set unordered_array_set_symmetric_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size + set2.size);
    for (int i = 0; i < set1.size; i++) {
        int is_unique = 0;
        for (int j = 0; j < set2.size; j++) {
            if (set1.data[i] == set2.data[j]) {
                is_unique = 1;
                break;
            }
        }
        if (!is_unique) {
            unordered_array_set_add(&result, set1.data[i]);
        }
    }
    for (int i = 0; i < set2.size; i++) {
        int is_unique = 0;
        for (int j = 0; j < set1.size; j++) {
            if (set2.data[i] == set1.data[j]) {
                is_unique = 1;
                break;
            }
        }
        if (!is_unique) {
            unordered_array_set_add(&result, set2.data[i]);
        }
    }
    return result;
}

unordered_array_set unordered_array_set_complement(unordered_array_set universumSet, unordered_array_set set) {
    unordered_array_set result = unordered_array_set_create(universumSet.size + set.size);
    for (int i = 0; i < universumSet.size; i++) {
        int is_unique = 1;
        for (int j = 0; j < set.size; j++) {
            if (universumSet.data[i] == set.data[j]) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unordered_array_set_add(&result, universumSet.data[i]);
        }

    }
    return result;
}

struct unordered_array_set unordered_array_set_delete_element(unordered_array_set *set, int element) {
    if (unordered_array_set_in(set, element) == -1) {
        unordered_array_set_is_able_append(set);
        append_(set->data, (size_t *) set->size, element);
    }
}

bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    int i = 0;
    int j = 0;
    while (i < set.size && j < subset.size) {
        if (set.data[i] == subset.data[j]) {
            i++;
            j++;
        } else if (set.data[i] > subset.data[j])
            j++;
        else
            return false;
    }
    return i == set.size;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    int i = 0;
    int j = 0;
    if (set1.size == set2.size)
        while (i < set1.size && j < set2.size) {
            if (set1.data[i] == set2.data[j]) {
                i++;
                j++;
            } else if (set1.data[i] > set2.data[j])
                j++;
            else
                return false;
        }
    return i == set1.size;
}
void unordered_array_set_print ( unordered_array_set set ){
    for(int i=0;i<set.size;i++){
        printf("%d",set.data[i]);
    }
}
void unordered_array_set_delete ( unordered_array_set set ){
    free(set.data);
}
#endif //UNTITLED7_UNORDERED_SET_C
