#include <stdio.h>
#define MAX 50

void topdown(int h[], int n);
void heapSort(int h[], int n);
void heapify(int h[], int n, int i);

int main() {
    int h[MAX], n;
    scanf("%d", &n);
    topdown(h, n);

    for (int i = 0; i < n; i++)
        printf("%d ", h[i]);
    printf("\n");

    heapSort(h, n);
    for (int i = 0; i < n; i++)
        printf("%d ", h[i]);

    return 0;
}

void topdown(int h[], int n) {
    int c, p, key;

    scanf("%d", &h[0]);

    for (int i = 1; i < n; i++) {
        scanf("%d", &h[i]);
        c = i;
        p = (c - 1) / 2;
        key = h[c];

        while (c > 0 && h[p] < key) {
            h[c] = h[p];
            c = p;
            p = (c - 1) / 2;
        }
        h[c] = key;
    }
}

void heapify(int h[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && h[left] > h[largest])
        largest = left;

    if (right < n && h[right] > h[largest])
        largest = right;

    if (largest != i) {
        int temp = h[i];
        h[i] = h[largest];
        h[largest] = temp;
        heapify(h, n, largest);
    }
}

void heapSort(int h[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(h, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = h[0];
        h[0] = h[i];
        h[i] = temp;

        heapify(h, i, 0);
    }
}
