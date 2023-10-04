#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

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
    return 0;
}