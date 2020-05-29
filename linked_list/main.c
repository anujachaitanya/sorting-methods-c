#include "linked_list_sorts.h"

void displayer(List_ptr list)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    printf("%d", *(int *)p_walk->element);
    p_walk = p_walk->next;
  }
}

Status int_compare(Element first, Element second)
{
  return *(int *)first > *(int *)second;
}

#include <stdio.h>

int main(void)
{
  int numbers[5] = {5, 3, 4, 2, 1};
  List_ptr list = init_linked_list(numbers, 5, 4);
  List_ptr insertion_sorted = insertion_sort(list, int_compare);
  // List_ptr bubble_sorted = bubble_sort(list, int_compare);
  // List_ptr selection_sorted = selection_sort(list, int_compare);
  // displayer(bubble_sorted);
  // displayer(selection_sorted);
  displayer(insertion_sorted);
  return 0;
}