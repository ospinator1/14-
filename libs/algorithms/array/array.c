
# include <stdio.h>
# include <assert.h>
# include <stdint.h>
# include "array.h"


void inputArray_ (int * const a , const size_t n ) {
    for ( size_t i = 0; i < n ; i ++)
        scanf ("%d", & a [ i ]) ;
}

void outputArray_ ( const int * const a , const size_t n ) {
    for ( size_t i = 0; i < n ; i ++)
        printf ("%d ", a [ i ]) ;
    printf ("\n") ;
}



void deleteByPosSaveOrder_ (int *a , size_t *n , const size_t pos ) {
    for ( size_t i = pos ; i < * n - 1; i ++)
        a [ i ] = a [ i + 1];
    (* n ) --;
}

void deleteByPosUnsaveOrder_ (int *a , size_t *n , size_t pos ) {
    a [ pos ] = a [* n - 1];
    (* n ) --;
}

int linearSearch_( const int *a , const int n , int x ) {
    for (size_t i = 0; i < n; i++) {
        if (a[i] == x)
            return i;
    }
    return n ;
}

int any_ ( const int *a , size_t n , int (* predicate ) (int) ) {
    for ( size_t i = 0; i < n ; i ++)
        if ( predicate ( a [ i ]) )
            return 1;
    return 0;
}

int all_ ( const int *a , size_t n , int (* predicate ) (int) ) {
    for ( size_t i = 0; i < n ; i ++)
        if (! predicate ( a [ i ]) )
            return 0;
    return 1;
}

int countIf_ ( const int * const a , const size_t n , int (* predicate ) (int) ){
    int count = 0;
    for ( size_t i = 0; i < n ; i ++)
        count += predicate ( a [ i ]) ;
    return count ;
}

void deleteIf_ (int * const a , size_t * const n , int (* deletePredicate ) (int) ) {
    size_t iRead = 0;
    while ( iRead < * n && ! deletePredicate ( a [ iRead ]) )
        iRead ++;
    size_t iWrite = iRead ;
    while ( iRead < * n ) {
        if (! deletePredicate ( a [ iRead ]) ) {
            a [ iWrite ] = a [ iRead ];
            iWrite ++;
        }
        iRead ++;
    }
    * n = iWrite ;
}

void forEach_ ( const int * source , int * dest , const size_t n , const int (*predicate ) ( int) ) {
    for ( size_t i = 0; i < n ; i ++)
        dest [ i ] = predicate ( source [ i ]) ;
}

