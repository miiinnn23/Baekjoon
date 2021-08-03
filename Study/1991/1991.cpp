#include <cstdio>
#define MAX 27

typedef struct node {
    char left;
    char right;
} NODE;

NODE arr[MAX];

void pre(char root);
void in(char root);
void post(char root);

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        getchar();
        char a, b, c;
        scanf("%c %c %c", &a, &b, &c);
        arr[a].left = b;
        arr[a].right = c;
    }

    pre('A');
    printf("\n");
    in('A');
    printf("\n");
    post('A');
    printf("\n");
    return 0;
}

void pre(char root) {
    if(root == '.') return;
    printf("%c", root);
    pre(arr[root].left);
    pre(arr[root].right);
}
void in(char root) {
    if(root == '.') return;
    in(arr[root].left);
    printf("%c", root);
    in(arr[root].right);
}
void post(char root) {
    if(root == '.') return;
    post(arr[root].left);
    post(arr[root].right);
    printf("%c", root);
}