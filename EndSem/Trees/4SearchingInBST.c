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

int search(struct Node* root,int val){
    if(root==NULL) return 0;
    if(val<root->data) return search(root->left,val);
    if(val>root->data) return search(root->right,val);
    if(val==root->data) return 1;
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


    printf("%d",search(root,7));
    return 0;
}