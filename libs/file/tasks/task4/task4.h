//
// Created by Assa on 29.04.2024.
//

#ifndef UNTITLED7_TASK4_H
#define UNTITLED7_TASK4_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../../strings/string/string_.h"
#include <ctype.h>

#define Letters 97
char _stringBuffer[MAX_STRING_SIZE + 1];

int compare_letters(const void* s1, const void* s2) {
    return *(const unsigned char*) s1 - *(const unsigned char*) s2;
}

void sort_word_letters(WordDescriptor * word) {
    qsort(word->begin, word->end - word->begin + 1, sizeof(char), compare_letters);
}


bool letters_belong_word(WordDescriptor sub_word, WordDescriptor word) {
    bool include[26] = {0};

    char* start = word.begin;
    char* end = word.end + 1;

    while (start != end) {
        if (isalpha(*start))
            include[*start - Letters] = true;

        start++;
    }

    while (sub_word.begin <= sub_word.end) {
        if (!include[*sub_word.begin - Letters])
            return false;

        sub_word.begin++;
    }

    return true;
}



void generate_string(const char* filename, char* source_string) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    size_t string_length = strlen_(source_string);

    for (size_t i = 0; i <= string_length; i++)
        fprintf(file, "%c", source_string[i]);

    fclose(file);
}


void filter_word(const char* filename, char* source_word) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (length == 0)
        return;

    fread(_stringBuffer, sizeof(char), length, file);
    _stringBuffer[length] = '\0';

    fclose(file);

    WordDescriptor word;
    getWordWithoutSpace(source_word, &word);
    sort_word_letters(&word);

    BagOfWords words = {.size = 0};
    char* begin_search = _stringBuffer;
    while (getWordWithoutSpace(begin_search, &words.words[words.size])) {
        begin_search = words.words[words.size].end + 1;
        words.size++;
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    for (size_t i = 0; i < words.size; i++) {
        if (letters_belong_word(word, words.words[i])) {
            while (words.words[i].begin <= words.words[i].end) {
                fprintf(file, "%c", *words.words[i].begin);
                words.words[i].begin++;
            }
            fprintf(file, " ");
        }
    }

    fprintf(file, "%c", '\0');


    fclose(file);
}
void test_filter_word_1_empty_file() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\4 tasks\\4_1.txt";
    generate_string(filename, "");
    char source_word[] = "source";
    filter_word(filename, source_word);
    FILE *file = fopen(filename, "r");
    char data[10] = "";
    fscanf(file, "%s", data);
    fclose(file);
    assert(strcmp(data, "") == 0);
}
void test_filter_word_2() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\4 tasks\\4_2.txt";
    generate_string(filename, "fkjsdfnkdjfn");
    char source_word[] = "amogus";
    filter_word(filename, source_word);
    FILE *file = fopen(filename, "r");
    char data[10] = "";
    fscanf(file, "%s", data);
    fclose(file);
    assert(strcmp(data, "") == 0);
}
void test_filter_word_3() {
    char filename[] = "C:\\Users\\Assa\\CLionProjects\\untitled7\\text labs 19\\4 tasks\\4_3.txt";
    generate_string(filename, "Herald of Darkness");
    char source_word[] = "Her";
    filter_word(filename, source_word);
    FILE *file = fopen(filename, "r");
    char data[100] = "";
    fscanf(file, "%s", data);
    fclose(file);
    assert(strcmp(data, "Herald") == 0);
}
void test_filter_word(){
    test_filter_word_1_empty_file();
    test_filter_word_2();
    test_filter_word_3();
}
#endif //UNTITLED7_TASK4_H
