#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void printList(struct Node *head, int size) {
    if (size == 0) {
        printf("You have no elements in the list.\n");
    } else {
        struct Node *current = head;
        for (int i = 0; i < size; i++) {
            printf("%d", i);
            printf(" element is %d", current->value);
//            printf("\nNext element value is ");
//            printf("%d", current->next->value);
            printf("\n");
            current = current->next;
        }
    }
}

struct Node *insertNode(struct Node *prev, int value) {
    prev->next->value = value;
    struct Node *newNode = (struct Node*) malloc(sizeof (struct Node));
    prev->next->next = newNode;
    return prev->next;
}

void deleteNode(struct Node *node, struct Node *head, int size) {
    struct Node *current = head;
    for (int i = 0; i < size-1; i++) {
        if (current->next->value == node->value) {
            struct Node *prevNext = current->next;
            struct Node *realNext = current->next->next;
            free(prevNext);
            current->next = realNext;
        } else {
            current = current->next;
        }
    }
}

int main(){
    struct Node head;
    struct Node second = *insertNode(&head, 10);
    struct Node third = *insertNode(&second, 20);
    struct Node fourth = *insertNode(&third, 30);
    deleteNode(&second, &head, 4);
    printList(&head, 3);

    return 0;
}