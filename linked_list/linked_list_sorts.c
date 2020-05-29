#include "linked_list_sorts.h"

List_ptr create_list(void)
{
  List_ptr new_list = malloc(sizeof(LinkedList));
  new_list->length = 0;
  new_list->first = NULL;
  new_list->last = NULL;
  return new_list;
}

void swap_elements(Element *a, Element *b)
{
  Element temp = *a;
  *a = *b;
  *b = temp;
}

Node_ptr create_node(Element data)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->element = data;
  new_node->next = NULL;
  return new_node;
}

Status add_to_list(List_ptr list, Element data)
{
  Node_ptr new_node = create_node(data);
  if (list->first == NULL)
  {
    list->first = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->length++;
  return Success;
}

List_ptr init_linked_list(Element data, int length, int data_size)
{
  List_ptr new_list = create_list();
  while (new_list->length < length)
  {
    Element data_to_add = data + (new_list->length * data_size);
    add_to_list(new_list, data_to_add);
  }
  return new_list;
}

List_ptr selection_sort(List_ptr list, Compare predicate)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    Node_ptr min_node = p_walk;
    Node_ptr another_p_walk = p_walk;
    while (another_p_walk != NULL)
    {
      if ((*predicate)(min_node->element, another_p_walk->element))
      {
        min_node = another_p_walk;
      }
      another_p_walk = another_p_walk->next;
    }
    Element temp = p_walk->element;
    p_walk->element = min_node->element;
    min_node->element = temp;
    p_walk = p_walk->next;
  }
  return list;
}

List_ptr bubble_sort(List_ptr list, Compare comparator)
{
  Node_ptr current_node, compare_node;
  Bool is_sorted = False;
  while (!is_sorted)
  {
    is_sorted = True;
    current_node = list->first;
    compare_node = current_node->next;
    while (compare_node != NULL)
    {
      if ((*comparator)(current_node->element, compare_node->element))
      {
        is_sorted = False;
        swap_elements(&current_node->element, &compare_node->element);
      }
      current_node = current_node->next;
      compare_node = compare_node->next;
    }
  }
  return list;
}

List_ptr insertion_sort(List_ptr list, Compare comparator)
{
  Node_ptr current_node = list->first;
  Node_ptr compare_node;
  for (int i = 0; i < list->length; i++)
  {
    compare_node = list->first;
    for (int j = 0; j < i; j++)
    {
      if ((*comparator)(compare_node->element, current_node->element))
      {
        swap_elements(&current_node->element, &compare_node->element);
      }
      compare_node = compare_node->next;
    }
    current_node = current_node->next;
  }
  return list;
}