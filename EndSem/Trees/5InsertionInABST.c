#include<stdio.h>
#include<stdlib.h>

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

void insertion(struct Node* root,int val){
    struct Node* prev = NULL;
    while(root!=NULL){
        prev = root;
        if(val == root->data){
            return;
        }
        else if(val < root->data){
            root=root->left;
        }
        else root=root->right;
    }
    struct Node* n = createNode(val);
    if(val < n->data) prev->left = n;
    else prev->right = n;
}

int main(){
    struct Node* root = createNode(7);
    struct Node* node1 = createNode(2);
    struct Node* node2 = createNode(9);
    struct Node* node3 = createNode(1);
    struct Node* node4 = createNode(10);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node2->right = node4;

    insertion(root,11);
    printf("%d",node4->right->data);

    return 0;
}