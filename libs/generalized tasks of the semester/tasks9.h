#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-err34-c"
//
// Created by Assa on 18.05.2024.
//

#ifndef UNTITLED7_TASKS9_H
#define UNTITLED7_TASKS9_H
#include <stdlib.h>
#include "../data_structures/vector/vector.h"
#include <time.h>
size_t fileWithSmallerValues(char *fileInputPath, char *fileOutputPath, int n) {
    FILE *fp = fopen(fileInputPath, "r");
    FILE *fd = fopen(fileOutputPath, "w+");

    if (fp == NULL) {
        fprintf(stderr, "Input file cannot be opened");
        exit(1);
    }
    if (fd == NULL) {
        fprintf(stderr, "Output file cannot be opened");
        exit(1);
    }

    size_t counter = 0;

    int val;
    while (fscanf(fp, "%d", &val) > 0) {
        if (val < n) {
            fprintf(fd, "%d\n", val);
            counter++;
        }
    }
    fclose(fp);
    fclose(fd);

    return counter;
}
void test(){
    int n = 500;
    srand((unsigned) time(NULL)); // NOLINT(*-msc51-cpp)
    FILE *fp = fopen ("C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 20\\tasks9\\1.txt", "w+");

    int expArray[1000];
    int idx = 0;
    for (int i = 0; i < 1000; i++) {
        int val = rand();
        if (val < n) {
            expArray[idx++] = val;
        }
        fprintf(fp, "%d\n", val);
    }
    fclose(fp);

    size_t res = fileWithSmallerValues("C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 20\\tasks9\\1.txt", "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 20\\tasks9\\2.txt", n);
    assert(idx == res);
}
int main() {
    test();
}
#endif //UNTITLED7_TASKS9_H

#pragma clang diagnostic pop