
#ifndef UNTITLED7_BITSET_H
#define UNTITLED7_BITSET_H


# include <stdint.h>
# include <stdbool.h>
#include <assert.h>
typedef struct bitset {
    uint32_t values ; // множество
    uint32_t maxValue ; // максимальный элемент универсума
} bitset ;

// возвращает пустое множество c универсумом 0, 1,..., maxValue
struct bitset bitset_create ( unsigned maxValue ) ;

// возвращает значение ’истина’, если значение value имеется в множестве set
// иначе - ’ложь’
bool bitset_in ( bitset set , unsigned int value ) ;

// возвращает значение ’истина’, если множества set1 и set2 равны// иначе - ’ложь’
bool bitset_is_equal ( bitset set1 , bitset set2 ) ;

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool bitset_is_subset ( bitset subset , bitset set ) ;

// добавляет элемент value в множество set
struct bitset bitset_insert ( bitset * set , unsigned int value ) ;

// удаляет элемент value из множества set
struct bitset bitset_delete_element ( bitset * set , unsigned int value ) ;

// возвращает объединение множеств set1 и set2
bitset bitset_union ( bitset set1 , bitset set2 ) ;

// возвращает пересечение множеств set1 и set2
bitset bitset_intersection ( bitset set1 , bitset set2 ) ;

// возвращает разность множеств set1 и set2
bitset bitset_difference ( bitset set1 , bitset set2 ) ;

// возвращает симметрическую разность множеств set1 и set2
bitset bitset_symmetric_difference ( bitset set1 , bitset set2 ) ;

// возвращает дополнение до универсума множества set
bitset bitset_complement ( bitset set ) ;
bitset bitset_create_from_array(const unsigned int a[], size_t size, unsigned max_value);
// возвращает дополнение до универсума множества set


// вывод множества set
struct bitset bitset_print ( bitset set ) ;

#endif //UNTITLED7_BITSET_H
