#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* link;
} NODE;

typedef struct list {
    int count;
    NODE* ptr;
} LIST;

void push(LIST* head, int num);
int pop(LIST* head, LIST* pointer, int index);

void printList(LIST* head) {
    if(head->ptr == NULL) {
        printf("...");
    } else {
        NODE* temp = head->ptr;
        do {
            printf("%d\t", temp->number);
            temp = temp->link;
        } while(temp->link != head->ptr);
        printf("%d\n", temp->number);
    }
}

int main(void) {
    int N, K;
    int i;

    LIST* head = (LIST *)malloc(sizeof(LIST));
    head->count = 0;
    head->ptr = NULL;
    
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        push(head, i + 1);
    }
    LIST* pointer = head;
    
    printf("<");
    for(i = 0; i < N; i++) {
        printf("%d", pop(head, pointer, K));
        if(i != (N - 1)) {
            printf(", ");
        }
    }
    printf(">");
    
    free(head);
    return 0;
}

void push(LIST* head, int num) {
    NODE* new_node = (NODE *)malloc(sizeof(NODE));
    new_node->number = num;
    
    if(head->ptr == NULL) {
        head->ptr = new_node;
        new_node->link = head->ptr;
    }
    else {
        new_node->link = head->ptr;
        NODE* temp = head->ptr;
        do {
            temp = temp->link;
        } while(temp->link != head->ptr);
        temp->link = new_node;
    }
    head->count++;
}

int pop(LIST* head, LIST* pointer, int index) {
    if (index == 1) {
        NODE* temp = head->ptr;
        head->ptr = temp->link;
        pointer = head;

        return temp->number;
    }
    else {
        NODE* temp = pointer->ptr;
        int count = 1;
 
        while(count < (index - 1)) {
            temp = temp->link;
            count++;
        }
        if(head->ptr == temp->link) {
            head->ptr = head->ptr->link;
        }
        int temp_data = temp->link->number;
        temp->link = temp->link->link;
        pointer->ptr = temp->link;

        head->count--;
        return temp_data;
    }
}