//
// Created by Assa on 01.05.2024.
//

#ifndef UNTITLED7_TASK5_H
#define UNTITLED7_TASK5_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "../../../strings/string/string_.h"

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define MAX_LINE_SIZE 100
char _stringBuffer[MAX_STRING_SIZE + 1];
BagOfWords _bag;
#include <windows.h>
void generate_text(const char *filename, int lines, int word, int max_word_size) {
    srand(time(NULL));
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < word; ++j) {
            for (int k = 0; k < rand() % max_word_size + 1; ++k) {

            }
            fprintf(file, " ");
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void leave_longest_word(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка чтения\n");
        exit(1);
    }
    char buff[MAX_LINE_SIZE] = "";
    char* rec_ptr = _stringBuffer;
    fgets(buff, sizeof(buff), file);
    size_t length = strlen_(buff);
    length = length == 0 ? 1 : length;
    rec_ptr = copy(buff, buff + length - 1, rec_ptr);
    *rec_ptr++ = ' ';
    size_t amount_word_in_line = 0;
    char* begin_search = _stringBuffer;
    while (getWordWithoutSpace(begin_search, &_bag.words[_bag.size])) {
        begin_search = _bag.words[_bag.size].end + 1;
        amount_word_in_line++;
        _bag.size++;
    }
    while (fgets(buff, sizeof(buff), file)) {
        rec_ptr = copy(buff, buff + strlen_(buff) - 1, rec_ptr);
        *rec_ptr++ = ' ';

        while (getWordWithoutSpace(begin_search, &_bag.words[_bag.size])) {
            begin_search = _bag.words[_bag.size].end + 1;
            _bag.size++;
        }
    }
    fclose(file);
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка чтения\n");
        exit(1);
    }
    for (size_t i = 0; i < _bag.size; i += amount_word_in_line) {
        WordDescriptor word_max_length = _bag.words[i];
        size_t max_length = word_max_length.end - word_max_length.begin + 1;

        for (size_t j = i + 1; j < i + amount_word_in_line; j++) {
            size_t current_length = _bag.words[j].end - _bag.words[j].begin + 1;

            if (current_length > max_length) {
                word_max_length = _bag.words[j];
                max_length = current_length;
            }
        }
        char* write_ptr = word_max_length.begin;
        while (write_ptr <= word_max_length.end) {
            fprintf(file, "%c", *write_ptr);
            write_ptr++;
        }

        fprintf(file, "\n");
    }
    free_bag(&_bag);
    fclose(file);
}


void test_printf_long_word_empty(){
    char filename[]="C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\5 tasks\\5_1.txt";
    FILE *file= fopen(filename,"w");
    fclose(file);
    leave_longest_word(filename);
    file= fopen(filename,"r");
    char data[100]="";
    fprintf(file,"s",data);
    fclose(file);
    assert(strcmp(data,"")==0);

}
void test_printf_long_word_2_one_element(){
    char filename[]="C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\5 tasks\\5_2.txt";
    char line1[] = "abcd";
    char line2[] = "efg";
    char line3[] = "hi";
    FILE* file = fopen(filename, "w");
    fprintf(file, "%s \n", line1);
    fprintf(file, "%s \n", line2);
    fprintf(file, "%s \n", line3);
    fclose(file);
    leave_longest_word(filename);
    file = fopen(filename, "r");
    char res_line1[10] = "";
    fscanf(file, "%s\n", res_line1);
    char res_line2[10] = "";
    fscanf(file, "%s\n", res_line2);
    char res_line3[10] = "";
    fscanf(file, "%s\n", res_line3);
    fclose(file);
    assert(strcmp(line1, res_line1) == 0);
    assert(strcmp(line2, res_line2) == 0);
    assert(strcmp(line3, res_line3) == 0);
}
void test_printf_long_word_3_more_element() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\5 tasks\\5_3.txt";
    char line1[] = "Herald of Darkness ";
    char line2[] = "Alan Wake ";
    char line3[] =  "Old Gods of Asgard";
    FILE* file = fopen(filename, "w");
    fputs(line1, file);
    fprintf(file, "\n");
    fputs(line2, file);
    fprintf(file, "\n");
    fputs(line3, file);
    fprintf(file, "\n");
    fclose(file);
    leave_longest_word(filename);
    file = fopen(filename, "r");
    char res_line1[20] = " ";
    fscanf(file, "%s\n", res_line1);
    char res_line2[10] = " ";
    fscanf(file, "%s\n", res_line2);
    char res_line3[10] = " ";
    fscanf(file, "%s\n", res_line3);
    fclose(file);
    char check1[] = "Darkness";
    char check2[] = "Alan";
    char check3[] = "Asgard";
    assert(strcmp(check1, res_line1) == 0);
    assert(strcmp(check2, res_line2) == 0);
    assert(strcmp(check3, res_line3) == 0);
}

void test_printf_long_word(){
    test_printf_long_word_empty();
    test_printf_long_word_2_one_element();
    test_printf_long_word_3_more_element();
}
#endif //UNTITLED7_TASK5_H
