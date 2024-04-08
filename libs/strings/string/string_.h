//
// Created by Assa on 07.04.2024.
//

#ifndef UNTITLED7_STRING_H
#define UNTITLED7_STRING_H
char findLength(char str[50]);//находит длину строки
int strlen_(const char *begin );// возвращает количество символов в строке (не cчитая ноль-символ)
char* find(char *begin, char *end, int ch);//возвращает указательна первый элемент с кодом ch, расположенным на ленте памяти между адресами begin и end не включая end.
char *findNonSpace(char *begin);//возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом
#endif //UNTITLED7_STRING_H
