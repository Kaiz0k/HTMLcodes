#include <stdio.h>

int getmax(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int a[], int exp, int n) {
    int output[n];
    int count[10] = {0};
    int i;
    for (i = 0; i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

void radixsort(int arr[], int n) {
    int max = getmax(arr, n);
    int exp;
    for ( exp = 1; max / exp > 0; exp *= 10) {
        count_sort(arr, exp, n);
    }
}

void printarray(int arr[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int l;
    printf("Enter number of elements: ");
    scanf("%d", &l);

    int arr[l];
    printf("Enter the elements: ");
    int i; 
    for (i = 0; i < l; i++) {
        scanf("%d", &arr[i]);
    }

    radixsort(arr, l);

    printf("Sorted array: ");
    printarray(arr, l);

    return 0;
}

