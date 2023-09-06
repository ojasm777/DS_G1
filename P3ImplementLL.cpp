#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }

    // ListNode(int val) : val(val) , next(nullptr){}
};

class LinkedList{ // User defined data type
public:
    ListNode* head;
    ListNode* tail;
    int size;
    LinkedList(){
        head=tail=NULL;
        size=0;
    }

    void insertAtTail(int val){
        ListNode* node=new ListNode(val);
        if(size==0) head=tail=node;
        else{
            tail->next=node;
            tail=node;
        }
        size++;
    }

    void insertAtHead(int val){
        ListNode* node=new ListNode(val);
        if(size==0) head=tail=node;
        else{
            node->next=head;
            head=node;
        }
        size++;
    }

    void insertAt(int idx,int val){
        if(size==0) insertAtHead(val);
        if(size==idx) insertAtTail(val);
        if(idx>size|| idx<0){
            cout<<"Invalid index"<<endl;
            return;
        }
        else{
            ListNode* temp=head;
            ListNode* node=new ListNode(val);
            for(int i=0; i<idx-1; i++){
                temp=temp->next;
            }
            node->next=temp->next;
            temp->next=node;
            size++;
        }
    }

    void deleteAtHead(){
        if(size==0){
            cout<<"List is Empty"<<endl;
        }
        else if(size==1){
            head=tail=NULL;
            size--;
        }
        else{
            head=head->next;
            size--;
        }
    }

    void deleteAtTail(){
        if(size==0) cout<<"List is empty"<<endl;
        else if(size==1){
            head=tail=NULL;
            size--;
        }
        else{
            ListNode* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size--;
        }
    }

    void display(){
        ListNode* temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void deleteAtIndex(int idx){
        if(size==0) cout<<"List is empty";
        else if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtTail();
        else{
            ListNode* temp=head;
            for(int i=1; i<idx; i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            size--;
        }
    }


};
int main(){
    LinkedList ll;
    ll.insertAtHead(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.display();
    ll.insertAt(1,15);
    ll.display();
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    cout<<ll.size<<endl;
    ll.insertAt(1,14);
    ll.insertAtTail(100);
    ll.display();
    ll.deleteAtIndex(2);
    ll.display();

    return 0;
}