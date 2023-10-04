#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

struct Node* f = NULL;
struct Node* r = NULL;

void enQueue(int val){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node*));
    if(n==NULL){
        printf("Queue is Full!\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(f == NULL){
            f=n;
            r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

void deQueue(){
    if(f==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp=f;
    f=f->next;
    free(temp);
}

void display(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){

    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    
    display(f);

    deQueue();
    deQueue();
    deQueue();

    display(f);
    return 0;
}