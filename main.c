#include <stdio.h>
#include "libs/data_structures//matrix/matrix.h"

typedef struct coord {
    int row1;
    int col1;
    int row2;
    int col2;
} coord;


void fill_matrix(const char* filename) {
    FILE* file = fopen(filename, "rb");
    int n;
    fread(&n, sizeof(int), 1, file);
    matrix m = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m.values[i][j] = 0;
    coord c;
    while(fread(&c, sizeof(coord), 1, file) == 1)
        for (int i = c.row1; i <= c.row2; i++)
            for (int j = c.col1; j <= c.col2; j++)
                m.values[i][j]++;

    fclose(file);
    file = fopen(filename, "wb");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fwrite(&m.values[i][j], sizeof(int), 1, file);
    fclose(file);
}

void test_fill_matrix() {
    const char* filename = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\1 tasks\\1_2.txt";

    FILE* file = fopen(filename, "wb");

    int n = 3;
    fwrite(&n, sizeof(int), 1, file);

    coord c1 = {1, 1, 2, 2};
    coord c2 = {0, 0, 1, 1};
    fwrite(&c1, sizeof(coord), 1, file);
    fwrite(&c2, sizeof(coord), 1, file);

    fclose(file);

    fill_matrix(filename);

    file = fopen(filename, "rb");

    int matrix_values[n][n];
    fread(&n, sizeof(int), 1, file);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fread(&matrix_values[i][j], sizeof(int), 1, file);

    fclose(file);


    printf("Updated matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix_values[i][j]);
        }
        printf("\n");
    }
}
int main(){
    test_fill_matrix();
}