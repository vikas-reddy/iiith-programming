#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node {
    int data;
    struct ll_node *next;
} node;

void ll_insert(node **head, int data) {
    node *new_node = NULL;
    new_node = (node *)malloc(sizeof(node));
    new_node->next = *head;
    new_node->data = data;

    *head = new_node;
}

void ll_print(node *head) {
    if(!head) {
        return;
    }

    node *temp = head;
    for(  ; temp; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

void ll_nonrecursive_reverse(node **head) {
    node *temp = NULL, *rev_head = NULL, *dummy = NULL;

    for(temp = *head; temp->next; ) {
        dummy = temp->next;
        temp->next = rev_head;
        rev_head = temp;

        temp = dummy;
    }
    temp->next = rev_head;
    rev_head = temp;

    *head = rev_head;
}

node * ll_recursive_reverse(node **head) {
    if(!(*head) || !((*head)->next)) {
        return (*head);
    }
    
    node *rev = ll_recursive_reverse(&((*head)->next));
    (*head)->next->next = *head;
    *head = rev;
    return rev;
}

main() {
    int n = 0, i = 0, data = 0;
    node *head = NULL;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &data);
        ll_insert(&head, data);
    }

    ll_print(head);
    ll_recursive_reverse(&head);
    ll_print(head);
}
