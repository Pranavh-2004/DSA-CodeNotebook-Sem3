//			PriorityQ_Heap.c

#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a priority queue
struct PriorityQueue 
{
    	int heap[MAX_SIZE]; // Array to store elements in the priority queue
    	int size;           // Current size of the priority queue
};

// Function to swap two elements in the priority queue
void swap(int* a, int* b) 
{
    	int temp = *a;
    	*a = *b;
    	*b = temp;
}

// Function to heapify a subtree rooted with node i
void maxHeapify(struct PriorityQueue* pq, int i) 
{
    	int largest = i;    // Initialize largest as the root
    	int left = 2 * i + 1; // Calculate index of the left child
    	int right = 2 * i + 2; // Calculate index of the right child

    	// If left child is larger than root
    	if (left < pq->size && pq->heap[left] > pq->heap[largest])
        	largest = left;

    	// If right child is larger than largest so far
    	if (right < pq->size && pq->heap[right] > pq->heap[largest])
        	largest = right;

    	// If largest is not root
    	if (largest != i) 
    	{
        	// Swap the found largest element with the root
        	swap(&pq->heap[i], &pq->heap[largest]);

        	// Recursively heapify the affected sub-tree
        	maxHeapify(pq, largest);
    	}
}

// Function to build a max heap
void buildMaxHeap(struct PriorityQueue* pq) 
{
    	// Start from the last non-leaf node and heapify all 
	// nodes in reverse order
    	for (int i = pq->size / 2 - 1; i >= 0; i--) 
    	{
        	maxHeapify(pq, i);
    	}
}

// Function to enqueue an element into the priority queue
void enqueue(struct PriorityQueue* pq, int value) 
{
    	if (pq->size == MAX_SIZE) 
    	{
        	printf("Priority Queue is full. Cannot enqueue.\n");
        	return;
    	}

    	pq->heap[pq->size] = value;
    	pq->size++;

    	// Rebuild the max heap after enqueue operation
    	buildMaxHeap(pq);
}

// Function to dequeue the maximum element from the priority queue
int dequeue(struct PriorityQueue* pq) 
{
    	if (pq->size == 0) 
    	{
        	printf("Priority Queue is empty. Cannot dequeue.\n");
        	return -1;  
		// Assuming -1 is not a valid element in the priority queue
    	}

    	int maxElement = pq->heap[0];
    	pq->heap[0] = pq->heap[pq->size - 1];
    	pq->size--;

    	// Rebuild the max heap after dequeue operation
    	maxHeapify(pq, 0);

    	return maxElement;
}

// Function to print the priority queue
void printPriorityQueue(struct PriorityQueue* pq) 
{
    	printf("Priority Queue: ");
    	for (int i = 0; i < pq->size; i++) 
    	{
        	printf("%d ", pq->heap[i]);
    	}
    	printf("\n");
}

int main() 
{
    	struct PriorityQueue pq = {{5, 10, 4, 3, 1}, 5}; 
	// Initialize a priority queue with some elements

    	printf("Initial ");
    	printPriorityQueue(&pq);

    	// Enqueue
    	enqueue(&pq, 15);
    	printf("After Enqueue (15): ");
    	printPriorityQueue(&pq);

    	// Dequeue
    	int maxElement = dequeue(&pq);
    	if (maxElement != -1) 
    	{
        	printf("Dequeued Max Element: %d\n", maxElement);
        	printPriorityQueue(&pq);
    	}

    	return 0;
}
