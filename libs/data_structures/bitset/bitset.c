

#define UNTITLED7_BITSET_H

# include <stdint.h>
#include <stdio.h>
# include <stdbool.h>
#include <assert.h>
typedef struct bitset {
    uint32_t values ; // множество
    uint32_t max_value ; // максимальный элемент универсума
} bitset ;
bitset bitset_create(unsigned max_value) {
    assert(max_value < 32);
    return (bitset){0, max_value};
}

void bitset_insert(bitset* set, unsigned value) {
    set -> values = (set -> values) | (1<< value);
}

bitset bitset_create_from_array(const unsigned int* a, size_t size, unsigned max_value) {
    bitset set = bitset_create(max_value);
    for (size_t i = 0; i < size; i++) {
        bitset_insert(&set, a[i]);
    }
    return set;
}


bool bitset_in(bitset set, unsigned value) {
    return set.values & (1 << value);
}

bool bitset_is_equal(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_is_subset(bitset subset, bitset set) {
    return (set.values & subset.values) == subset.values;
}


void bitset_delete_element(bitset* set, unsigned value) {
    assert(value < 32);
    set->values &= ~(1U << value);
}
bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.max_value == set2.max_value);
    return (bitset) {set1.values | set2.values, set1.max_value};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.max_value == set2.max_value);
    return (bitset) {set1.values & set2.values,set1.max_value};
}

bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.max_value == set2.max_value);
    return (bitset){set1.values & ~set2.values, set1.max_value};
}

bitset bitset_symmetric_difference(bitset set1, bitset set2) {
    assert(set1.max_value == set2.max_value);
    return (bitset) {set1.values ^ set2.values,set1.max_value};
}

bitset bitset_complement(bitset set) {
    uint32_t universum = (1<< (set.max_value + 1)) - 1;
    return (bitset) {universum&!set.max_value, set.max_value};
}

void bitset_print(bitset set) {
    printf ("{") ;
    int is_empty = 1;

    for (int i = 0; i <= set.max_value; i++) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            is_empty = 0;
        }
    }
    if (is_empty)
        printf("}\n");
    else
        printf("\b\b}\n");
}
