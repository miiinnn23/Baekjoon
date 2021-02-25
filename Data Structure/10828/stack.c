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
int size(STACK* head);
int is_empty(STACK* head);
int top(STACK* head);

int main(void) {
    int cmd_num = 0;
    int i;

    STACK* head_ptr;

    head_ptr = (STACK *)malloc(sizeof(STACK));
    head_ptr->ptr = NULL;
    head_ptr->count = 0;

    scanf("%d", &cmd_num);
    getchar();
    for(i = 0; i < cmd_num; i++) {
        char temp[15];
        fgets(temp, sizeof(temp), stdin);

        char command[6];
        char* str_ptr;
        int num;
        str_ptr = strtok(temp, " ");
        while(str_ptr != NULL) {
            if(strcmp(temp, "push") == 0) {
                strcpy(command, temp);
                str_ptr = strtok(NULL, " ");
                num = atoi(str_ptr);
            } else {
                strcpy(command, temp);
            }
            str_ptr = strtok(NULL, " ");
        }
        if(strcmp(command, "push") == 0) {
            push(head_ptr, num);
        }
        else if(strcmp(command, "pop\n") == 0) {
            printf("%d\n", pop(head_ptr));
        }
        else if(strcmp(command, "size\n") == 0) {
            printf("%d\n", size(head_ptr));
        }
        else if(strcmp(command, "empty\n") == 0) {
            printf("%d\n", is_empty(head_ptr));
        }
        else if(strcmp(command, "top\n") == 0) {
            printf("%d\n", top(head_ptr));
        }
    }
    free(head_ptr);
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

int size(STACK* head) {
    return head->count;
}

int is_empty(STACK* head) {
    if (head->count == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int top(STACK* head) {
    if(head->count == 0) {
        return -1;
    } else {
        return head->ptr->data;
    }
}