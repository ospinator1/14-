#include <stdlib.h>
#include "libs/generalized tasks of the semester/tasks9.h"
#include <time.h>
void test(){
    int n = 500;
    srand((unsigned) time(NULL));
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
