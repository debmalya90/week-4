#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* reverseDLL(struct Node* head) {
    struct Node *temp = NULL, *current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;

    return head;
}

void printDLL(struct Node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int main() {
    struct Node* head = newNode(10);
    struct Node* second = newNode(20);
    struct Node* third = newNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Original DLL:\n");
    printDLL(head);

    head = reverseDLL(head);

    printf("Reversed DLL:\n");
    printDLL(head);

    return 0;
}
