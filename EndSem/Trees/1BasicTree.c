#include<stdio.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* createNode(int val){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){
    // Method 1

    // 1 size of pointer of new node
    // struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    // node1->left = NULL;
    // node1->data = 100;
    // node1->right = NULL;

    // struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    // node2->left = NULL;
    // node2->data = 200;
    // node2->right = NULL;

    // struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    // root->left = node1;
    // root->data = 50;
    // root->right = node2;


    // Method 2

    struct Node* root = createNode(50);
    struct Node* node1 = createNode(100);
    struct Node* node2 = createNode(200);
    root->left = node1;
    root->right = node2;
    return 0;
}