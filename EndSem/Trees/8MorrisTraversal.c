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

void morrisTraversal(struct Node* root){
    struct Node* curr = root;
    while(curr!=NULL){
        // case 1 when there is no left
        if(curr->left==NULL){
            printf("%d ",curr->data);
            curr = curr->right;
        }
        // case 2 when left exists
        else{
            struct Node* iop=curr->left;
            while(iop->right && iop->right!=curr){
                iop = iop->right;
            }
            if(iop->right==NULL){
                //create thread
                iop->right = curr;
                curr = curr->left;
            }
            else{
                // iop->right == curr
                // cut the thread
                iop->right = NULL;
                printf("%d ",curr->data);
                curr = curr->right;
            }
        }
    }
}

void morrisTraversalPreorder(struct Node* root){
    struct Node* curr = root;
    while(curr!=NULL){
        // case 1 when there is no left
        if(curr->left==NULL){
            printf("%d ",curr->data);
            curr = curr->right;
        }
        // case 2 when left exists
        else{
            struct Node* iop=curr->left;
            while(iop->right && iop->right!=curr){
                iop = iop->right;
            }
            if(iop->right==NULL){
                //create thread
                iop->right = curr;
                printf("%d ",curr->data);
                curr = curr->left;
            }
            else{
                // iop->right == curr
                // cut the thread
                iop->right = NULL;
                curr = curr->right;
            }
        }
    }
}
int arr[5];
int i=0;
void morrisTraversalPostorder(struct Node* root){
    struct Node* curr = root;
    while(curr!=NULL){
        // case 1 when there is no right
        if(curr->right==NULL){
            // printf("%d ",curr->data);
            arr[i++] = curr->data;
            curr = curr->left;
        }
        // case 2 when right exists
        else{
            struct Node* ios=curr->right;
            while(ios->left && ios->left!=curr){
                ios = ios->left;
            }
            if(ios->left==NULL){
                //create thread
                // printf("%d ",curr->data);
                arr[i++] = curr->data;
                ios->left = curr;
                curr = curr->right;
            }
            else{
                // ios->left == curr
                // cut the thread
                ios->left = NULL;
                curr = curr->left;
            }
        }
    }
    for(int i=5-1; i>=0; i--){
        printf("%d ",arr[i]);
    }
}

void preorder(struct Node* root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    struct Node* root = createNode(7);
    struct Node* node1 = createNode(2);
    struct Node* node2 = createNode(3);
    struct Node* node3 = createNode(1);
    struct Node* node4 = createNode(4);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node2->right = node4;

    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    printf("morrisTraversalPreorder: ");
    morrisTraversalPreorder(root);
    printf("\n");
    printf("morrisTraversal: ");
    morrisTraversal(root);
    printf("\n");
    printf("morrisTraversalPostorder: ");
    morrisTraversalPostorder(root);
    printf("\n");
    return 0;
}