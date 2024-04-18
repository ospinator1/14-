//
// Created by Assa on 07.04.2024.
//

#ifndef UNTITLED7_STRING_H
#define UNTITLED7_STRING_H
#define MAX_STRING_SIZE 100
char findLength(char str[50]);//находит длину строки
int strlen_(const char *begin );// возвращает количество символов в строке (не cчитая ноль-символ)
char* find(char *begin, char *end, int ch);//возвращает указательна первый элемент с кодом ch, расположенным на ленте памяти между адресами begin и end не включая end.
char *findNonSpace(char *begin);//возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом
char *findSpace(char *begin);//возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ.
char *findNonSpaceReverse(char *rbegin, const char *rend);//возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти, начиная с rbegin (последний символ строки, за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки). Если символ не найден, возвращается адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend);//возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти, начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
char *copy(const char *beginSource, const char *endSource, char *beginDestination);//записывает по адресу beginDestinationфрагмент памяти, начиная с адреса beginSource до endSource.Возвращает указатель на следующий свободный фрагмент памяти в destination
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));//записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource заканчивая endSource, удовлетворяющие функции-предикату f. Функция  памяти.
int isLetter(int x);
int strcmp(const char *lhs, const char *rhs);
        char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));//записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f. Функция возвращает значение beginDestination по окончанию работ функции.
char _stringBuffer[MAX_STRING_SIZE + 1];
struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;
char *getEndOfString(char *s);
void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);
#endif //UNTITLED7_STRING_H
