#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node* link;
} NODE;

typedef struct stack {
    int count;
    NODE* ptr;
} STACK;

void push(STACK* head);
void pop(STACK* head);
int size(STACK* head);

int main(void) {
    char* stick = (char *)malloc(sizeof(char) * 100001);
    int i;
    int count = 0;

    scanf("%s", stick);
    int* lasor = (int *)malloc(sizeof(int) * strlen(stick));

    STACK* head = (STACK *)malloc(sizeof(STACK));
    head->count = 0;
    head->ptr = NULL;
    
    for(i = 0; i < strlen(stick) - 1; i++) {
        if(stick[i] == '(' && stick[i + 1] == ')') {
            lasor[i] = 1;
        }
        else {
            lasor[i] = 0;
        }
    }

    for(i = 0; i < strlen(stick); i++) {
        if(lasor[i] == 1) {
            count += head->count;
        }
        else {
            switch (stick[i])
            {
            case '(':
                push(head);
                break;
            case ')':
                if(lasor[i - 1] == 1) {
                    break;
                }
                pop(head);
                count++;;
                break;
            default:
                break;
            }
        }
    }
    printf("%d\n", count);
    free(head);
    free(lasor);
    free(stick);
    return 0;
}

void push(STACK* head) {
    NODE* new_top;
    new_top = (NODE *)malloc(sizeof(NODE));

    new_top->link = head->ptr;

    head->count++;
    head->ptr = new_top;
}

void pop(STACK* head) {
    if(head->ptr == NULL) {
        return;
    }
    NODE* temp = head->ptr;
    
    head->ptr = temp->link;
    head->count--;
}

int size(STACK* head) {
    return head->count;
}