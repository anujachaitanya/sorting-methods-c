#include "array_sorts.h"
#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print_array(int_ptr array, int length)
{
  for (size_t i = 0; i < length; i++)
  {
    printf("%d\t", array[i]);
  }
  printf("\n");
};

int_ptr bubble_sort(int_ptr array, int length)
{
  Bool is_sorted = False;
  for (int i = 0; i < length - 1 && !is_sorted; i++)
  {
    is_sorted = True;
    for (int j = 0; j < length - i - 1; j++)
    {
      if (!(array[j] < array[j + 1]))
      {
        is_sorted = False;
        swap(&array[j], &array[j + 1]);
      }
    }
  }
  return array;
}

int_ptr selection_sort(int_ptr array, int length)
{
  for (size_t i = 0; i < length; i++)
  {
    int index_of_min = i;
    for (size_t j = i; j < length; j++)
    {
      if (array[j] < array[index_of_min])
      {
        index_of_min = j;
      }
    }
    swap(&array[i], &array[index_of_min]);
  }
  return array;
}

int_ptr insertion_sort(int_ptr array, int length)
{
  for (size_t i = 1; i < length; i++)
  {
    int current_element = array[i];
    int j = i - 1;
    while (current_element < array[j] && j >= 0)
    {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = current_element;
  }
  return array;
}

int partition(int_ptr array, int low, int high)
{
  int pivot = array[high];
  int pivot_index = (low - 1);
  for (int index = low; index <= high - 1; index++)
  {
    if (array[index] <= pivot)
    {
      pivot_index++;
      swap(&array[pivot_index], &array[index]);
    }
  }
  swap(&array[pivot_index + 1], &array[high]);
  return (pivot_index + 1);
}

int_ptr quick_sort(int_ptr array, int low, int high)
{
  if (low < high)
  {
    int pivot = partition(array, low, high);
    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);
  }
  return array;
}
