#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    int priority;
    struct node* next;
    struct node* prev;
};

struct node* insert(struct node* head, int n, int p) {
    struct node* newNode = malloc(sizeof(struct node));
    struct node* temp = head;

    newNode->data = n;
    newNode->priority = p;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void swapNodes(struct node* a, struct node* b) {
    if (a == b) return;
    int tempData = a->data;
    int tempPriority = a->priority;
    a->data = b->data;
    a->priority = b->priority;
    b->data = tempData;
    b->priority = tempPriority;
}

struct node* sort(struct node* head) {
    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;

    if (head == NULL) return NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->priority > ptr1->next->priority) {
                swapNodes(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int i, n, d, p;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data and priority: ");
        scanf("%d %d", &d, &p);
        head = insert(head, d, p);
    }

    printf("Before sorting:\n");
    display(head);

    head = sort(head);

    printf("After sorting:\n");
    display(head);

    return 0;
}
