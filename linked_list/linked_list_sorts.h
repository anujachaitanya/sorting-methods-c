#include <stdio.h>
#include <stdlib.h>

/*
The consumer of this Linked List library is expected to take care of allocating & freeing elements.
The Linked List maintains the element references in a sequence and provides convenient operations on them.
*/

#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

typedef enum
{
  Failure,
  Success
} Status;

typedef enum
{
  False,
  True
} Bool;

typedef void *Element;

typedef struct node
{
  Element element;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node_ptr current;
  Node_ptr previous;
} Node_tracker;

typedef Node_tracker *Node_tracker_ptr;

typedef struct linklist
{
  Node *first;
  Node *last;
  int length;
} LinkedList;

typedef LinkedList *List_ptr;

typedef Status (*Matcher)(Element, Element);
typedef Status (*Compare)(Element, Element);

List_ptr create_list(void);
List_ptr selection_sort(List_ptr list, Compare predicate);
List_ptr bubble_sort(List_ptr array, Compare compare);
List_ptr insertion_sort(List_ptr list, Compare compare);
Node_ptr create_node(Element data);
void swap_elements(Element *a, Element *b);
List_ptr init_linked_list(Element data, int length, int data_size);
#endif
