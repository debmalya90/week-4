#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* deleteNode(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
        return head; // Not found

    if (temp->prev == NULL) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
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

    head = deleteNode(head, 20);

    printf("After deleting 20:\n");
    printDLL(head);

    return 0;
}
