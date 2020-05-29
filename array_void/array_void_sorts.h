#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include <stdlib.h>

typedef void *Object;

typedef void (*Displayer)(Object);
typedef enum
{
  False,
  True
} Bool;

typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;

typedef Bool (*Compare)(Object, Object);

void display_ArrayVoid(ArrayVoid_ptr array, Displayer displayer);
ArrayVoid_ptr init_void_array(Object array, int length, int size);
ArrayVoid_ptr init_void_array(Object array, int length, int size);
ArrayVoid_ptr selection_sort(ArrayVoid_ptr void_array, Compare comparator);
ArrayVoid_ptr insertion_sort(ArrayVoid_ptr void_array, Compare comparator);
ArrayVoid_ptr bubble_sort(ArrayVoid_ptr array, Compare comparator);
ArrayVoid_ptr quick_sort(ArrayVoid_ptr array, int low, int high, Compare comparator);
int partition(ArrayVoid_ptr void_array, int low, int high, Compare comparator);
void display(ArrayVoid_ptr array, Displayer displayer);

#endif