#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* link;
} NODE;

typedef struct stack {
    NODE* ptr;
} STACK;

void push(STACK* head, char c);
int pop(STACK* head);
int is_empty(STACK* head);

int main(void) {
    int count_num = 0;
    int i;

    scanf("%d", &count_num);
    for(i = 0; i < count_num; i++) {
        STACK* head = (STACK* )malloc(sizeof(STACK));
        head->ptr = NULL;
        char temp[50];
        int flag = 0;
        scanf("%s", temp);

        int j = 0;
        for(j = 0; j < strlen(temp); j++) {
            switch (temp[j])
            {
            case '(':
                push(head, temp[j]);
                flag += 1;
                break;
            case ')':
                pop(head);
                flag -= 1;
                break;
            default:
                break;
            }
        }

        if (is_empty(head) == 0) {
            flag += 1;
        }

        if (flag == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
        free(head);
    }
    return 0;
}

void push(STACK* head, char c) {
    NODE* new_top;
    new_top = (NODE *)malloc(sizeof(NODE));

    new_top->data = c;
    new_top->link = head->ptr;

    head->ptr = new_top;
}

int pop(STACK* head) {
    if(head->ptr == NULL) {
        return -1;
    }

    NODE* temp = head->ptr;

    head->ptr = temp->link;
    return 0;
}

int is_empty(STACK* head) {
    if (head->ptr == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
