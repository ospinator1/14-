#ifndef UNTITLED7_TASKS10_H
#define UNTITLED7_TASKS10_H
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

FILE *file;
int N;
void handle_sigint(__attribute__((unused)) int sig) {
    char line[256];
    for (int i = 0; i < N; i++)
        if(fgets(line, sizeof(line), file))
            printf("%s", line);
        else
            exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <N>\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    N = atoi(argv[2]); // NOLINT(*-err34-c)
    signal(SIGINT, handle_sigint);
    getchar();
    return 0;
}
#endif //UNTITLED7_TASKS10_H
