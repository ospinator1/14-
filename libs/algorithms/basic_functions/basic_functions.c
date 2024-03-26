//
// Created by Assa on 16.03.2024
//
#ifndef UNTITLED7_BASIC_FUNCTIONS_С
#define UNTITLED7_BASIC_FUNCTIONS_С

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
float abs1(float z) {
    float x = abs(z);
    return x;
}
int max2(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int max3(int a, int b, int c){
    return max2(max2( a,b),c);
}

double getDistance(int x1,int y1,int x2,int y2){
    double length=x2-x1;
    double width=y2-y1;
    return sqrt(pow(length,2)+pow(width,2));
}
double solveX2(int a, int b, int c) {
    double D = b * b - 4 * a * c;
    double sqrtD = sqrt(D);
    if (D >= 0) {
        double x1 = (-b - sqrtD )/ (2 * a);
        double x2 = (-b + sqrtD) / (2 * a);
        printf("%f %f\n", x1, x2);
    } else {
        printf("Корней нет\n");
    }
}
int isDigit(int x){
    int digit=0;

    if (x>0 && x<9){
        digit=1;
    }
    return digit;
}
void swap(int a,int b){
    int t=a;
    a=b;
    b=t;
}
void sort2(float *a,float *b){
    if (*a>*b)
        swap(a,b);
}
void sort3(float *a, float *b, float *c) {
    sort2(a, b);
    sort2(b, c);
    sort2(a, b);
}
int isPrime(int x) {
    int flag = 1;
    if (x == 10)
        flag = 0;
    else if (x > 2)
        for (int i = 2; i <= x; i++) {
            if (x % i == 0) {
                return 0;
            }
        }
    return flag;
}
int isPrime1(int x) {
    int flag = 1;
    if (x == 1) {
        flag = 0;
    } else if (x > 2) {
        for (int i = 2; i <= sqrt(x) + 1; i++) {
            if (x % i == 0)
                return 0;
        }
    }
    return flag;
}
int isPrime2(int x) {
    int flag = 1;

    if (x == 1) {
        flag = 0;
    } else if (x > 2) {
        for (int i = 3; i <= sqrt(x) + 1; i++) {
            if (x % i == 0)
                return 0;
        }
    }
    return flag;
}

int isPerfectNumber(long long x) {
    const int minPossibleDivider = 2;
    const long long upperBound = sqrtl(x);
    long long sumOfDividers = 1;
    for (int possibleDivider = minPossibleDivider;
         possibleDivider <= upperBound; possibleDivider++) {
        if (x % possibleDivider == 0) {
            sumOfDividers += possibleDivider;
            sumOfDividers += x / possibleDivider;
        }
    }
    if (upperBound * upperBound == x)
        sumOfDividers -= upperBound;
    return x == sumOfDividers;
}

int reverseDigit(int n){
    int rev=0;
    while (n>0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return rev;
}

int amountPolindromes (int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int reverse_i_digit = reverseDigit(i);
        if (reverse_i_digit == i)
            count++;
    }
    return count;
}

int countDigits(int x) {
    int count = 1;
    while (x >9) {
        count++;
        x/=10;
    }
    return count;
}
int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i) {

        if (a[i] < min)
            a[i] = min;
    }
    return min;
}
#endif