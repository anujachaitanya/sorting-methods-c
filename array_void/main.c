#include <stdio.h>
#include "array_void_sorts.h"

Bool int_compare(Object number1, Object number2)
{
  return *(int *)number1 < *(int *)number2;
}

void int_display(Object number)
{
  printf("%d\t", *(int *)number);
}

int main(void)
{
  int a[] = {3, 4, 51, 1};
  ArrayVoid_ptr array = init_void_array(a, 4, sizeof(a) / sizeof(int));
  // ArrayVoid_ptr selection_sorted = selection_sort(array, int_compare);
  // display_ArrayVoid(selection_sorted, int_display);
  // ArrayVoid_ptr insertion_sorted = insertion_sort(array, int_compare);
  // display_ArrayVoid(insertion_sorted, int_display);
  // ArrayVoid_ptr bubble_sorted = bubble_sort(array, int_compare);
  // display_ArrayVoid(bubble_sorted, int_display);
  ArrayVoid_ptr quick_sorted = quick_sort(array, 0, 3, int_compare);
  display_ArrayVoid(quick_sorted, int_display);

  return 0;
}