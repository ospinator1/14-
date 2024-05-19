#include <stdio.h>
#include <stdlib.h>
#include "libs/strings/string/string_.h"
#include <assert.h>

#define MAX_REQUEST 128
BagOfWords _bag;
BagOfWords _bag2;
char _stringBuffer[MAX_STRING_SIZE + 1];
typedef struct request {
    WordDescriptor sequence;
    int position;
} request;
typedef struct requests {
    request request[MAX_REQUEST];
    size_t size;
} requests;

void printWord(const WordDescriptor *word) {
    for (char *j = word->begin; j < word->end; j++) {
        printf("%c", *j);
    }
    printf("\n");
}

void print_request(request *r) {
    printf("%d", r->position);
    printWord(&r->sequence);
}

bool is_sub_word(WordDescriptor word1, WordDescriptor word2) {
    char *begin1 = word1.begin;
    char *begin2 = word2.begin;

    while (begin1 <= word1.end) {
        if (*begin1 != *begin2)
            return false;

        begin1++;
        begin2++;
    }

    if (word1.end - begin1 > 0)
        return false;

    return true;
}

void auto_completion(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }
    int n, q;
    fscanf(file, "%d", &n);
    fscanf(file, "%d", &q);
    _bag.size = 0;
    char *begin = _stringBuffer;
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s", begin);
        getWordWithoutSpace(begin, &_bag.words[_bag.size]);
        begin = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }
    requests rs = {.size = 0};
    for (int i = 0; i < q; i++) {
        fscanf(file, "%d", &rs.request[i].position);
        fscanf(file, "%s", begin);
      getWordWithoutSpace(begin, &rs.request[i].sequence);
        begin = rs.request[i].sequence.end + 1;
        rs.size++;
    }
    fclose(file);
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }
    for (int i = 0; i < q; i++) {
        int amount = 0;
        for (int j = 0; j < n; j++) {
            if (is_sub_word(rs.request[i].sequence, _bag.words[j])) {
                amount++;
                if (amount == rs.request[i].position)
                    fprintf(file, "%d\n", j + 1);
            }
        }
        if (amount < rs.request[i].position)
            fprintf(file, "-1\n");
    }
    fclose(file);

}

void test_empty_file() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 20\\tasks11\\1.txt";
    FILE *file = fopen(filename, "w");
    int n = 0;
    int q = 0;
    fprintf(file, "%d %d \n", n, q);
    fclose(file);
    auto_completion(filename);
    file = fopen(filename, "r");
    char res[100] = "";
    fgets(res, 100, file);
    fclose(file);
    assert(strcmp(res, "") == 0);
}

void test_q_zero() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 20\\tasks11\\2.txt";
    FILE *file = fopen(filename, "w");
    int n = 5;
    int q = 0;
    fprintf(file, "%d %d \n", n, q);
    fprintf(file, "Alan\n");
    fprintf(file, "Wake\n");
    fprintf(file, "Herald\n");
    fprintf(file, "Darkness\n");
    fprintf(file, "Old\n");
    fclose(file);
    auto_completion(filename);
    file = fopen(filename, "r");
    char res[100] = "";
    fgets(res, 100, file);
    fclose(file);
    assert(strcmp(res, "") == 0);
}

void test_different_element() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 20\\tasks11\\3.txt";
    FILE *file = fopen(filename, "w");
    int n = 10;
    int q = 3;
    fprintf(file, "%d %d \n", n, q);
    fprintf(file, "aa\n");
    fprintf(file, "aaa\n");
    fprintf(file, "aab\n");
    fprintf(file, "ab\n");
    fprintf(file, "abc\n");
    fprintf(file, "ac\n");
    fprintf(file, "ba\n");
    fprintf(file, "daa\n");
    fprintf(file, "dab\n");
    fprintf(file, "dadba\n");
    fprintf(file, "4 a\n");
    fprintf(file, "2 da\n");
    fprintf(file, "4 da\n");
    fclose(file);
    auto_completion(filename);
    file = fopen(filename, "r");
    int n1, n2, n3;
    fscanf(file, "%d\n", &n1);
    fscanf(file, "%d\n", &n2);
    fscanf(file, "%d\n", &n3);
    fclose(file);
    assert(n1 == 4);
    assert(n2 == 9);
    assert(n3 == -1);
}

void test() {
    test_empty_file();
    test_q_zero();
    test_different_element();
}

int main() {
    test();
}