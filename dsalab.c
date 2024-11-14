#include<stdio.h>
#include<stdlib.h>

void insert(int arr[], int* n, int key) {
    (*n)++;
    int i = (*n) - 1;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
void show(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[7];
    int n = 0; 
    insert(arr, &n, 1);
    insert(arr, &n, 5);
    insert(arr, &n, 6);
    insert(arr, &n, 8);
    insert(arr, &n, 9);
    insert(arr, &n, 7);
    insert(arr, &n, 3);

    printf("Min Heap elements: ");
    show(arr, n);

    return 0;
}

