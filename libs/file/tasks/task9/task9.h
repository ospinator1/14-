//
// Created by Assa on 02.05.2024.
//

#ifndef UNTITLED7_TASK9_H
#define UNTITLED7_TASK9_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "../../../data_structures/vector/vector.h"
#include <windows.h>
#include "../../../strings/string/string_.h"
#define MAX_LENGTH_STRING 200
#define MAX_AMOUNT_SPORTSMAN 20
#include <math.h>


typedef struct sportsman {
    char name[MAX_LENGTH_STRING];
    double best_result;
} sportsman;


static void generate_name(char *s) {
    int name_length = rand() % 30 + 5;

    char *rec_ptr = s;
    for (int i = 0; i < name_length; i++) {
        *rec_ptr = rand() % 26 + 97;
        rec_ptr++;
    }
    *rec_ptr = '\0';
}

void generate_team(const char *filename, const int n) {
    srand(time(NULL));

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Ошибка чтения\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        sportsman s;
        generate_name(s.name);
        s.best_result = (double) rand() / 100;
        fwrite(&s, sizeof(sportsman), 1, file);
    }
    fclose(file);
}

void sort_sportsman(sportsman sm[], const int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (sm[j].best_result < sm[j + 1].best_result) {
                sportsman temp = sm[j];
                sm[j] = sm[j + 1];
                sm[j + 1] = temp;
            }
}

void getBestTeam(const char *filename, const int n) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка чтения\n");
        exit(1);
    }
    sportsman *team = (sportsman *) malloc(MAX_AMOUNT_SPORTSMAN * sizeof(sportsman));
    sportsman *rec_ptr = team;
    int amount_sportsman = 0;
    while (fread(rec_ptr, sizeof(sportsman), 1, file) == 1) {
        rec_ptr++;
        amount_sportsman++;
    }
    fclose(file);
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Ошибка чтения\n");
        exit(1);
    }
    sort_sportsman(team, amount_sportsman);
    int amount_in_team = amount_sportsman >= n ? n : amount_sportsman;
    for (int i = 0; i < amount_in_team; i++) {
        fwrite(team + i, sizeof(sportsman), 1, file);
    }
    free(team);
    fclose(file);
}

void print_team(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("ошибка чтения\n");
        exit(1);
    }
    sportsman s;
    while (fread(&s, sizeof(sportsman), 1, file) == 1) {
        printf("%s %lf", s.name, s.best_result);
        printf("\n");
    }
    fclose(file);
}
void test_getBestTeam_empty(){
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\9 tasks\\9_1.txt";
    FILE *file= fopen(filename,"wb");
    fclose(file);
    getBestTeam(filename,0);
    file = fopen(filename, "rb");
    char data[100] = "";
    fread(data, sizeof(data), 1, file);
    fclose(file);
    assert(strcmp(data, "") == 0);
}
void test_getBestTeam_1() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\9 tasks\\9_2.txt";
    FILE *file = fopen(filename, "wb");
    sportsman sportsman1 = {.name="Alex", .best_result=10.5};
    sportsman sportsman2 = {.name="Alan", .best_result=10.0};
    fwrite(&sportsman1, sizeof(sportsman), 1, file);
    fwrite(&sportsman2, sizeof(sportsman), 1, file);
    fclose(file);
    getBestTeam(filename, 3);
    file = fopen(filename, "rb");
    sportsman result_s1, result_s2;
    fread(&result_s1, sizeof(sportsman), 1, file);
    fread(&result_s2, sizeof(sportsman), 1, file);
    fclose(file);
    assert(strcmp((const char *) &sportsman1.name, (const char *) &result_s1.name) == 0 &&
           fabs(sportsman1.best_result - result_s1.best_result) <= 0.001);
    assert(strcmp((const char *) &sportsman1.name, (const char *) &result_s1.name) == 0 &&
           fabs(sportsman1.best_result - result_s1.best_result) <= 0.001);
}
void test_getBestTeam_2(){
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\9 tasks\\9_3.txt";
    FILE *file = fopen(filename, "wb");
    sportsman sportsman1 = {.name="Alex", .best_result=10.5};
    sportsman sportsman2 = {.name="Alan", .best_result=10.0};
    fwrite(&sportsman1, sizeof(sportsman), 1, file);
    fwrite(&sportsman2, sizeof(sportsman), 1, file);
    fclose(file);
    getBestTeam(filename, 1);
    file = fopen(filename, "rb");
    sportsman result_s1;
    fread(&result_s1, sizeof(sportsman), 1, file);

    fclose(file);
    assert(strcmp((const char *) &sportsman1.name, (const char *) &result_s1.name) == 0 &&
           fabs(sportsman1.best_result - result_s1.best_result) <= 0.001);
}
void test_getBestTeam(){
    test_getBestTeam_empty();
    test_getBestTeam_1();
    test_getBestTeam_2();
}
#endif //UNTITLED7_TASK9_H
