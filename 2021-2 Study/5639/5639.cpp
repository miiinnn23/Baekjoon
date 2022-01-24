#include <cstdio>

struct node {
    int data;
    node* left;
    node* right;
};

node* insert(node* tree, int data);
void post(node* tree);

int main(void) {
    node* tree;
    tree = NULL;

    int num;
    while(scanf("%d", &num) != EOF) {
        tree = insert(tree, num);
    }

    post(tree);
    return 0;
}

node* insert(node* tree, int data) {
    if(tree == NULL) {
        tree = new node();
        tree->data = data;
        tree->left = tree->right = NULL;
    }

    else if(data > tree->data) {
        tree->right = insert(tree->right, data);
    }
    else {
        tree->left = insert(tree->left, data);
    }

    return tree;
}

void post(node* tree) {
    if(tree->left != NULL) post(tree->left);
    if(tree->right != NULL) post(tree->right);
    printf("%d\n", tree->data);
}