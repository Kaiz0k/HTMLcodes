#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int findMax(struct Node* head) {
    int max = head->data;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int getDigit(int number, int place) {
    return (number / place) % 10;
}

void radixSort(struct Node** head) {
    int max = findMax(*head);
    int place = 1;

    while (max / place > 0) {
        struct Node* buckets[10] = {NULL};
        struct Node* last[10] = {NULL};
        struct Node* temp = *head;

        while (temp != NULL) {
            int digit = getDigit(temp->data, place);
            if (buckets[digit] == NULL) {
                buckets[digit] = last[digit] = temp;
            } else {
                last[digit]->next = temp;
                last[digit] = temp;
            }
            temp = temp->next;
        }

        *head = NULL;
        struct Node* current = NULL;
        int i;
        for (i = 0; i < 10; i++) {
            if (buckets[i] != NULL) {
                if (*head == NULL) {
                    *head = buckets[i];
                    current = last[i];
                } else {
                    current->next = buckets[i];
                    current = last[i];
                }
            }
        }

        if (current != NULL) {
            current->next = NULL;
        }

        place *= 10;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int i,n,x;
    printf("enter number of elements: ");
    scanf("%d",& n);
    for(i=0;i<n;i++)
    {
    	scanf("%d", & x);
    	insertNode(&head,x);
	}

    printf("Original List:\n");
    printList(head);

    radixSort(&head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}
