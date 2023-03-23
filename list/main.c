#include <stdlib.h>
#include <stdio.h>
#include "single_linked_list.h"

void sll_test()
{
  printf("SINGLE LINKED LIST\n");
  printf("==================\n\n");

  sll_node** head = sll_create(6);
  printf("New list starting with 6:");
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
  free(removed);
  sll_destroy(head);

  printf("List destroyed\n\n");
}

i32 main()
{
  sll_test();

  return 0;
}