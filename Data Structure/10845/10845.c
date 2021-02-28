#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* link;
} NODE;

typedef struct queue {
    NODE* front;
    NODE* rear;
} QUEUE;

void push(QUEUE* que, int X);
int pop(QUEUE* que);
int size(QUEUE* que);
int is_empty(QUEUE* que);
int front(QUEUE* que);
int rear(QUEUE* que);

int main(void) {
    int C, i;

    QUEUE* que = (QUEUE *)malloc(sizeof(QUEUE));
    que->front = NULL;
    que->rear = NULL;

    scanf("%d", &C);
    getchar();
    for(i = 0; i < C; i++) {
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
            printf("%s %d\n", command, num);
            // push(que, num);
        }
        else if(strcmp(command, "pop\n") == 0) {
            printf("%s\n", command);
            // printf("%d\n", pop(que));
        }
        else if(strcmp(command, "size\n") == 0) {
            printf("%s\n", command);
            // printf("%d\n", size(que));
        }
        else if(strcmp(command, "empty\n") == 0) {
            printf("%s\n", command);
            // printf("%d\n", is_empty(que));
        }
        else if(strcmp(command, "front\n") == 0) {
            printf("%s\n", command);
            // printf("%d\n", front(que));
        }
        else if(strcmp(command, "back\n") == 0) {
            printf("%s\n", command);
            // printf("%d\n", rear(que));
        }
    }

    free(que);
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

int size(QUEUE* que) {
    if(que->front == NULL) {
        return 0;
    }
    int count = 0;
    NODE* temp = que->front;

    do {
        count += 1;
        temp = temp->link;
    } while(temp->link != NULL);
    return count;
}

int is_empty(QUEUE* que) {
    if(que->front == NULL) {
        return 1;
    }
    return 0;
}

int front(QUEUE* que) {
    if(que->front == NULL) {
        return -1;
    }
    return que->front->data;
}

int rear(QUEUE* que) {
    if(que->rear == NULL) {
        return -1;
    }

    return que->rear->data;
}