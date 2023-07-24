#include <stdio.h>

void printsort(int val[], int end) {
    for (int i = 0; i < end; i++) {
        printf("%d ", val[i]);
    }
}

int partition(int val[], int start, int end) {
    int pivot = start;
    int i = start;
    int j = end;
    while (i < j) {
        while (val[i] <= val[pivot] && i < end) {
            i++;
        }
        while (val[j] > val[pivot]) {
            j--;
        }
        if (i < j) {
            int temp = val[i];
            val[i] = val[j];
            val[j] = temp;
        }
    }
    int temp = val[start];
    val[start] = val[j];
    val[j] = temp;
    return j;
}

void quicksort(int val[], int start, int end) {
    if (start < end) {
        int pivot = partition(val, start, end);
        quicksort(val, start, pivot - 1);
        quicksort(val, pivot + 1, end);
    }
}

int main() {
    printf("Enter the number of elements: ");
    int size;
    scanf("%d", &size);
    printf("Enter the elements: ");
    int val[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &val[i]);
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", val[i]);
    }
    printf("\n");
    int start = 0, end = size;
    quicksort(val, start, end - 1);
    printsort(val, end);
    return 0;
}
