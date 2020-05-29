#include <stdio.h>
#include "array_sorts.h"

int main(void)
{
  int numbers[5] = {5, 4, 3, 2, 1};
  // int_ptr insertion_sorted = insertion_sort(numbers, 5);
  // int_ptr bubble_sorted = bubble_sort(numbers, 5);
  // int_ptr selection_sorted = selection_sort(numbers, 5);
  int_ptr quick_sorted = quick_sort(numbers, 0, 4);
  // print_array(insertion_sorted, 5);
  // print_array(bubble_sorted, 5);
  // print_array(selection_sorted, 5);
  print_array(quick_sorted, 5);
  return 0;
}