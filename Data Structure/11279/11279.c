#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* heap;
    int heap_size;
} HEAP;

HEAP* createHeap(int n) {
    HEAP* h = (HEAP *)malloc(sizeof(HEAP));
    h->heap = (int *)malloc(sizeof(int) * n);
    h->heap_size = 0;

    return h;
}

void insert(HEAP* heap, int X);
int delete(HEAP* heap);

int main(void) {
    int N, X;
    scanf("%d", &N);
    int i;

    HEAP* head = createHeap(N);

    for(i = 0; i < N; i++) {
        scanf("%d", &X);
        if(X == 0) {
            printf("%d\n", delete(head));
        } else {
            insert(head, X);
        }
    }

    return 0;
}

void insert(HEAP* head, int X) {
    int i;
    head->heap_size++;
    i = head->heap_size;
    while((i != 1) && (X > head->heap[i / 2])) {
        head->heap[i] = head->heap[i / 2];
        i /= 2;
    }

    head->heap[i] = X;
}

int delete(HEAP* head) {
    int parent, child;
    int item, temp;

    if(head->heap_size == 0) {
        return 0;
    }

    item = head->heap[1];
    temp = head->heap[head->heap_size];
    head->heap_size--;

    parent = 1;
    child = 2;
    while(child <= head->heap_size) {
        if((child < head->heap_size) && (head->heap[child] < head->heap[child + 1])) child++;
        if(temp >= head->heap[child]) break;
        else {
            head->heap[parent] = head->heap[child];
            parent = child;
            child = child * 2;
        }
    }

    head->heap[parent] = temp;
    return item;
}