#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int ispresent(int val, int* arr, int size){
    for(int i=0; i<size; i++){
        if(arr[i]==val) return 1;
    }
    return 0;
}

void setUnion(struct Node* head1, struct Node* head2){
    int arr[100]; // sufficient size
    struct Node* temp=head1;

    int i=0;
    while(temp!=NULL){
        if(!ispresent(temp->data,arr,i)){
            arr[i]=temp->data;
            i++;
        }
        temp=temp->next;
    }

    struct Node* temp2=head2;
    while(temp2!=NULL){
        if(!ispresent(temp2->data,arr,i)){
            arr[i]=temp2->data;
            i++;
        }
        temp2=temp2->next;
    }

    for(int j=0; j<i; j++){
        printf("%d ",arr[j]);
    }
    printf("\n");

    struct Node* ansHead=(struct Node*)malloc(sizeof(struct Node*));
    temp=ansHead;
    for(int j=0; j<i; j++){
        struct Node* node=(struct Node*)malloc(sizeof(struct Node*));
        node->data=arr[j];
        node->next=NULL;
        temp->next=node;
        temp=temp->next;
    }
    temp=ansHead->next;
    printf("Linked List 3: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

int main(){
    struct Node* head,*second,*third,*fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    second->data=7;
    third->data=100;
    fourth->data=109;
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    struct Node* head2,*second2,*third2,*fourth2;
    head2=(struct Node*)malloc(sizeof(struct Node));
    second2=(struct Node*)malloc(sizeof(struct Node));
    third2=(struct Node*)malloc(sizeof(struct Node));
    fourth2=(struct Node*)malloc(sizeof(struct Node));

    head2->data=200;
    second2->data=100;
    third2->data=1;
    fourth2->data=10;
    head2->next=second2;
    second2->next=third2;
    third2->next=fourth2;
    fourth2->next=NULL;


    struct Node* temp=head;
    printf("Linked List 1: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

    struct Node* temp2=head2;
    printf("Linked List 2: ");
    while(temp2!=NULL){
        printf("%d ",temp2->data);
        temp2=temp2->next;
    }
    printf("\n");

    setUnion(head,head2);
    // int arr[]={1,2,3,4};
    // printf("%d",ispresent(4,arr,4));
    return 0;
}