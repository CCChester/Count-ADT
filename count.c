/**
 * File: q2a/count.c
 * Enter a description of this file.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "count.h"

struct count{
    int *data;
    int len;
    int count; 
};


Count create_Count(void){
    Count new = malloc(sizeof(struct count));
    new->data = malloc(sizeof(int) * 101);
    new->len = 0;
    new->count = 0;
    return new;
}

void destroy_Count(Count c){
    assert(c);
    free(c->data);
    free(c);
}

void next(Count c, int i){
    assert(c);
    ++c->count;
    c->data[i-1] += 1;
    if (c->data[i-1] == 1){
       	++c->len;
    }
}

int total(Count c){
    assert(c);
    return c->count;
}

int unique(Count c){
    assert(c);
    return c->len;
}

int count(Count c, int i){
    assert(c);
    return c->data[i-1];
}
    
    
int mostfreq(Count c){
    assert(c);
    assert(total(c) > 0);
    int pos = 1;
    int same = 0;
    int mypos = 0;
    while (pos <= c->len){
        int t = count(c,pos);
        if (same < t){
            same = t;
            mypos = pos;
        }
        ++pos;
    }
    return mypos;
}
 


void stats(Count c){
    assert(c);
    int k=1;
    int i=0;
    while (k < c->count){
        int first = c->data[i];
        if (c->data[k-1] != 0){
            printf("%d: %d\n",k, first);
        }
        ++i;
        ++k;
    }
}
