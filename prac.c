#include <stdio.h>

#define MAX_SIZE 100

int heapsize;

// Function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify the tree from index i (max-heap)
void Heapify(int A[], int i) {
    int largest = i;
    int l = 2 * i;     // left(i) = 2 * i
    int r = 2 * i + 1; // right(i) = 2 * i + 1

    if (l <= heapsize && A[l] > A[i])
        largest = l;
    if (r <= heapsize && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        swap(&A[i], &A[largest]);
        Heapify(A, largest);
    }
}

// Function to build a max heap
void BuildHeap(int A[], int length) {
    heapsize = length;
    for (int i = length / 2; i >= 1; i--) {
        Heapify(A, i);
    }
}

// Function to perform heap sort
void HeapSort(int A[], int length) {
    BuildHeap(A, length);
    for (int i = length; i >= 2; i--) {
        swap(&A[1], &A[i]); // Move current root to the end
        heapsize--;
        Heapify(A, 1); // Restore heap property
    }
}

// Utility function to print the array
void printArray(int A[], int length) {
    for (int i = 1; i <= length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[MAX_SIZE] = {0, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1}; // Sample array (1-based index)
    int length = 10;

    printf("Original array: ");
    printArray(A, length);

    HeapSort(A, length);

    printf("Sorted array: ");
    printArray(A, length);

    return 0;
}
