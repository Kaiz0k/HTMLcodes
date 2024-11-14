#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int exp;
    struct node *next;
};

struct node *insert(struct node *head, int data, int exp) {
    struct node *nnode = malloc(sizeof(struct node));
    nnode->data = data;
    nnode->exp = exp;
    nnode->next = NULL;
    if (head == NULL) {
        head = nnode;
        return head;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nnode;
        return head;
    }
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d x^%d ", temp->data, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf("+");
        }
    }
    printf("\n");
}

struct node *Add_Poly(struct node *head, int coef2, int exp2) {
    struct node *temp = head;
    if (head == NULL) {
        head = insert(head, coef2, exp2);
        return head;
    }
    while (temp != NULL) {
        if (temp->exp == exp2) {
            temp->data += coef2;
            return head;
        } else if (temp->exp < exp2) {
            struct node *nnode = malloc(sizeof(struct node));
            nnode->data = coef2;
            nnode->exp = exp2;
            nnode->next = temp;
            head = nnode;
            return head;
        } else {
            temp = temp->next;
        }
    }
    head = insert(head, coef2, exp2);
    return head;
}

int main() {
    struct node *head = NULL;
    int n, m, coef, exp, i, j;
    printf("Enter number of terms for 1st polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        head = insert(head, coef, exp);
    }
    printf("Enter number of terms for 2nd polynomial: ");
    scanf("%d", &m);
    for (j = 0; j < m; j++) {
        scanf("%d %d", &coef, &exp);
        head = Add_Poly(head, coef, exp);
    }
    display(head);
    return 0;
}
