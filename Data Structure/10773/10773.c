#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} NODE;

typedef struct stack {
    int count;
    NODE* ptr;
} STACK;

void push(STACK* head, int X);
int pop(STACK* head);
int is_empty(STACK* head);

int main(void) {
    int N;
    int i, sum = 0;
    scanf("%d", &N);

    STACK* head = (STACK *)malloc(sizeof(STACK));
    head->count = 0;
    head->ptr = NULL;

    for(i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        if(temp == 0) {
            pop(head);
        }
        else {
            push(head, temp);
        }
    }

    while(!is_empty(head)) {
        sum += pop(head);
    }
    printf("%d\n", sum);

    free(head);
    return 0;
}

void push(STACK* head, int X) {
    NODE* new_top;
    new_top = (NODE *)malloc(sizeof(NODE));

    new_top->data = X;
    new_top->link = head->ptr;

    head->count++;
    head->ptr = new_top;
}

int pop(STACK* head) {
    if(head->ptr == NULL) {
        return -1;
    }
    NODE* temp = head->ptr;
    int temp_data = temp->data;

    head->ptr = temp->link;
    head->count--;

    return temp_data;
}

int is_empty(STACK* head) {
    if(head->count == 0) {
        return 1;
    }
    
    return 0;
}