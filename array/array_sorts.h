#ifndef __SORTS_H
#define __SORTS_H
#include <stdlib.h>

typedef int *int_ptr;

typedef enum
{
  False,
  True
} Bool;

int_ptr selection_sort(int_ptr array, int length);

int_ptr bubble_sort(int_ptr array, int length);

int_ptr insertion_sort(int_ptr array, int length);

void swap(int *a, int *b);
int partition(int_ptr array, int start, int end);
int_ptr quick_sort(int_ptr array, int start, int end);
void print_array(int_ptr array, int length);
#endif