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

void push_front(QUEUE* que, int X);
void push_back(QUEUE* que, int X);
int pop_front(QUEUE* que);
int pop_back(QUEUE* que);
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
        char temp[20];
        fgets(temp, sizeof(temp), stdin);

        char command[6];
        char* str_ptr;
        int num = 0;
        str_ptr = strtok(temp, " ");
        while(str_ptr != NULL) {
            if(strcmp(temp, "push_front") == 0 || strcmp(temp, "push_back") == 0) {
                strcpy(command, temp);
                str_ptr = strtok(NULL, " ");
                num = atoi(str_ptr);
            } else {
                strcpy(command, temp);
            }
            str_ptr = strtok(NULL, " ");
        }
        
        if(strcmp(command, "push_front") == 0) {
            push_front(que, num);
        }
        if(strcmp(command, "push_back") == 0) {
            push_back(que, num);
        }
        else if(strcmp(command, "pop_front\n") == 0) {
            printf("%d\n", pop_front(que));
        }
        else if(strcmp(command, "pop_back\n") == 0) {
            printf("%d\n", pop_back(que));
        }
        else if(strcmp(command, "size\n") == 0) {
            printf("%d\n", size(que));
        }
        else if(strcmp(command, "empty\n") == 0) {
            printf("%d\n", is_empty(que));
        }
        else if(strcmp(command, "front\n") == 0) {
            printf("%d\n", front(que));
        }
        else if(strcmp(command, "back\n") == 0) {
            printf("%d\n", rear(que));
        }
    }

    free(que);
    return 0;
}

void push_front(QUEUE* que, int X) {
    NODE* enque = (NODE *)malloc(sizeof(NODE));
    enque->data = X;
    enque->link = que->front;

    if(que->rear == NULL) {
        que->front = enque;
        que->rear = enque;
    }
    else {
        enque->link = que->front;
        que->front = enque;
    }
}

void push_back(QUEUE* que, int X) {
    NODE* enque = (NODE *)malloc(sizeof(NODE));
    enque->data = X;
    enque->link = NULL;

    if(que->rear == NULL) {
        que->front = enque;
        que->rear = enque;
    }
    else {
        que->rear->link = enque;
        que->rear = enque;
    }
}

int pop_front(QUEUE* que) {
    if(que->front == NULL) {
        que->rear = NULL;
        return -1;
    }
    NODE* temp = que->front;
    int temp_data = temp->data;
    if(que->front == que->rear) {
        que->front = NULL;
        que->rear = NULL;
        return temp->data;
    }
    que->front = que->front->link;

    return temp_data;
}

int pop_back(QUEUE* que) {
    if(que->front == NULL) {
        que->rear = NULL;
        return -1;
    }
    NODE* temp = que->rear;
    int temp_data = temp->data;

    if(que->front == que->rear) {
        que->front = NULL;
        que->rear = NULL;
        return temp->data;
    }
    
    NODE* temp_node = que->front;
    while(temp_node->link != que->rear) {
        temp_node = temp_node->link;
    }
    
    que->rear = temp_node;
    temp_node->link = NULL;

    return temp_data;
}

int size(QUEUE* que) {
    if(que->front == NULL) {
        return 0;
    }
    else if(que->front == que->rear) {
        return 1;
    }
    int count = 1;
    NODE* temp = que->front;
    
    do {
        count += 1;
        temp = temp->link;
    } while (temp->link != NULL);
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