#include <stdio.h>
#define MAX 50

void heapify(int heap[], int n, int i);
void insertToHeap(int heap[], int *size, int value, int z);

int main() {
    int n, z;
    int heap[MAX] = {0};
    int heapSize = 0;

    scanf("%d", &n);
    scanf("%d", &z);

    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);

        insertToHeap(heap, &heapSize, element, z);

        for (int j = 0; j < heapSize; j++) {
            printf("%d ", heap[j]);
        }
        printf("\n");
    }

    return 0;
}

void heapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap, n, largest);
    }
}

void insertToHeap(int heap[], int *size, int value, int z) {
    if (*size < z) {
        heap[*size] = value;
        (*size)++;

        for (int i = (*size / 2) - 1; i >= 0; i--)
            heapify(heap, *size, i);
    }
    else if (value < heap[0]) {
        heap[0] = value;
        heapify(heap, z, 0);
    }
}
