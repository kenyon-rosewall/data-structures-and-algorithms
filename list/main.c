#include <stdlib.h>
#include <stdio.h>
#include "single_linked_list.h"
#include "double_linked_list.h"

void sll_test()
{
  printf("SINGLE LINKED LIST\n");
  printf("==================\n\n");

  sll_node** head = sll_create();
  printf("New list:");
  sll_print(head);

  sll_push(head, 6);
  printf("Pushed 6:");
  sll_print(head);
  
  sll_unshift(head, 14);
  printf("Unshifted 14:");
  sll_print(head);

  sll_push(head, 7);
  printf("Pushed 7:");
  sll_print(head);

  sll_push(head, 1);
  printf("Pushed 1:");
  sll_print(head);

  sll_node* popped = sll_pop(head);
  printf("Should have just popped 1:");
  sll_print(head);

  sll_node* shifted = sll_shift(head);
  printf("Should have just shifted 14:");
  sll_print(head);

  sll_unshift(head, 4);
  printf("Unshifted 4:");
  sll_print(head);

  sll_insert_after((*head)->next, 8);
  printf("Inserted into 3rd place 8:");
  sll_print(head);

  sll_push(head, 26);
  printf("Pushed 26:");
  sll_print(head);

  sll_push(head, 52);
  printf("Pushed 52:");
  sll_print(head);

  sll_node* removed_after = sll_remove_after(*head);
  printf("Should have removed 6:");
  sll_print(head);

  sll_unshift(head, 100);
  printf("Unshifted 100:");
  sll_print(head);

  sll_node* removed = sll_remove(head, 3);
  printf("Should have removed 7:");
  sll_print(head);

  sll_insert_after((*head)->next, 73);
  printf("Inserted into 3rd place 73:");
  sll_print(head);

  sll_node* at = sll_at(head, 3);
  printf("The node at position 3 is: %ld \n", at->data);

  printf("Searching for the number 73: ");
  sll_search(head, 73) ? printf("YES \n") : printf("NO \n");

  printf("Searching for the number 52: ");
  sll_search(head, 52) ? printf("YES \n") : printf("NO \n");

  printf("Searching for the number 53: ");
  sll_search(head, 53) ? printf("YES \n") : printf("NO \n");

  printf("Current list is:");
  sll_print(head);

  printf("The sum of the removed elements should be 28: %ld \n", popped->data + shifted->data + removed_after->data + removed->data);
  printf("The count of the list should be 6: %d \n", sll_count(head));

  free(popped);
  free(shifted);
  free(removed_after);
  free(removed);
  sll_destroy(head);

  printf("List destroyed\n\n");
}

void dll_test()
{
  printf("DOUBLE LINKED LIST\n");
  printf("==================\n\n");

  dll_node** head = dll_create();
  printf("New list:");
  dll_print(head);

  dll_push(head, 6);
  printf("Pushed 6:");
  dll_print(head);
  
  dll_unshift(head, 14);
  printf("Unshifted 14:");
  dll_print(head);

  dll_push(head, 7);
  printf("Pushed 7:");
  dll_print(head);

  dll_push(head, 1);
  printf("Pushed 1:");
  dll_print(head);

  dll_node* popped = dll_pop(head);
  printf("Should have just popped 1:");
  dll_print(head);

  dll_node* shifted = dll_shift(head);
  printf("Should have just shifted 14:");
  dll_print(head);

  dll_unshift(head, 4);
  printf("Unshifted 4:");
  dll_print(head);

  dll_insert_after((*head)->next, 8);
  printf("Inserted into 3rd place 8:");
  dll_print(head);

  dll_push(head, 26);
  printf("Pushed 26:");
  dll_print(head);

  dll_push(head, 52);
  printf("Pushed 52:");
  dll_print(head);

  dll_node* removed_after = dll_remove_after(*head);
  printf("Should have removed 6:");
  dll_print(head);

  dll_unshift(head, 100);
  printf("Unshifted 100:");
  dll_print(head);

  dll_node* removed = dll_remove(head, 3);
  printf("Should have removed 7:");
  dll_print(head);

  dll_insert_after((*head)->next, 73);
  printf("Inserted into 3rd place 73:");
  dll_print(head);

  dll_node* at = dll_at(head, 3);
  printf("The node at position 3 is: %ld \n", at->data);

  printf("Searching for the number 73: ");
  dll_search(head, 73) ? printf("YES \n") : printf("NO \n");

  printf("Searching for the number 52: ");
  dll_search(head, 52) ? printf("YES \n") : printf("NO \n");

  printf("Searching for the number 53: ");
  dll_search(head, 53) ? printf("YES \n") : printf("NO \n");

  printf("Current list is:");
  dll_print(head);

  printf("The sum of the removed elements should be 28: %ld \n", popped->data + shifted->data + removed_after->data + removed->data);
  printf("The count of the list should be 6: %d \n", dll_count(head));

  free(popped);
  free(shifted);
  free(removed_after);
  free(removed);
  dll_destroy(head);

  printf("List destroyed\n\n");
}

i32 main()
{
  sll_test();
  dll_test();

  return 0;
}