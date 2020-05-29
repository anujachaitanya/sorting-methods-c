#include "array_void_sorts.h"
#include <stdio.h>
void swap_elements(Object *a, Object *b)
{
  Object temp = *a;
  *a = *b;
  *b = temp;
}

ArrayVoid_ptr init_void_array(Object array, int length, int size)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->array = malloc(sizeof(Object) * length);
  new_array->length = 0;

  while (new_array->length < length)
  {
    new_array->array[new_array->length] = array + (new_array->length * size);
    new_array->length++;
  }
  return new_array;
};

void display_ArrayVoid(ArrayVoid_ptr array, Displayer displayer)
{
  for (int i = 0; i < array->length; i++)
  {
    (*displayer)(array->array[i]);
  }
  printf("\n");
}

ArrayVoid_ptr selection_sort(ArrayVoid_ptr void_array, Compare comparator)
{
  for (int i = 0; i < void_array->length; i++)
  {
    int min_index = i;
    for (int j = i + 1; j < void_array->length; j++)
    {
      if ((*comparator)(void_array->array[j], void_array->array[min_index]))
      {
        min_index = j;
      }
    }
    swap_elements(&void_array->array[i], &void_array->array[min_index]);
  }
  return void_array;
}

ArrayVoid_ptr insertion_sort(ArrayVoid_ptr void_array, Compare comparator)
{
  for (int i = 0; i < void_array->length; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if ((*comparator)(void_array->array[i], void_array->array[j]))
      {
        swap_elements(&void_array->array[i], &void_array->array[j]);
      }
    }
  }
  return void_array;
}

ArrayVoid_ptr bubble_sort(ArrayVoid_ptr void_array, Compare comparator)
{
  Bool is_sorted = False;
  for (int i = 0; i < void_array->length - 1 && !is_sorted; i++)
  {
    is_sorted = True;
    for (int j = 0; j < void_array->length - i - 1; j++)
    {
      if ((*comparator)(void_array->array[j + 1], void_array->array[j]))
      {
        is_sorted = False;
        swap_elements(&void_array->array[j], &void_array->array[j + 1]);
      }
    }
  }
  return void_array;
}

int partition(ArrayVoid_ptr void_array, int low, int high, Compare comparator)
{
  Object pivot = void_array->array[high];
  int pivot_index = (low - 1);
  for (int index = low; index <= high - 1; index++)
  {
    if ((*comparator)(void_array->array[index], pivot))
    {
      pivot_index++;
      swap_elements(&void_array->array[pivot_index], &void_array->array[index]);
    }
  }
  swap_elements(&void_array->array[pivot_index + 1], &void_array->array[high]);
  return (pivot_index + 1);
}

ArrayVoid_ptr quick_sort(ArrayVoid_ptr array, int low, int high, Compare comparator)
{
  if (low < high)
  {
    int pivot = partition(array, low, high, comparator);
    quick_sort(array, low, pivot - 1, comparator);
    quick_sort(array, pivot + 1, high, comparator);
  }
  return array;
}