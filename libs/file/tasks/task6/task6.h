//
// Created by Assa on 01.05.2024.
//

#ifndef UNTITLED7_TASK6_H
#define UNTITLED7_TASK6_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "../../../data_structures/vector/vectorVoid.h"
#include <math.h>
#include "../../../strings/string/string_.h"

typedef struct monomial {
    int degree;
    double coefficient;
} monomial;

void generate_polynamial(const char *filename, int lines, int word, int max_word_size) {
    srand(time(NULL));
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }
    int amount_polynamial = rand() % +2;
    for (int i = 0; i < amount_polynamial; ++i) {
        amount_polynamial = rand() % +1;
        amount_polynamial = rand() % +2;
        struct monomial mono;
        for (int j = 0; j <= amount_polynamial; ++j) {
            mono.degree = amount_polynamial - i;
            mono.coefficient = 2.0 * rand() / RAND_MAX - 1.0;
            fwrite(&mono, sizeof(monomial), 1, file);
        }
    }
    fclose(file);
}

double get_monomial_value(struct monomial mono, double x) {
    return pow(x, mono.degree) * mono.coefficient;
}

void remove_polynomial(const char *filename, double x) {
    vectorVoid v = createVectorV(16, sizeof( monomial));

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка чтения\n");
        exit(1);
    }

    struct monomial mono;
    while (fread(&mono, sizeof( monomial), 1, file) == 1)
        pushBackV(&v, &mono);

    fclose(file);


    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Ошибка чтения\n");
        exit(1);
    }

    struct monomial m;
    vectorVoid temp = createVectorV(8, sizeof(monomial));
    double result = 0;
    for (size_t i = 0; i < v.size; i++) {
        getVectorValueV(&v, i, &m);
        pushBackV(&temp, &m);
        result += get_monomial_value(m, x);

        if (m.degree == 0) {
            if (fabs(result) >= 0.001) {
                struct monomial temp_mono;
                for (size_t j = 0; j < temp.size; j++) {
                    getVectorValueV(&temp, j, &temp_mono);
                    fwrite(&temp_mono, sizeof( monomial), 1, file);
                }
            }

            result = 0;
        }
    }


    fclose(file);
}

void print_polynamial(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка чтенияr\n");
        exit(1);
    }
    struct monomial mono;
    while (fread(&mono, sizeof(monomial), 1, file) == 1) {
        printf("%5.2lf * x^%lld + ", mono.coefficient, mono.degree);
        if (mono.degree == 0)
            printf("\b\b \n");
    }
    fclose(file);
}

void test_remove_polynomial_empty_file() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\6 tasks\\6_1.txt";
    FILE *file = fopen(filename, "wb");
    fclose(file);
    remove_polynomial(filename, 1.0);
    file = fopen(filename, "rb");
    char data[100] = "";
    fscanf(file, "%s", data);
    fclose(file);
    assert(strcmp(data, "") == 0);
}

void test_remove_polynomial_2() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\6 tasks\\6_2.txt";
    double x = 2.0;
    struct monomial x1 = {.coefficient=3.0, .degree=2.0};
    struct monomial x2 = {.coefficient=10, .degree=-2};
    struct monomial x3 = {.coefficient=0, .degree=0};
    FILE *file = fopen(filename, "wb");
    fwrite(&x1, sizeof(monomial), 1, file);
    fwrite(&x2, sizeof( monomial), 1, file);
    fwrite(&x3, sizeof( monomial), 1, file);
    fclose(file);
    remove_polynomial(filename, x);
    file = fopen(filename, "rb");
    monomial res_x1;
    fread(&res_x1, sizeof(monomial), 1, file);
    monomial res_x2;
    fread(&res_x2, sizeof( monomial), 1, file);
    monomial res_x3;
    fread(&res_x3, sizeof( monomial), 1, file);
    fclose(file);
    assert(x1.coefficient - res_x1.coefficient <= 0.0001 && x1.degree == res_x1.degree);
    assert(x2.coefficient - res_x2.coefficient <= 0.0001 && x2.degree == res_x2.degree);
    assert(x3.coefficient - res_x3.coefficient <= 0.0001 && x3.degree == res_x3.degree);
}

void test_remove_true_polynomial_3_true_expression() {
    const char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\6 tasks\\6_3.txt";
    double x = 1.0;
    monomial x2 = {.coefficient = 1.0, .degree = 2};
    monomial x1 = {.coefficient = -2.0, .degree = 1};
    monomial x3 = {.coefficient = 1.0, .degree = 0};
    FILE *file = fopen(filename, "rb");
    fwrite(&x2, sizeof(monomial), 1, file);
    fwrite(&x1, sizeof(monomial), 1, file);
    fwrite(&x3, sizeof(monomial), 1, file);
    fclose(file);
    remove_polynomial(filename, x);
    file = fopen(filename, "rb");
    char data[100] = "";
    fscanf(file, "%s", data);
    fclose(file);

}

void test_polynamial() {
    test_remove_polynomial_empty_file();
    test_remove_polynomial_2();
    test_remove_true_polynomial_3_true_expression();
}

#endif //UNTITLED7_TASK6_H
