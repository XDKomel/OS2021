#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void printList(struct Node *head) {
    if (head == NULL) {
        printf("You have no elements in the list.\n");
    } else {
        struct Node *current = head;
        int i = 0;
        while (current != NULL)  {
            printf("%d", i);
            printf(" element is %d", current->value);
//            printf("\nNext element value is ");
//            printf("%d", current->next->value);
            printf("\n");
            current = current->next;
            i++;
        }
    }
}

struct Node* insertNode(struct Node *prev, int value) {
    struct Node *insertingNode = (struct Node*) malloc(sizeof (struct Node));
    struct Node *oldNextNode = prev->next;
    insertingNode->next = oldNextNode;
    insertingNode->value = value;
    prev->next = insertingNode;
    return insertingNode;
}

void deleteNode(struct Node *node, struct Node *head) {
    struct Node *current = head;
    while (current->next != NULL) {
        if (current->next == node) {
            struct Node *oldNext = current->next;
            struct Node *realNext = oldNext->next;
            free(oldNext);
            current->next = realNext;
        } else {
            current = current->next;
        }
    }
}

int main(){
    struct Node head = {.next = NULL};
    struct Node *first = insertNode(&head, 10);
    struct Node *second = insertNode(first, 20);
    struct Node *third = insertNode(second, 30);
    deleteNode(third, &head);
    printList(&head);

    return 0;
}