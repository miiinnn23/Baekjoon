#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int n, i;
    int j = 0, k = 1;

    scanf("%d", &n);
    int* sequence = (int *)malloc(sizeof(int) * n);

    STACK* head = (STACK *)malloc(sizeof(STACK));
    head->count = 0;
    head->ptr = NULL;

    for(i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }
    char* result = (char *)malloc(sizeof(char) * 2 * n);

    while(sequence[j] >= k) {
        push(head, k);
        strcat(result, "+\n");
        k++;
    }
    printf("%s", result);
    
    free(result);
    free(head);
    free(sequence);
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
    if (head->count == 0) {
        return 1;
    }
    else {
        return 0;
    }
}