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

void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

struct Node* prev = NULL;
void isBST(struct Node* root,int& check){
    if(root==NULL) return;
    isBST(root->left,check);
    if(prev!=NULL){
        if(root->data <=prev->data){
            check = 0;
            return;
        }
    }
    prev = root;
    isBST(root->right,check);
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

    int check = 1;
    isBST(root,check);
    printf("%d", check);
    return 0;
}