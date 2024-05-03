//
// Created by Assa on 29.04.2024.
//

#ifndef UNTITLED7_TASKS3_H
#define UNTITLED7_TASKS3_H
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "../../../strings/string/string_.h"

void generate_operand(char *filename) {
    srand(time(NULL));

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка чтения\n");
        exit(1);
    }
    int x1 = rand() % 10;
    int x2 = rand() % 10;
    int x3 = rand() % 10;
    char operators[] = "-+*/";
    char op1 = operators[rand() % 4];
    char op2 = operators[rand() % 4];
    bool one_operation = rand() % 2;
    if (one_operation) {
        fprintf(file, "(%d,%c,%d)", x1, op1, x2);
    } else
        fprintf(file, "(%d,%c,%d) %c %d", x1, op1, x2, op2, x3);
    fclose(file);
}

void evaluate_expression(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Ошибка чтения\n");
        exit(1);
    }
    int x1, x2, x3;
    char op1, op2;
    char open_bracket, close_bracket;
    float result;
    int amount_element = fscanf(file, "%c %d %c %d %c %c %d", &open_bracket, &x1, &op1, &x2, &close_bracket, &op2, &x3);
    bool two_operation = amount_element == 7 ? true : false;
    switch (op1) {
        case '+':
            result = x1 + x2;
            break;
        case '-':
            result = x1 - x2;
            break;
        case '*':
            result = x1 * x2;
            break;
        case '/':
            if (x2 == 0) {
                (stderr, "Zero division");
                exit(1);
            }
            result = x1 / x2;
            break;
        default:
            fprintf(stderr, "unknown operation");
            exit(1);
    }
    if (two_operation) {
        switch (op2) {
            case '+':
                result += x3;
                break;
            case '-':
                result -= x3;
                break;
            case '*':
                result *= x3;
                break;
            case '/':
                if (x3 == 0) {
                    (stderr, "Zero division");
                    exit(1);
                }
                result /= x3;
                break;
            default:
                fprintf(stderr, "unknown operation");
                exit(1);
        }

    }
    fseek(file, 0, SEEK_END);
    fprintf(file, " = %.2f", result);

    fclose(file);
}

void test_evaluate_expression_empty() {
    /* если файл пуст, то будет выведено сообщение unknown operation */
}

void test_evaluate_expression_2_operation() {
    const char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\3 tasks\\3_2.txt";
    char expression[] = "(8 * 9)";
    FILE *f = fopen(filename, "w");
    fputs(expression, f);
    fclose(f);
    evaluate_expression("C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\3 tasks\\3_2.txt");
    f = fopen(filename, "r");
    char data[50] = "";
    fgets(data, sizeof(data), f);
    fclose(f);
    char result[] = "(8*9)=72.0";
    assert(strcmp(result, data));
}

void test_evaluate_expression_3_operation() {
    const char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\3 tasks\\3_3.txt";
    char expression[] = "(8 * 9)+10";
    FILE *f = fopen(filename, "w");
    fputs(expression, f);
    fclose(f);
    evaluate_expression("C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\3 tasks\\3_3.txt");
    f = fopen(filename, "r");
    char data[50] = "";
    fgets(data, sizeof(data), f);
    fclose(f);
    char result[] = "(8*9)+10=82.0";
    assert(strcmp(result, data));
}

void test_evaluate_expression() {
    test_evaluate_expression_empty();
    test_evaluate_expression_2_operation();
    test_evaluate_expression_3_operation();
}
#endif //UNTITLED7_TASKS3_H
