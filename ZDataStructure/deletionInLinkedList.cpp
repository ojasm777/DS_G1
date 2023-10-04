#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* deleteAtHead(struct Node* head){
    if(head==NULL) return NULL;
    struct Node* temp=head;
    head=temp->next;
    free(temp);
    return head;
}

struct Node* deleteAtIdx(struct Node* head,int idx){
    if(head==NULL) return NULL;
    if(idx==0) return deleteAtHead(head);
    struct Node* ptr=head;
    for(int i=0; i<idx-1; i++){
        ptr=ptr->next;
    }
    struct Node* temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    return head;
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

    head=deleteAtIdx(head,1);

    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}