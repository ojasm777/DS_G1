#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
void insertAtHead(struct Node* head,int val){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=val;
    temp->next=head;
    head=temp;
}

void insertAtIdx(struct Node* head,int idx,int val){
    if(head==NULL) return;
    if(idx==0) insertAtHead(head,val);
    struct Node* temp=head;
    struct Node* insert=(struct Node*)malloc(sizeof(struct Node*));
    insert->data=val;
    for(int i=0; i<idx-1; i++){
        temp=temp->next;
    }
    insert->next=temp->next;
    temp->next=insert;
}

int main(){
    struct Node* head,*second,*third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    second->data=7;
    third->data=100;
    head->next=second;
    second->next=third;
    third->next=NULL;

    struct Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    insertAtIdx(head,2,20);
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}