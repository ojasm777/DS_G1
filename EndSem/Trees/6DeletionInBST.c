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

struct Node* predecessor(struct Node* root){
    if(root==NULL) return NULL;
    root=root->left;
    if(root==NULL) return NULL;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

struct Node* successor(struct Node* root){
    if(root==NULL) return NULL;
    root=root->right;
    if(root==NULL) return NULL;
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

struct Node* deletion(struct Node* root, int val){
    if(root == NULL) return NULL;
    if(val == root->data){
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL || root->right == NULL){
            if(root->left == NULL) return root->right;
            else return root->left;
        }
        else{
            struct Node* ip = predecessor(root);
            root->data = ip->data;
            root->left = deletion(root->left,ip->data);
        }
    }
    else if(val < root->data){
        root->left = deletion(root->left,val);
    }
    else if(val > root->data){
        root->right = deletion(root->right,val);
    }
    return root;
}


void inorder(struct Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
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

    inorder(root);
    deletion(root,7);
    printf("\n");
    inorder(root);

    return 0;
}