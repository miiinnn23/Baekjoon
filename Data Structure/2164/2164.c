#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} NODE;

typedef struct queue {
    NODE* front;
    NODE* rear;
} QUEUE;

void push(QUEUE* head, int num);
int pop(QUEUE* head);
void play(QUEUE* card);

int main(void) {
    int N;

    scanf("%d", &N);
    QUEUE* head = (QUEUE *)malloc(sizeof(QUEUE));
    head->front = NULL;
    head->rear = NULL;

    int i;
    for(i = 1; i <= N; i++) {
        push(head, i);
    }
    
    play(head);
    printf("\n");
    
    free(head);
    return 0;
}

void push(QUEUE* que, int X) {
    NODE* enque = (NODE *)malloc(sizeof(NODE));
    enque->data = X;
    enque->link = NULL;

    if(que->front == NULL) {
        que->front = enque;
        que->rear = enque;
    }
    else {
        que->rear->link = enque;
        que->rear = enque;
    }
}

int pop(QUEUE* que) {
    if(que->front == NULL) {
        que->rear = NULL;
        return -1;
    }
    NODE* temp = que->front;
    int temp_data = temp->data;
    
    que->front = que->front->link;

    return temp_data;
}

void play(QUEUE* card) {
    int i = 1;
    while(card->front != card->rear) {
        if(i % 2 != 0) {
            pop(card);
        }
        else {
            int temp = card->front->data;
            push(card, temp);
            pop(card);
        }
        i++;
    }
    printf("%d", card->front->data);
}